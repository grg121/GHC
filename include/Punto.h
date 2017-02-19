#ifndef _PUNTO_PUNTO_H_
#define _PUNTO_PUNTO_H_

#include<set>
#include<coleccion.h>
#include<satelite.h>


using namespace std;

class Punto {

private:

    int longitud, latitud ;

    set<Coleccion*> colecciones ;
    set<Satelite*> satelites ;

    int owner ;

public:

    Punto(int longitud, int lat, int owner = -1) ;
    int getLongitud() ;
    int getLatitud() ;
    set<Coleccion*> getColecciones() ;
    set<Satelite*> getSatelites() ;
    void insertc(Coleccion * c) ;
    void inserts(Satelite * s) ;
    void removc(Coleccion * c) ;
    void removs(Satelite * s) ;
    bool usado() ;

    // Devuelve el satélite encargado de fotografiar el punto
    int getOwner() ;

    void setOwner(int id){
    	owner = id;
    }

    /**
     * Más prioridad == más importante
     * Factores: menos satélites, más conjuntos, no está.
     **/

    int getPriority() ;
};

#endif
