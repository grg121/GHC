#include <list>
#include "punto.h"

using namespace std;

class Satelite{
    private:
        const long int 
            ini_lon,   //longitud inicial
            ini_lat,    //latitud inicial
            velocidad,  //velocidad satelite (v>0 -> hacia el sur)
            w,          //max arcsec change through turns
            d;          //max total arcsec change
        
        list<Punto*> list_puntos;   //Lista de puntos que puede abarcar
        
        inline long int adjust_lat(long int arcs);
        inline long int adjust_lon(long int arcs);
    
        struct Area{
            long int 
                centro,
                left_limit,
                right_limit,
                top_limit,
                bottom limit;
            
            list<Punto *> list_puntos_posibles;
            
            Area(long int centro, long int d):
                centro(centro),
                left_limit(adjust_lon(centro-d)),
                right_limit(adjust_lon(centro+d)),
                top_limit(adjust_lat(centro+d)),
                bottom_limit(adjust_lat(centro-d))
            {};
                
        };
        list<Area> list_areas;

    public:
        Satelite(long int ini_lon, long int ini_lat, long int vel, long int w, long int d);
        bool pertenece_punto(Punto * p);
        void aniade_punto(Punto * p);
        list<pair<Punto,long int> > get_optimo();            
}