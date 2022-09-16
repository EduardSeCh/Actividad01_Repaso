#ifndef PAQUETE_H_INCLUDED
#define PAQUETE_H_INCLUDED

using namespace std;

class Paquete{
    int id;
    int peso;
    int *origen;
    int *destino;
public:
        void setId(int id){
            this->id = id;
        }
        int getId(){
            return this->id;
        }

        void setPeso(int peso){
            this->peso = peso;
        }
        int getPeso(){
            return this->peso;
        }

        void setOrigen(int origen){
            this->origen = &origen;
        }
        int* getOrigen(){
            return this->origen;
        }

        void setDestino(int destino){
            this->destino = &destino;
        }
        int* getDestino(){
            return this->destino;
        }
};



#endif // PAQUETE_H_INCLUDED
