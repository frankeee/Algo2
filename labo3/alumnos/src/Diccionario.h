#ifndef __DICCIONARIO_H__
#define __DICCIONARIO_H__

#include <vector>

using namespace std;


typedef int Clave;
typedef int Valor;

class Diccionario {
public:
	Diccionario();
	void definir(Clave k, Valor v);
	bool def(Clave k) ;
	Valor obtener(Clave k);
	void borrar(Clave k);
    vector<tuple<Clave,Valor>> vectorDi;
    bool operator ==(const Diccionario &a);
    std::vector<Clave> claves() const;
	
private:
	// Completar para el ejercicio 3


	struct Asociacion {
		Clave clave;
		Valor valor;
	};


	
};

#endif /*__DICCIONARIO_H__*/
