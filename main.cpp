#include <iostream>
#include "Vettore.cpp"
#include <string>
using namespace std;
class prova{
    public:
    int dato1;
    int dato2;
    prova(){ dato1 = 100; dato2 = 300; };
};
int main()
{
    Vettore <int> test(100,0);
    Vettore <int> test2[200];
    printf("FINE PROGRAMMA\n");
    return 1;
}