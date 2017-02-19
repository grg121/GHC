#include "satelite.h"
#include <math.h>

Satelite::Satelite(long int id, long int ini_lon, long int ini_lat, long int vel, long int w, long int d, long int pasos):
    id(id),
    ini_lat(ini_lat),
    ini_lon(ini_lon),
    velocidad(v),
    w(w),
    d(d),
    pasos(pasos)
{
    long int
        vel = v,
        lat = ini_lat,
        lon = ini_lon;
    for(long int i=0; i<pasos; i++){
        Satelite::Area a(lon, lat, d);
        list_areas.push_back(a);
        if(adjust_lat(lat+=v)){
            lon-=180;
            vel*=-1;
        }
        adjust_lon(lon-=15);
    }

}

list<pair<Punto*, long int> > Satelite::get_optimo(){
    const long int RESOLUCION = 2*d/w;
    list<pair<Punto*, long int> > resultado;

    list<Area>::iterator it, fin;
    ini = fin = list_areas.begin();
    for(long int i=0; i<RESOLUCION && fin != list_areas.end(); i++)
        ++fin;

    list<Satelite::Area> proximos(it, fin);
    long int    lon = ini_lon,
                lat = ini_lat,
                vel = velocidad, 
                lon_offset = 0, 
                lat_offset = 0;
    Point* objetivo = NULL;
    for(int i=0; it != list_areas.end(); ++it, i++){
        lon = it->lon;
        lat = it->lat;
        Area a(lon + lon_offset, lat + lat_offset,w);
        //Compruebo si llego al punto
        if(objetivo && a.pertenece(objetivo)){
            lon_offset = p->getLongitud() - lon;
            lat_offset = p->getLatitud() - lat;
            objetivo->setOwner(id);
            resultado.push_back(make_pair(objetivo,i));
            objetivo = NULL;
        
        //Elijo punto y desplazo el offset
        }else{
            //Elijo el mejor punto
            //TODO LOGICA RANGO
            list<Satelite::Area>::const_reverse_iterator it1;
            list<Punto *>::const_iterator it2;
            long int i_plano, j=RESOLUCION;
            for(it1 = proximos.rbegin(); it1 != proximos.rend(); ++it1){
                RESOLUCION--;
                for(it2 = it1->list_puntos_posibles.begin(); it2 >= it1->list_puntos_posibles.end()){
                    if(!objetivo || ((*it2)->getPriority() > objetivo->getPriority())){
                        objetivo = *it2;
                        i_plano = j;
                    }
                }
            }
            //Actualizo offset
            int num_pasos_h,num_pasos_v;
            it1 = proximos.begin()
            for(int i = 0 ; i < i_plano; i++, ++it1){}//For vacío
            it1->pasosHasta(objetivo,lon_offset, lat_offset, w,w,num_pasos_h,num_pasos_v);
            if(i_plano <= abs(num_pasos_h))
                if(num_pasos_h > 0)
                    lon_offset += w;
                else if(num_pasos_h < 0)
                    lon_offset -= w;
            if(i_plano <= abs(num_pasos_v))
                if(num_pasos_v > 0)
                    lat_offset += w;
                else if(num_pasos_v < 0)
                    lat_offset -= w;
        }
        //Actualizar lista siguientes
        if(fin != list_areas.end()){
            proximos.push_back(*fin);            
            ++fin;
        }
        proximos.pop_fron();
    }
}

inline bool adjust_lat(int &arcs){
  bool desborda = false;
  if(arcs < ((-90)*3600)){
    arcs = (-180*3600) - arcs;
    desborda = true;
  }
  else if(arcs > (90*3600)){
    arcs = 180*3600 - arcs;
    desborda = true;
  }
  return desborda;
}

inline bool adjust_lon(int &arcs){
  bool desborda = false;
  else if(arcs < (-180*3600)){
    arcs += 360*3600;
    desborda = true;
  }
  else if(arcs > (180*3600)-1){
    arcs -= 360*3600;
    desborda = true;
  }
  return desborda;
}

bool Satelite::pertenece_punto(Punto *p){
    bool esta = false;
    list<Area>::const_iterator it;
    for(it = list_areas.begin(); it != list_areas.end(); ++it){
        bool en_area = (*it).pertenece(p);

        if(en_area){
            esta = true;
            it->list_puntos_posibles.push_back(p);
        }
    }
    if(esta)
        set_puntos.insert(p);
    return esta;
}

bool Satelite::Area::pertenece(Punto * p){
  bool pertenece = false;
  if (p->getLatitud() <= top_limit && p->getLatitud >= bottom_limit) {
    if (desb_rig) {
      pertenece = p->getLongitud() <= right_limit && p->getLongitud <= left_limit;
    }
    else if (desb_lef) {
      pertenece = p->getLongitud() >= left_limit && p->getLongitud() >= right_limit;
    }
    else{
      pertenece = p->getLongitud() >= left_limit && p->getLongitud() <= right_limit;
    }
  }
  return pertenece;
}

void Satelite::Area::pasosHasta(
    Punto * p,
    long int hor_offset, long int ver_offset,
    long int lim_hor, long int lim_ver,
    long int & hor, long int & ver)
{
      double horizontal = 1.0*(p->getLongitud()-(lon+hor_offset)) / lim_hor;
      double vertical = 1.0*(p->getLatitud()-(lat+ver_offset)) / lim_ver;
      if (horizontal < 0.0)
        horizontal -= 1.0;
      if (vertical < 0.0)
        vertical -= 1.0;
      hor = ceil(horizontal);
      ver = ceil(vertical);
}
