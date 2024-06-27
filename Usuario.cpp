#include <ctime>
#include <chrono>
#include "Usuario.hpp"

Anuncio* Usuario::criarAnuncio(Produto _produto, std::string _titulo, int _disponibilidade, float _preco, int* _id, std::vector<std::string> _tipo) {
	Anuncio novoAnuncio(_titulo, _disponibilidade, _preco, _id, _produto, user);
	anuncios.push_back(novoAnuncio);
	for (int i = 0; i <= anuncios.size(); i++) {
		if (anuncios.at(i).operator==(&novoAnuncio)) {
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
	user = this;
}

bool Usuario::deletarAnuncio(int _id) {
	for (int i = 0; i < anuncios.size(); i++) {
		if (anuncios.at(i).id == _id) {
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
	if (anuncioCompra->disponibilidade == 0) {
		Compra compra(endereco, anuncioCompra, &counterIdCompra);
		compras.push_back(compra);
		return true;
	}
	return false;
}

bool Usuario::removerDoCarrinho(Compra* compra) {
	if (compra->getStatus() == 2 || compra->getStatus() == 5) {
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
	if (compraDevolver->getStatus() == 3) {
		compraDevolver->setStatus(5);
		compraDevolver->setDataDevolucao(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()) + _diasDevolucao * 60 * 60 * 24);
		return true;
	}
	return false;
}

bool Usuario::desfavoritar(Anuncio* anuncioFavorito) {
	auto i = std::find(favoritos.begin(), favoritos.end(), anuncioFavorito);
	if (i > favoritos.end()) {
		return false;
	}
	int z = std::distance(favoritos.begin(), i);
	favoritos.erase(favoritos.begin() + z);
	return true;
}

void Usuario::calcEntrega() {
	for (int i = 0; i < compras.size(); i++) {
		if (compras.at(i).getStatus() == 2 && compras.at(i).getDataEntrega() >= std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())) {
			compras.at(i).setStatus(3);
		}
	}
}

void Usuario::calcDevolucao() {
	for (int i = 0; i < compras.size(); i++) {
		if (compras.at(i).getStatus() == 5 && compras.at(i).getDataDevolucao() >= std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())) {
			compras.at(i).setStatus(6);
		}
	}
}

bool Usuario::comprar(int pagamento, int parcelas) {
	if (compras.size() == 0) {
		return false;
	}
	for (int i = 0; i < compras.size(); i++) {
		compras.at(i).setStatus(2);
		compras.at(i).setPagamento(pagamento);
		if (pagamento == 5 || pagamento == 6) {
			compras.at(i).setParcelas(parcelas);
		}
	}
	return true;
}

bool Usuario::cancelarCompra(Compra* compraCancelar) {
	if (compraCancelar->getStatus() == 1 || compraCancelar->getStatus() == 2) {
		compraCancelar->setStatus(4);
		return true;
	}
	return true;
}

bool Usuario::favoritar(Anuncio* anuncioFavoritar) {
	for (int i = 0; i < favoritos.size(); i++) {
		if (favoritos.at(i)->operator==(anuncioFavoritar)) {
			favoritos.push_back(anuncioFavoritar);
			return true;
		};
	}
	return false;
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
		if (compras.at(i).getId() == idCompra) {
			compras.at(i).setStatus(6);
			return true;
		}
	}
	return false;
}

void Usuario::setTempoDeBanimento(int dias) {
	tempoDeBanimento = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()) + dias * 24 * 60 * 60;
}

int Usuario::getTempoDeBanimento() {
	if (tempoDeBanimento < std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())) {
		return 0;
	}
	std::time_t banTime = tempoDeBanimento - std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	struct tm stTime;
	localtime_s(&stTime, &banTime);
	int stDia = stTime.tm_mday;
	int stMes = stTime.tm_mon;
	int stAno = stTime.tm_year;
	return stDia * stMes * stAno;
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