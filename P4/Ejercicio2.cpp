#include <iostream>
#include "pila_enla.hpp"
#include <cstring>

using namespace std;

bool palindromomul(string cad);

int main () 
{
    string cad;
    cout << "Introduce una cadena del tipo X&Y: ";
    cin >> cad;
    if(palindromomul(cad))
    {
        cout << "Se cumple la condicion";
    }
    else
    {
        cout << "No se cumple la condicion";
    }

    return 0;

}

bool palindromomul(string cad)
{
    Pila<char> pila;
    
    int i=0;
    while(i < cad.length() - 1)
    {
        int aux=1;
        while(cad[i] != '&')
        {
            pila.push(cad[i]);
            i++;
            aux++;
        }
        int k=1;
        for(int j = i + 1 ; k < aux; j++)
        {
            if (cad[j] != pila.tope())
            {
                return false;
            }
            else
            {
                pila.pop();
                k++;
            }
        }

        i=i+k;

        if(cad[i] == '#')
        {
            i++;
        }
        else
        {
            return true;
        }
    }
}