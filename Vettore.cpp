#include "Vettore.h"
#include <iostream>


/*
//costruttore senza parametri
1 deve inizializzare il vettore interno a NULL
2 dim e dimax a 0
3 curr a NULL
4 fine
test case :
1 cosa succede se si tenta di inizializzare due volte lo stesso oggetto ?
*/
template<typename T>
Vettore<T>::Vettore(){
    this->vettore = NULL;
    this->dim = 0;
    this->dimMax = 0;
    this->curr = NULL;
    //fine
}

/*
//costruttore con elemento
1 vettore e curr a null
2 dim e dimax a 0
3 curr a null
4 setto la dim a 1
5 setto dimmax a 2
6 inizializzo il vettore con la new dimensione 2
7 inizializzo il curr come il vettore
8 inserisco l'elmento nel vettore
9 incremento il curr di 1
10 fine
test case :
1 cosa succede se si tenta di inizializzare due volte lo stesso oggetto ?
2 provare tutti i tipi di dato anche oggetti personalizza
*/
template<typename T>
Vettore<T>::Vettore(T elemento){
    this->vettore = NULL;
    this->dim = 1;
    this->dimMax = 2;
    this->curr = NULL;
    this->vettore = new T[dimMax];
    this->curr = this->vettore;
    *(this->vettore) = elemento;
    this->curr++;
    // fine
}

/*
// costruttore con dimensione e valore/elemento
1 vettore e curr a null
2 dim e dimax a 0
3 curr a null
4 setto la dim = alla dimensione passata come parametro
5 setto la dimmax come : dim * 2
6 inizializzo il vettore interno con new e dim = a dimax
7 inizializzo curr come il vettore interno (punta all elemento indice 0)
8 inizio iterazione per riempire il vettore con il valore passato come parametro
9 ad ogni iterazione inserisco l'elemento nel vettore e incremento curr di 1
10 fine iterazione
11 fine 
test case :
1 cosa succede se si tenta di inizializzare due volte lo stesso oggetto ?
2 provare tutti i tipi di dato anche oggetti personalizzati
*/

template<typename T>
Vettore<T>::Vettore(int dim, T valore){
    this->vettore = NULL;
    this->dim = 1;
    this->dimMax = 2;
    this->curr = NULL;
    this->dim = dim;
    this->dimMax = dim *2;
    this->vettore = new T[dimMax];
    this->curr = this->vettore;
    for (int i = 0; i < dim; i++)
    {
        *(this->vettore + i) = valore;
    }
    // fine
}