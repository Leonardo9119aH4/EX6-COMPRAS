#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include "Admin.hpp"
#ifndef ADMIN_HPP_
#define ADMIN_HPP_

bool Admin::banirUsuario(Usuario* usuarioBanir, std::time_t* _tempoDeBanimento) {
	tempoDeBanimento = _tempoDeBanimento;
	return true;
}

bool Admin::unbanUsuario(Usuario* usuarioDesbanir) {
	tempoDeBanimento = 0;
	return true;
}

#endif