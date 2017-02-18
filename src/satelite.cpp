#include "satelite.h"

inline bool adjust_lat(int &arcs){
  bool desborda = false;
  if(arcs < ((-90)*3600)){
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
  bool desborda = false;
  else if(arcs < (-180*3600)){
    arcs += 360*3600;
    desborda = true;
  }
  else if(arcs > (180*3600)-1){
    arcs -= 360*3600;
    desborda = true;
  }
  return desborda;
}

bool Satelite::pertenece_punto(Punto *p){
    bool esta = false;
    list<Punto *>::const_iterator it;
    for(it = list_areas.begin(); it != list_areas.end(); ++it){
        bool en_area = true;
        en_area = en_area && ((*it)->left_limit <= p->getLongitud());
        en_area = en_area && ((*it)->right_limit >= p->getLongitud());
        en_area = en_area && ((*it)->top_limit >= p->getLatitud());
        en_area = en_area && ((*it)->bottom_limit <= p->getLatitud());

        if(en_area){
            esta = true;
            (*it)->push_back(p);
        }
    }
    return esta;
}
