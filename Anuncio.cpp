#include "Anuncio.hpp"

Anuncio::Anuncio(std::string _titulo, int _disponibilidade, float _preco, int* _id, Produto _produto, Usuario* _dono) {
	titulo = _titulo;
	disponibilidade = _disponibilidade;
	preco = _preco;
	id = *_id;
	produto = _produto;
	dono = _dono;
	*_id += 1;
}