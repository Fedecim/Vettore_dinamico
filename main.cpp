#include <iostream>
#include "vettore.cpp"
#include <string>
using namespace std;
int main()
{
    // istanza oggetto di classe Vettore con costruttore di range
    Vettore <int>test(10,0);
    // assegnazione all indice zero del vettore valore : 100
    test.at(0) = 100;
    // visualizzo valore assegnato
    printf("valore indice 0 : %d\n",test[0]);
    // inserisco elemento nel vettore con metodo push_back()
    test.push_back(200);
    // visualizzo numero di elementi e dimensione massima del vettore
    printf("Elementi nel vettore : %d\nDimensione massima : %d\n", test.getDim(), test.getDimMax());
    // stampa del contenuto del vettore tramite puntantori costanti : inzio e fine
    int count = 0;
    for (int* it = test.inizio(); it != test.fine(); ++it) 
    {
        printf("[%d]: %d\n",count,*it);
        count++;
    }
    // il metodo pop_back elimina l'ultimo elemento inserito 
    test.pop_back();
    printf("-----------------------------------------\n\nVettore dopo pop_back():\n\n");
    count = 0;
    for (int* it = test.inizio(); it != test.fine(); ++it) 
    {
        printf("[%d]: %d\n",count,*it);
        count++;
    }
    return 1;
}