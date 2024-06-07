#include <iostream>
#include <vector>
#include "Produto.hpp"
#ifndef ANUNCIO_HPP
#define ANUNCIO_HPP
class Anuncio {
public:
	std::string titulo;
	int disponibilidade;
	float preco;
	Produto produto;
};


#endif