#include <iostream>
#include <vector>
#include "Produto.hpp"
#ifndef ANUNCIO_HPP
#define ANUNCIO_HPP
class Anuncio {
public:
	Anuncio(std::string _titulo, int _disponibilidade, float _preco, int* _id, Produto _produto);
	~Anuncio() {};
	bool operator==(Anuncio other) {
		bool isEqual = (this->titulo == other.titulo) && (this->disponibilidade == other.disponibilidade) && (this->preco == other.preco) && produto.operator==(other.produto);
		return isEqual;
	};
	std::string titulo;
	int disponibilidade;
	float preco;
	int id;
	Produto produto;
};

#endif