#include<set>

class Punto {

private:

    int longitud, latitud ;

    set<int> coleccioneses ;
    set<int> satelites ;

    int owner = -1 ;

public:

    Punto(int long, int lat) ;
    int getLongitud() ;
    int getLatitud() ;
    set<int> getColecciones() ;
    set<int> getSatelites() ;
    void insertc(int c) ;
    void inserts(int s) ;
    bool usado() ;

    // Devuelve el satélite encargado de fotografiar el punto
    int getOwner() ;

}
