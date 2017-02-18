#include "satelite.h"

inline bool adjust_lat(int &arcs){
  bool desborda;
  if (arcs >= ((-90)*3600) && arcs <= (90*3600) ) {
    desborda = false;
  }
  else if(arcs < ((-90)*3600)){
    arcs = (-180) - arcs;
    desborda = true;
  }
  else if(arcs > (90*3600)){
    arcs = 180 - arcs;
    desborda = true;
  }
  return desborda;
}

inline int adjust_lon(int arcs, bool &desb){
  if (arcs <= 647999 && ) {
    /* code */
  }
}
