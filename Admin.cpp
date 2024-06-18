#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include "Admin.hpp"
#ifndef ADMIN_HPP_
#define ADMIN_HPP_

bool Admin::banirUsuario(Usuario* usuarioBanir, std::time_t _tempoDeBanimento) {
	usuarioBanir->tempoDeBanimento = _tempoDeBanimento;
	return true;
}

bool Admin::unbanUsuario(Usuario* usuarioDesbanir) {
	tempoDeBanimento = 0;
	return true;
}

bool Admin::excluirAnuncio(Anuncio* anuncioDeletar) {
	anuncioDeletar->~Anuncio();
}

Admin::Admin(std::string _login, std::string _email, std::string _telefone, std::string _endereco, std::string _cpf, std::string _senha) : Usuario(_login, _email, _telefone, _endereco, _cpf, _senha) {};

#endif