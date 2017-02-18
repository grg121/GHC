#include "satelite.h"

inline long int adjust_lat(long int arcs, bool & cambia_velocidad){
  long int resultado;
  arcs *= 3600;
  if (arcs >= (-90) && arcs <= 90) {
    resultado = arcs;
    cambia_velocidad = false;
  }
  else if(arcs > 90){
    resultado = 180 - arcs;
    cambia_velocidad = true;
  }
  else if(arcs < (-90)){
    resultado = (-180) - arcs;
    cambia_velocidad = true;
  }
  return resultado;
}

inline long int adjust_lon(long int arcs, bool & cambia_velocidad){
  long int resultado;
  arcs *= 3600;
  if (arcs >= (-90) && arcs <= 90) {
    resultado = arcs;
    cambia_velocidad = false;
  }
  else {
    resultado = (-180) + arcs;
    cambia_velocidad = true;
  }
  return resultado;
}
