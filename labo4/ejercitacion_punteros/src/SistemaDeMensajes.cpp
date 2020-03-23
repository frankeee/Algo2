#include "SistemaDeMensajes.h"

// Completar...

SistemaDeMensajes::SistemaDeMensajes() {



}
void SistemaDeMensajes::registrarJugador(int id, string ip){

    ConexionJugador h  = ConexionJugador(ip);
    _conns[id] = &h;

}

void SistemaDeMensajes::enviarMensaje(int id, string mensaje){
    if(_conns[id] != nullptr){
        ConexionJugador h = *_conns[id];
        h.enviarMensaje(mensaje);

    }

}

bool SistemaDeMensajes::registrado(int id) const{
    if(_conns[id] != nullptr){
        return false;
    }
    return true;

}

string SistemaDeMensajes:: ipJugador(int id) const{
    ConexionJugador* h = _conns[id];
    return h->ip();



}