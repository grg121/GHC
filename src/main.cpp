#include <iostream>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <math.h>
#include "coleccion.h"
#include "Punto.h"
#include "satelite.h"

using namespace std;


int main (int argc, char *argv[]){
    int tiempo, nsatelites, ncolecciones;
    vector<Satelite*> satelites;
    vector<Coleccion*> colecciones;
    map<pair<int,int>, Punto*> mapapuntos;

if (argc != 2){
        cout << "\nPasa el fichero de entrada enferm@\n";
        return -1;
    }

    ifstream in (argv[1]);
    ofstream out ("salida.txt");

    in >> tiempo >> nsatelites;

    // Lanzando satelites en orbita
    for (int i= 0; i < nsatelites; i++){
        int lat, lon, vel, w, d;

        in >> lat >> lon >> vel >> w >> d;

        Satelite *s= new Satelite (i, lon, lat, vel, w, d, tiempo);
        satelites.push_back (s);
    }

    in >> ncolecciones;

    // Estableciendo colecciones
    for (int i= 0; i < ncolecciones; i++){
        list<Punto*> puntos;
        list<pair<int,int> > rangos;

        int valor;
        int nfotos, nrangos;

        in >> valor >> nfotos >> nrangos;
        // Iniciando puntos de esa coleccion
        for (int j= 0; j < nfotos; j++){
            int lat_foto, lon_foto;
            pair<int, int> punto_foto;
            in >> lat_foto >> lon_foto;

            punto_foto.first= lat_foto;
            punto_foto.second= lon_foto;

            Punto *p= new Punto (lon_foto, lat_foto);
            
            if(mapapuntos.count(punto_foto)==0)
                mapapuntos.insert (pair < pair <int,int>, Punto*> (punto_foto, p));
            
            puntos.push_back (p);

        }
        for (int j= 0; j < nrangos; j++){
            int ran_i, ran_s;

            in >> ran_i >> ran_s;

            pair<int, int> rango (ran_i, ran_s);

            rangos.push_back (rango);
        }

        Coleccion *c= new Coleccion (valor, rangos, puntos);
        colecciones.push_back (c);

        // Insertamos colecciones en cada punto

        for (list<Punto*>::iterator it= puntos.begin(); it != puntos.end(); ++it){
            (*it)->insertc (colecciones[i]);
        }
    }

    // Establecer en cada punto su posible satelite
    map <pair <int,int>, Punto*>::iterator it;

    for (it= mapapuntos.begin(); it != mapapuntos.end(); ++it){
        for (int i= 0; i < satelites.size(); i++){
            if (satelites[i]->pertenece_punto ((*it).second)){
                (*it).second->inserts (satelites[i]);
            }
        }
    }

     // Comienza el juego
    for (int i= 0; i < nsatelites; i++){
        list<pair <Punto *, long int> > cogidos= satelites[i]->get_optimo();
        unordered_set<Punto *> quitados= satelites[i]->get_puntos();

        for (list<pair <Punto *, int> >::iterator iter= cogidos.begin(); iter != cogidos.end(); ++iter){
            out << (*iter).first->getLatitud() << " " << 
            (*iter).first->getLongitud() << " " << i << " " <<
            (*iter).second << endl;
        }

        for (unordered_set<Punto*>::iterator iter= quitados.begin(); iter != quitados.end(); ++iter){
            (*iter)->removs (satelites[i]);
        }

    }


    // PRUEBA DEL PAÑUELO
    out << tiempo << endl << satelites.size() << endl;

    for (int i= 0; i < satelites.size(); i++){
        out << "POS INICIO" << endl;
    }

    out << colecciones.size() << endl;

    for (int i= 0; i < colecciones.size(); i++){
        list<Punto*> lis_p=  colecciones[i]->getListPuntos();
        list<pair<int,int> > lis_r= colecciones[i]->getRangos();
        out << colecciones[i]->getPuntuacion() << " "
        << lis_p.size() << " "
        << lis_r.size() << endl;

        for (list<Punto*>::const_iterator iter= lis_p.begin();
            iter != lis_p.end(); ++iter){
                out << (*iter)->getLatitud() << " " 
                << (*iter)->getLongitud() << " " << endl;
        }

        for (list<pair<int,int> >::const_iterator iter= lis_r.begin();
            iter != lis_r.end(); ++iter){
                out << (*iter).first << " " << (*iter).second << endl;
            }
    }
    // ALI ALI OOOOH

    out.close();
}

