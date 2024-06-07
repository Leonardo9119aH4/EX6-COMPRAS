#include <iostream>
#include <vector>
#include "Produto.hpp"
#ifndef ANUNCIO_HPP
#define ANUNCIO_HPP
class Anuncio {
public:
	Anuncio() {};
	~Anuncio() {};
	bool operator==(Anuncio& other) {
		bool isEqual = (this->titulo == other.titulo) && (this->disponibilidade == other.disponibilidade) && (this->preco == other.preco) && (this->produto == other.produto);
		return isEqual;
	};
	std::string titulo;
	int disponibilidade;
	float preco;
	Produto produto;
};


#endif