#include <iostream>
#include <vector>
using namespace std;

vector<int> multiplica_polinomios(vector<int> &P, vector<int> &Q) {
    int n = P.size();
    int m = Q.size();

    vector<int> resultado(n + m - 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            resultado[i + j] += P[i] * Q[j];
        }
    }
    return resultado;
}

void mostrar_polinomio(const vector<int> &polinomio) {
    for (int i = 0; i < polinomio.size(); i++) {
        cout << polinomio[i] << (i < polinomio.size() - 1 ? ", " : "");
    }
    cout << endl;
}

int main() {

    vector<int> P = {3, -4, 0, 1}; // 3x^3 - 4x^2 + 1
    vector<int> Q = {-2, 1, 0};    // -2x^2 + x

    cout << "Coeficientes del primer polinomio P(x): ";
    mostrar_polinomio(P);

    cout << "Coeficientes del segundo polinomio Q(x): ";
    mostrar_polinomio(Q);

    vector<int> producto = multiplica_polinomios(P, Q);

    cout << "Coeficientes del producto P(x) * Q(x): ";
    mostrar_polinomio(producto);

    return 0;
}
