#include <iostream>
#include <conio.h>

using namespace std;

struct Nodo {
    int dato;
    int prioridad;
    Nodo* siguiente;
};

void agregarProceso(Nodo*&, int, int);
void atenderProceso(Nodo*&);
void imprimirProcesos(Nodo*);

int main() {
    Nodo* pila = NULL;
    int dato, prioridad;
    char opcion;

    do {
        cout << "Menu:\n";
        cout << "1. Agregar proceso\n";
        cout << "2. Atender procesos\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case '1':
            cout << "Ingrese el numero del proceso: ";
            cin >> dato;
            cout << "Ingrese la prioridad del proceso (1, 2, o 3): ";
            cin >> prioridad;
            agregarProceso(pila, dato, prioridad);
            break;
        case '2':
            atenderProceso(pila);
            break;
        case '3':
            cout << "Saliendo del programa.\n";
            break;
        default:
            cout << "Opcion invalida. Por favor seleccione una opcion valida.\n";
        }
    } while (opcion != '3');

    return 0;
}

void agregarProceso(Nodo*& pila, int dato, int prioridad) {
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = dato;
    nuevo_nodo->prioridad = prioridad;
    nuevo_nodo->siguiente = NULL;

    if (pila == NULL) {
        pila = nuevo_nodo;
    } else {
        Nodo* aux = pila;
        Nodo* anterior = NULL;
        while (aux != NULL && aux->prioridad <= prioridad) {
            anterior = aux;
            aux = aux->siguiente;
        }
        if (anterior == NULL) {
            nuevo_nodo->siguiente = pila;
            pila = nuevo_nodo;
        } else {
            anterior->siguiente = nuevo_nodo;
            nuevo_nodo->siguiente = aux;
        }
    }
    cout << "Proceso agregado correctamente.\n";
}

void atenderProceso(Nodo*& pila) {
    if (pila == NULL) {
        cout << "No hay procesos en espera.\n";
        return;
    }

    Nodo* aux = pila;
    pila = pila->siguiente;
    cout << "Atendiendo proceso: " << aux->dato << " de prioridad " << aux->prioridad << endl;
    delete aux;

    cout << "Numeros restantes en la pila:\n";
    imprimirProcesos(pila);
}

void imprimirProcesos(Nodo* pila) {
    Nodo* aux = pila;
    while (aux != NULL) {
        cout << aux->dato << " - Prioridad: " << aux->prioridad << endl;
        aux = aux->siguiente;
    }
    cout << endl;
}

