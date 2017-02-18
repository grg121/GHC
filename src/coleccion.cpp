#include <iostream>
#include "coleccion.h"

using namespace std;

Coleccion::Coleccion(long int puntuacion, list<pair<int,int> > & rangos, list<Punto*> &puntos):
  puntuacion(puntuacion),
  rangos(rangos),
  puntos(puntos)
  {}

int Coleccion::getTamListPuntos() const{
  return puntos.size();
}

long int Coleccion::getPuntuacion() const{
  return puntuacion;
}

const list<pair<int,int> >& Coleccion::getRangos() const{
  return rangos;
}

const list<Punto*> & Coleccion::getListPuntos() const{
  return puntos;
}
