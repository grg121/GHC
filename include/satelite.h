#include <list>
#include "Punto.h"

using namespace std;

class Satelite{
    private:
        const long int
            ini_lon,   //longitud inicial
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
                centro,
                left_limit,
                right_limit,
                top_limit,
                bottom limit;

            list<Punto *> list_puntos_posibles;

            Area(long int centro, long int d):
                centro(centro)
            {
                bool dummy;
                left_limit = adjust_lon(centro-d,dummy);
                right_limit = adjust_lon(centro+d,dummy);
                top_limit = adjust_lat(centro+d,dummy);
                bottom_limit = adjust_lat(centro-d,dummy );
            };
            list<Area> list_areas;      
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
        Area a()
        list_areas.push_back(Area())
    }

}

bool Satelite::pertenece_punto(Punto *p){
    bool esta = false;
    list<Punto *>::const_iterator it;
    for(it = list_areas.begin(); it != list_areas.end(); ++it){
        bool en_area = true;
        en_area = en_area && ((*it)->left_limit <= p->getLongitud());
        en_area = en_area && ((*it)->right_limit >= p->getLongitud());
        en_area = en_area && ((*it)->top_limit >= p->getLatitud());
        en_area = en_area && ((*it)->bottom_limit <= p->getLatitud());

        if(en_area){
            esta = true;
            (*it)->push_back(p);
        }
    }
    return esta;
}

//list<pair<Punto, long int> > Satelite::get_optimo(){
//
//}
