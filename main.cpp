#include <iostream>
#include <vector>
#include <limits>
#include "Anuncio.hpp"
#include "Compra.hpp"
#include "Produto.hpp"
#include "Usuario.hpp"
#include "Admin.hpp"
#include "Pesquisa.hpp"
void Cadastrar(std::vector<Usuario>* usuarios, std::vector<Admin>* admins, bool cadAdmin); 
void Login(std::vector<Usuario>* usuarios, std::vector<Admin>* admins, int* countId, std::vector<Anuncio*>* anuncios); 
void OpcUsuario(std::vector<Usuario>* usuarios, Usuario* usuario, bool isAdmin, int* countId, std::vector<Anuncio*>* anuncios);
void NovoAnuncio(Usuario* usuario, int* countId, std::vector<Anuncio*>* anuncios);
void ViewAnuncio(std::vector<Anuncio*>* anuncios);

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
	int opc1, opc2, id;
	std::string str1, str2;
	bool boolAux;
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
			std::cout << "1- Buscar por categoria\n2- Visualizar anuncio\n3- Favoritar um anuncio\n4- Desfavoritar um anuncio\n5- Listar favoritos\n6- Adicionar um produto ao carrinho\n7- Ver carrinho\n8- Comprar\n9- Remover um produto do carrinho\n10- Ver compras\n11- Cancelar uma compra\n12- Devolver um produto";
			std::cin >> opc2;
			switch (opc2) {
			case 1:

				break;
			case 2:
				ViewAnuncio(anuncios);
				break;
			case 3:
				std::cout << "Digite o ID do anuncio a ser favoritado: ";
				std::cin >> id;
				boolAux = false;
				for (int i = 0; i < anuncios->size(); i++) {
					if (anuncios->at(i)->id == id) {
						usuario->favoritar(anuncios->at(i));
						boolAux = true;
						break;
					}
				}
				if (boolAux) {
					std::cout << "Anuncio favoritado com exito" << std::endl;
				}
				else {
					std::cout << "Anuncio nao encontrado" << std::endl;
				}
				break;
			case 4:
				std::cout << "Digite o ID do anuncio a ser desfavoritado: ";
				std::cin >> id;
				boolAux = false;
				for (int i = 0; i < anuncios->size(); i++) {
					if (anuncios->at(i)->id == id) {
						//usuario->desfavoritar(anuncios->at(i));
						boolAux = true;
						break;
					}
				}
				if (boolAux) {
					std::cout << "Anuncio desfavoritado com exito" << std::endl;
				}
				else {
					std::cout << "Anuncio nao encontrado" << std::endl;
				}
				break;
			case 5:
				//for(int i=0; i<usuario->getFavoritos().size(); i++)
				break;
			case 6:
				std::cout << "Digite o ID do anuncio a ser adicionado no carrinho: ";
				std::cin >> id;
				boolAux = false;
				for (int i = 0; i < anuncios->size(); i++) {
					if (anuncios->at(i)->id == id) {
						std::cout << "Digite o endereco de entrega: ";
						std::cin >> str1;
						//usuario->adicionarAoCarrinho()
						boolAux = true;
						break;
					}
				}
				if (boolAux) {
					std::cout << "Anuncio adicionado ao carrinho com exito" << std::endl;
				}
				else {
					std::cout << "Anuncio nao entregado" << std::endl;
				}
				break;
			case 7:
				VerCarrinho(usuario);
				break;
			case 8:
				break;
			case 9:
				break;
			default:
				std::cout << "Opcao invalida!" << std::endl;
				break;
			}
			break;
		case 2:
			std::cout << "1- Criar anuncio\n2- Deletar um anuncio\n3- Listar anuncios\nDigite uma opcao: ";
			std::cin >> opc2;
			switch (opc2) {
			case 1:
				NovoAnuncio(usuario, countId, anuncios);
				break;
			case 2:
				std::cout << "Digite o ID do anuncio a ser deletado: ";
				std::cin >> id;
				//usuario->deletarAnuncio(countId);
				for (int i = 0; i < anuncios->size(); i++) {
					if (anuncios->at(i)->id == id) {
						anuncios->erase(anuncios->begin()+i);
					}
				}
				break;
			case 3:
				std::vector<Anuncio>* usuarioAnuncios;
				//usuarioAnuncios = usuario->getAnuncios();
				for (int i = 0; i < usuarioAnuncios->size(); i++) {
					std::cout << "Anuncio " << usuarioAnuncios->at(i).titulo << ", sob ID" << usuarioAnuncios->at(i).id;
				}
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
void NovoAnuncio(Usuario* usuario, int* countId, std::vector<Anuncio*>* anuncios) {
	int num;
	float preco;
	std::string str1, str2, str3, str4;
	std::vector<std::string> strs;
	Anuncio* anuncio;
	std::cout << "Digite o nome do produto: ";
	std::cin >> str1;
	std::cout << "Digite a descricao do produto (sem espacos, use '_'): ";
	std::cin >> str2;
	do {
		std::cout << "Digite quantos tipos (tagnames) o seu produto vai ter: ";
		std::cin >> num;
		if (num <= 0) {
			std::cout << "Opcao invalida!" << std::endl;
			str4 = "n";
		}
		else {
			for (int i = 0; i < num; i++) {
				std::cout << "Digite um tipo: ";
				std::cin >> str3;
				strs.push_back(str3);
			}
			std::cout << "Tipos: " << std::endl;
			for (int i = 0; i < strs.size(); i++) {
				if (strs.at(i) == strs.back()) {
					std::cout << strs.at(i) << std::endl;
				}
				else {
					std::cout << strs.at(i) << " ,";
				}
			}
			do {
				std::cout << "Os tipos estao certos e digitados corretamente? (s/n): ";
				std::cin >> str4;
				if (str4 != "n" && str4 != "s") {
					std::cout << "Opcao invalida!" << std::endl;
				}
			} while (str4 != "n" && str4 != "s");
		}
	} while (str4 == "n");
	Produto produto;
	std::cout << "Digite o titulo do anuncio: ";
	std::cin >> str1;
	do {
		std::cout << "Digite quantos produtos voce tem disponivel: ";
		std::cin >> num;
		if (num < 0) {
			std::cout << "Valor invalido!" << std::endl;
		}
	} while (num < 0);
	do {
		std::cout << "Digite o preco do produto (0 para gratuito): ";
		std::cin >> preco;
		if (preco < 0) {
			std::cout << "Valor invalido!" << std::endl;
		}
	} while (preco < 0);
	//anuncio = usuario->criarAnuncio(produto, str1, num, preco, countId);
	anuncios->push_back(anuncio); //salva o ponteiro do anuncio dentro de usuario
	std::cout << "Anuncio craido com exito!" << std::endl;
}
void ViewAnuncio(std::vector<Anuncio*>* anuncios) {
	int id;
	bool existe = false;
	std::cout << "Digite o anuncio a ser exibido: ";
	std::cin >> id;
	for (int i = 0; i < anuncios->size(); i++) {
		if (anuncios->at(i)->id == id) {
			existe = true;
			Produto* produto = &anuncios->at(i)->produto;
			std::cout << "Titulo: " << anuncios->at(i)->titulo << ", preco: R$" << anuncios->at(i)->preco << ", disponiveis: " << anuncios->at(i)->disponibilidade << std::endl;
			std::cout << "Produto: " << produto->nome << "\nDescricao: " << produto->descricao << "\nTags: ";
			for (i = 0; i < produto->tipos.size(); i++) {
				if (produto->tipos.at(i) == produto->tipos.back()) {
					std::cout << produto->tipos.at(i) << std::endl;
				}
				else {
					std::cout << produto->tipos.at(i) << ", ";
				}
			}
			break;
		}
	}
	if (!existe) {
		std::cout << "Anuncio nao encontrado" << std::endl;
	}
}
void VerCarrinho(Usuario* usuario) {
	std::vector<Compra>* compras = usuario->getCompras();
	bool existe;
	for (int i = 0; i < compras->size(); i++) {
		if (compras->at(i).getStatus() == 1) {
			std::cout << "Compra do produto: " << compras->at(i).getAnuncio()->produto.nome << ", ID de anuncio: " << compras->at(i).getAnuncio()->id << ", ID da compra: " << compras->at(i).getId() << std::endl;
		}
	}
}
int main() {
	int Opc;
	std::vector<Usuario> usuarios;
	std::vector<Admin> admins;
	std::vector<std::string> tipos;
	std::vector<Anuncio*> anuncios;
	int countIdAds = 0;
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