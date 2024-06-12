#include <iostream>
#include <vector>
#include <limits>
#include "Anuncio.hpp"
#include "Compra.hpp"
#include "Produto.hpp"
#include "Usuario.hpp"
#include "Admin.hpp"
void Cadastrar(), void Login();
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
				OpcUsuario(usuarios, &usuarios->at(i), false, countId, anuncios);
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
			OpcUsuario(usuarios, &admins->at(i), true, countId, anuncios);
			break;
		}
	}
	if (!exito) {
		std::cout << "Nome de usuario e/ou senha incorreto(s)!" << std::endl;
	}
}
void OpcUsuario(std::vector<Usuario>* usuarios, Usuario* usuario, bool isAdmin, int* countId, std::vector<Anuncio*>* anuncios) {
	int opc1, opc2, id, num;
	std::string str1, str2;
	std::vector<std::string> strs;
	if (isAdmin) {
		std::cout << "1- Area do comprador\n2- Area do vendedor\n3- Area do admininstrador\n4- Verificar dados cadastrais\n5- Alterar o endereco de residencia\n6- Alterar a senha\n7- Logout\nDigite a opcao: ";
	}
	else {
		std::cout << "1- Area do comprador\n2- Area do vendedor\n4- Verificar dados cadastrais\n5- Alterar o endereco de residencia\n6- Alterar a senha\n7- Logout\nDigite a opcao: ";
	}
	std::cin >> opc1;
	do {
		switch (opc1) {
		case 1:
			std::cout << "1- Buscar por categoria\n2- Favoritar um anuncio\n3- Desfavoritar um anuncio\n4- Listar favoritos\n5- Adicionar um produto ao carrinho\n6- Comprar\n7- Remover um produto do carrinho\n8- Ver compras\n9- Cancelar uma compra\n10- Devolver um produto";
			std::cin >> opc2;
			switch (opc2) {
			case 1:

				break;
			case 2:
				std::cout << "Digite o ID do anuncio a ser favoritado: ";
				std::cin >> id;
				for (int i = 0; i < anuncios->size(); i++) {
					if (anuncios->at(i)->id == id) {
						usuario->favoritar(anuncios->at(i));
					}
				}
				break;
			case 3:
				std::cout << "Digite o ID do anuncio a ser desfavoritado: ";
				std::cin >> id;
				for (int i = 0; i < anuncios->size(); i++) {
					if (anuncios->at(i)->id == id) {
						//usuario->favoritar(anuncios->at(i));
					}
				}
				break;
			case 4:

				break;
			case 5:

				break;
			case 6:
				for (int i = 0; i < 1; i++) {
					//if(usuario.getCompras())
				}
				break;
			default:
				std::cout << "Opcao invalida!" << std::endl;
				break;
			}
			break;
		case 2:
			std::cout << "1- Criar anuncio\n2- Deletar um anuncio\nDigite uma opcao: ";
			std::cin >> opc2;
			switch (opc2) {
			case 1:
				std::cout << "Digite o nome do produto: ";
				std::cin >> str1;
				std::cout << "Digite a descricao do produto (sem espacos, use '_'): ";
				std::cin >> str2;
				std::cout << "Digite quantos tipos (tagnames)";
				break;
			default:
				std::cout << "Opcao invalida!" << std::endl;
			}
			break;
		case 3:
			if (isAdmin) {
				std::cout << "1- Listar usuarios\n2- Banir um usuario\n3- Desbanir um usuario\n4- Cadastrar um admininistrador\n5- Deletar um anuncio\nDigite uma opcao: ";
				std::cin >> opc2;
				switch (opc2) {
				case 1:
					break;
				default:
					std::cout << "Opcao invalida!" << std::endl;
					break;
				}
			}
			else {
				std::cout << "Acesso negado" << std::endl;
			}
			break;
		case 4:
			std::cout << "O seu login eh " << usuario->login << "\nO seu endereco de residencia eh " << usuario->getEndereco() << "\nO seu email eh " << usuario->getEmail() << "\nO seu telefone eh " << usuario->getTelefone() << "\nO seu CPF eh" << usuario->getCpf() << std::endl;
			break;
		case 5:
			std::cout << "Digite o seu novo endereco: ";
			std::cin >> str1;
			//usuario->setEndereco(str);
			break;
		case 6:
			std::cout << "Digite a sua senha atual: ";
			std::cin >> str1;
			if (usuario->getSenha() == str1) {
				std::cout << "Digite a nova senha: ";
				std::cin >> str1;
				//usuario->setSenha(str);
			}
			else {
				std::cout << "Senha incorreta!" << std::endl;
			}
			break;
		case 7:
			std::cout << "Logout!" << std::endl;
		default:
			std::cout << "Opcao invalida!" << std::endl;
		}
	} while (opc1 != 6);
}
int main() {
	int Opc;
	std::vector<Usuario> usuarios;
	std::vector<Admin> admins;
	std::vector<std::string> tipos;
	std::vector<Anuncio*> anuncios;
	int countId = 0;
	do {
		std::cout << "1- Login\n2- Cadastrar\n3- Sair\nDigite a opcao: ";
		std::cin >> Opc;
		switch (Opc) {
		case 1:
			Login(&usuarios, &admins, &countId, &anuncios);
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