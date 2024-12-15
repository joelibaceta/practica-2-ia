#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>
#include <set>
using namespace std;

string cadena(string a, string b, string c) {
    string x, y,m;
    string valor=c;

    for (int i=0;  i<=a.size(); i++) {
        x=a[i];
        if (x==valor){
            a.erase(i, 1);
        }

        for (int j=0; j<=b.size(); j++) {
            y=b[j];
            if (x==y|| y==valor) {
                b.erase(j, 1);

                continue;
            }
        }
    }
    return a+b;
}


int main() {
    string a, b,c; // d;// x, y,m;
    //int k=0;

    cout << "Ingrese un el primer número de  4 cifras o más: ";
    cin >> a;

    while ( a.size() < 4) {
        cout << "Ingrese un el segundo número de  4 cifras o más: ";
        cin >> a;
    }

    cout << "Ingrese el segundo numero entero positivo con 4 o mas cifras: ";
    cin >> b;

    while (b.size() <4) {
        cout << "El numero debe tener 4 o mas cifras. Intente de nuevo: ";
        cin >> b;
    }

    cout << "Ingrese el un numero: ";
    cin >> c;
    string resultado, busqueda;
    resultado=cadena(a, b,  c);
    sort(resultado.begin(), resultado.end());
    cout << resultado;
}




