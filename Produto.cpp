#include <iostream>
#include "Produto.hpp"

Produto::Produto(std::string _nome, std::string _descricao, std::vector<std::string> _tipos) {
	nome = _nome;
	descricao = _descricao;
	tipos = _tipos;
}

std::string Produto::getNome() {
	return nome;
}
std::string Produto::getDescricao() {
	return descricao;
}
std::vector<std::string> Produto::getTipos() {
	return tipos;
}