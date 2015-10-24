#include <iostream>
#include "tablero.h"
using namespace std;


int main(){
	int ancho, alto;
	cout << "Ingrese el alto y luego el ancho del tablero a crear." << endl; 
	cin >> ancho;
	cin >> alto;
	
	Tablero miTablero(ancho,alto);
	int numeroIteracion = 0;
	
	miTablero.avanzarCicloVidaCelulas();
	miTablero.imprimir(numeroIteracion++);	
	while(miTablero.cambioConRespectoAlAnteriorCiclo()){	
		miTablero.avanzarCicloVidaCelulas();
		miTablero.imprimir(numeroIteracion++);	
	}
}
