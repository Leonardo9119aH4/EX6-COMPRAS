#include <iostream>
#include <vector>
#include <chrono>
#include "Usuario.hpp"
#ifndef ADMIN_HPP
#define ADMIN_HPP

class Admin : public Usuario {
public:
	Admin(std::string _login, std::string _email, std::string _telefone, std::string _endereco, std::string _cpf, std::string _senha);
	~Admin() {};
	bool banirUsuario(Usuario* usuarioBanir, int tempoDeBanimento);
	bool unbanUsuario(Usuario* usuarioDesbanir);
};
#endif