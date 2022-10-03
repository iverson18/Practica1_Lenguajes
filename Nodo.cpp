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

Nodo *Nodo::eliminar(Nodo *head, string username, string password){
    if(head == NULL){
        cout<<"ERROR"<<endl;
        return NULL;
    }
    Nodo *actual;
    Nodo *anterior;
    actual = head;
    if((username == actual->username)&&(password == actual->password)){
            anterior = actual;
            actual = anterior->next;
            anterior->next = NULL; 
            delete anterior;
            return actual;
        }
    while(actual->next != NULL){
        anterior = actual;
        actual = anterior->next;
        if((username == actual->username)&&(password == actual->password)){
            anterior->next = actual->next;
            actual->next = NULL;
        }
    }
    if((actual->next == NULL)&&(username == actual->username)&&(password == actual->password)){
            anterior->next = NULL;
            delete actual;
    }
    return head;
}
