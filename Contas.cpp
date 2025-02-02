#include <iostream>
#include <vector>
#include <limits>
#include "Contas.hpp"
#include "Operacoes.hpp"
void Cadastrar(std::vector<Usuario>* usuarios, std::vector<Admin>* admins, bool cadAdmin) { //cadastra usuario ou admin
	bool conflito = false; //verifica se o login ja existe (chave primaria)
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
	bool existe = false;
	std::string login, senha;
	std::cout << "Digite o seu login: ";
	std::cin >> login;
	std::cout << "Digite a sua senha: ";
	std::cin >> senha;
	for (int i = 0; i < usuarios->size(); i++) { 
		if (usuarios->at(i).login == login && usuarios->at(i).getSenha() == senha) {
			if (usuarios->at(i).getTempoDeBanimento() == 0) { //a funcao obtem o tempo em dias (int)
				usuarios->at(i).verificarCompras(); //verifica se alguma compra chegou
				Operacoes::OpcUsuario(usuarios, admins, &usuarios->at(i), countId, anuncios); //polimorfismo (evita cast)
			}
			else if (usuarios->at(i).getTempoDeBanimento() == std::numeric_limits<time_t>::max()) { //obtem a variavel time_t direto com valor limite
				std::cout << "A sua conta foi banida permanentemente. Contate um admininstrador do sistema." << std::endl;
			}
			else {
				std::cout << "A sua conta foi banida por " << usuarios->at(i).getTempoDeBanimento() << " dias" << std::endl;
			}
			existe = true;
		}
	}
	for (int i = 0; i < admins->size(); i++) {
		if (admins->at(i).login == login && admins->at(i).getSenha() == senha) {
			if (admins->at(i).getTempoDeBanimento() == 0) { //a funcao obtem o tempo em dias (int)
				admins->at(i).verificarCompras(); //verifica se alguma compra chegou
				Operacoes::OpcUsuario(usuarios, admins, &admins->at(i), countId, anuncios); //polimorfismo (pq odeiam tanto cast?)
			}
			else if (admins->at(i).getTempoDeBanimento() == std::numeric_limits<time_t>::max()) { //obtem a variavel time_t direto com valor limite
				std::cout << "A sua conta foi banida permanentemente. Contate um admininstrador do sistema." << std::endl;
			}
			else {
				std::cout << "A sua conta foi banida por " << admins->at(i).getTempoDeBanimento() << " dias" << std::endl;
			}
			existe = true;
		}
	}
	if (!existe) {
		std::cout << "Nome de usuario e/ou senha incorreto(s)!" << std::endl;
	}
}