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
    txt = txt + "\n"; 
    txt = txt + this->password + "\n";
    return txt;
}
