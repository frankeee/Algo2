/* Completar */

#include "Diccionario.h"
#include <vector>
#include <tuple>
using namespace std;


Diccionario::Diccionario() {


}

bool operator==(const Diccionario &a,const Diccionario &b) {
    if(a.vectorDi.size() != b.vectorDi.size()){
        return false;
    }
    int i = 0;
    while(i<a.vectorDi.size()){
        if(a.vectorDi[i] != b.vectorDi[i]){
            return false;
        }
        i++;
    }
    return true;
}

std::vector<Clave> Diccionario::claves() const{
    vector<Clave> clavesux;
    int i =0;
    while(i<vectorDi.size()){
        clavesux.push_back(get<0>(vectorDi[i]));
        i++;
    }
    return clavesux;
}

bool Diccionario::def(Clave k) {

    int i = 0;
    while(i<vectorDi.size()){
        if(get<0>(vectorDi[i])== k){

            return true;

        }
        i++;
    }
    return false;

}
void Diccionario::definir(Clave k, Valor v){


    if(def(k)){
        int i = 0;
        while(i<vectorDi.size()){
            if(get<0>(vectorDi[i])== k){
                get<1>(vectorDi[i])= v;
            }
            i++;
        }

    }
    else{
    vectorDi.push_back(tuple<Clave, Valor>(k, v));
    }

}

Valor Diccionario::obtener(Clave k){
    int i =0;
    while(i<vectorDi.size()){
        if(get<0>(vectorDi[i])== k){

            return get<1>(vectorDi[i]);

        }
        i++;
    }


}
void Diccionario :: borrar(Clave k){
    vector<tuple<Clave,Valor>> vectorD2;
    
    int i =0;
    while(i<vectorDi.size()){
        if(get<0>(vectorDi[i])!= k){

            vectorD2.push_back(vectorDi[i]);

        }
        i++;
    }
    vectorDi = vectorD2;


}


