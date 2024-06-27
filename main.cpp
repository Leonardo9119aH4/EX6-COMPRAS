#include <iostream>
#include <vector>
#include "Anuncio.hpp"
#include "Compra.hpp"
#include "Produto.hpp"
#include "Usuario.hpp"
#include "Admin.hpp"
#include "Operacoes.hpp"
#include "Contas.hpp"

int main() {
	int Opc;
	std::vector<Usuario> usuarios;
	std::vector<Admin> admins;
	std::vector<std::string> tipos;
	std::vector<Anuncio*> anuncios;
	int countIdAds = 0;
	//debug
	Admin admin("admin", "adm", "adm", "adm", "adm", "admin");
	std::vector<std::string> testeStr = { "A", "B", "C"};
	Produto produto("depurador", "descricao_generica", testeStr);
	anuncios.push_back(admin.criarAnuncio(produto, "depuracao", 3, 100, &countIdAds));
	admins.push_back(admin);
	Usuario usuario("user", "user", "user", "user", "user", "123");
	usuarios.push_back(usuario);
	//endDebug
	do {
		std::cout << "1- Login\n2- Cadastrar\n3- Sair\nDigite a opcao: ";
		std::cin >> Opc;
		switch (Opc) {
		case 1:
			Login(&usuarios, &admins, &countIdAds, &anuncios);
			break;
		case 2:
			Cadastrar(&usuarios, &admins, false);
			break;
		case 3:
			std::cout << "Saindo do programa..." << std::endl;
			break;
		default:
			std::cout << "Opcao invalida!" << std::endl;
		}
	} while (Opc != 3);
	return 0;
}