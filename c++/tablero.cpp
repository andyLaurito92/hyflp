#include "tablero.h"

using namespace std;
using std::vector;

Tablero::Tablero(int ancho,int alto){
	_ancho = ancho;
	_alto = alto;
	_mundoActual = vector<vector<int> >(_alto+2, vector<int> (_ancho+2, 0));
	_mundoAnterior = vector<vector<int> >(_alto+2, vector<int> (_ancho+2, 0));

	/* inicializamos la semilla del random */
 	srand (time(NULL));

	for(int i = 1; i < _alto+1; i++){
		for(int j = 1; j < _ancho+1; j++){
			int numeroAleatorio = rand() % 10 + 1;
			if(numeroAleatorio < 4)	_mundoActual[i][j] = 1;
			else			_mundoActual[i][j] = 0;
		}
	}

	establecerMundoAnteriorComoElActual();
}

void Tablero::establecerMundoAnteriorComoElActual(){
	for(int i = 1; i < _alto+1; i++){
		for(int j = 1; j < _ancho+1; j++){
			_mundoAnterior[i][j] = _mundoActual[i][j];
		}
	}
}

void Tablero::avanzarCicloVidaCelulas(){
	establecerMundoAnteriorComoElActual();
	for(int i = 1; i < _alto+1; i++){
		for(int j = 1; j < _ancho+1; j++){
			int cantidadVecinosVivos = 0;
			cantidadVecinosVivos += _mundoAnterior[i][j] + _mundoAnterior[i-1][j];
			cantidadVecinosVivos += _mundoAnterior[i][j-1] + _mundoAnterior[i][j+1];
			cantidadVecinosVivos += _mundoAnterior[i+1][j-1] + _mundoAnterior[i+1][j];
			cantidadVecinosVivos += _mundoAnterior[i][j] + _mundoAnterior[i+1][j+1];

			if(_mundoAnterior[i][j] == 1){
				if( cantidadVecinosVivos < 2 ) _mundoActual[i][j] = 0;
				if( cantidadVecinosVivos > 2 ) _mundoActual[i][j] = 0;
				if( cantidadVecinosVivos == 2 ) _mundoActual[i][j] = 1;
				
			}else{
				if( cantidadVecinosVivos == 3 ) _mundoActual[i][j] = 1;
			}
		}
	}				
}

void Tablero::imprimir(int iteracion){
	cout << "___________ITERACION " << iteracion << "___________" << endl;
	for(int i = 1; i < _alto+1; i++){
		cout << " " << endl;
		for(int j = 1; j < _ancho+1; j++){
			if( _mundoActual[i][j] == 1 )	cout << " # ";
			else				cout << " * ";
		}
	} 
	cout << endl;
}

bool Tablero::cambioConRespectoAlAnteriorCiclo(){
	bool cambio = false;
	for(int i = 1; i < _alto +1; i++){
		for(int j = 1; (j < _ancho+1) && !cambio ; j++){
			if(_mundoActual[i][j] != _mundoAnterior[i][j]) cambio = true;
		}
	}
	return cambio;
}	

