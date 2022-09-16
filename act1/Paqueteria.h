#ifndef PAQUETERIA_H_INCLUDED
#define PAQUETERIA_H_INCLUDED
#include <iostream>
#include <vector>
using namespace std;

class Paqueteria{
    vector<Paquete> paquetes;
public:
        void InsertarALInicio(Paquete paquete){
            paquetes.push_back(paquete);
        }

        void EliminarAlInicio(){
            vector<Paquete> ::iterator it = paquetes.begin();
            it = paquetes.erase(it);
        }
};




#endif // PAQUETERIA_H_INCLUDED
