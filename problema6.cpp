#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string suma_hexadecimal(string num1, string num2) {

    int max_len = max(num1.size(), num2.size());
    while (num1.size() < max_len) num1 = "0" + num1;
    while (num2.size() < max_len) num2 = "0" + num2;

    string resultado = "";
    int carry = 0;

    for (int i = max_len - 1; i >= 0; --i) {

        int val1 = isdigit(num1[i]) ? num1[i] - '0' : toupper(num1[i]) - 'A' + 10;
        int val2 = isdigit(num2[i]) ? num2[i] - '0' : toupper(num2[i]) - 'A' + 10;

        int suma = val1 + val2 + carry;
        carry = suma / 16;
        int digito = suma % 16;

        resultado += (digito < 10) ? (digito + '0') : (digito - 10 + 'A');
    }

    if (carry > 0) {
        resultado += (carry < 10) ? (carry + '0') : (carry - 10 + 'A');
    }

    reverse(resultado.begin(), resultado.end());
    return resultado;
}

int main() {
    // Ejemplo de uso
    string num1, num2;

    cout << "Ingrese el primer número hexadecimal: ";
    cin >> num1;
    cout << "Ingrese el segundo número hexadecimal: ";
    cin >> num2;

    string resultado = suma_hexadecimal(num1, num2);
    cout << "La suma es: " << resultado << endl;

    return 0;
}