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
	int opc; //opcao inserida
	std::vector<Usuario> usuarios; //vetor de usuarios cadastrados
	std::vector<Admin> admins; //vetor de admins cadastrados
	std::vector<Anuncio*> anuncios; //vetor de referencia aos ads de todos os usuarios (facilita na busca)
	int countIdAds = 0; //contador de id para criacao de ads (evita conflitos)
	//beginDebug 
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
		std::cin >> opc;
		switch (opc) {
		case 1:
			Login(&usuarios, &admins, &countIdAds, &anuncios);
			break;
		case 2:
			Cadastrar(&usuarios, &admins, false); //booleano verifica se esta cadastrando admin ou usuario
			break;
		case 3:
			std::cout << "Saindo do programa..." << std::endl;
			break;
		default: //se o usuario for retardado
			std::cout << "Opcao invalida!" << std::endl;
		}
	} while (opc != 3);
	return 0;
}