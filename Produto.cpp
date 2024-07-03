#include <iostream>
#include "Produto.hpp"
//construtor do produto
Produto::Produto(std::string _nome, std::string _descricao, std::vector<std::string> _tipos) {
	nome = _nome;
	descricao = _descricao;
	tipos = _tipos;
}