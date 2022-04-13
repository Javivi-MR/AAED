#include "polinom.hpp"

//using namespace std;

polinomio::polinomio(unsigned gradoMax)
{
    vector = new double[gradoMax]; //definimos un vector de tamaño gradoMax

    for (int i=0;i<gradoMax;i++)        //rellenamos el vector con 0 (nulo)
    {
        vector[i] = 0;
    }
    grad_max = gradoMax;
    grad_pol = 0;     
}

unsigned polinomio::grado() const
{
    return grad_pol; //devolvemos el grado del polinomio
}

double polinomio::coeficiente(unsigned n) const
{
    if(n > grad_max)        //si esta fuera de rango
    {
        return 0;           //el coeficiente siempre será 0
    }
    else                    //si esta dentro de rango
    {   
        return vector[n];   //devolvemos el valor del coeficiente que tenga el grado n
    }
}

void polinomio::coeficiente(unsigned n, double c)
{
    if(n > grad_pol)        //si esta fuera de rango
    {
        grad_pol = n;
    }
    vector[n] = c;
}
