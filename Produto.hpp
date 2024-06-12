#include <iostream>
#include <vector>
#ifndef PRODUTO_HPP
#define PRODUTO_HPP
class Produto {
public:
	Produto();
	~Produto();
	std::string nome, descricao;
	std::vector<std::string> tipos;
};

#endif