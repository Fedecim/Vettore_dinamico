#include "vettore.h"
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
        *(this->curr) = valore;
        this->curr++;
    }
    // fine
}

/*
costruttore di copia 
1 controllo che l'oggetto passato sia inizializzato in caso contrario termina
2 con l ogg inizializzato controllo che la dimensione sia diversa da 0 in caso contrario termina. (se la dim è 0 la dimmax saràßempre = a 2)
3 con ogg iniz. con dim != da 0 setto dim = ogg.dim
4 setto dimmax = ogg.dimax
### controllo che dim non sia = a dimmax-1 se lo è : dimmax * 2
5 inizializzo il vettore interno con new e dim = dimax
6 inizializzo curr = al vettore interno
7 inizio iterazione scorro l array interno dell ogg di copia
8 ad ogni iter : inserisco copia elemento nel vettore interno e incremento curr
9 fine iterazione
10 fine.
*/
template<typename T>
Vettore<T>::Vettore(const Vettore &copia){

    // controllo che l'oggetto passato sia inizializzato in caso contrario termina
    if(!(copia.getVett())){
        return;
    }
    //con l ogg inizializzato controllo che la dimensione sia diversa da 0 in caso contrario termina. 
    //(se la dim è 0 la dimmax saràßempre = a 2)
    if(copia.getDim() == 0){
        this->dimMax = 2;
        this->dim = 0;
        this->vettore = new T[this->dimMax];
        this->curr = this->vettore;
        return;
    }
    //con ogg iniz. con dim != da 0 setto dim = ogg.dim
    this->dim = copia.getDim();
    //setto dimmax = ogg.dimax
    this->dimMax = copia.getDimMax();
    //controllo che dim non sia = a dimmax-1 se lo è : dimmax * 2
    if(this->dim == this->dimMax-1){
        this->dimMax *= 2;
    }
    //5 inizializzo il vettore interno con new e dim = dimax
    this->vettore = new T[this->dimMax];
    //6 inizializzo curr = al vettore interno
    this->curr = this->vettore;
    //7 inizio iterazione scorro l array interno dell ogg di copia
    for (int i = 0; i < copia.getDim(); i++) 
    {
        //8 ad ogni iter : inserisco copia elemento nel vettore interno e incremento curr
        *(this->curr) = *(copia.getVett()+i);
        this->curr++;
    }
    //this->vettore = NULL;
    printf("Fine costruttore di copia\n");
}
template<typename T>
Vettore::Vettore(const T& array){
    
}
/*
metodo push_back :
in sintesi bisogna :
 - controllare se esiste
 - controllare se è pieno
 - controllare se è quasi pieno (dimax - 1)

1 - controlla se il vettore esiste ? : inizializzalo ma prima inizializza tutte le variabili : dim e dimax poi vettore e curr
2 - controlla se il vettore è pieno ? : crea copia del vettore con dimax * 2
3 - controlla se è quasi pieno ? : crea copia del vettore con dimax * 2
*/

template<typename T>
void Vettore<T>::push_back(const T& elemento){
    // controlla se il vettore è inizializzato
    if(this->vettore == NULL){
        this->dim = 0;
        this->dimMax = 2;
        this->vettore = new T[dimMax];
        this->curr = this->vettore;
    }
    // controllo se il vettore è pieno / quasi pieno
    if(this->dim == this->dimMax || this->dim == this->dimMax-1){
        // qui bisogna creare una copia del vettore e allocare nuova memoria
        this->dimMax *= 2;
        T* temp = new T[this->dimMax];
        // setto il curr uguale all vettore temp
        this->curr = temp;
        //inizio iterazione per copiare gli elementi del vett interno in temp
        for (int i = 0; i < this->dim; i++) {
            *(temp+i) = *(this->vettore+i);
            this->curr++;
        }
        
        // ora distruggo il vettore interno e gli assegno il vettore temp
        //this->vettore = NULL;
        delete [] this->vettore;
        this->vettore = temp;
    }
    // inserisco l elemento nel vettore
    *(this->curr) = elemento;
    this->curr++;
    this->dim++;
    printf("SONO IL METODO push_back\n");
}
/*
popoback:
- controllare che sia inizializzato in caso non lo sia : o ritorniamo eccezzione o facciamo gli indiani
- controllare che non sia vuoto : eccezzione o indiani
- controllare che la dimMax non sia grande 4 volte la dim in caso lo sia dimMax/2

*/
template<typename T>
void Vettore<T>::pop_back(){
    // caso vettore non inizializzato
    if(this->vettore == NULL){
        return;
    }
    // caso vettore inizializzato ma vuoto
    if(this->curr == this->vettore){
        return;
    }
    // controllo la dimensione massima del vettore
    if(this->dimMax > this->dim * 4){
        // ridurre la dimensione : dimMax / 2
        this->dimMax/=2;
        // per farlo utilizzo la funzione di C realloc (non dovrebbe, ma potrebbe dare problemi con la new)
        this->vettore = (T*)realloc(this->vettore,this->dimMax * sizeof(T));
    }
    // ora posso 'eliminare' l'elemento dal vettore
    // semplicemente sposto indietro il curr
    this->curr--;
    this->dim--;
    //printf("Hello im the pop back method motherfucker\n");
}