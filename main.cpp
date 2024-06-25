#include <iostream>
#include <vector>
#include <limits>
#include "Anuncio.hpp"
#include "Compra.hpp"
#include "Produto.hpp"
#include "Usuario.hpp"
#include "Admin.hpp"
#include "Operacoes.hpp"

void Cadastrar(std::vector<Usuario>* usuarios, std::vector<Admin>* admins, bool cadAdmin) {
	bool conflito=false;
	std::string login, senha, email, telefone, endereco, cpf;
	std::cout << "Digite o nome de usuario a ser criado: ";
	std::cin >> login;
	for (int i = 0; i < usuarios->size(); i++) {
		if (login == usuarios->at(i).login) {
			conflito = true;
		}
	}
	for (int i = 0; i < admins->size(); i++) {
		if (login == admins->at(i).login) {
			conflito = true;
		}
	}
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
			Admin admin(login, email, telefone, endereco, cpf, senha);
			admins->push_back(admin);
		}
		else {
			Usuario usuario(login, email, telefone, endereco, cpf, senha);
			usuarios->push_back(usuario);
		}
	}
}
void Login(std::vector<Usuario>* usuarios, std::vector<Admin>* admins, int* countId, std::vector<Anuncio*>* anuncios) {
	bool exito = false;
	std::string login, senha;
	std::cout << "Digite o seu login: ";
	std::cin >> login;
	std::cout << "Digite a sua senha: ";
	std::cin >> senha;
	for (int i = 0; i < usuarios->size(); i++) {
		if (usuarios->at(i).login == login && usuarios->at(i).getSenha() == senha) {
			if (usuarios->at(i).tempoDeBanimento == 0) {
				exito = true;
				Operacoes::OpcUsuario(usuarios, &usuarios->at(i), false, countId, anuncios);
				break;
			}
			else if (usuarios->at(i).tempoDeBanimento == std::numeric_limits<time_t>::max()) {
				std::cout << "A sua conta foi banida permanentemente. Contate um admininstrador do sistema." << std::endl;
			}
			else {
				struct tm diaTm;
				localtime_s(&diaTm, &usuarios->at(i).tempoDeBanimento);
				std::cout << "A sua conta foi banida por" << diaTm.tm_mday << " dias" << std::endl;
			}	
		}
	}
	for (int i = 0; i < admins->size(); i++) {
		if (admins->at(i).login == login && admins->at(i).getSenha() == senha) {
			exito = true;
			Operacoes::OpcUsuario(usuarios, &admins->at(i), true, countId, anuncios);
			break;
		}
	}
	if (!exito) {
		std::cout << "Nome de usuario e/ou senha incorreto(s)!" << std::endl;
	}
}
int main() {
	int Opc;
	std::vector<Usuario> usuarios;
	std::vector<Admin> admins;
	std::vector<std::string> tipos;
	std::vector<Anuncio*> anuncios;
	int countIdAds = 0;
	admins.push_back(Admin("admin", "adm", "adm", "adm", "adm", "admin"));
	Produto produto("sla", "sla", { "sla", "sla" });
	admins.at(0).criarAnuncio(produto, "sla", 5, 10, &countIdAds, {"sla", "sla"});
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