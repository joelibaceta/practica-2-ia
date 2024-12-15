#include <iostream>
#include <string>
using namespace std;


struct Espia {
    string nombre;
    Espia* siguiente;


    Espia(string _nombre) {
        nombre = _nombre;
        siguiente = NULL;
    }
};

int numeroEspias(Espia* espiaInicial) {
    if (!espiaInicial) return 0;
    int contador = 1;
    Espia* actual = espiaInicial;
    while (actual->siguiente != espiaInicial) {
        actual = actual->siguiente;
        contador++;
    }
    return contador;
}

Espia* avanzar(Espia* espiaInicial, int X) {
    Espia* actual = espiaInicial;
    for (int i = 0; i < X - 1; i++) {
        actual = actual->siguiente;
    }
    return actual;
}

Espia* ultimoSobreviviente(Espia* espiaInicial, int K) {
    Espia* actual = espiaInicial;


    while (actual->siguiente != actual) {
        Espia* eliminado = avanzar(actual, K);
        cout << "El espia " << eliminado->nombre << " ha sido eliminado.\n";

        actual->siguiente = eliminado->siguiente;
        delete eliminado;

        actual = actual->siguiente;
    }
    return actual;
}

int main() {
    Espia* pDiego = new Espia("Diego");
    Espia* pPamela = new Espia("Pamela");
    Espia* pRafael = new Espia("Rafael");
    Espia* pPaulo = new Espia("Paulo");
    Espia* pSamir = new Espia("Samir");

    pDiego->siguiente = pPamela;
    pPamela->siguiente = pRafael;
    pRafael->siguiente = pPaulo;
    pPaulo->siguiente = pSamir;
    pSamir->siguiente = pDiego;

    cout << "Cantidad de espias: " << numeroEspias(pDiego) << "\n";

    int K = 3;
    Espia* sobreviviente = ultimoSobreviviente(pDiego, K);

    cout << "El ultimo espia sobreviviente es: " << sobreviviente->nombre << "\n";

    delete sobreviviente;

    return 0;
}
