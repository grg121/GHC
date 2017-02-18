Punto(int long, int lat){
    longitud = long ;
    latitud = lat ;
}

int getLongitud(){
    return longitud ;
}

int getLatitud(){
    return latitud ;
}

set<int> getColecciones(){
    return colecciones ;
}

set<int> getSatelites(){
    return satelites ;
}

void insertc(int c){
    colecciones.insert(c) ;
}

void inserts(int s){
    satelites.inset(s) ;
}

bool usado(){
    if (owner < 0)
        return false ;
    else return true ;
}

/**
 * Devuelve el satélite encargado de fotografiar el punto
 */
int getOwner(){
    return owner ;
}
