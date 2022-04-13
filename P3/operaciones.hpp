#ifndef OPERACIONES_HPP
#define OPERACIONES_HPP
#include "polinom.hpp"
#include <iostream>

using namespace std;


//cabecera : polinomio operator+(const polinomio a , const polinomio b)
//precondicion = recibe dos polinomios inicializados
//postcondicion = devuelve un polinomio formado a partir de la suma de los polinomios a y b
polinomio operator+(const polinomio a , const polinomio b);

//cabecera : polinomio operator-(const polinomio a , const polinomio b)
//precondicion = recibe dos polinomios inicializados
//postcondicion = devuelve un polinomio formado a partir de la resta de los polinomios a y b
polinomio operator-(const polinomio a , const polinomio b);

//cabecera : polinomio operator*(const polinomio a , const polinomio b)
//precondicion = recibe dos polinomios inicializados
//postcondicion = devuelve un polinomio formado a partir del producto de los polinomios a y b
polinomio operator*(const polinomio a , const polinomio b);

//cabecera : polinomio derivada(const polinomio a);
//precondicion = recibe un polinomio inicializado
//postcondicion = devuelve un polinomio formado a partir de la derivada del polinomios a
polinomio derivada(const polinomio a);

polinomio crea();
void imprimir(const polinomio a);


#endif