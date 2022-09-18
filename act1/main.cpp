#include <iostream>
#include "Paquete.h"
#include "Paqueteria.h"
#include <fstream>
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif // _WIN32

using namespace std;
enum {AGREGAR=1,ELIMINAR,MOSTRAR,GUARDAR,RECUPERAR,SALIR};
Paquete packet;
Paqueteria carrito;
int contador=1;
void MenuPrincipal(int& opc);
int opcionesMenu(int& opc);
void agregarPaquete();
void eliminarPaquete();
void pausar();

int main(){
    int opc;
    MenuPrincipal(opc);
    return 0;
}

void MenuPrincipal(int& opc){
    do{
        opcionesMenu(opc);
        switch(opc){
            case AGREGAR:
                agregarPaquete();
                break;
            case ELIMINAR:
                carrito.eliminarAlInicio();
                break;
            case MOSTRAR:
                carrito.listarPaquetes();
                break;
            case GUARDAR:
                carrito.guardarParaRecuperar();
                carrito.guardarPaquetes();
                break;
            case RECUPERAR:
                contador = carrito.recuperarArchivo();
                break;
            case SALIR:
                break;
            default:
            cout<<"Opcion no valida...";
        }
    }
    while(opc!=SALIR);
}

int opcionesMenu(int& opc){
    system(CLEAR);
    cout<<"Menu Principal"<< endl;
    cout<<"1.Agregar paquete"<<endl;
    cout<<"2.Eliminar paquete"<<endl;
    cout<<"3.Mostrar paquete"<<endl;
    cout<<"4.Guardar paquete"<<endl;
    cout<<"5.Recuperar paquete"<<endl;
    cout<<"6.Salir"<<endl;
    cin>>opc;
    return opc;
}

void agregarPaquete(){
    system(CLEAR);
    float peso;
    string origen;
    string destino;

    packet.setId(contador);
    cout<<"Paquete #"<<packet.getId()<<endl;
    cout<<"Peso (kg): ";
    cin>>peso;
    packet.setPeso(peso);
    cin.get();
    cout<<"Origen: ";
    getline(cin,origen);
    packet.setOrigen(origen);
    cout<<"Destino: ";
    getline(cin,destino);
    packet.setDestino(destino);
    carrito.insertarALInicio(packet);
    cout<<"Paquete agregado al carrito"<<endl;
    contador++;
    carrito.pausar();
}
