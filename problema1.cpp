#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>
#include <set>
#include <algorithm>
using namespace std;

bool isnumero(const string& palabra)
try {
    double num = stod(palabra);
     return true;

} catch (const invalid_argument& e) {
    return false;
}

int cantidad_vocales(const string& palabra) {
    int j=0;
    set<char> letrasunicas(palabra.begin(), palabra.end());
    for (char c:letrasunicas) {
        switch  (c) {
            case 'a':
                j=j+1;
                break;
            case 'e':
                j=j+1;
            break;
            case 'i':
                j=j+1;
            break;
            case 'o':
                j=j+1;
            break;
            case 'u':
                j=j+1;
            break;
        }
    }
return j;
}

int total_contador(const vector<int>& vector, int valor) {
    int contador = 0;
    for (int i = 0; i < vector.size(); i++) {
        if (vector[i] == valor) {
            contador++;
        }
    }

    return contador;
}

int main() {
    string oracion;
    string palabra;
    vector<int> posiciones;
    int total=0;
    int suma=0;
    int valor ;
    int count ;
    int cv=0;
    cout << "Ingrese una cadena: ";
    cin >> oracion;
    while ( oracion.size() >200 ){  // Mientras el número sea menor que 1000 (menos de 4 cifras)
        cout << "la cantidad de caracteres no puede ser mayor a 200";
        cin >> oracion;
    }
    getline(cin, oracion);

    istringstream stream(oracion);
    // Extraer las palabras una a una cadena
    while (stream >> palabra) {
       // cout << palabra << endl;
        if (isnumero(palabra)) {
            total=total + stoi(palabra);
        }
        else {
            cv= cantidad_vocales(palabra);
            //cout << "Letra " << cv << ": " <<palabra << endl;
            posiciones.push_back(cv);

        }
    }
    suma=(total%5)+ 1;
    cout << "El resultado de la suma es : " +to_string(suma)<< endl;

    sort(posiciones.begin(), posiciones.end());

        int tot_vec =posiciones.size();

        for (int j=0; j<tot_vec; j++) {
            count=0;
            valor=posiciones[j];

            count=total_contador(posiciones, valor)  ;
            cout << "Hay " << count<< " palabras con " << valor << " vocales diferentes" << std::endl;
            }

        return 0;
    }




