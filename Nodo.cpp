#include <iostream>
#include <string>
#include "Nodo.h"

using namespace std;

Nodo::Nodo(){
    
};

Nodo::~Nodo(){
};

void Nodo::setUsername(string user){
    this->username = user;
};

string Nodo::getUsername(){
    return this->username;
};

void Nodo::setPassword(string pass){
    this->password = pass;
};

string Nodo::getPassword(){
    return this->password;
};

void Nodo::setNext(Nodo *next){
    this->next = next;
};
Nodo *Nodo::getNext(){
    return this->next;
};
