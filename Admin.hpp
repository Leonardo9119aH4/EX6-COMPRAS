#include <iostream>
#include <vector>
#include <chrono>
#include "Usuario.hpp"

class Admin : public Usuario {
	Admin() {};
	~Admin() {};
	bool banirUsuario(Usuario* usuarioBanir, std::chrono::system_clock time_t);
};