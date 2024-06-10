#include <iostream>
#include <vector>
#include <chrono>
#include "Usuario.hpp"

class Admin : public Usuario {
	bool banirUsuario(Usuario* usuarioBanir, std::time_t* tempoDeBanimento);
	bool unbanUsuario(Usuario* usuarioDesbanir);
	bool excluirAnuncio(Anuncio* anuncioDeletar);
};