

template<class Clave , class Valor>
class Diccionario{
public:
    void definir(Clave c ,Valor v){
        _claves.push_back(c);
        _valores.push_back(v);

    }

    bool def(Clave c){
        int i =0;
        while(i <_claves.size()){
            if(_claves[i]==c){
                return true;
            }
            i++;
        }
        return false;
    }
    Valor obtener(Clave k){
        int i = 0;
        while(i<_claves.size()){
            if(k == _claves[i]){
                return _valores[i];
            }
        }
    }
    std::vector<Clave> claves() const{
        return _claves;
    }
private:
    std::vector<Clave> _claves;
    std::vector<Valor> _valores;


};










