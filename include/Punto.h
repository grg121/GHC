#include<set>

using namespace std;

class Punto {

private:

    int longitud, latitud ;

    set<int> colecciones ;
    set<int> satelites ;

    int owner ;

public:

    Punto(int longitud, int lat) ;
    int getLongitud() ;
    int getLatitud() ;
    set<int> getColecciones() ;
    set<int> getSatelites() ;
    void insertc(int c) ;
    void inserts(int s) ;
    void removc(int c) ;
    void removs(int s) ;
    bool usado() ;

    // Devuelve el satélite encargado de fotografiar el punto
    int getOwner() ;

    /**
     * Menor prioridad == más importante
     * Factores: menos satélites, más conjuntos, no está.
     **/

    int getPriority() ;
};
