#ifndef _SATELITE_H_
#define _SATELITE_H_
#endif

#include <list>
#include <unordered_set>
#include <stdlib.h>
#include "Punto.h"


using namespace std;

class Satelite{
    private:
        const long int
            id,         //identificador satelite
            ini_lon,    //longitud inicial
            ini_lat,    //latitud inicial
            w,          //max arcsec change through turns
            d,          //max total arcsec change
            pasos;      //num total de pasos
        long int velocidad;  //velocidad satelite (v>0 -> hacia el sur)
        list<Punto*> list_puntos;   //Lista de puntos que puede abarcar

        inline long int adjust_lat(long int arcs, bool & cambia_velocidad);
        inline long int adjust_lon(long int arcs, bool & cambia_velocidad);
        struct Area{
            long int
                lon,lat,
                left_limit,
                right_limit,
                top_limit,
                bottom limit;
            bool desb_lef, desb_rig, desb_top, desb_bot;
            list<Punto *> list_puntos_posibles;

            Area(long int lon, long int lat, long int d):
                lon(lon),
                lat(lat)
            {
                /*
                    Tres casos:
                        -Desborda por la izquierda
                        -Desborda por arriba
                        -Desborda por abajo
                */
                //Left limit
                left_limit = lon-d;
                desb_lef = adjust_lon(left_limit);
                //Right limit
                right_limit = lon+d;
                desb_rig = adjust_lon(right_limit);
                //Top limit
                top_limit = lat+d;
                desb_top =  adjust_lat(top_limit);
                //Bottom limit
                bottom_limit = lat-d;
                desb_bot = adjust_lat(bottom_limit);

            };
            list<Area> list_areas;  

            bool pertenece(Punto * p);  
            void pasosHasta(Punto * p, long int lim_hor, long int lim_ver, long int & hor, long int & ver);  
        };

    public:
        Satelite(long int ini_lon, long int ini_lat, long int vel, long int w, long int d, long int pasos);
        bool pertenece_punto(Punto * p);
        list<pair<Punto,long int> > get_optimo();
}

Satelite::Satelite(long int ini_lon, long int ini_lat, long int vel, long int w, long int d):
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
        Satelite::Area a(lon, lat);
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
    for(long int i=0; i<RESOLUCION; i++)
        ++fin;

    list<Satelite::Area> proximos(it, fin);
    long int    lon = ini_lon,
                lat = ini_lat, 
                lon_offset = 0, 
                lat_offset = 0;
    Point* objetivo = NULL;
    for(int i=0; it != list_areas.end(); ++it, i++){
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
            it1->pasosHasta(objetivo,num_pasos_h,num_pasos_v);
            if(i_plano > abs(num_pasos_h))
                lon_offset += w;
        }

        //Actualizar lon, lat y lista siguientes
    }
}
