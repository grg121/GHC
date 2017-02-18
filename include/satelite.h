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

        long int lat_plus(long int arcs);
        long int long_plus(long int arcs);
    
    public:
        bool pertenece_punto(Punto * p);
        void aniade_punto(Punto * p);
        list<pair<Punto,long int> > get_optimo();
}