#include <iostream>
#include <vector>
#ifndef PRODUTO_HPP
#define PRODUTO_HPP
class Produto {
public:
	Produto(std::string nome, std::string descricao, std::vector<std::string> tipos);
	~Produto();
	bool operator==(Produto _produto) {
		bool isEqual = (nome == _produto.nome) && (descricao == _produto.descricao) && (tipos == _produto.tipos);
		return isEqual;
	}
	std::string nome, descricao;
	std::vector<std::string> tipos;
};

#endif