#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct Nodo {
    int dato;
    Nodo *siguiente;
    Nodo *anterior;
};

void insertarLista(Nodo *&, int);
void mostrarLista(Nodo*);
void calcularMayorMenor(Nodo *);
void suma(Nodo *);
void mostrarListaInversa(Nodo *);

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

    cout << "\nElementos de la lista\n";
    mostrarLista(lista);
    calcularMayorMenor(lista);
    suma(lista);

    cout << "\nElementos de la lista en sentido inverso\n";
    mostrarListaInversa(lista);

    return 0;
}

void insertarLista(Nodo *&lista, int n) {
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = NULL;
    nuevo_nodo->anterior = NULL;

    if (lista == NULL) {
        lista = nuevo_nodo;
    } else {
        Nodo *aux = lista;
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo_nodo;
        nuevo_nodo->anterior = aux;
    }
    cout << "\nElemento " << n << " agregado correctamente";
}

void mostrarLista(Nodo *lista) {
    Nodo *temp = lista;
    while (temp != NULL) {
        cout << temp->dato << " -> ";
        temp = temp->siguiente;
    }
    
}

void calcularMayorMenor(Nodo *lista) {
    if (lista == NULL) {
        cout << "La lista está vacía." << endl;
        return;
    }

    int mayor = lista->dato;
    int menor = lista->dato;
    Nodo *actual = lista->siguiente;

    while (actual != NULL) {
        if (actual->dato > mayor) {
            mayor = actual->dato;
        }

        if (actual->dato < menor) {
            menor = actual->dato;
        }

        actual = actual->siguiente;
    }

    cout << "\nEl mayor elemento es: " << mayor << endl;
    cout << "El menor elemento es: " << menor << endl;
}

void suma(Nodo *lista) {
    if (lista == NULL) {
        cout << "La lista está vacía." << endl;
        return;
    }

    int suma = 0;
    Nodo *actual = lista;

    while (actual != NULL) {
        suma += actual->dato;
        actual = actual->siguiente;
    }

    cout << "La suma de los elementos es: " << suma << endl;
}

void mostrarListaInversa(Nodo *lista) {
    if (lista == NULL) {
        cout << "La lista está vacía." << endl;
        return;
    }

    // Moverse al último nodo de la lista
    Nodo *actual = lista;
    while (actual->siguiente != NULL) {
        actual = actual->siguiente;
    }

    // Recorrer la lista en sentido inverso e imprimir los elementos
    while (actual != NULL) {
        cout << actual->dato << " -> ";
        actual = actual->anterior;
    }
    
}

