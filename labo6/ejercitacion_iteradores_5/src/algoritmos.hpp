#ifndef ALGO2_LABO_CLASE5_ALGORITMOS_H
#define ALGO2_LABO_CLASE5_ALGORITMOS_H

#include <utility>
#include <iterator>
#include <vector>

// Completar con las funciones del enunciado

template<class Contenedor>
typename Contenedor::value_type minimo(const Contenedor& c){
    typename Contenedor::const_iterator it = c.begin();
    typename Contenedor::value_type min = *it;
    while(it != c.end()){
        if(*it < min){
            min = *it;
        }
        ++it;
    }
    return min;
}

template<class Contenedor>
typename Contenedor::value_type promedio(const Contenedor& c){
    typename Contenedor::const_iterator it = c.begin();
    typename Contenedor::value_type acum = *it;
    ++it;
    int i = 1;
    while(it != c.end()){
        acum += *it;
        ++it;
        i++;
    }
    return acum/i;
}

template<class Iterator>
typename Iterator::value_type minimoIter(const Iterator& desde, const Iterator& hasta){
    Iterator d = desde;
    typename Iterator::value_type min = *desde;
    while(d != hasta){
        if(min > *d){
            min = *d;
        }
        ++d;
    }
    return min;
}

template<class Iterator>
typename Iterator::value_type promedioIter(const Iterator& desde, const Iterator& hasta){
    int n = 1;
    Iterator d = desde;
    typename Iterator::value_type acum = *desde;
    ++d;
    while(d != hasta){
        acum += *d;
        ++d;
        n ++;
    }
    return acum/n;
}

template<class Contenedor>
void filtrar(Contenedor &c, const typename Contenedor::value_type& elem){
    typename Contenedor::const_iterator it = c.begin();
    while(it != c.end()){
        if(*it != elem){
            ++it;
        }else {
            it = c.erase(it);
        }
    }
}

template<class Contenedor>
bool ordenado(Contenedor &c){
    typename Contenedor::const_iterator it = c.begin();
    typename Contenedor::const_iterator hasta = (c.end());

    while(it != hasta){
        if(*it >= *(++it)){
            return false;
        }
        ++it;
    }
    return true;
}

template<class Contenedor>
std::pair<Contenedor, Contenedor>
split(const Contenedor & c,
      const typename Contenedor::value_type& elem){
    typename Contenedor::const_iterator it = c.begin();
    std::pair<Contenedor, Contenedor> tupla ;
    auto itC1 = tupla.first.begin();
    auto itC2 = tupla.second.begin();
    while(it != c.end()){
        if(*it< elem){
            itC1.insert(*it);
        }
        else{
            //insert(*it,tupla.second);
        }
        ++it;
    }
    return tupla;
}

#endif //ALGO2_LABO_CLASE5_ALGORITMOS_H
