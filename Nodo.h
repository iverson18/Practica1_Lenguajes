#ifndef Nodo_h
#define Nodo_h
#include <string>
using namespace std;

class Nodo{
    private:
        string username;
        string password;
        Nodo *next;

    public:
        Nodo();
        Nodo(string,string);
        ~Nodo();
        void setUsername(string user);
        string getUsername();
        void setPassword(string pass);
        string getPassword();
        void setNext(Nodo *next);
        Nodo *getNext();
        Nodo *eliminar(Nodo *N, string, string);
};

#endif
