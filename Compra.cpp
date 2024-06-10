#include <iostream>
#include <vector>
#include <algorithm>
#include "Compra.hpp"
Compra::Compra(std::string _entrega) {
	entrega = _entrega;
	status = 1;
}
std::vector<Anuncio*> Compra::getAnuncios(){
	return anuncios;
}
void Compra::addAnuncio(Anuncio* anuncio) {
	anuncios.push_back(anuncio);
	valor += anuncio->preco;
}
bool Compra::removeAnuncio(Anuncio* anuncio) {
	int index;
	auto it = std::find(anuncios.begin(), anuncios.end(), anuncio);
	if (it != anuncios.end()) {
		index = std::distance(anuncios.begin(), it);
		anuncios.erase(anuncios.begin() + index);
	}
	valor -= anuncio->preco;
}
std::string Compra::getEntrega() {
	return entrega;
}
void Compra::setEntrega(std::string _entrega) {
	entrega = _entrega;
}
int Compra::getStatus() {
	return status;
}
void Compra::setStatus(int _status) {
	status = _status;
}
int Compra::getPagamento() {
	return pagamento;
}
float Compra::getValor() {
	return valor;
}
float Compra::Parcelar(int vezes) {
	float parcela = valor / vezes;
	parcela += parcela * 0.03;
	return parcela;
}

void Compra::Pagar(int _pagamento) {
	pagamento = _pagamento;
	status = 2;
}
