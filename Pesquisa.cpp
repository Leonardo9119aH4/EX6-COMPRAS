#include <iostream>
#include <vector>
#include <algorithm>
#include "Pesquisa.hpp"
#include "Usuario.hpp"

void pesquisar(std::vector<Anuncio*> *anuncios) {
	char opc;
	bool opcbool = false;
	std::cout << "Voce deseja pesquisar por mais de uma tag? ";
	std::cin >> opc;
	if (opc == 's' || opc == 'S') {
		opcbool = true;
	}
	std::string tag;
	std::vector<std::string> userTipos;
	while (opcbool) {
		std::cout << "Digite as tags que voce deseja poesquisar (uma por ves): ";
		std::cin >> tag;
		userTipos.push_back(tag);
	}
	for (int y = 0; y <= anuncios->size(); y++) {
		for (int i = 0; i <= userTipos.size(); i++) {
			auto c = std::find(anuncios->at(y)->produto.tipos.begin(), anuncios->at(y)->produto.tipos.end(), userTipos.at(i));
			if (!(c > anuncios->at(y)->produto.tipos.end())) {
				std::cout << anuncios->at(y);
			}
		}
	}
}