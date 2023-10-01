# Documentazione della Classe `Vettore`

La classe `Vettore` è una rappresentazione di un vettore dinamico in C++, implementato tramite template per consentire l'uso di diversi tipi di dati. Questa classe offre funzionalità per l'inizializzazione, l'accesso e la manipolazione sicura dei dati all'interno del vettore.

### Costruttori

#### Costruttore Predefinito
```cpp
 template<typename T>
Vettore<T>::Vettore();
```
Inizializza un vettore vuoto.

#### Costruttore con Elemento Iniziale
```cpp
template<typename T>
Vettore<T>::Vettore(T elemento);
```
Inizializza un vettore con un singolo elemento specificato.

#### Costruttore con Dimensione e Valore Iniziale
```cpp
template<typename T>
Vettore<T>::Vettore(int dim, T valore);
```
Inizializza un vettore con una dimensione specificata e tutti gli elementi impostati a un valore specifico.

#### Costruttore di Copia
```cpp
template<typename T>
Vettore<T>::Vettore(const Vettore &copia);
```
Inizializza un vettore copiando un altro vettore esistente.

#### Costruttore da Range
```cpp
template<typename T>
Vettore<T>::Vettore(const T* inizio, const T* fine);
```
Inizializza un vettore con gli elementi compresi tra due puntatori specificati (`inizio` e `fine`).

### Metodi di Modifica

#### `push_back(const T& elemento)`
Aggiunge un elemento alla fine del vettore.

#### `pop_back()`
Rimuove l'ultimo elemento dal vettore.

#### `clear()`
Svuota il vettore.

### Metodi di Accesso

#### `T& at(const int& indice)`
Restituisce un riferimento all'elemento del vettore all'indice specificato, sollevando un'eccezione `std::out_of_range` se l'indice è fuori dai limiti del vettore.

#### `T operator[](int indice) const`
Restituisce l'elemento del vettore all'indice specificato in sola lettura. Se l'indice è fuori dai limiti del vettore, il comportamento è indefinito.

### Altri Metodi

#### `T* inizio() const`
Restituisce un puntatore costante al primo elemento del vettore.

#### `T* fine() const`
Restituisce un puntatore costante al prossimo elemento da inserire nel vettore.

#### `Vettore<T>& operator=(const Vettore<T>& copia)`
Sovrascrive l'operatore di assegnamento per consentire la copia sicura di un vettore in un altro.

### Eccezioni
- `std::out_of_range`: Lanciata quando si tenta di accedere a un elemento al di fuori dei limiti del vettore.
- `std::invalid_argument`: Lanciata quando si tenta di utilizzare un oggetto `Vettore` non valido o NULL.
