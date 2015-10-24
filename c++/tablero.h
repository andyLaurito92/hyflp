class Tablero{
	int _alto,_ancho;
	public:
		Tablero(int ancho,int alto);
		void avanzarCicloVidaCelulas();
		bool hayMovimientosDisponibles();
		void imprimir();
};
