#include<Punto.h>
#include<iostream>
using namespace std;

int main(){

    Punto punto(5,5) ;

    cout << "La longitud es " << punto.getLongitud() << endl
         << "La latitud es " << punto.getLatitud() ;

    punto.insertc(1) ;
    punto.insertc(2) ;
    punto.insertc(3) ;

    punto.inserts(1) ;
    punto.inserts(5) ;
    punto.inserts(10) ;

    set<int> satelites = punto.getSatelites() ;

    set<int>::iterator it = satelites.begin() ;

    while(it != satelites.end() ){
        cout << * it ;
        ++it ;
    }


}
