#include "operaciones.hpp"


polinomio operator+ (const polinomio a, const polinomio b)
{
    unsigned gradoaux;
    if(a.grado() > b.grado())
    {
        gradoaux = a.grado();
    }
    else
    {
        gradoaux = b.grado();
    }

    polinomio c(gradoaux);
    
    for (int i=0 ; i < gradoaux ; i++)
    {
        c.coeficiente(i, a.coeficiente(i) + b.coeficiente(i));
    }
    return c;
}

polinomio operator- (const polinomio a, const polinomio b)
{
    unsigned gradoaux;
    if(a.grado() > b.grado())
    {
        gradoaux = a.grado();
    }
    else
    {
        gradoaux = b.grado();
    }

    polinomio c(gradoaux);
    
    for (int i=0 ; i < gradoaux ; i++)
    {
        c.coeficiente(i, a.coeficiente(i) - b.coeficiente(i));
    }
    return c;
}

polinomio operator* (const polinomio a, const polinomio b)
{
    int gradoaux = a.grado() + b.grado();

    polinomio c(gradoaux);

    for (int i = a.grado() ; i >= 0  ; i--)
    {
        for (int j = b.grado() ; j >= 0 ; j--)
        {
            c.coeficiente(i+j,a.coeficiente(i) * b.coeficiente(j) + c.coeficiente(i+j));
        }
    }

    return c;
}

polinomio derivada (const polinomio a)
{
    int gradoaux = a.grado() - 1;
    
    polinomio c(gradoaux);

    for(int i = a.grado() - 1 ; i >= 0  ; i--)
    {
        c.coeficiente(i,a.coeficiente(i + 1 ) * (i + 1));
    }

    return c;
}

polinomio crea()
{
    unsigned grado, coef;
    cout << "¿De qué grado va a ser tu polinomio?" << endl;
    cin >> grado;
    polinomio pol(grado);
    for (int i = grado; i >= 0; i--){
        cout << "Ingresa el coeficiente correspondiente a x^" << i << ": ";
        cin >> coef;
        pol.coeficiente(i, coef);
        cout << endl;
    }

    return pol;
}

void imprime(const polinomio a){
    for (int i = a.grado(); i >= 0; i--){
        if (a.coeficiente(i) >= 0 && i != a.grado())
            cout << " + ";
        if (i == 0){
            cout << a.coeficiente(i) << endl;
                
        }else if (i == 1){
            cout << a.coeficiente(i) << "x ";

        }else cout << a.coeficiente(i) << "x^" << i << " ";
    }
}

