#ifndef PAQUETE_H_INCLUDED
#define PAQUETE_H_INCLUDED

using namespace std;

class Paquete{
    int id;
    float peso;
    string origen;
    string destino;
public:
        void setId(int idP){
            id = idP;
        }
        int getId(){
            return id;
        }

        void setPeso(float pesoP){
            peso = pesoP;
        }
        float getPeso(){
            return peso;
        }

        void setOrigen(string origenP){
            origen = origenP;
        }
        string getOrigen(){
            return origen;
        }

        void setDestino(string destinoP){
            destino = destinoP;
        }
        string getDestino(){
            return destino;
        }
};



#endif // PAQUETE_H_INCLUDED
