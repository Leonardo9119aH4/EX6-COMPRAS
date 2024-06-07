#include <iostream>
#include <vector>
#include "Anuncio.hpp"
#ifndef COMPRA_HPP
#define COMPRA_HPP
class Compra {
	std::vector<Anuncio> anuncios;
	std::string endereco_entrega, status;
	float valor;
};
#endif // !COMPRA_HPP
