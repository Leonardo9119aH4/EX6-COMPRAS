#include <iostream>
#include <vector>
#include "Usuario.hpp"

std::vector<Anuncio> pesquisar(std::vector<std::string> tags, std::vector<Usuario> usuarios, std::vector<std::string> userTipos) {
	std::vector<Anuncio> anunciosAchados;
	for (int i = 0; i <= usuarios.size(); i++) {
		for (int y = 0; y <= usuarios.at(i).anuncios.size(); y++) {
			for (int z = 0; z <= usuarios.at(i).anuncios.at(y).produto.tipos.size(); z++) {
				for (int x = 0; x <= userTipos.size(); x++) {
					if (usuarios.at(i).anuncios.at(y).produto.tipos.at(z) == userTipos.at(x)) {
						anunciosAchados.push_back(usuarios.at(i).anuncios.at(y));
					}
				}
			}
		}
	}
	return anunciosAchados;
}