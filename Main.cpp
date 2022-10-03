#include <stdio.h>
#include <iostream>
#include <string>
#include "Nodo.h"
#include <fstream>

using namespace std;

int main(){
    Nodo *head = NULL;
    Nodo *lista;
    string usuario, contraseña; 
    ifstream archivo,lectura;
    ofstream ingresar;
    string linea, texto;
    
    archivo.open("usuarios.txt",ios::in);
    int i = 0;
    while(getline(archivo,linea)){
        texto = texto + linea + "\n";
        if((linea != "")&&(i == 0)){
            usuario = linea;
            i = 1;
            continue;
        }else if((linea != "")&&(i == 1)){
            contraseña = linea;
            Nodo *nuevoN = new Nodo(usuario, contraseña);
            if(head == NULL){
                head = nuevoN;
                lista = head;
            }else{
                lista->setNext(nuevoN);
                lista = nuevoN;               
            }
            i = 0;
        }
    }
    archivo.close();
//menú
    while(true){
        int num;
        cout<<"Ingrese 0 para finalizar la ejecucion del programa."<<"\n";
        cout<<"Ingrese 1 para crear un nuevo usuario."<<"\n";
        cout<<"Ingrese 2 para buscar usuario existente."<<"\n";
        cout<<"Ingrese 3 para eliminar un usuario existente."<<"\n";
        cout<<"Ingrese 4 para mostrar la lista de usuarios."<<"\n";
        cin>>num;
        if(num == 0){
                break;
        }
        switch(num){
            case 1: {
                cout<<"Ingrese el nuevo usuario:\n";
                cin>>usuario;
                cout<<"Ingrese la nueva contraseña:\n";
                cin>>contraseña;
                Nodo *nuevoN = new Nodo(usuario,contraseña);
                cout<<"\n";
                ofstream ingresar("usuarios.txt");
                texto = texto + nuevoN->toString();
                ingresar<<texto;
                if(head == NULL){
                    head = nuevoN;
                    lista = head;
                }else{
                    lista->setNext(nuevoN);
                    lista = nuevoN;
                }
                ingresar.close();
                break;
            }
            case 2:{
                cout<<"Ingrese el usuario:\n";
                cin>>usuario;
                cout<<"Ingrese la contraseña:\n";
                cin>>contraseña;
                if((texto.find(usuario) != -1)&&(texto.find(contraseña) != -1 )){
                    cout<<"\n"<<"Bienvenido"<<endl;
                }else{
                    cout<<"\n"<<"No se encontró ese usuario"<<endl;
                }
                break;
            }
            case 3:{    
                cout<<"Ingrese el usuario:\n";
                cin>>usuario;
                cout<<"Ingrese la contraseña:\n";
                cin>>contraseña;
                if(texto.find(usuario) != -1){
                    texto = "";
                    lectura.open("usuarios.txt",ios::in);
                    ingresar.open("temp.txt",ios::out);
                    while(getline(lectura,linea)){
                        if((linea == usuario)||(linea == contraseña)){
                            continue;
                        }else{
                            texto = texto + linea + "\n";  
                        }
                    }
                    ingresar<<texto;
                    ingresar.close();
                    lectura.close();
                    rename("temp.txt","usuarios.txt");
                    Nodo *temp = head;
                    head = head->eliminar(temp,usuario,contraseña);
                }else{
                    cout<<"\n"<<"No se encontró ese usuario"<<"\n"<<endl;
                }
                break;
            }
            case 4:{
                cout<<"lista:\n";
                Nodo *temp = head;
                while(temp != NULL){
                    cout<<temp->getUsername()<<endl;
                    temp = temp->getNext();
                }
                break;
            }
        }
    }
    delete head;
}
