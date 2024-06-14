#include <iostream>
#include <vector>
#ifndef PRODUTO_HPP
#define PRODUTO_HPP
class Produto {
public:
	Produto(std::string nome, std::string descricao, std::vector<std::string> tipos);
	~Produto();
	std::string nome, descricao;
	std::vector<std::string> tipos;
};

#endif