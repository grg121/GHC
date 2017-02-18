#include<set>
#include<satelite>
#include<coleccion>
class Punto {
private:
    int longitud, latitud ;

    set<int> coleccioneses ;
    set<int> satelites ;

    int owner = -1 ;

public:

    int getLongitud(){
        return longitud ;
    }

    int getLatitud(){
        return latitud ;
    }

    set<int> colecciones getColecciones(){
        return colecciones ;
    }

    set<int> satelites getSatelites(){
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

    int getOwner(){
        return owner ;
    }


}
