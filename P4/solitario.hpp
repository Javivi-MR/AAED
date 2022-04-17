#ifndef SOLITARIO_HPP
#define SOLITARIO_HPP

#include "pila.hpp"
#include <iostream>

enum figura{VACIA, AS, DOS, TRES, CUATRO, CINCO, SEIS, SIETE, SOTA, CABALLO, REY};
enum palo{OROS, COPAS, ESPADAS, BASTOS};

class tCarta
{
    public:
        tCarta(palo p = OROS, figura f = AS);
        figura verFig() const;
        palo verPalo() const;

    private:
        figura fig;
    palo pal;
    static const char* nom_palo[], * nom_fig[];

};

const char* tCarta::nom_palo[] = {"OROS   ", "COPAS  ", "ESPADAS", "BASTOS "};

const char* tCarta::nom_fig[] = {"-------", "AS     ", "DOS    ", "TRES   ", 
                                "CUATRO ", "CINCO  ", "SEIS   ", "SIETE  ",
                                "SOTA   ", "CABALLO", "REY    "};


std::ostream& operator <<(std::ostream& os, const tCarta& c)
{
    os << "(" << tCarta::nom_fig[c.verFig()] << ", " << tCarta::nom_palo[c.verPalo()] << ")";
    return os;
}

bool solitario(tCarta* baraja, figura* base)
{
    Pila<tCarta> mazo(40), descartes(40);
    int colocadas;

   
    for(int i = 0; i < 40; i++){
        mazo.push(baraja[i]);
    }

    base[OROS] = VACIA; base[COPAS] = VACIA; 
    base[ESPADAS] = VACIA; base[BASTOS] = VACIA; 
    
    do{
        colocadas = 0;
        while(!mazo.vacia()){
            descartes.push(mazo.tope());
            mazo.pop();
            if(!mazo.vacia()){
                descartes.push(mazo.tope());
                mazo.pop();
            }

            while(!descartes.vacia() && descartes.tope().verFig() == (base[descartes.tope().verPalo()] + 1)){
                base[descartes.tope().verPalo()] = descartes.tope().verFig();
                descartes.pop();
                colocadas++;
            }
        }

        while(!descartes.vacia()){
            mazo.push(descartes.tope());
            descartes.pop();
        }

    }while(colocadas > 0 && !mazo.vacia());
    return (mazo.vacia());
}

#endif
