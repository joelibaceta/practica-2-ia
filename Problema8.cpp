#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <string>
using namespace std;

bool esDoblete(const string& a, const string& b) {
    if (a.size() != b.size()) return false;

    int diferencias = 0;
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            diferencias++;
            if (diferencias > 1) return false;
        }
    }

    return diferencias == 1;
}

// Construcción del grafo
unordered_map<string, vector<string>> construirGrafo(const vector<string>& palabras) {
    unordered_map<string, vector<string>> grafo;

    for (size_t i = 0; i < palabras.size(); i++) {
        for (size_t j = i + 1; j < palabras.size(); j++) {
            if (esDoblete(palabras[i], palabras[j])) {
                grafo[palabras[i]].push_back(palabras[j]);
                grafo[palabras[j]].push_back(palabras[i]);
            }
        }
    }

    return grafo;
}

// BFS para encontrar el camino más corto
vector<string> bfs(const unordered_map<string, vector<string>>& grafo, const string& inicio, const string& fin) {
    if (inicio == fin) return {inicio};

    queue<vector<string>> q;
    unordered_set<string> visitados;

    q.push({inicio});
    visitados.insert(inicio);

    while (!q.empty()) {
        vector<string> camino = q.front();
        q.pop();

        string ultimo = camino.back();

        for (const string& vecino : grafo.at(ultimo)) {
            if (visitados.find(vecino) == visitados.end()) {
                vector<string> nuevoCamino = camino;
                nuevoCamino.push_back(vecino);

                if (vecino == fin) return nuevoCamino;

                q.push(nuevoCamino);
                visitados.insert(vecino);
            }
        }
    }

    return {};
}

int main() {
    vector<string> palabras = {
        "booster",
        "rooster",
        "roaster",
        "roasted",
        "coasted",
        "coastal",
        "postal"
    };

    vector<pair<string, string>> pares = {
        {"booster", "roasted"},
        {"coastal", "postal"}
    };

    unordered_map<string, vector<string>> grafo = construirGrafo(palabras);

    for (const auto& par : pares) {
        const string& inicio = par.first;
        const string& fin = par.second;

        // Validar si las palabras están en el grafo
        if (grafo.find(inicio) == grafo.end() || grafo.find(fin) == grafo.end()) {
            cout << "No solution." << endl;
            cout << endl;
            continue;
        }

        // Encontrar el camino más corto
        vector<string> camino = bfs(grafo, inicio, fin);

        if (camino.empty()) {
            cout << "No solution." << endl;
        } else {
            for (const string& palabra : camino) {
                cout << palabra << endl;
            }
        }
        cout << endl;
    }

    return 0;
}