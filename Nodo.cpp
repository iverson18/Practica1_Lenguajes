#include <iostream>
#include <string>
#include "Nodo.h"

using namespace std;

Nodo::Nodo(){ 
}

Nodo::Nodo(string user, string pass){ 
    this->next = NULL;
    this->username = user;
    this->password = pass;
}

Nodo::~Nodo(){
}

void Nodo::setUsername(string user){
    this->username = user;
}

string Nodo::getUsername(){
    return this->username;
}

void Nodo::setPassword(string pass){
    this->password = pass;
}

string Nodo::getPassword(){
    return this->password;
}

void Nodo::setNext(Nodo *next){
    this->next = next;
}

Nodo *Nodo::getNext(){
    return this->next;
}

string Nodo::toString(){
    string txt = this->username + "\n";
    txt = txt + this->password;
    return txt;
}

void Nodo::eliminar(Nodo *lista, string username, string password){
    if(lista != NULL){
        Nodo *borrar;
        Nodo *anterior;
        borrar = lista;
        
        while((borrar != NULL)&&(username != borrar->username)&&(password != borrar->password)){
            anterior = borrar;
            borrar = borrar->next;
        }
        if(borrar == NULL){
            cout<<"ERROR"<<endl;
        }else if(anterior == NULL){
            lista = lista->next;
            delete borrar;
        }else{
            anterior->next = borrar->next;
            delete borrar;
        }
    } 
}
