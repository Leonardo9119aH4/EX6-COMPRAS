#include "Usuario.hpp"

Anuncio* Usuario::criarAnuncio(Produto _produto, std::string _titulo, int _disponibilidade, float _preco, int* _id, std::vector<std::string> _tipo) {
	Anuncio novoAnuncio(_titulo, _disponibilidade, _preco, _id, _produto);
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
	Compra compra(endereco, anuncioCompra, &counterIdCompra);
	compras.push_back(compra);
	return true;
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

bool Usuario::desfavoritar(Anuncio* anuncioFavorito) {
	auto i = std::find(favoritos.begin(), favoritos.end(), anuncioFavorito);
	if (i > favoritos.end()) {
		return false;
	}
	int z = std::distance(favoritos.begin(), i);
	favoritos.erase(favoritos.begin() + z);
	return true;
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
	compraCancelar->setStatus(4);
	return true;
}

bool Usuario::favoritar(Anuncio* anuncioFavoritar) {
	favoritos.push_back(anuncioFavoritar);
	return true;
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

/*
1 - boleto vista
2 - pix vista
3 - credito vista
4 - debito vista
5 - credito prazo
6 - debito prazo
*/