#include <vector>
#include <stdlib.h>
#include <time.h> 
#include <iostream>

using namespace std;
using std::vector;

class Tablero{
	int _alto,_ancho;
	vector< vector<int> > _mundoActual;
	vector< vector<int> > _mundoAnterior;
	public:
		Tablero(int ancho,int alto);
		void avanzarCicloVidaCelulas();
		bool cambioConRespectoAlAnteriorCiclo();
		void imprimir(int iteracion);
		void establecerMundoAnteriorComoElActual();
};
