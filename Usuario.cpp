#include <ctime>
#include <chrono>
#include "Usuario.hpp"

Anuncio* Usuario::criarAnuncio(Produto _produto, std::string _titulo, int _disponibilidade, float _preco, int* _id) {
	Anuncio novoAnuncio(_titulo, _disponibilidade, _preco, _id, _produto, login);
	anuncios.push_back(novoAnuncio);
	for (int i = 0; i <= anuncios.size(); i++) {
		if (anuncios.at(i).operator==(&novoAnuncio)) { //encontra esse novo anuncio no vetor (por algum caralho de motivo esse � o �nico jeito que funciona)
			Anuncio* novoNovoAnuncio = &anuncios.at(i);
			return novoNovoAnuncio;
		}
	}
	return nullptr;
}

Usuario::Usuario(std::string _login, std::string _email, std::string _telefone, std::string _endereco, std::string _cpf, std::string _senha) {
	email = _email;
	login = _login;
	telefone = _telefone;
	endereco = _endereco;
	cpf = _cpf;
	senha = _senha;
	tempoDeBanimento = 0;
	counterIdCompra = 0;
}

bool Usuario::deletarAnuncio(int _id) {
	for (int i = 0; i < anuncios.size(); i++) {
		if (anuncios.at(i).id == _id) {
			anuncios.erase(anuncios.begin() + i);
			return true;
		}
	}
	return false;
}

std::vector<Anuncio>* Usuario::getAnuncios() {
	return &anuncios;
}

std::vector<Compra>* Usuario::getCompras() {
	return &compras;
}

bool Usuario::adicionarAoCarrinho(Anuncio* anuncioCompra, std::string endereco) {
	if (anuncioCompra->disponibilidade != 0) {
		Compra compra(endereco, anuncioCompra, &counterIdCompra);
		compras.push_back(compra);
		return true;
	}
	return false;
}

bool Usuario::removerDoCarrinho(Compra* compra) {
	if (compra->getStatus() == 2 || compra->getStatus() == 5) { // 2 = efetuada (n�o entregue), 5 = em devolu��o
		return false;
	}
	else {
		for (int i = 0; i < compras.size(); i++) {
			if (compras.at(i).operator==(*compra)) {
				compras.erase(compras.begin() + i);
				return true;
			}
		}
		return false;
	}
}

bool Usuario::devolverCompra(Compra* compraDevolver, int _diasDevolucao) {
	if (compraDevolver->getStatus() == 3) { // 3 = entregue
		compraDevolver->setStatus(5); // 5 = em devolu��o
		compraDevolver->setDataDevolucao(std::time(nullptr) + _diasDevolucao * 60 * 60 * 24);
		return true;
	}
	return false;
}

void Usuario::desfavoritar(int z) {
	favoritos.erase(favoritos.begin() + z);
}

void Usuario::verificarCompras() {
	for (int i = 0; i < compras.size(); i++) {
		if (compras.at(i).getStatus() == 2 && compras.at(i).getDataEntrega() <= std::time(nullptr)) {
			compras.at(i).setStatus(3);
		}
		if (compras.at(i).getStatus() == 5 && compras.at(i).getDataDevolucao() <= std::time(nullptr)) {
			compras.at(i).setStatus(6);
		}
	}
}

bool Usuario::comprar(int pagamento, int parcelas) {
	if (compras.size() == 0) {
		return false;
	}
	for (int i = 0; i < compras.size(); i++) {
		if (compras.at(i).getStatus() == 1) {
			if (compras.at(i).getAnuncio()->disponibilidade == 0) {
				return false;
			}
			compras.at(i).setStatus(2);
			compras.at(i).getAnuncio()->disponibilidade--;
			compras.at(i).setPagamento(pagamento);
			if (pagamento == 5 || pagamento == 6) {
				compras.at(i).setParcelas(parcelas);
			}
		}
	}
	return true;
}

bool Usuario::cancelarCompra(Compra* compraCancelar) {
	if (compraCancelar->getStatus() == 2) {
		compraCancelar->setStatus(4);
		return true;
	}
	return true;
}

void Usuario::favoritar(Anuncio* anuncioFavoritar) {
	favoritos.push_back(anuncioFavoritar);
}

std::string Usuario::getEmail() {
	return email;
}

std::string Usuario::getTelefone() {
	return telefone;
}

std::string Usuario::getEndereco() {
	return endereco;
}

std::string Usuario::getCpf() {
	return cpf;
}

std::string Usuario::getSenha() {
	return senha;
}

void Usuario::setSenha(std::string _senha) {
	senha = _senha;
}

void Usuario::setEndereco(std::string _endereco) {
	endereco = _endereco;
}

bool Usuario::devolverCompra(int idCompra) {
	for (int i = 0; i < compras.size(); i++) {
		if (compras.at(i).getId() == idCompra && compras.at(i).getStatus() == 3) { // s� devolve a compra se ela for entregue
			compras.at(i).setStatus(6);
			return true;
		}
	}
	return false;
}

void Usuario::setTempoDeBanimento(time_t dias) {
	tempoDeBanimento = dias;
}

int Usuario::getTempoDeBanimento() {
	if (tempoDeBanimento < std::time(nullptr)) {
		return 0;
	}
	int banTime = tempoDeBanimento - std::time(nullptr); // calcula quanto tempo ele est� banido
	return banTime / (60 * 60 * 24); // converte em dias
}

std::vector<Anuncio*> Usuario::getFavoritos() {
	return favoritos;
}

/*
1 - boleto vista
2 - pix vista
3 - credito vista
4 - debito vista
5 - credito prazo
6 - debito prazo
*/