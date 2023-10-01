#include <iostream>
#include <stdexcept>

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
    Vettore(T elemento); // inizializza vettore e caria elemento
    Vettore(int dim, T valore); // inizializza vettore con dimensione ed ogni elemento con il valore passato come parametro 
    Vettore(const Vettore &copia); // inzializza vettore come la copia di un oggetto vettore passato come parametro
    Vettore(const T* inizio, const T* fine); //inizializza oggetto vettore con la copia degli elementi tra due indirizzi di un array C (costruttore di range)
    
    // DISTRUTTORE
    //~Vettore();

    // SET / GET
    int getDim()const{ return this->dim; } // restituisce valore che rappresenta il numero di elementi nel vettore
    int getDimMax()const{ return this->dimMax; } // restituisce la dimensione massima del vettore
    T* getVett()const{ return this->vettore; } // restituisce un puntatore costante al vettore interno
    T* getCurr()const{ return this->curr; } // restituisce puntatore costante a curr(punta indirizzo del prossimo elemento da inserire)

    // INSERIMENTO
    void push_back(const T& elemento); // inserisce un elemento passato come parametro nel vettore
    void pop_back(); // cancella l'ultimo elemento inserito nel vettore
    
    // CANCELLAZIONE
    void clear(); // cancella il contenuto del vettore 
    
    // ACCESSO AGLI ELEMENTI
    T& at(const int &indice); // restituisce riferimento all'elemento dell array corrispondente all indice passato come parametro
    // indice (int): L'indice dell'elemento nel vettore a cui si desidera accedere
    // T&: Un riferimento all'elemento del vettore all'indice specificato.
    // std::out_of_range: Viene lanciata se l'indice specificato è fuori dai limiti del vettore
    T* inizio()const{ return this->vettore; } // restituisce puntatore costante all vettore interno
    T* fine()const{ return this->curr; } //  restituisce un puntatore costante al prossimo elemento da inserire nel vettore.(fine del vettore)
    
    // OPERATORI
    T operator[](int indice)const;//  consente di recuperare il valore dell'elemento del vettore situato all'indice specificato. 
    // indice che rappresenta la posizione dell'elemento nel vettore.
    // Non consente la modifica diretta degli elementi del vettore
    // Se l'indice è fuori dai limiti del vettore, comporta un comportamento imprevedibile.
    Vettore<T>& operator=(const Vettore<T> &copia);// ccopia il contenuto di un altro oggetto della classe Vettore nell'oggetto corrente
    // copia : oggetto Vettore da cui recuperare i dati
    // std::invalid_argument Viene lanciata se l'oggetto passato come parametro non e' stato inizializzato.
};