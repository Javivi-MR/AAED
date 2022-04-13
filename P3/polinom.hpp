#ifndef POLINOM_HPP
#define POLINOM_HPP

class polinomio
{
    public:
        polinomio(unsigned gradoMax); //constructor
        unsigned grado() const; //devuelve el grado de un polinomio
        double coeficiente(unsigned n) const;   // devuelve coeficiente del grado n
        void coeficiente(unsigned n, double c);   //asigna al grado n el coeficiente c

    private:
        double* vector;
        unsigned grad_max;
        unsigned grad_pol;
};

#endif