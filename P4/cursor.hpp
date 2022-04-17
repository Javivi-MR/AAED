#ifndef CURSOR_HPP
#define CURSOR_HPP

#include "pila_enla.hpp"


class cursor{

    public:
        avanzar();
        retrasar();
        final();
        principio();
        suprimir();
        borrar();
        insertar(char x);
        sobreescribir(char x);

    private:
        Pila<char> der;
        Pila<char> izq;
};

inline void cursor::avanzar()
{
    if(!der.vacia())
    {
        izq.push(der.tope());
        der.pop;
    }
}

inline void cursor::retrasar()
{
    if(!izq.vacia())
    {
        der.push(izq.tope());
        izq.pop;
    }
}

inline void cursor::final()
{
    while(!der.vacia())
    {
        izq.push(der.tope());
        der.pop;
    }
}

inline void cursor::principio()
{
    while(izq.vacia())
    {
        der.push(izq.tope());
        izq.pop;
    }
}

inline void cursor::suprimir()
{
    if(!der.vacia())
    {
        der.pop();
    }
}

inline void cursor::borrar()
{
    if(!izq.vacia())
    {
        izq.pop();
    }
}

inline void cursor::insertar(char x)
{
    der.push(x);
}

inline void sobreescribir(char x)
{
    if(!der.vacia())
    {
        der.pop();
        der.push(x);
    }
}

#endif