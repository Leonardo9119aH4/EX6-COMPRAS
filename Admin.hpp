#include <iostream>
#include <vector>
#include <chrono>
#include "Usuario.hpp"

class Admin : private Usuario {
	Admin(std::string& _login, std::string& _email, std::string& _telefone, std::string& _endereco, std::string& _cpf, std::string& _senha);
	~Admin() {};
	bool banirUsuario(Usuario* usuarioBanir, std::time_t tempoDeBanimento);
	bool unbanUsuario(Usuario* usuarioDesbanir);
	bool excluirAnuncio(Anuncio* anuncioDeletar);
};