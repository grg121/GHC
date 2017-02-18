#include "satelite.h"

inline bool adjust_lat(int &arcs){
  bool desborda;
  if (arcs >= ((-90)*3600) && arcs <= (90*3600) ) {
    desborda = false;
  }
  else if(arcs < ((-90)*3600)){
    arcs = (-180*3600) - arcs;
    desborda = true;
  }
  else if(arcs > (90*3600)){
    arcs = 180*3600 - arcs;
    desborda = true;
  }
  return desborda;
}

inline bool adjust_lon(int &arcs){
  bool desborda;
  if (arcs <= (180*3600)-1 && arcs >= (-180*3600)) {
    desborda = false;
  }
  else if(arcs < (-180*3600)){
    arcs += 180*3600*2;
    desborda = true;
  }
  else if(arcs > (180*3600)-1){
    arcs -= 180*3600*2;
    desborda = true;
  }
  return desborda;
}
