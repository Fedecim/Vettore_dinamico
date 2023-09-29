#include <iostream>
#include <iterator>
template <typename T>
class Vettore
{
private:
    T* vettore; // rappresenta il vettore interno
    T* curr; // rappresenta la posizione del prossimo elemento da inserire
    int dim; // rappresenta numero di elementi all interno del vettore
    int dimMax;// rappresenta dimensione massima del vettore

public:
    // COSTRUTTORI
    Vettore(); // inzializza vettore vuoto 
    Vettore(const T& elemento); // inizializza vettore e caria elemento
    Vettore(int dim, T valore); // inizializza vettore con dimensione ed ogni elemento con il valore passato come parametro 
    Vettore(const Vettore &copia); // inzializza vettore come la copia di un oggetto vettore passato come parametro
    //Vettore(const T& array); // inizialliza vettore con la copia di elementi contenuti nell array C passato come parametro
    Vettore(const T* inizio, const T* fine); // inizializza oggetto vettore con la copia degli elementi tra due indirizzi di un array C (costruttore di range) 
    /*
    // DISTRUTTORE
    ~Vettore();

    // SET / GET
    void setDim(int dim);
    void setDimax(int dimMax);
    void setCurr(T* curr);
    void setVett(T* vett);*/
    int getDim()const{ return this->dim; }
    int getDimMax()const{ return this->dimMax; }
    T* getVett()const{ return this->vettore; }
    T* getCurr()const{ return this->curr; }

    // INSERIMENTO
    void push_back(const T& elemento);
    void pop_back();

    // ITERATORI
    
    
    /*

    // CANCELLAZIONE
    void clear();

    // ACCESSO ELEMENTI
    T operator [](int indice);
    T at(int indice);
    T front();
    T last();

    // OPERATORI
    Vettore operator "="(const Vettore &copia);

    // ITERATORI
    std::iterator begin(); // iteratore costante alla testa del vettore
    std::iterator end(); // iteratore costante alla fine del vettore*/
};