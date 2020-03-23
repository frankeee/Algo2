

#include "Lista.h"

template <typename T>
Lista<T>::Lista() {
    // Completar
    tam=0;
    primero = nullptr;
    ultimo = nullptr;

    
}

template <typename T>
Lista<T>::Lista(const Lista<T>& l) : Lista() {
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;
}

template <typename T>
Lista<T>::~Lista() {
    //Destructooooooorrrr  borrar coment
    Nodo* i = this->primero;
    while(i != nullptr) {
        i = i->siguiente;
        delete primero;
        primero = i;
    }
}

template <typename T>
Lista<T>& Lista<T>::operator=(const Lista<T>& aCopiar) {
    Nodo* i = this->primero;
    while (i != nullptr) {
        i = i->siguiente;
        delete this->primero;
        this->primero = i;
    }
    delete i;
    tam = 0;
    this->primero = this->ultimo = nullptr;

    Nodo* iterador = aCopiar.primero;
    while(iterador!= nullptr){
        agregarAtras(iterador->valor);
        iterador = iterador->siguiente;
    }
    //delete iterador;




    return *this;
}

template <typename T>
void Lista<T>::agregarAdelante(const T& elem) {
    tam++;
    Nodo* nuevo = new Nodo(elem);
    if(primero == nullptr){
        primero = nuevo;
        ultimo = nuevo;
        nuevo->siguiente = nullptr;
        nuevo->anterior = nullptr;
    }
    else {
        primero->anterior = nuevo;
        nuevo->siguiente = primero;
        primero = nuevo;
    }
    // Completar

}

template <typename T>
void Lista<T>::agregarAtras(const T& elem) {
    // Completar
    tam++;
    Nodo* nuevo = new Nodo(elem);
    if (ultimo == nullptr) {
        ultimo = nuevo;
        primero = nuevo;
        nuevo->siguiente = nullptr;
        nuevo->anterior = nullptr;
    } else {
        ultimo->siguiente = nuevo;
        nuevo->anterior = ultimo;
        ultimo = nuevo;

    }
    //delete nuevo;

}

template <typename T>
void Lista<T>::eliminar(Nat i) {
    int h = 0;
    Nodo* juan = primero;
    if(i==0){
        if(tam !=1){
            Nodo* segundo = juan->siguiente;
            segundo->anterior = nullptr;
        }
        primero = juan->siguiente;
        if(tam ==1){
            ultimo = nullptr;
        }
        delete juan;
    }
    else{
        while(h!=i){
            juan = juan->siguiente;
            h++;
        }
        if(juan == ultimo){
            Nodo* anteult = juan->anterior;
            ultimo = anteult;
            anteult->siguiente = nullptr;
            delete juan;
        }
        else {
            Nodo* homero = juan->anterior;
            homero->siguiente = juan->siguiente;
            Nodo* jorge = juan->siguiente;
            jorge->anterior = juan->anterior;
            delete juan;
        }
    }
    tam--;
}

template <typename T>
int Lista<T>::longitud() const {

    return tam;
}

template <typename T>
const T& Lista<T>::iesimo(Nat i) const {
    // Completar
    int h = 0;
    Nodo* juan =primero;
    while(h!=i){
        juan = juan->siguiente;
        h++;
    }
    return juan->valor;
    //assert(false);
}

template <typename T>
T& Lista<T>::iesimo(Nat i) {
    // Completar (hint: es igual a la anterior...)
    int h = 0;
    Nodo* juan =primero;
    while(h!=i){
        juan = juan->siguiente;
        h++;
    }
    return juan->valor;
    //assert(false);
}

template <typename T>
void Lista<T>::mostrar(ostream& o) {
    // Completar
}