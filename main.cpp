#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include "satelite.h"
#include "coleccion.h"
#include "Punto.h"

using namespace std;



int main (int argc, char *argv[]){
    int tiempo, nsatelites, ncolecciones, 
    vector<Satelite> satelites;
    vector<Coleccion> colecciones;
    unordered_map<pair<int,int>, Punto*> mapapuntos;
    list<Punto*> puntos;

    ifstream in (argv[1]);
    ofstream out ("salida.txt");

    in >> tiempo >> nsatelites;

    for (int i= 0; i < nsatelites; i++){
        int lat, lon, vel, w, d;

        in >> lat >> lon >> vel >> w >> d;

        Satelite s (lat, lon, vel, w, d, tiempo);
        satelites.push_back (s);
    }

    in >> ncolecciones;

    for (int i= 0; i < ncolecciones; i++){
        long int valor;
        int nfotos, nrangos;
        list<pair<int,int> > rangos;

        in >> valor >> nfotos >> nrangos;

        for (int j= 0; j < nfotos; j++){
            int lat_foto, lon_foto;
            pair<int, int> punto_foto;
            in >> lat_foto >> lon_foto;

            punto_foto.first= lat_foto;
            punto_foto.second= lon_foto;

            Punto *p= new Punto (lat_foto, lon_foto);

            unordered_map<pair <int, int>, Punto*>::iterator it;

            it= mapapuntos.find (punto_foto);

            // Si ya existia el punto añade la nueva coleccion
            if (it != mapapuntos.end()){
                (*it).second.insertc (i);
            }
            // Si no crea
            else{
                mapapuntos.insert (pair < pair <int, int>, Punto*> (punto_foto, p));
            }

            puntos.push_back (p);

        }

        for (int j= 0; j < nrangos; j++){
            int ran_i, ran_s;

            in >> ran_i >> ran_s;

            pair<int, int> rango (ran_i, ran_s);

            rangos.push_back (rango);
        }

        colecciones.push_back (valor, puntos, rangos);

    }

    unordered_map <pair <int, int>, Punto*> it;

    for (it= mapapuntos.begin(); it != mapapuntos.end(); ++it){
        for (int i= 0; i < satelites.size(); i++){
            if (satelites.pertenece_punto ((*it).second)){
                (*(*it).second).inserts (i);
            }
        }
    }

    // Comienza el juego
    for (int i= 0; i < tiempo; i++){

    }


    out.close();
}