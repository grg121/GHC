#include <iostream>
#include <list>
#include "Punto.h"

using namespace std;

class Coleccion{
  private:
    const long int puntuacion;
    list<long int> rangos;
    list<Punto*> puntos;
  public:
    /**
      Constructor con parametros
    */
    Coleccion(long int puntuacion, list<long int> & rangos, list<Punto*> &puntos);
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
    list<long int> & getRangos() const;
    /**
    * Devuelve la lista de puntos
    */
    list<Punto> & getListPuntos() const;
};
