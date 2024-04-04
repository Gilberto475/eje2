#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

void insertarlista (Nodo *&,int );

int main (){
	
	

	
	
	
	
	getch ();
	return 0;


}



void insertarlista (Nodo lista ,int n){
	Nodo *nuevonodo = new Nodo;
	Nodo *aux = new Nodo;
	
	nuevonodo->dato=n;
	nuevonodo->siguiente=NULL;
	
	if (lista==NULL){
		
		lista= nuevonodo;
		
	}
	else {
		aux=lista;
		while (aux->siguiente!=NULL){
			aux=aux->siguiente;
		}
		
		aux->siguiente=nuevonodo;
	}
	
	cout<<"\nEl numero "<<n<<" ha sido ingresado correctamente";
}



