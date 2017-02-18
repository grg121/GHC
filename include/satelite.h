#include <list>
#include <unordered_set>
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
    long int lon_offset = 0, lat_offset = 0;
    Point* objetivo = NULL;
    for(; it != list_areas.end(); ++it){
        if(objetivo && )
    }
}
