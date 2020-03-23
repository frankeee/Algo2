#include "Conjunto.h"
template <class T>
Conjunto<T>::Conjunto() {
    _raiz = nullptr;
    tam =0;
}

template <class T>
Conjunto<T>::~Conjunto() {

    if(_raiz!= nullptr){
        Nodo* r = _raiz;
        destruye(r);
    }
    _raiz = nullptr;
    tam =0;
}
template <class T>
void Conjunto<T>::destruye(Nodo* r) {

    if(r->der != nullptr){
        destruye(r->der);
    }
    if(r->izq!=nullptr){
        destruye(r->izq);
    }
    delete r;
}

template <class T>
bool Conjunto<T>::pertenece(const T& clave) const {
    Nodo* r = _raiz;
    while(r != nullptr){
        if(r->valor == clave){
            return true;
        }
        else if(r->valor< clave){
            r = r->der;
        }

        else if(r->valor > clave){
            r = r->izq;
        }
        }


    return false;
}

template <class T>
void Conjunto<T>::insertar(const T& clave) {
    tam++;
    Nodo* nuevo = new Nodo(clave);
    Nodo* r = _raiz;
    bool i = true;
    if(_raiz == nullptr){
        nuevo->der = nullptr;
        nuevo->izq = nullptr;
        nuevo->anterior= nullptr;
        _raiz = nuevo;
        i = false;
    }
    while(i){
        if(r->valor == clave){
            i = false;
            tam--;
            delete nuevo;
        }
        else if(r->valor<clave){
            if(r->der == nullptr){
                r-> der = nuevo;
                nuevo->der = nullptr;
                nuevo->izq = nullptr;
                nuevo->anterior = r;
                i = false;
            }
            else{r = r->der;}
        }
        else{
            if(r->izq == nullptr){
                r->izq = nuevo;
                nuevo->der = nullptr;
                nuevo->izq = nullptr;
                nuevo->anterior = r;
                i = false;
            }
            else{
                r = r->izq;
            }
        }
    }
}
template <class T>
void Conjunto<T>::removedor(T clave, Nodo* x,string h){

    if(x->valor< clave){
        removedor(clave,x->der,"der");
    }
    else if(x->valor > clave){
        removedor(clave,x->izq,"izq");
    }
    else{
        if(x->der== nullptr && x->izq == nullptr){
            if(h == "der"){
                Nodo* j = x->anterior;
                j->der=nullptr;
            }
            if(h == "izq"){
                Nodo* j = x->anterior;
                j->izq = nullptr;
            }
            delete x;
        }
        else{
            if(x->der!=nullptr){
                x->valor= sigasiga(x->valor,x);
                removedor(x->valor,x->der,"der");

            }
            else{
                x->valor = previardi(x->valor,x);
                removedor(x->valor,x->izq,"izq");

            }
        }
    }

}


template <class T>
void Conjunto<T>::remover(const T& clave) {
    if(pertenece(clave)){
        Nodo* r = _raiz;
        tam --;

        if (r->izq == nullptr && r->der == nullptr && r->valor == clave) {

            delete r;
            _raiz = nullptr;
        }
        else if(r->valor == clave){
            if(r->der!=nullptr){
                r->valor= sigasiga(r->valor,r);
                removedor(r->valor,r->der,"der");

            }
            else{
                r->valor = previardi(r->valor,r);
                removedor(r->valor,r->izq,"izq");

            }
        }
        else(removedor(clave,r,""));
    }
}

template <class T>
T& Conjunto<T>::sigasiga(T& clave,Nodo* x){
    Nodo* r = x;
    while(r->valor!=clave){
        if(r->valor < clave){
            r = r->der;
        }
        else if(r->valor>clave){
            r = r->izq;
        }
    }
    if(r->der!= nullptr){
        r = r->der;
        if(r->izq== nullptr){
            return r->valor;
        }
        else{
            r = r->izq;
            while(r->izq!=nullptr){
                r = r->izq;
            }
            return r->valor;
        }
    }
    else {r = r->anterior;}

    return r->valor;
}




template <class T>
const T& Conjunto<T>::siguiente(const T& clave) {
    Nodo* r = _raiz;
    while(r->valor!=clave){
        if(r->valor < clave){
            r = r->der;
        }
        else if(r->valor>clave){
            r = r->izq;
        }
    }
    if(r->der!= nullptr){
        r = r->der;
        if(r->izq== nullptr){
            return r->valor;
        }
        else{
            r = r->izq;
            while(r->izq!=nullptr){
                r = r->izq;
            }
            return r->valor;
        }
    }
    else {r = r->anterior;}

    return r->valor;
}

template <class T>
T& Conjunto<T>::previardi(T& clave,Nodo* x){
    Nodo* r = x;
    if(r!= nullptr) {
        while (r->valor != clave) {
            if (r->valor < clave) {
                r = r->der;
            } else if (r->valor > clave) {
                r = r->izq;
            }
        }
        if (r->izq != nullptr) {
            r = r->izq;
            if (r->der == nullptr) {
                return r->valor;
            } else {
                r = r->der;
                while (r->der != nullptr) {
                    r = r->der;
                }
                return r->valor;
            }
        } else { r = r->anterior; }
    }

    return r->valor;
}


template <class T>
const T& Conjunto<T>::previo(const T& clave) {
    Nodo* r = _raiz;
    while(r->valor!= clave){
        if(r->valor < clave){
            r = r->der;
        }
        else if(r->valor>clave){
            r = r->izq;
            }
        }
    if(r->izq!= nullptr){
        r = r->izq;
        if(r->der== nullptr){
            return r->valor;
        }
        else{
            r = r->der;
            while(r->der!=nullptr){
                r = r->der;
            }
            return r->valor;
        }
    }
    else {r = r->anterior;}

    return r->valor;
}

template <class T>
const T& Conjunto<T>::minimo() const {
    Nodo* r = _raiz;
    while(r->izq != nullptr){
        r = r->izq;
    }
    return r->valor;
}

template <class T>
const T& Conjunto<T>::maximo() const {
    Nodo* r = _raiz;
    while(r->der != nullptr){
        r = r->der;
    }
    return r->valor;
}

template <class T>
unsigned int Conjunto<T>::cardinal() const {
    return tam;
}

template <class T>
void Conjunto<T>::mostrar(std::ostream&) const {
}

