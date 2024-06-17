#include <iostream>
#include <vector>
#include <algorithm>
#include "Usuario.hpp"
#ifndef USUARIO_HPP_
#define USUARIO_HPP_

Anuncio* Usuario::criarAnuncio(Produto _produto, std::string _titulo, int _disponibilidade, float _preco, int* _id, std::vector<std::string> _tipo) {
	Anuncio novoAnuncio = Anuncio(_titulo, _disponibilidade, _preco, _id, _produto);
	novoAnuncio.produto = _produto;
	anuncios.push_back(novoAnuncio);
	auto i = std::find(anuncios.begin(), anuncios.end(), novoAnuncio);
	int j = std::distance(anuncios.begin(), i);
	Anuncio* novoNovoAnuncio = &anuncios.at(j);
	return novoNovoAnuncio;
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

bool Usuario::adicionarAoCarrinho(Anuncio anuncioCompra, std::string endereco) {
	Compra compra = Compra(endereco, &anuncioCompra, counterIdCompra);
	++counterIdCompra;
	compras.push_back(compra);
	return true;
}

bool Usuario::removerDoCarrinho(Compra* compra) {
	if (compra->getStatus() == 2 || compra->getStatus() == 5) {
		return false;
	}
	else {
		auto i = std::find(compras.begin(), compras.end(), compra);
		int i2 = std::distance(compras.begin(), i);
		compras.erase(compras.begin(), i);
		return true;
	}
}

bool Usuario::desfavoritar(Anuncio* anuncioFavorito) {
	auto i = std::find(favoritos.begin(), favoritos.end(), anuncioFavorito);
	if (i > favoritos.end()) {
		return false;
	}
	favoritos.erase(favoritos.begin(), i);
	return true;
}

bool Usuario::comprar(bool avista, char opc, int pagamento, int parcelas) {
	if (compras.size() == 0) {
		return false;
	}
	for (int i = 0; i < compras.size(); i++) {
		compras.at(i).setStatus(2);
		compras.at(i).set
	}
	return true;
}

bool Usuario::cancelarCompra(Compra* compraCancelar) {
	compraCancelar->setStatus(4);
}

bool Usuario::favoritar(Anuncio* anuncioFavoritar) {
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

std::vector<Anuncio*> Usuario::getFavoritos() {
	return favoritos;
}

#endif

/*
1 - boleto vista
2 - pix vista
3 - credito vista
4 - debito vista
5 - credito prazo
6 - debito prazo
*/