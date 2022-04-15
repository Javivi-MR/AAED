#include <iostream>
#include "pila_enla.hpp"
#include <cstring>

using namespace std;

bool palindromo(string cad);


int main () 
{
    string cad;
    cout << "Introduce una cadena del tipo X&Y: ";
    cin >> cad;
    if(palindromo(cad))
    {
        cout << "Se cumple la condicion";
    }
    else
    {
        cout << "No se cumple la condicion";
    }

    return 0;

}

bool palindromo(string cad)
{
    Pila<char> pila;
    int i;
    for(i = 0 ; i < cad.length() && cad[i] != '&' ; i++)
    {
        pila.push(cad[i]);
    }

    for(int j = i + 1 ; j < cad.length() ; j++)
    {
        if (cad[j] != pila.tope())
        {
            return false;
        }
        else
        {
            pila.pop();
        }
    }
    return true;
}