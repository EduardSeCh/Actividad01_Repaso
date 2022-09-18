#ifndef PAQUETERIA_H_INCLUDED
#define PAQUETERIA_H_INCLUDED
#include <iostream>
#include <vector>
#include <fstream>
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif // _WIN32
using namespace std;

class Paqueteria{
    vector<Paquete> paquetes;
public:
        void pausar(){
        cout << "Presiona entrar para continuar...";
        cin.get();
        }

        void insertarALInicio(Paquete paquete){
            paquetes.push_back(paquete);
        }

        void eliminarAlInicio(){
            if(paquetes.size() > 0){
                vector<Paquete> ::iterator it = paquetes.begin();
                it = paquetes.erase(it);
                cout<<"Paquete eliminado"<<endl;
                cin.get();
                pausar();
            }
            else {
                cout<<"Lista vacia..."<<endl;
                cin.get();
                pausar();
            }
        }

        void listarPaquetes(){
            system(CLEAR);
            if(paquetes.size()==0){
                cout<<"lista vacia..."<<endl;
                pausar();
            }
            for(size_t i=0; i< paquetes.size();i++){
                cout<<"Paquete #"<<paquetes[i].getId()<<endl;
                cout<<"Peso:"<<paquetes[i].getPeso()<<endl;
                cout<<"Origen:"<<paquetes[i].getOrigen()<<endl;
                cout<<"Destino:"<<paquetes[i].getDestino()<<endl<<endl;

            }
            cin.get();
            pausar();
        }

        void guardarPaquetes(){
            ofstream archivo("Paquetes.txt");
            if (archivo.is_open()){
                archivo << left;
                for(size_t i=0;i< paquetes.size();i++){
                    archivo<<"Paquete #"<<paquetes[i].getId()<<endl;
                    archivo<<"Peso:"<<paquetes[i].getPeso()<<endl;
                    archivo<<"Origen:"<<paquetes[i].getOrigen()<<endl;
                    archivo<<"Destino:"<<paquetes[i].getDestino()<<endl<<endl;
                }
            }
            archivo.close();
            cout<<"Lista de paquetes guardados"<<endl;
            cin.get();
            pausar();
        }

        void guardarParaRecuperar(){
            ofstream archivo("Recuperar.txt");
            if (archivo.is_open()){
                archivo << left;
                for(size_t i=0;i< paquetes.size();i++){
                    archivo<<paquetes[i].getId()<<endl;
                    archivo<<paquetes[i].getPeso()<<endl;
                    archivo<<paquetes[i].getOrigen()<<endl;
                    archivo<<paquetes[i].getDestino()<<endl;
                }
            }
            archivo.close();
        }

        int recuperarArchivo(){
            ifstream archivo("Recuperar.txt");
            int contador;
            if(archivo.is_open()){
                Paquete p;
                string temp; //temporal
                int id;
                
                float peso;

                while (true){
                    getline(archivo,temp); //ID
                    if(archivo.eof()){
                        cout<<"Paquetes recuperados"<<endl;
                        cin.get();
                        pausar();
                        break;
                    }
                    id = stoi(temp);
                    p.setId(id);
                    contador = id;
                    getline(archivo,temp);//peso
                    peso = stof(temp);
                    p.setPeso(peso);

                    getline(archivo,temp);//Origen
                    p.setOrigen(temp);

                    getline(archivo,temp); //Destino
                    p.setDestino(temp);

                    insertarALInicio(p);
                }

            }
            archivo.close();
            return contador+1;
        }
        
};
#endif // PAQUETERIA_H_INCLUDED
