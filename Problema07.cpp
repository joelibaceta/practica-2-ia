#include <iostream>
using namespace std;

void ingresarDatos(int arr[], int& size) {
    cout << "Ingrese la cantidad de empleados: ";
    int n;
    cin >> n;
    
    int index = 0;
    for (int i = 0; i < n; i++) {
        cout << "Ingrese el código del empleado " << (i + 1) << ": ";
        cin >> arr[index++];
        
        cout << "Ingrese el número de meses con horas extras del empleado: ";
        int meses;
        cin >> meses;

        cout << "Ingrese las horas extras para cada mes: ";
        for (int j = 0; j < meses; j++) {
            cin >> arr[index++];
        }
    }
    size = index;
}

void mostrarArreglo(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void procesarEmpleados(int arr[], int& size) {
    int index = 0;
    int totalEmpleados = 0;
    int totalHoras = 0;

    while (index < size) {
        int codigo = arr[index++];
        int sumaHoras = 0;
        while (index < size && arr[index] >= 0 && arr[index] <= 99) {
            sumaHoras += arr[index++];
        }
        totalHoras += sumaHoras;
        totalEmpleados++;
    }
    
    float promedio = (float)totalHoras / totalEmpleados;

    int newArr[1000];
    int newIndex = 0;
    index = 0;

    while (index < size) {
        int codigo = arr[index++];
        int sumaHoras = 0;
        int startIndex = newIndex;

        newArr[newIndex++] = codigo; 

        while (index < size && arr[index] >= 0 && arr[index] <= 99) {
            sumaHoras += arr[index];
            newArr[newIndex++] = arr[index++];
        }

        if (sumaHoras > promedio) {
            newIndex = startIndex; 
        }
    }

    for (int i = 0; i < newIndex; i++) {
        arr[i] = newArr[i];
    }
    size = newIndex;
}

int main() {
    const int MAX_SIZE = 1000;
    int arr[MAX_SIZE] = {
        200, 40, 40,       
        150, 20, 10, 10,  
        300, 20, 30, 10, 20 
    };
    int size = 12; 

    cout << "Arreglo inicial:" << endl;
    mostrarArreglo(arr, size);

    procesarEmpleados(arr, size);

    cout << "Arreglo final después de eliminar empleados:" << endl;
    mostrarArreglo(arr, size);

    return 0;
}