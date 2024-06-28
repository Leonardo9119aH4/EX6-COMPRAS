#include <limits>
#include "Admin.hpp"

bool Admin::banirUsuario(Usuario* usuarioBanir, int _tempoDeBanimento) {
	if (_tempoDeBanimento == 0) { // se tempo de ban for permanete então tempoDeBanimento = numeric_limits
		usuarioBanir->setTempoDeBanimento(std::numeric_limits<int>::max());
		return false;
	}
	time_t tempo = std::time(nullptr) + _tempoDeBanimento * 60 * 60 * 24; //converte o _tempoDeBanimento em segundos
	usuarioBanir->setTempoDeBanimento(tempo); // tempo = até quando o usuario é banido
	return true;
}

bool Admin::unbanUsuario(Usuario* usuarioDesbanir) {
	if (tempoDeBanimento == 0) {
		return true;
	}
	usuarioDesbanir->setTempoDeBanimento(0);
	return false;
}

Admin::Admin(std::string _login, std::string _email, std::string _telefone, std::string _endereco, std::string _cpf, std::string _senha) : Usuario(_login, _email, _telefone, _endereco, _cpf, _senha) {};