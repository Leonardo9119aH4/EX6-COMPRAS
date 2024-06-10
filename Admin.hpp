#include <iostream>
#include <vector>
#include <chrono>
#include "Usuario.hpp"

class Admin : public Usuario {
	bool banirUsuario(Usuario* usuarioBanir, std::chrono::system_clock* tempoDeBanimento);
	bool desbanirUsuario(Usuario* usuarioDesbanir);
	bool excluirAnuncio(Anuncio* anuncioDeletar);
};