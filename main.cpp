#include <iostream>
#include <vector>
#include "Anuncio.hpp"
#include "Compra.hpp"
#include "Produto.hpp"
#include "Usuario.hpp"

void Cadastrar(std::vector<Usuario>* usuarios, /* std::vector<Admin>* admins, */ bool cadAdmin) {
	bool conflito=false;
	std::string login, senha, email, telefone, endereco, cpf;
	std::cout << "Digite o nome de usuario a ser criado: ";
	std::cin >> login;
	for (int i = 0; i < usuarios->size(); i++) {
		if (login == usuarios->at(i).login) {
			conflito = true;
		}
	}
	//for (int i = 0; i < admins->size(); i++) {
	//	if (login == admins->at(i).login) {
	//		conflito = true;
	//	}
	//}
	if (conflito) {
		std::cout << "Esse nome de usuario ja existe!" << std::endl;
	}
	else {
		std::cout << "Digite a senha a ser criada: ";
		std::cin >> senha;
		std::cout << "Digite o seu email: ";
		std::cin >> email;
		std::cout << "Digite o telefone: ";
		std::cin >> telefone;
		std::cout << "Digite o endereco de residencia: ";
		std::cin >> endereco;
		std::cout << "Digite o seu CPF: ";
		std::cin >> cpf;
		if (cadAdmin) {
			//Admin admin();
			//admins->push_back(admin)
		}
		else {
			Usuario usuario();
			usuarios->push_back(usuario);
		}
	}
}

int main() {
	std::vector<Usuario> usuarios;
	//std::vector<Admin> admins;
	return 0;
}