#ifndef CONJUNTO_H_
#define CONJUNTO_H_

#include <assert.h>
#include <string>
#include <iostream>

using namespace std;

template <class T>
class Conjunto
{
    public:

        // Constructor. Genera un conjunto vacío.
        Conjunto();

        // Destructor. Debe dejar limpia la memoria.
        ~Conjunto();

        // Inserta un elemento en el conjunto. Si este ya existe,
        // el conjunto no se modifica.
        void insertar(const T&);


        // Decide si un elemento pertenece al conjunto o no.
        bool pertenece(const T&) const;

        // Borra un elemento del conjunto. Si este no existe,
        // el conjunto no se modifica.
        void remover(const T&);


        // Siguiente elemento al recibido por párametro, en orden.
        const T& siguiente(const T& elem);
        const T& previo(const T& elem);
        // Devuelve el mínimo elemento del conjunto según <.
        const T& minimo() const;

        // Devuelve el máximo elemento del conjunto según <.
        const T& maximo() const;

        // Devuelve la cantidad de elementos que tiene el conjunto.
        unsigned int cardinal() const;

        // Muestra el conjunto.
        void mostrar(std::ostream&) const;



    private:

        /**
         * Completar con lo que sea necesario...
         **/


        struct Nodo
        {
            // El constructor, toma el elemento al que representa el nodo.
            Nodo(const T& v):valor(v){}
            // El elemento al que representa el nodo.
            T valor;
            // Puntero a la raíz del subárbol izquierdo.
            Nodo* izq = nullptr;
            // Puntero a la raíz del subárbol derecho.
            Nodo* der = nullptr;
            Nodo* anterior = nullptr;//probar esto en algun momento
            void operator=(const Nodo& aCopiar){
                valor = aCopiar->valor;
                izq = aCopiar->izq;
                der = aCopiar->der;
                anterior = aCopiar-> anterior;
            }

        };

        // Puntero a la raíz de nuestro árbol.
        Nodo* _raiz;
        unsigned int tam;

        void removedor(T , Nodo* z,string h);
        void destruye(Nodo* z);
        T& sigasiga(T& elem,Nodo* x);
        T& previardi(T& elem,Nodo* x);
};

template<class T>
std::ostream& operator<<(std::ostream& os, const Conjunto<T>& c) {
	 c.mostrar(os);
	 return os;
}

#include "Conjunto.hpp"

#endif // CONJUNTO_H_
