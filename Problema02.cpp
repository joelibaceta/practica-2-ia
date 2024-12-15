#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void elimina_duplicado(string& texto) {
    string x, y;
    int n;
    char letra = '*';
    vector<int> posiciones;
    bool tiene_duplicados = false;

    for (int i = 0; i < texto.size() - 1; i++) {
        x = texto[i];
        y = texto[i + 1];
        if (x == y) {
            posiciones.push_back(i);
            posiciones.push_back(i + 1);
            tiene_duplicados = true;
        }
    }

    if (tiene_duplicados) {
        for (int j = 0; j < posiciones.size(); j++) {
            n = posiciones[j];
            texto[n] = letra;
        }

        texto.erase(remove(texto.begin(), texto.end(), letra), texto.end());
        elimina_duplicado(texto);
    }
}

int main() {
    string a;
    cout << "Ingrese una cadena: ";
    cin >> a;
    if (a.size() < 1 || a.size() > 200000) {
        cout << "la cadena no puede sobrepasar los 200,000 caracteres." << endl;
        return 1;
    }
    elimina_duplicado(a);
    cout << "resultado: " << a << endl;
    return 0;
}

