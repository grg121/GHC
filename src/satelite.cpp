#include "satelite.h"
#include <math.h>

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
    return esta;
}

bool pertenece Satelite::Area::pertenece(Punto * p){
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
