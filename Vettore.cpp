#include "vettore.h"
#include <iostream>

template<typename T>
Vettore<T>::Vettore(){
    this->vettore = NULL;
    this->dim = 0;
    this->dimMax = 0;
    this->curr = NULL;
}
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
}
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
}
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
}
template<typename T>
Vettore<T>::Vettore(const T* inizio, const T* fine){
    // controlla che inizio non sia NULL
    if(!(inizio)){
        return;
    }
    // se inizio e fine sono uguali
    if(inizio == fine){
        return;
    }
    // inizializzo il vettore interno
    this->dimMax = (fine - inizio ) * 2;
    this->dim = fine-inizio;
    this->vettore = new T[dimMax];
    this->curr = this->vettore;
    // inizio iterazione
    for (const T* it = inizio; it != fine; ++it) {
        *(this->curr) = *it;
        this->curr++;
    }
}
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
}
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
}

// CANCELLAZIONE
// CLEAR : Per cancellare gli elementi del vettore è sufficente fare tornare il puntatore interno
// curr (che punta posizione prossimo elemento) indietro uguale al vettore interno (stesso indirizzo)
template<typename T>
void Vettore<T>::clear(){
    // se il vettore interno non è inizializzato
    if(this->vettore == NULL){
        return;
    }
    // se il vettore è gia vuoto
    if(this->vettore == this->curr){
        return;
    }
    this->curr = this->vettore;
    this->dim = 0;
}
template<typename T>
Vettore<T>& Vettore<T>::operator=(const Vettore<T> &copia){
    // se il vettore non è uguale a null è pieno e andrebbe distrutto e rinizializzato
    if(this->vettore){
        delete[]this->vettore;
    }
    // controllare che l'oggetto passato sia un oggetto valido : inizializzato
    if(!(copia.getVett())){
        return *this;
    }
    this->dim = copia.getDim();
    this->dimMax =copia.getDimMax();
    this->vettore = new T[dimMax];
    this->curr = this->vettore;
    if(copia.getCurr() != copia.getVett()){
        for (T* i = copia.inizio(); i != copia.fine(); ++i) {
            *(this->curr) = *i;
            this->curr++;
        }
    }
    else
    {
        throw std::invalid_argument("Oggetto di copia non valido");
    }
    return *this;
}

template<typename T>
T& Vettore<T>::at(const int &indice){
    if(indice < 0 || indice > this->dim){
        throw  std::out_of_range("Index out of range");
    }
    return *(this->vettore + indice);
}

template<typename T>    
T Vettore<T>::operator[](int indice)const{
    return *(this->vettore + indice);
}