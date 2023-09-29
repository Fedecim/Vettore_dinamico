#include <iostream>
#include "Vettore.cpp"
#include <string>
using namespace std;
template<typename T>
void stampa(Vettore<T>& vett){
    T* curr = nullptr;
    curr = vett.getVett();
    for (int i = 0; i < vett.getDim(); i++) {
        cout << "["<< i<< "]: "<< *( vett.getVett() + i) << "\n";
    }
}
int main()
{
    Vettore <int> vettore(5,0);
    vettore.push_back(10);
    stampa(vettore);
    vettore.pop_back();
    stampa(vettore);
    vettore.push_back(20000);
    stampa(vettore);
    printf("FINE PROGRAMMA\n");
    return 1;
}