#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include "Admin.hpp"
#ifndef ADMIN_HPP_
#define ADMIN_HPP_

bool Admin::banirUsuario(Usuario* usuarioBanir, std::chrono::system_clock* _tempoDeBanimento) {
	usuarioBanir->isBan = true;
	tempoDeBanimento = _tempoDeBanimento;
}

bool Admin::unbanUsuario()

#endif