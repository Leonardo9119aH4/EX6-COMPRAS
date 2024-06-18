#include <iostream>
#include <vector>
#ifndef PRODUTO_HPP
#define PRODUTO_HPP
class Produto {
public:
	Produto();
	Produto(std::string _nome, std::string _descricao, std::vector<std::string> _tipos);
	~Produto();
	bool operator==(Produto _produto) {
		bool isEqual = (nome == _produto.nome) && (descricao == _produto.descricao) && (tipos == _produto.tipos);
		return isEqual;
	}
	std::string nome, descricao;
	std::vector<std::string> tipos;
};

#endif