#ifndef PILA_HPP
#define PILA_HPP
#include <cassert>

template <typename tElemento> 
class Pila
{
    public:
        explicit Pila(unsigned TamaMax); //constructor con tam max
        Pila(const Pila &p);    //constructor estilo Pila A (B) siendo B una pila (copia)
        Pila& operator= (const Pila& p);   //constructor de asignacion
        bool vacia() const;     //comprob si esta vacia
        bool llena() const;     //comprob si esta llena (Requerida por la implementacion)
        const tElemento& tope() const;      // Mostrar el elemento que esta en el tope
        void pop();   // sacar elemnto del tope
        void push(const tElemento& x);  // meter elemento a la pila
        ~Pila(); //borra pila (destructor)
    private:
        tElemento *elementos;   //vector de los elementos
        int Lmax;   //Tamaño de la pila
        int tope_; //posicion del tope
};

template <typename tElemento>
inline Pila<tElemento>::Pila(unsigned TamaMax)
{
    elementos = new tElemento[tamaMax];
    Lmax = tamaMax; 
    tope_ = -1; //pila vacia sin elementos
}

template <typename tElemento>
Pila<tElemento>::Pila(const Pila<tElemento>& p)
{
    elementos = new tElemento[p.Lmax];
    Lmax = p.Lmax; 
    tope_ = p.tope_;

    for(int i = 0; i <= tope_; i++){
        elementos[i] = p.elementos[i];
    }
}

template <typename tElemento>
Pila<tElemento>& Pila<tElemento>::operator= (const Pila<tElemento>& p)
{
    if (this != &p) { // evitar autoasignación
    // Destruir el vector y crear uno nuevo si es necesario
    if (Lmax != p.Lmax) {
        delete[] elementos;
        Lmax = p.Lmax;
        elementos = new tElemento[Lmax];
    }
    // Copiar el vector
    tope_ = p.tope_;
    for (int i = 0; i <= tope_; i++)
        elementos[i] = p.elementos[i];
    }
    return *this;
}

template <typename tElemento>
inline bool Pila<tElemento>::vacia() const 
{
    return (tope_ == -1);
}

template <typename tElemento>
inline bool Pila<tElemento>::llena() const 
{
    return (tope_ == Lmax - 1);
}

template <typename tElemento>
inline const tElemento &Pila<tElemento>::tope() const
{
    assert(!vacia());
    return elementos[tope_];
}

template <typename tElemento>
inline void Pila<tElemento>::pop(){
    assert(!vacia());
    --tope_;
}

template <typename tElemento>
inline void Pila<tElemento>::push(const tElemento& x)
{
    assert(!llena());
    ++tope_;
    elementos[tope_] = x;
}

template <typename tElemento>
inline Pila<tElemento>::~Pila()
{
    delete[] elementos;
}

#endif