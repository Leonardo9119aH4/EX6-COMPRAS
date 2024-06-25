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
void Operacoes::OpcUsuario(std::vector<Usuario>* usuarios, std::vector<Admin>* admins ,Usuario* usuario, bool isAdmin, int* countId, std::vector<Anuncio*>* anuncios) {
	int opc;
	std::string str;
	do {
		if (isAdmin) {
			std::cout << "1- Area do comprador\n2- Area do vendedor\n3- Area do admininstrador\n4- Verificar dados cadastrais\n5- Alterar o endereco de residencia\n6- Alterar a senha\n7- Logout\nDigite a opcao: ";
		}
		else {
			std::cout << "1- Area do comprador\n2- Area do vendedor\n4- Verificar dados cadastrais\n5- Alterar o endereco de residencia\n6- Alterar a senha\n7- Logout\nDigite a opcao: ";
		}
		std::cin >> opc;
		switch (opc) {
		case 1:
			AreaComprador(usuarios, usuario, countId, anuncios);
			break;
		case 2:
			AreaVendedor(usuarios, usuario, countId, anuncios);
			break;
		case 3:
			if (isAdmin) {
				AreaAdmin(usuarios, admins, usuario, anuncios);
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
			std::cin >> str;
			usuario->setEndereco(str);
			break;
		case 6:
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
		case 7:
			std::cout << "Logout!" << std::endl;
			break;
		default:
			std::cout << "Opcao invalida!" << std::endl;
			break;
		}
	} while (opc != 7);
}
void Operacoes::AreaComprador(std::vector<Usuario>* usuarios, Usuario* usuario, int* countId, std::vector<Anuncio*>* anuncios) {
	std::string str1, str2;
	int opc, id;
	bool boolAux;
	std::cout << "1- Buscar por categoria\n2- Visualizar anuncio\n3- Favoritar um anuncio\n4- Desfavoritar um anuncio\n5- Listar favoritos\n6- Adicionar um produto ao carrinho\n7- Ver carrinho\n8- Comprar\n9- Remover um produto do carrinho\n10- Ver compras\n11- Cancelar uma compra\n12- Devolver um produto\nDigite uma opcao: ";
	std::cin >> opc;
	switch (opc) {
	case 1:
		pesquisar(anuncios);
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
				boolAux = usuario->desfavoritar(anuncios->at(i));
				break;
			}
		}
		if (boolAux) {
			std::cout << "Anuncio desfavoritado com exito" << std::endl;
		}
		else {
			std::cout << "Anuncio inexistente ou nao favoritado" << std::endl;
		}
		break;
	case 5:
		for (int i = 0; i < usuario->getFavoritos().size(); i++) {
			std::cout << "Titulo do anuncio: " << usuario->getFavoritos().at(i)->titulo << ", comprando o produto: " << usuario->getFavoritos().at(i)->produto.nome << ", ID de anuncio: " << usuario->getFavoritos().at(i)->id << std::endl;
		}
		break;
	case 6:
		std::cout << "Digite o ID do anuncio a ser adicionado no carrinho: ";
		std::cin >> id;
		boolAux = false;
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
			std::cout << "Anuncio nao entregado" << std::endl;
		}
		break;
	case 7:
		VerCarrinho(usuario);
		break;
	case 8:
		ComprarTudo(usuario);
		break;
	case 9:
		std::cout << "Digite o ID da compra a ser deletada: ";
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
	case 10:
		ViewCompras(usuario);
		break;
	case 11:
		std::cout << "Digite o ID da compra a ser cancelada: ";
		std::cin >> id;
		for (int i = 0; i < usuario->getCompras()->size(); i++) {
			if (usuario->getCompras()->at(i).getId() == id) {
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
	case 12:
		std::cout << "Digite o ID da compra a ser devolvida: ";
		std::cin >> id;
		//devolver
		break;
	default:
		std::cout << "Opcao invalida!" << std::endl;
		break;
	}
}
void Operacoes::AreaVendedor(std::vector<Usuario>* usuarios, Usuario* usuario, int* countId, std::vector<Anuncio*>* anuncios) {
	int opc, id;
	std::cout << "1- Criar anuncio\n2- Deletar um anuncio\n3- Listar anuncios\nDigite uma opcao: ";
	std::cin >> opc;
	switch (opc) {
	case 1:
		NovoAnuncio(usuario, countId, anuncios);
		break;
	case 2:
		std::cout << "Digite o ID do anuncio a ser deletado: ";
		std::cin >> id;
		usuario->deletarAnuncio(id);
		for (int i = 0; i < anuncios->size(); i++) {
			if (anuncios->at(i)->id == id) {
				anuncios->erase(anuncios->begin() + i);
			}
		}
		break;
	case 3:
		for (int i = 0; i < usuario->getAnuncios()->size(); i++) {
			std::cout << "Anuncio " << usuario->getAnuncios()->at(i).titulo << ", sob ID " << usuario->getAnuncios()->at(i).id << ", com o produto " << usuario->getAnuncios()->at(i).produto.nome << std::endl;
		}
		break;
	default:
		std::cout << "Opcao invalida!" << std::endl;
		break;
	}
}
void Operacoes::AreaAdmin(std::vector<Usuario>* usuarios, std::vector<Admin>* admins, Usuario* usuario, std::vector<Anuncio*>* anuncios) {
	bool existe, boolAux;
	int opc, ban, id;
	std::string str;
	std::cout << "1- Listar usuarios\n2- Banir um usuario\n3- Desbanir um usuario\n4- Cadastrar um admininistrador\n5- Deletar um anuncio\nDigite uma opcao: ";
	std::cin >> opc;
	switch (opc) {
	case 1: 
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
				//usuarios->at(i).banir(ban);
				existe = true;
			}
		}
		for (int i = 0; i < admins->size(); i++) {
			if (admins->at(i).login == str) {
				//admins->at(i).banir(ban);
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
				//boolAux = usuarios->at(i).desbanir(); //boolAux retorna se o usuario estava banido ou nao
				existe = true; //verifica existencia do usuario
			}
		}
		for (int i = 0; i < admins->size(); i++) {
			if (admins->at(i).login == str) {
				//boolAux = admins->at(i).desbanir(); //boolAux retorna se o usuario estava banido ou nao
				existe = true; //verifica existencia do usuario
			}
		}
		if (!existe) {
			std::cout << "Nome de usuario nao encontrado" << std::endl;
		}
		/*if (!boolAux) {
			std::cout << "O usuario nao estava banido" << std::endl;
		}*/
	case 4: //cadastrar admin
		Cadastrar(usuarios, admins, true);
		break;
	case 5: //deletar anuncio
		std::cout << "Digite o ID do anuncio a ser deletado: ";
		std::cin >> id;
		for (int i = 0; i < anuncios->size(); i++) {

		}
		break;
	default:
		std::cout << "Opcao invalida!" << std::endl;
		break;
	}
}

void Operacoes::NovoAnuncio(Usuario* usuario, int* countId, std::vector<Anuncio*>* anuncios) {
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
	Produto produto(str1, str2, strs);
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
	anuncio = usuario->criarAnuncio(produto, str1, num, preco, countId, strs);
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
	std::string str1;
	float valorCount = 0;
	int opc, parcelas;
	do {
		std::cout << "ATENCAO! Todos os itens no carrinho serao comprados. Certo? (s/n): ";
		std::cin >> str1;
		if (str1 == "n") {
			return;
		}
		if (str1 != "n" && str1 != "s") {
			std::cout << "Opcao invalida" << std::endl;
		}
	} while (str1 != "s" && str1 != "n");
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
			std::cin >> str1;
			if (str1 == "n") {
				return;
			}
			if (str1 != "n" && str1 != "s") {
				std::cout << "Opcao invalida" << std::endl;
			}
		} while (str1 != "s" && str1 != "n");
		usuario->comprar(opc, parcelas);
		std::cout << "Compra realizada com exito" << std::endl;
	}
	else {
		for (int i = 0; i < compras->size(); i++) {
			valorCount += compras->at(i).getValor();
		}
		do {
			std::cout << "Voce pagara " << valorCount << ", prossegue? (s/n): ";
			std::cin >> str1;
			if (str1 == "n") {
				return;
			}
			if (str1 != "n" && str1 != "s") {
				std::cout << "Opcao invalida" << std::endl;
			}
		} while (str1 != "s" && str1 != "n");
		usuario->comprar(opc, -1); //o pagamento eh a vista
		std::cout << "Compra realizada com exito" << std::endl;
	}

}
void Operacoes::pesquisar(std::vector<Anuncio*>* anuncios) {
	char opc;
	int QtTags = 1;
	std::cout << "Voce deseja pesquisar por mais de uma tag? (s/n); ";
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
			int z = std::distance(anuncios->at(y)->produto.tipos.begin(), c);
			if (!(z > anuncios->at(y)->produto.tipos.size())) {
				std::cout << "Titulo: " << anuncios->at(y)->titulo << std::endl << "Preco: R$" << anuncios->at(y)->preco << std::endl << "Disponibilidade: " << anuncios->at(y)->disponibilidade << std::endl << "ID: " << anuncios->at(y)->id << std::endl << "Nome do produto: " << anuncios->at(y)->produto.nome << std::endl << "Descricao do produto" << anuncios->at(y)->produto.descricao << std::endl << "Tags: ";
				for (int w = 0; w < anuncios->at(y)->produto.tipos.size(); w++) {
					std::cout << anuncios->at(y)->produto.tipos.at(w) << std::endl;
				}
			}
		}
	}
}
void Operacoes::ViewCompras(Usuario* usuario) {
	std::vector<Compra>* compras = usuario->getCompras();
	struct tm dataCompra;
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
				std::cout << "Compra ID " << compras->at(i).getId() << ", realizada no dia " << dataCompra.tm_mday << "/" << dataCompra.tm_mon << ", com data de entrega prevista " << dataEntrega.tm_mday << "/" << dataEntrega.tm_mon << "\nProduto: " << compras->at(i).getAnuncio()->produto.nome << ", do anuncio " << compras->at(i).getAnuncio()->titulo << ", com ID " << compras->at(i).getAnuncio()->id << std::endl;
				break;
			case 3:
				dtaCompr = compras->at(i).getDataCompra();
				dtaEntr = compras->at(i).getDataEntrega();
				localtime_s(&dataCompra, &dtaCompr);
				localtime_s(&dataEntrega, &dtaEntr);
				std::cout << "Compra ID " << compras->at(i).getId() << ", realizada no dia " << dataCompra.tm_mday << "/" << dataCompra.tm_mon << ", entregue em " << dataEntrega.tm_mday << "/" << dataEntrega.tm_mon << "\nProduto: " << compras->at(i).getAnuncio()->produto.nome << ", do anuncio " << compras->at(i).getAnuncio()->titulo << ", com ID " << compras->at(i).getAnuncio()->id << std::endl;
				break;
			case 4:
				std::cout << "Compra ID " << compras->at(i).getId() << ", cancelada" << std::endl;
				break;
			case 5:
				dtaCompr = compras->at(i).getDataCompra();
				dtaEntr = compras->at(i).getDataEntrega();
				localtime_s(&dataCompra, &dtaCompr);
				localtime_s(&dataEntrega, &dtaEntr);
				std::cout << "Compra ID " << compras->at(i).getId() << ", realizada no dia " << dataCompra.tm_mday << "/" << dataCompra.tm_mon << ", entregue em " << dataEntrega.tm_mday << "/" << dataEntrega.tm_mon << ", está aguardando devolucao\nProduto: " << compras->at(i).getAnuncio()->produto.nome << ", do anuncio " << compras->at(i).getAnuncio()->titulo << ", com ID " << compras->at(i).getAnuncio()->id << std::endl;
				break;
			case 6:
				dtaCompr = compras->at(i).getDataCompra();
				dtaEntr = compras->at(i).getDataEntrega();
				dtaDev = compras->at(i).getDataDevolucao();
				localtime_s(&dataCompra, &dtaCompr);
				localtime_s(&dataEntrega, &dtaEntr);
				localtime_s(&dataDev, &dtaDev);
				std::cout << "Compra ID " << compras->at(i).getId() << ", realizada no dia " << dataCompra.tm_mday << "/" << dataCompra.tm_mon << "entregue em " << dataEntrega.tm_mday << "/" << dataEntrega.tm_mon << ", devolvida em " << dataDev.tm_mday << "/" << dataDev.tm_mon << "\nProduto: " << compras->at(i).getAnuncio()->produto.nome << ", do anuncio " << compras->at(i).getAnuncio()->titulo << ", com ID " << compras->at(i).getAnuncio()->id << std::endl;
				break;
		}
	}
}
void Operacoes::listarUsuarios(std::vector<Usuario>* usuarios, std::vector<Admin>* admins) {
	time_t tempoBanido;
	struct tm tempoBan;
	std::cout << "Usuarios comuns: " << std::endl;
	for (int i = 0; i < usuarios->size(); i++) {
		if (usuarios->at(i).tempoDeBanimento == 0) {
			std::cout << "Usuario: " << usuarios->at(i).login << ", sob CPF " << usuarios->at(i).getCpf() << ", com email " << usuarios->at(i).getEmail() << ", com telefone " << usuarios->at(i).getTelefone() << ", nao esta banido" << std::endl;
		}
		else {
			tempoBanido = usuarios->at(i).tempoDeBanimento;
			localtime_s(&tempoBan, &tempoBanido);
			std::cout << "Usuario: " << usuarios->at(i).login << ", sob CPF " << usuarios->at(i).getCpf() << ", com email " << usuarios->at(i).getEmail() << ", com telefone " << usuarios->at(i).getTelefone() << ", esta banido por " << tempoBan.tm_mday << " dias" << std::endl;
		}
	}
	std::cout << "Admins: " << std::endl;
	for (int i = 0; i < admins->size(); i++) {
		if (admins->at(i).tempoDeBanimento == 0) {
			std::cout << "Admin: " << admins->at(i).login << ", sob CPF " << admins->at(i).getCpf() << ", com email " << admins->at(i).getEmail() << ", com telefone " << admins->at(i).getTelefone() << ", nao esta banido" << std::endl;
		}
		else {
			tempoBanido = admins->at(i).tempoDeBanimento;
			localtime_s(&tempoBan, &tempoBanido);
			std::cout << "Admin: " << admins->at(i).login << ", sob CPF " << admins->at(i).getCpf() << ", com email " << admins->at(i).getEmail() << ", com telefone " << admins->at(i).getTelefone() << ", esta banido por " << tempoBan.tm_mday << " dias" << std::endl;
		}
	}
}
