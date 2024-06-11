#include <iostream>
#include <vector>
#include "Usuario.hpp"
#ifndef USUARIO_HPP_
#define USUARIO_HPP_

Anuncio Usuario::criarAnuncio(Produto *produto) {
	Anuncio novoAnuncio = Anuncio();
	novoAnuncio.produto = *produto;
	anuncios.push_back(novoAnuncio);
	return novoAnuncio;
}

Usuario::Usuario(std::string _login, std::string _email, std::string _telefone, std::string _endereco, std::string _cpf, std::string _senha) {
	email = _email;
	login = _login;
	telefone = _telefone;
	endereco = _endereco;
	cpf = _cpf;
	senha = _senha;
	tempoDeBanimento = 0;
}

bool Usuario::deletarAnuncio(Anuncio *anuncioDeletar) {
	for (int i = 0; i < anuncios.size(); i++) {
		if (anuncioDeletar->operator==(anuncios.at(i))) {
			anuncios.erase(anuncios.begin() + i);
			return true;
		}
	}
	return false;
}

bool Usuario::comprar(Compra *anuncioCompra, bool avista, char opc, int pagamento, int parcelas) {
	char opc;
	int pagamento;
	int parcelas;
	bool avista;
	compras.push_back(anuncioCompra);
	anuncioCompra->setStatus(1);
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
#endif

/*
1 - boleto vista
2 - pix vista
3 - credito vista
4 - debito vista
5 - credito prazo
6 - debito prazo
*/