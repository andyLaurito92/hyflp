#include <iostream>
#include "tablero.h"
using namespace std;


int main(){

	cout << "Corriendo el conways!!" << endl;

	int ancho, alto;
	cout << "Ingrese el alto y luego el ancho del tablero a crear." << endl; 
	cin >> ancho;
	cin >> alto;
	
	Tablero untablero(ancho,alto);
	while(untablero.hayMovimientosDisponibles()){	
		untablero.avanzarCicloVidaCelulas();
		untablero.imprimir();	
	}
}