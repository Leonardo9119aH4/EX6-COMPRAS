#include <iostream>
#include <vector>
#include <algorithm>
#include "Pesquisa.hpp"
#include "Usuario.hpp"

void pesquisar(std::vector<std::string> tags, std::vector<Anuncio*> *anuncios, std::vector<std::string> userTipos) {
	char opc;
	std::cout << "Voce deseja pesquisar por mais de uma tag? ";
	std::cin >> opc;
	if (opc == 's' || opc == 'S') {
		//PAREI AQUI
	}
	while (true) {
		std::cout << "Digite as tags que voce deseja poesquisar: "
	}
	std::vector<Anuncio> anunciosAchados;
	for (int y = 0; y <= anuncios->size(); y++) {
		for (int i = 0; i <= userTipos.size(); i++) {
			auto c = std::find(anuncios->at(y)->produto.tipos.begin(), anuncios->at(y)->produto.tipos.end(), userTipos.at(i));
			if (c > anuncios->at(y)->produto.tipos.end()) {
				std::cout << anuncios->at(y);
			}
		}
	}
}