#include <iostream>
#include "coleccion.h"

using namespace std;

Coleccion::Coleccion(long int puntuacion, list<long int> & rangos, list<Punto*> &puntos){
  this->puntuacion = puntuacion;
  this->rangos = rangos;
  this->puntos = puntos;
}

int Coleccion::getTamListPuntos() const{
  return puntos.size();
}

long int Coleccion::getPuntuacion() const{
  return puntuacion;
}

list<long int> & Coleccion::getRangos() const{
  return rangos;
}

list<Punto> & Coleccion::getListPuntos() const{
  return puntos;
}
