#include <iostream>
#include <vector>
#include <limits>
#include <ctime>
#include <chrono>
#include "Anuncio.hpp"
#include "Compra.hpp"
#include "Produto.hpp"
#include "Usuario.hpp"
#include "Admin.hpp"
#include "Operacoes.hpp"
#include "Contas.hpp"
void Operacoes::OpcUsuario(std::vector<Usuario>* usuarios, std::vector<Admin>* admins ,Usuario* usuario, int* countId, std::vector<Anuncio*>* anuncios) {
	int opc; //area do usuario (polimorfismo)
	std::string str;
	do {
		std::cout << "1- Area do comprador\n2- Area do vendedor\n3- Verificar dados cadastrais\n4- Alterar o endereco de residencia\n5- Alterar a senha\n6- Logout\nDigite a opcao: ";
		std::cin >> opc;
		switch (opc) {
		case 1:
			AreaComprador(usuarios, usuario, countId, anuncios);
			break;
		case 2:
			AreaVendedor(usuarios, usuario, countId, anuncios);
			break;
		case 3: //verificar dados cadastrais
			std::cout << "O seu login eh " << usuario->login << "\nO seu endereco de residencia eh " << usuario->getEndereco() << "\nO seu email eh " << usuario->getEmail() << "\nO seu telefone eh " << usuario->getTelefone() << "\nO seu CPF eh" << usuario->getCpf() << std::endl;
			break;
		case 4: //mudar endereco
			std::cout << "Digite o seu novo endereco: ";
			std::cin >> str;
			usuario->setEndereco(str); 
			break;
		case 5: //mudar senha
			std::cout << "Digite a sua senha atual: ";
			std::cin >> str;
			if (usuario->getSenha() == str) {
				std::cout << "Digite a nova senha: ";
				std::cin >> str;
				usuario->setSenha(str);
			}
			else {
				std::cout << "Senha incorreta!" << std::endl;
			}
			break;
		case 6: //logout
			std::cout << "Logout!" << std::endl;
			break;
		default: //se o usuario for burro
			std::cout << "Opcao invalida!" << std::endl;
			break;
		}
	} while (opc != 6);
}
void Operacoes::OpcUsuario(std::vector<Usuario>* usuarios, std::vector<Admin>* admins, Admin* admin, int* countId, std::vector<Anuncio*>* anuncios) {
	int opc; //area do admin (polimorfismo)
	std::string str;
	do {
		std::cout << "1- Area do comprador\n2- Area do vendedor\n3- Area do admininstrador\n4- Verificar dados cadastrais\n5- Alterar o endereco de residencia\n6- Alterar a senha\n7- Logout\nDigite a opcao: ";
		std::cin >> opc;
		switch (opc) {
		case 1:
			AreaComprador(usuarios, admin, countId, anuncios);
			break;
		case 2:
			AreaVendedor(usuarios, admin, countId, anuncios);
			break;
		case 3:
			AreaAdmin(usuarios, admins, admin, anuncios);
			break;
		case 4: //ver dados cadastrais
			std::cout << "O seu login eh " << admin->login << "\nO seu endereco de residencia eh " << admin->getEndereco() << "\nO seu email eh " << admin->getEmail() << "\nO seu telefone eh " << admin->getTelefone() << "\nO seu CPF eh" << admin->getCpf() << std::endl;
			break;
		case 5: //mudar endereco
			std::cout << "Digite o seu novo endereco: ";
			std::cin >> str;
			admin->setEndereco(str);
			break;
		case 6: //mudar senha
			std::cout << "Digite a sua senha atual: ";
			std::cin >> str;
			if (admin->getSenha() == str) {
				std::cout << "Digite a nova senha: ";
				std::cin >> str;
				admin->setSenha(str);
			}
			else {
				std::cout << "Senha incorreta!" << std::endl;
			}
			break;
		case 7: //logout
			std::cout << "Logout!" << std::endl;
			break;
		default: //se o admin dar uma de usuario
			std::cout << "Opcao invalida!" << std::endl;
			break;
		}
	} while (opc != 7);
}
void Operacoes::AreaComprador(std::vector<Usuario>* usuarios, Usuario* usuario, int* countId, std::vector<Anuncio*>* anuncios) {
	std::string str1, str2; //strings auxiliares (varias funcoes)
	int opc, id; //seletor de opcoes
	bool boolAux; //booleano auxiliar
	std::cout << "1- Buscar por categoria\n2- Visualizar anuncio\n3- Favoritar um anuncio\n4- Desfavoritar um anuncio\n5- Listar favoritos\n6- Adicionar um produto ao carrinho\n7- Ver carrinho\n8- Comprar\n9- Remover um produto do carrinho\n10- Ver compras\n11- Cancelar uma compra\n12- Devolver um produto\nDigite uma opcao: ";
	std::cin >> opc;
	switch (opc) {
	case 1: //pesquisar
		pesquisar(anuncios);
		break;
	case 2: //ver anuncio
		ViewAnuncio(anuncios);
		break;
	case 3: //favoritar ad
		std::cout << "Digite o ID do anuncio a ser favoritado: ";
		std::cin >> id;
		boolAux = false; //anuncio existe?
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
	case 4: //desfavoritar ad
		boolAux = false; //existe?
		std::cout << "Digite o ID do anuncio a ser desfavoritado: ";
		std::cin >> id;
		for (int i = 0; i < usuario->getFavoritos().size(); i++) {
			if (usuario->getFavoritos().at(i)->id == id) {
				usuario->desfavoritar(i);
				boolAux = true;
				break;
			}
		}
		if (!boolAux) {
			std::cout << "Esse anuncio nao existe ou nao consta nos seus favoritos" << std::endl;
		}
		break;
	case 5: //listar favoritos
		for (int i = 0; i < usuario->getFavoritos().size(); i++) {
			std::cout << "Titulo do anuncio: " << usuario->getFavoritos().at(i)->titulo << ", comprando o produto: " << usuario->getFavoritos().at(i)->produto.nome << ", ID de anuncio: " << usuario->getFavoritos().at(i)->id << std::endl;
		}
		break;
	case 6: //add ao carrinho
		std::cout << "Digite o ID do anuncio a ser adicionado no carrinho: ";
		std::cin >> id;
		boolAux = false; //existe?
		for (int i = 0; i < anuncios->size(); i++) {
			if (anuncios->at(i)->id == id) {
				std::cout << "Digite o endereco de entrega: ";
				std::cin >> str1;
				usuario->adicionarAoCarrinho(anuncios->at(i), str1);
				boolAux = true;
				break;
			}
		}
		if (boolAux) {
			std::cout << "Anuncio adicionado ao carrinho com exito" << std::endl;
		}
		else {
			std::cout << "Anuncio nao encontrado" << std::endl;
		}
		break;
	case 7: //ver carrinho
		VerCarrinho(usuario);
		break;
	case 8: //comprar tudo do carrinho
		ComprarTudo(usuario);
		break;
	case 9: //remover do carrinho
		std::cout << "Digite o ID da compra a ser removida: ";
		std::cin >> id;
		for (int i = 0; i < usuario->getCompras()->size(); i++) {
			if (usuario->getCompras()->at(i).getId() == id) {
				boolAux = usuario->removerDoCarrinho(&usuario->getCompras()->at(i));
				if (boolAux) {
					std::cout << "Compra removida com exito" << std::endl;
				}
				else {
					std::cout << "Voce nao pode remover uma compra ja efetuada/entregue" << std::endl;
				}
				break; //aqui
			}
		}
		std::cout << "ID de compra nao encontrada!" << std::endl; //early break
		break;
	case 10: //ver compras
		ViewCompras(usuario);
		break;
	case 11: //cancelar uma compra
		std::cout << "Digite o ID da compra a ser cancelada: ";
		std::cin >> id;
		for (int i = 0; i < usuario->getCompras()->size(); i++) { 
			if (usuario->getCompras()->at(i).getId() == id) { //early break
				boolAux = usuario->cancelarCompra(&usuario->getCompras()->at(i));
				if (boolAux) {
					std::cout << "Compra cancelada com exito" << std::endl;
				}
				else {
					std::cout << "Compra ja entregue ou nao efetuada" << std::endl;
				}
				break; //aqui
			}
		}
		break;
	case 12: //devolver um produto
		std::cout << "Digite o ID da compra a ser devolvida: ";
		std::cin >> id;
		boolAux = usuario->devolverCompra(id); //exito ao devolver?
		if (!boolAux) {
			std::cout << "Compra nao encontrada ou fora do status 'recebida'." << std::endl;
		}
		break;
	default:
		std::cout << "Opcao invalida!" << std::endl;
		break;
	}
}
void Operacoes::AreaVendedor(std::vector<Usuario>* usuarios, Usuario* usuario, int* countId, std::vector<Anuncio*>* anuncios) {
	bool existe;
	int opc, id;
	std::cout << "1- Criar anuncio\n2- Deletar um anuncio\n3- Listar anuncios\nDigite uma opcao: ";
	std::cin >> opc;
	switch (opc) {
	case 1: //criar ad
		NovoAnuncio(usuario, countId, anuncios);
		break;
	case 2: //deletar ad
		std::cout << "Digite o ID do anuncio a ser deletado: ";
		std::cin >> id;
		existe = usuario->deletarAnuncio(id);
		if (existe) {
			for (int i = 0; i < anuncios->size(); i++) {
				if (anuncios->at(i)->id == id) {
					anuncios->erase(anuncios->begin() + i);
				}
			}
		}
		else {
			std::cout << "Nao existe anuncio no seu usuario com ID especificado." << std::endl;
		}
		
		break;
	case 3: //listar ad
		for (int i = 0; i < usuario->getAnuncios()->size(); i++) {
			std::cout << "Anuncio " << usuario->getAnuncios()->at(i).titulo << ", sob ID " << usuario->getAnuncios()->at(i).id << ", com o produto " << usuario->getAnuncios()->at(i).produto.nome << std::endl;
		}
		break;
	default:
		std::cout << "Opcao invalida!" << std::endl;
		break;
	}
}
void Operacoes::AreaAdmin(std::vector<Usuario>* usuarios, std::vector<Admin>* admins, Admin* admin, std::vector<Anuncio*>* anuncios) {
	bool existe, estavaBanido;
	int opc, ban, id;
	std::string str; //string auxiliar
	std::cout << "1- Listar usuarios\n2- Banir um usuario\n3- Desbanir um usuario\n4- Cadastrar um admininistrador\n5- Deletar um anuncio\nDigite uma opcao: ";
	std::cin >> opc;
	switch (opc) {
	case 1: //listar usuarios
		listarUsuarios(usuarios, admins);
		break;
	case 2: //banir usuario
		existe = false;
		std::cout << "Digite o nome de usuario a ser banido: ";
		std::cin >> str;
		std::cout << "Digite o tempo em dias de banimento (0 para banimento permanente): ";
		std::cin >> ban;
		for (int i = 0; i < usuarios->size(); i++) {
			if (usuarios->at(i).login == str) {
				admin->banirUsuario(&usuarios->at(i), ban);
				existe = true;
			}
		}
		for (int i = 0; i < admins->size(); i++) {
			if (admins->at(i).login == str) {
				admin->banirUsuario(&admins->at(i), ban);
				existe = true;
			}
		}
		if (!existe) {
			std::cout << "Nome de usuario nao encontrado" << std::endl;
		}
		break;
	case 3: //desbanir usuario
		std::cout << "Digite o nome de usuario a ser desbanido: ";
		std::cin >> str;
		for (int i = 0; i < usuarios->size(); i++) {
			if (usuarios->at(i).login == str) {
				estavaBanido = admin->unbanUsuario(&usuarios->at(i));
				existe = true; //verifica existencia do usuario
			}
		}
		for (int i = 0; i < admins->size(); i++) {
			if (admins->at(i).login == str) {
				estavaBanido = admin->unbanUsuario(&admins->at(i));
				existe = true; //verifica existencia do usuario
			}
		}
		if (!existe) {
			std::cout << "Nome de usuario nao encontrado" << std::endl;
		}
		if (!estavaBanido) {
			std::cout << "O usuario nao estava banido" << std::endl;
		}
		break;
	case 4: //cadastrar admin
		Cadastrar(usuarios, admins, true);
		break;
	case 5: //deletar anuncio de outro usuario
		deletarAds(usuarios, admins, anuncios);
		break;
	default:
		std::cout << "Opcao invalida!" << std::endl;
		break;
	}
}

void Operacoes::NovoAnuncio(Usuario* usuario, int* countId, std::vector<Anuncio*>* anuncios) {
	int quantTipos;
	float preco;
	std::string nome, descricao, tipo, resp;
	std::vector<std::string> tipos;
	std::cout << "Digite o nome do produto: ";
	std::cin >> nome;
	std::cout << "Digite a descricao do produto (sem espacos, use '_'): ";
	std::cin >> descricao;
	do {
		std::cout << "Digite quantos tipos (tagnames) o seu produto vai ter: ";
		std::cin >> quantTipos;
		if (quantTipos <= 0) {
			std::cout << "Opcao invalida!" << std::endl;
			resp = "n";
		}
		else {
			for (int i = 0; i < quantTipos; i++) {
				std::cout << "Digite um tipo: ";
				std::cin >> tipo;
				tipos.push_back(tipo);
			}
			std::cout << "Tipos: " << std::endl;
			for (int i = 0; i < tipos.size(); i++) {
				if (tipos.at(i) == tipos.back()) {
					std::cout << tipos.at(i) << std::endl;
				}
				else {
					std::cout << tipos.at(i) << " ,";
				}
			}
			do {
				std::cout << "Os tipos estao certos e digitados corretamente? (s/n): ";
				std::cin >> resp;
				if (resp != "n" && resp != "s") {
					std::cout << "Opcao invalida!" << std::endl;
				}
			} while (resp != "n" && resp != "s");
		}
	} while (resp == "n");
	Produto produto(nome, descricao, tipos);
	std::cout << "Digite o titulo do anuncio: ";
	std::cin >> nome;
	do {
		std::cout << "Digite quantos produtos voce tem disponivel: ";
		std::cin >> quantTipos;
		if (quantTipos < 0) {
			std::cout << "Valor invalido!" << std::endl;
		}
	} while (quantTipos < 0);
	do {
		std::cout << "Digite o preco do produto (0 para gratuito): ";
		std::cin >> preco;
		if (preco < 0) {
			std::cout << "Valor invalido!" << std::endl;
		}
	} while (preco < 0);
	Anuncio* anuncio = usuario->criarAnuncio(produto, nome, quantTipos, preco, countId); 
	anuncios->push_back(anuncio); //salva o ponteiro do anuncio no vetor global de ponteiros
	std::cout << "Anuncio craido com exito!" << std::endl;
}
void Operacoes::ViewAnuncio(std::vector<Anuncio*>* anuncios) {
	int id;
	bool existe = false;
	std::cout << "Digite o ID do anuncio a ser exibido: ";
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
void Operacoes::VerCarrinho(Usuario* usuario) {
	std::vector<Compra>* compras = usuario->getCompras();
	bool existe;
	for (int i = 0; i < compras->size(); i++) {
		if (compras->at(i).getStatus() == 1) {
			std::cout << "Compra do produto: " << compras->at(i).getAnuncio()->produto.nome << ", ID de anuncio: " << compras->at(i).getAnuncio()->id << ", ID da compra: " << compras->at(i).getId() << std::endl;
		}
	}
}
void Operacoes::ComprarTudo(Usuario* usuario) {
	std::vector<Compra>* compras = usuario->getCompras();
	std::string resposta;
	float valorCount = 0;
	int opc, parcelas;
	do {
		std::cout << "ATENCAO! Todos os itens no carrinho serao comprados. Certo? (s/n): ";
		std::cin >> resposta;
		if (resposta == "n") {
			return;
		}
		if (resposta != "n" && resposta != "s") {
			std::cout << "Opcao invalida" << std::endl;
		}
	} while (resposta != "s" && resposta != "n");
	do {
		std::cout << "1- Boleto a vista\n2- Pix a vista\n3- Credito a vista\n4- Debito a vista\n5- Credito a prazo\n6- Debito a prazo\nQual forma de pagamento? ";
		std::cin >> opc;
		if (opc != 1 && opc != 2 && opc != 3 && opc != 4 && opc != 5 && opc != 6) {
			std::cout << "Opcao invalida!" << std::endl;
		}
	} while (opc != 1 && opc != 2 && opc != 3 && opc != 4 && opc != 5 && opc != 6);
	if (opc == 5 || opc == 6) {
		do {
			std::cout << "Digite em quantas vezes voce quer parcelar: ";
			std::cin >> parcelas;
			if (parcelas == 1) {
				std::cout << "Voce eh burro? Por que vai parcelar em uma vez em vez de pagar a vista?" << std::endl;
			}
			if (parcelas <= 0) {
				std::cout << "Valor invalido!" << std::endl;
			}
		} while (parcelas < 2);
		for (int i = 0; i < compras->size(); i++) {
			valorCount += compras->at(i).Parcelar(parcelas);
		}
		do {
			std::cout << "Cada parcelar custara R$" << valorCount << ", prossegue? (s/n): ";
			std::cin >> resposta;
			if (resposta == "n") {
				return;
			}
			if (resposta != "n" && resposta != "s") {
				std::cout << "Opcao invalida" << std::endl;
			}
		} while (resposta != "s" && resposta != "n");
		usuario->comprar(opc, parcelas);
		std::cout << "Compra realizada com exito" << std::endl;
	}
	else {
		for (int i = 0; i < compras->size(); i++) {
			valorCount += compras->at(i).getValor();
		}
		do {
			std::cout << "Voce pagara " << valorCount << ", prossegue? (s/n): ";
			std::cin >> resposta;
			if (resposta == "n") {
				return;
			}
			if (resposta != "n" && resposta != "s") {
				std::cout << "Opcao invalida" << std::endl;
			}
		} while (resposta != "s" && resposta != "n");
		usuario->comprar(opc, -1); //o pagamento eh a vista
		std::cout << "Compra realizada com exito" << std::endl;
	}
}
void Operacoes::pesquisar(std::vector<Anuncio*>* anuncios) {
	char opc; //resposta (s/n)
	int QtTags = 1;
	std::cout << "Voce deseja pesquisar por mais de uma tag? (s/n): ";
	std::cin >> opc;
	if (opc == 's' || opc == 'S') {
		std::cout << "Digite a quantidade de tags que voce deseja pesquisar: ";
		std::cin >> QtTags;
	}
	std::string tag;
	std::vector<std::string> userTipos;
	int auxQt = 0;
	while (QtTags > auxQt) {
		std::cout << "Digite uma tag: ";
		std::cin >> tag;
		userTipos.push_back(tag);
		auxQt++;
	}
	for (int y = 0; y < anuncios->size(); y++) {
		for (int i = 0; i < userTipos.size(); i++) {
			auto c = std::find(anuncios->at(y)->produto.tipos.begin(), anuncios->at(y)->produto.tipos.end(), userTipos.at(i));
			if (!(c > anuncios->at(y)->produto.tipos.end())) {
				std::cout << "Titulo: " << anuncios->at(y)->titulo << std::endl << "Preco: R$" << anuncios->at(y)->preco << std::endl << "Disponibilidade: " << anuncios->at(y)->disponibilidade << std::endl << "ID: " << anuncios->at(y)->id << std::endl << "Nome do produto: " << anuncios->at(y)->produto.nome << std::endl << "Descricao do produto" << anuncios->at(y)->produto.descricao << std::endl << "Tags: ";
				for (int w = 0; w < anuncios->at(y)->produto.tipos.size(); w++) {
					std::cout << anuncios->at(y)->produto.tipos.at(w) << std::endl;
				}
			}
		}
	}
}
void Operacoes::ViewCompras(Usuario* usuario) {
	usuario->verificarCompras();
	std::vector<Compra>* compras = usuario->getCompras();
	struct tm dataCompra; //structs pro localtime_s
	struct tm dataEntrega;
	struct tm dataDev;
	time_t dtaCompr;
	time_t dtaEntr;
	time_t dtaDev; //Visual Studio eh retardado e eu tive que fazer isso
	for (int i = 0; i < compras->size(); i++) {
		switch (compras->at(i).getStatus()) {
			case 2:
				dtaCompr = compras->at(i).getDataCompra();
				dtaEntr = compras->at(i).getDataEntrega();
				localtime_s(&dataCompra, &dtaCompr);
				localtime_s(&dataEntrega, &dtaEntr);
				std::cout << "Compra ID " << compras->at(i).getId() << ", realizada no dia " << dataCompra.tm_mday << "/" << dataCompra.tm_mon + 1 << ", com data de entrega prevista " << dataEntrega.tm_mday << "/" << dataEntrega.tm_mon + 1 << "\nProduto: " << compras->at(i).getAnuncio()->produto.nome << ", do anuncio " << compras->at(i).getAnuncio()->titulo << ", com ID " << compras->at(i).getAnuncio()->id << std::endl;
				break;
			case 3:
				dtaCompr = compras->at(i).getDataCompra();
				dtaEntr = compras->at(i).getDataEntrega();
				localtime_s(&dataCompra, &dtaCompr);
				localtime_s(&dataEntrega, &dtaEntr);
				std::cout << "Compra ID " << compras->at(i).getId() << ", realizada no dia " << dataCompra.tm_mday << "/" << dataCompra.tm_mon + 1 << ", entregue em " << dataEntrega.tm_mday << "/" << dataEntrega.tm_mon + 1 << "\nProduto: " << compras->at(i).getAnuncio()->produto.nome << ", do anuncio " << compras->at(i).getAnuncio()->titulo << ", com ID " << compras->at(i).getAnuncio()->id << std::endl;
				break;
			case 4:
				std::cout << "Compra ID " << compras->at(i).getId() << ", cancelada" << std::endl;
				break;
			case 5:
				dtaCompr = compras->at(i).getDataCompra();
				dtaEntr = compras->at(i).getDataEntrega();
				localtime_s(&dataCompra, &dtaCompr);
				localtime_s(&dataEntrega, &dtaEntr);
				std::cout << "Compra ID " << compras->at(i).getId() << ", realizada no dia " << dataCompra.tm_mday << "/" << dataCompra.tm_mon + 1 << ", entregue em " << dataEntrega.tm_mday << "/" << dataEntrega.tm_mon + 1 << ", est� aguardando devolucao\nProduto: " << compras->at(i).getAnuncio()->produto.nome << ", do anuncio " << compras->at(i).getAnuncio()->titulo << ", com ID " << compras->at(i).getAnuncio()->id << std::endl;
				break;
			case 6:
				dtaCompr = compras->at(i).getDataCompra();
				dtaEntr = compras->at(i).getDataEntrega();
				dtaDev = compras->at(i).getDataDevolucao();
				localtime_s(&dataCompra, &dtaCompr);
				localtime_s(&dataEntrega, &dtaEntr);
				localtime_s(&dataDev, &dtaDev);
				std::cout << "Compra ID " << compras->at(i).getId() << ", realizada no dia " << dataCompra.tm_mday << "/" << dataCompra.tm_mon + 1 << "entregue em " << dataEntrega.tm_mday << "/" << dataEntrega.tm_mon + 1 << ", devolvida em " << dataDev.tm_mday << "/" << dataDev.tm_mon + 1 << "\nProduto: " << compras->at(i).getAnuncio()->produto.nome << ", do anuncio " << compras->at(i).getAnuncio()->titulo << ", com ID " << compras->at(i).getAnuncio()->id << std::endl;
				break;
		}
	}
}
void Operacoes::listarUsuarios(std::vector<Usuario>* usuarios, std::vector<Admin>* admins) {
	std::cout << "Usuarios comuns: " << std::endl;
	for (int i = 0; i < usuarios->size(); i++) {
		if (usuarios->at(i).getTempoDeBanimento() == std::numeric_limits<time_t>::max()) { //limits::max eh ban permanente
			std::cout << "Usuario: " << usuarios->at(i).login << ", sob CPF " << usuarios->at(i).getCpf() << ", com email " << usuarios->at(i).getEmail() << ", com telefone " << usuarios->at(i).getTelefone() << ", esta banido permanentemente" << std::endl;
		}
		else if (usuarios->at(i).getTempoDeBanimento() == 0) {
			std::cout << "Usuario: " << usuarios->at(i).login << ", sob CPF " << usuarios->at(i).getCpf() << ", com email " << usuarios->at(i).getEmail() << ", com telefone " << usuarios->at(i).getTelefone() << ", nao esta banido" << std::endl;
		}
		else {
			std::cout << "Usuario: " << usuarios->at(i).login << ", sob CPF " << usuarios->at(i).getCpf() << ", com email " << usuarios->at(i).getEmail() << ", com telefone " << usuarios->at(i).getTelefone() << ", esta banido por " << usuarios->at(i).getTempoDeBanimento() << " dias" << std::endl;
		}
	}
	std::cout << "Admins: " << std::endl;
	for (int i = 0; i < admins->size(); i++) {
		if (admins->at(i).getTempoDeBanimento() == std::numeric_limits<time_t>::max()) {
			std::cout << "Admin: " << admins->at(i).login << ", sob CPF " << admins->at(i).getCpf() << ", com email " << admins->at(i).getEmail() << ", com telefone " << admins->at(i).getTelefone() << ", esta banido permanentemente" << std::endl;
		}
		else if (admins->at(i).getTempoDeBanimento() == 0) {
			std::cout << "Admin: " << admins->at(i).login << ", sob CPF " << admins->at(i).getCpf() << ", com email " << admins->at(i).getEmail() << ", com telefone " << admins->at(i).getTelefone() << ", nao esta banido" << std::endl;
		}
		else {
			std::cout << "Admin: " << admins->at(i).login << ", sob CPF " << admins->at(i).getCpf() << ", com email " << admins->at(i).getEmail() << ", com telefone " << admins->at(i).getTelefone() << ", esta banido por " << admins->at(i).getTempoDeBanimento() << " dias" << std::endl;
		}
	}
}
void Operacoes::deletarAds(std::vector<Usuario>* usuarios, std::vector<Admin>* admins, std::vector<Anuncio*>* anuncios) { //deletar ad de outro usuario
	int id;
	std::cout << "Digite o ID do anuncio a ser deletado: ";
	std::cin >> id;
	for (int x = 0; x < usuarios->size(); x++) {
		for (int y = 0; y < usuarios->at(x).getAnuncios()->size(); y++) {
			if (usuarios->at(x).getAnuncios()->at(y).id == id) {
				usuarios->at(x).deletarAnuncio(id);
				for (int z = 0; z < anuncios->size(); z++) {
					if (anuncios->at(z)->id == id) {
						anuncios->erase(anuncios->begin() + z);
						std::cout << "Anuncio deletado com exito" << std::endl;
						return;
					}
				}
			}
		}
	}
	for (int x = 0; x < admins->size(); x++) {
		for (int y = 0; y < admins->at(x).getAnuncios()->size(); y++) {
			if (admins->at(x).getAnuncios()->at(y).id == id) {
				admins->at(x).deletarAnuncio(id);
				for (int z = 0; z < admins->size(); z++) {
					if (anuncios->at(z)->id == id) {
						anuncios->erase(anuncios->begin() + z);
						std::cout << "Anuncio deletado com exito" << std::endl;
						return;
					}
				}
			}
		}
	}
	std::cout << "Anuncio nao encontrado." << std::endl; //early return (eh util as vezes)
}