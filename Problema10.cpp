#include <iostream>
#include <vector>
using namespace std;

bool esMosaicoValido(const vector<vector<int>>& imagen, const vector<vector<int>>& submatriz, int filasSub, int columnasSub) {
    int filasOriginal = imagen.size();
    int columnasOriginal = imagen[0].size();

    for (int i = 0; i < filasOriginal; i++) {
        for (int j = 0; j < columnasOriginal; j++) {
            if (imagen[i][j] != submatriz[i % filasSub][j % columnasSub]) {
                return false;
            }
        }
    }
    return true;
}

vector<vector<int>> encontrarMenorSubmatriz(const vector<vector<int>>& imagen) {
    int filas = imagen.size();
    int columnas = imagen[0].size();

    for (int filasSub = 1; filasSub <= filas; filasSub++) {
        for (int columnasSub = 1; columnasSub <= columnas; columnasSub++) {
            if (filas % filasSub == 0 && columnas % columnasSub == 0) {
                vector<vector<int>> submatriz(filasSub, vector<int>(columnasSub));
                for (int i = 0; i < filasSub; i++) {
                    for (int j = 0; j < columnasSub; j++) {
                        submatriz[i][j] = imagen[i][j];
                    }
                }
                if (esMosaicoValido(imagen, submatriz, filasSub, columnasSub)) {
                    return submatriz;
                }
            }
        }
    }

    return imagen;
}

int main() {
    vector<vector<int>> imagen = {
        {0, 120, 0, 0, 120, 0, 0, 120, 0},
        {120, 255, 120, 120, 255, 120, 120, 255, 120},
        {0, 120, 0, 0, 120, 0, 0, 120, 0},
        {0, 120, 0, 0, 120, 0, 0, 120, 0},
        {120, 255, 120, 120, 255, 120, 120, 255, 120},
        {0, 120, 0, 0, 120, 0, 0, 120, 0}
    };

    // Encontrar la submatriz más pequeña
    vector<vector<int>> submatrizMinima = encontrarMenorSubmatriz(imagen);

    // Imprimir la submatriz mínima
    cout << "Submatriz mínima:" << endl;
    for (const auto& fila : submatrizMinima) {
        for (int valor : fila) {
            cout << valor << " ";
        }
        cout << endl;
    }

    return 0;
}