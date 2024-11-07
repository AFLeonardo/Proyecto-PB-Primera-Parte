#include <iostream>
using namespace std;
int main() {
    int w=4;
    char cadena[10];
    cout<<"Ingresa una frase";
    cin.width(5);
    while(cin>>cadena) {
        cout.width(w++);
        cout<<cadena<<'\a'<<'\n';
        cin.width(5);
    }
    return 0;

}