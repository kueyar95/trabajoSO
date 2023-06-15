class Hardware {
	public:
		Hardware(int capacidad, int velocidad, std::string tipo, std::string descripcion);
		int getCapacidad();
		void setCapacidad(int capacidad);
		int getVelocidad();
		void setVelocidad(int velocidad);
		std::string getTipo();
		void setTipo(std::string tipo);
		std::string getDescripcion();
		void setDescripcion(std::string descripcion);

	private:
		int capacidad;
		int velocidad;
		std::string tipo; // Tipo de hardware (por ejemplo, CPU, GPU, memoria, almacenamiento, etc.)
		std::string descripcion; // Descripción de las especificaciones técnicas del hardware
};
