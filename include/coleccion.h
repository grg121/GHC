#ifndef _COLECCION_H_
#define _COLECCION_H_

#include <iostream>
#include <list>
#include "Punto.h"

using namespace std;

class Coleccion{
  private:
    const long int puntuacion;
    list<pair<int,int> > rangos;
    list<Punto *> puntos;
  public:
    /**
      Constructor con parametros
    */
    Coleccion(long int puntuacion, list<pair<int,int> > & rangos, list<Punto*> &puntos):
    	  puntuacion(puntuacion),
    	  rangos(rangos),
    	  puntos(puntos)
    	  {};
    /**
    * Devuelve el tamaño de la lista de punteros a Puntos
    */
    int getTamListPuntos() const;
    /**
    * Devuelve la puntuacion
    */
    long int getPuntuacion() const;
    /**
    * Devuelve la lista de rangos
    */
    const list<pair<int,int> > & getRangos() const;
    /**
    * Devuelve la lista de puntos
    */
    const list<Punto*> & getListPuntos() const;
};

#endif
