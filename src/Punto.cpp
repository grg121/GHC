#include "Punto.h"

Punto::Punto(int longitud, int lat){
    longitud = longitud ;
    latitud = lat ;
}

int Punto::getLongitud(){
    return longitud ;
}

int Punto::getLatitud(){
    return latitud ;
}

set<int> Punto::getColecciones(){
    return colecciones ;
}

set<int> Punto::getSatelites(){
    return satelites ;
}

void Punto::insertc(int c){
    colecciones.insert(c) ;
}

void Punto::inserts(int s){
    satelites.insert(s) ;
}

bool Punto::usado(){
    if (owner < 0)
        return false ;
    else return true ;
}

void removc(int c){
    colecciones.erase(c) ;
}

void removs(int s){
    satelites.erase(s) ;
}

/**
 * Devuelve el satélite encargado de fotografiar el punto
 */
int Punto::getOwner(){
    return owner ;
}
