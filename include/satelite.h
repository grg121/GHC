#ifndef _SATELITE_H_
#define _SATELITE_H_

#include <list>
#include <unordered_set>
#include <stdlib.h>
#include "Punto.h"
#include "coleccion.h"


using namespace std;

inline bool adjust_lat(long int &arcs){
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

inline bool adjust_lon(long int &arcs){
  bool desborda = false;
  if(arcs < (-180*3600)){
    arcs += 360*3600;
    desborda = true;
  }
  else if(arcs > (180*3600)-1){
    arcs -= 360*3600;
    desborda = true;
  }
  return desborda;
}

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
        unordered_set<Punto *> set_puntos;   //Lista de puntos que puede abarcar


        struct Area{
            long int
            	lon,
            	lat,
            	left_limit,
            	right_limit,
            	top_limit,
            	bottom_limit;
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
            bool pertenece(Punto * p);
            void pasosHasta(Punto * p, long int hor_offset, long int ver_offset, long int lim_hor, long int lim_ver, long int & hor, long int & ver);

            friend class Satelite;

        };
        list<Area> list_areas;

    public:
        Satelite(long int id, long int ini_lon, long int ini_lat, long int vel, long int w, long int d, long int pasos);
        bool pertenece_punto(Punto * p);
        list<pair<Punto *,long int> > get_optimo();
        unordered_set<Punto *> get_puntos(){
            return set_puntos;
        }
};

#endif
