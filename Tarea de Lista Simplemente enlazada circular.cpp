#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct Nodo {
    int dato;
    Nodo *siguiente;
};

void insertarLista(Nodo *&, int);
void mostrarLista(Nodo*);
void calcularMayorMenor(Nodo *);
void suma(Nodo *);

int main() {
    Nodo *lista = NULL;
    int dato;
    char respuesta;

    do {
        cout << "Digite un numero: ";
        cin >> dato;
        insertarLista(lista, dato);
        cout << "\nDesear agregar otro nodo (s/n): ";
        cin >> respuesta;
    } while ((respuesta == 'S') || (respuesta == 's'));

    Nodo *aux = lista;
    while (aux->siguiente != NULL) {
        aux = aux->siguiente;
    }
    aux->siguiente = lista;

    cout << "\nElementos de la lista\n";
    mostrarLista(lista);
    calcularMayorMenor(lista);
    suma(lista);

    return 0;
}

void insertarLista(Nodo *&lista, int n) {
    Nodo *nuevo_nodo = new Nodo();
    Nodo *aux;

    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = NULL;

    if (lista == NULL) {
        lista = nuevo_nodo;
    } else {
        aux = lista;
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo_nodo;
    }
    cout << "\nElemento " << n << " agregado correctamente";
}

void mostrarLista(Nodo *lista) {
    Nodo *temp = lista;
    do {
        cout << temp->dato << " -> ";
        temp = temp->siguiente;
    } while (temp != lista);
}

void calcularMayorMenor(Nodo *lista) {
    int mayor = 0, menor = 99999;
    Nodo *temp = lista;
    do {
        if ((temp->dato) > mayor) {
            mayor = temp->dato;
        }

        if ((temp->dato) < menor) {
            menor = temp->dato;
        }

        temp = temp->siguiente;
    } while (temp != lista);

    cout << "\nEl mayor elemento es: " << mayor << endl;
    cout << "El menor elemento es: " << menor << endl;
}

void suma(Nodo *lista) {
    int suma = 0;
    Nodo *actual= lista;

    do {
        suma += actual->dato;
        actual = actual->siguiente;
    } while (actual != lista);

    cout << "La suma de los elementos es: " << suma << endl;
}

