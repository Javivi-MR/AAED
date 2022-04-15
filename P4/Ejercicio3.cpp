#include <iostream>
#include "pila_enla.hpp"
using namespace std;

void invertir(Pila<char>& P, char a, char b);


int main()
{
    Pila<char> pila;
    string cadena = {'9','8','7','6','5','4','3','2','1'};
    char a = '3', b = '7';
    cout << "pila original: ";
    for(int i = 0 ; i < cadena.length() ; i++)
    {
        pila.push(cadena[i]);
        cout << pila.tope();
    }
    invertir(pila,a,b);
    cout<< endl <<"Pila final: ";
    for (int i = 0; i < cadena.length() ; i++)
    {
        cout<< pila.tope();
        pila.pop();
    }
    return 0;
}

void invertir(Pila<char>& pila,char a,char b)
{
    Pila<char> aux1,aux2,aux3;
    while(pila.tope() != a)
    {
        aux1.push(pila.tope());
        pila.pop();
    }
    while(pila.tope() != b)
    {
        aux2.push(pila.tope());
        pila.pop();
        if (pila.tope() == b)
        {
            aux2.push(pila.tope());
        }
    }
    pila.pop(); //eliminar b
    while(!aux2.vacia())
    {
        aux1.push(aux2.tope());
        aux2.pop();
    }
    while(!pila.vacia())
    {    
        aux1.push(pila.tope());
        pila.pop();      
    }
    while(!aux1.vacia())
    {
        aux3.push(aux1.tope());
        aux1.pop();
    }
    while(!aux3.vacia())
    {
        pila.push(aux3.tope());
        aux3.pop();
    }
}