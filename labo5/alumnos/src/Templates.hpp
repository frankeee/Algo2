

template <class miTipo>
miTipo cuadrado (miTipo a) {
    return (a*a);
}


template<class Contenedor, class Elem>

bool contiene(Contenedor c,Elem a ){
    int i = 0;
    while(i<c.size()){
        if(c[i]== a){
            return true;
        }
        i++;
    }
    return false;
}

template<class Contenedor>
bool esPrefijo(Contenedor a, Contenedor b){
    if(a.size()>b.size()){
        return false;
    }
    int i = 0;
    while(i<a.size()){
        if(a[i]!=b[i]){
            return false;

        }
        i++;
    }
    return true;
}

template<class Contenedor,class Elem>
Elem maximo(Contenedor c){
    int i = 1;
    int maximo = c[0];
    while(i<c.size()){
        if(c[i]>maximo){
            maximo = c[i];
        }
        i++;
    }
    return maximo;
}



