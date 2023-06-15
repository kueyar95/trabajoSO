class Usuario {
public:
    Usuario(std::string nombre, std::string tipo);
    std::string getNombre();
    void setNombre(std::string nombre);
    std::string getTipo();
    void setTipo(std::string tipo);
	void realizarSolicitud(Sistema* sistema, int recursosRequeridos);

private:
    std::string nombre; // Nombre del usuario
    std::string tipo; // Tipo de usuario (por ejemplo, humano, sistema, etc.)
};