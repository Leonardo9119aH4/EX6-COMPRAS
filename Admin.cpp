#include <limits>
#include "Admin.hpp"

bool Admin::banirUsuario(Usuario* usuarioBanir, int _tempoDeBanimento) {
	if (_tempoDeBanimento == 0) {
		usuarioBanir->setTempoDeBanimento(std::numeric_limits<int>::max());
		return false;
	}
	time_t tempo = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()) + _tempoDeBanimento * 60 * 60 * 24;
	usuarioBanir->setTempoDeBanimento(tempo);
	return true;
}

bool Admin::unbanUsuario(Usuario* usuarioDesbanir) {
	if (tempoDeBanimento == 0) {
		return true;
	}
	usuarioDesbanir->setTempoDeBanimento(0);
	return false;
}

bool Admin::excluirAnuncio(Anuncio* anuncioDeletar) {
	anuncioDeletar->~Anuncio();
	return true;
}

Admin::Admin(std::string _login, std::string _email, std::string _telefone, std::string _endereco, std::string _cpf, std::string _senha) : Usuario(_login, _email, _telefone, _endereco, _cpf, _senha) {};