#include <iostream>
#include "coleccion.h"

using namespace std;

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
