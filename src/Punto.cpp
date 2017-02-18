#include "Punto.h"

int Punto::getPriority(){
    /*
     * sum = para cada coleccion, sum += valor/tam
     * prioridad = sum/numero de satelites que tienen acceso al punto
     */

    int output = 0 ;
    int a,b,c  ;
    a = b = c = 1 ;
    set<Coleccion*>::iterator it = colecciones.begin() ;
    int tam, pun ;
    while(it != colecciones.end()){
        tam = (*it)->getTamListPuntos() ;
        pun = (*it)->getPuntiacion ;
        output += ((pun/tam)/satelites.size()) ;
        ++it ;
    }
    return output ;
}

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

void Punto::insertc(Coleccion * c){
    colecciones.insert(c) ;
}

void Punto::inserts(Satelite * s){
    satelites.insert(s) ;
}

bool Punto::usado(){
    if (owner < 0)
        return false ;
    else return true ;
}

void Punto::removc(Coleccion * c){
    colecciones.erase(c) ;
}

void Punto::removs(Satelite *s){
    satelites.erase(s) ;
}

/**
 * Devuelve el satélite encargado de fotografiar el punto
 */
int Punto::getOwner(){
    return owner ;
}
