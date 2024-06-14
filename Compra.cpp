#include <iostream>
#include <vector>
#include "Compra.hpp"
Compra::Compra(std::string _entrega, Anuncio* _anuncio, int* counter) {
	entrega = _entrega;
	anuncio = _anuncio;
	valor = anuncio->preco + 20; //sao 20 reais de frete
	status = 1;
	id = *counter;
	counter++;
	dataCompra = std::time(nullptr);
	dataEntrega = dataCompra + 60 * 60 * 24 * 5;
}
Anuncio* Compra::getAnuncio(){
	return anuncio;
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
bool Compra::Cancelar() {
	if (status == 1 || status == 2) {
		status == 4;
		return true;
	}
	return false;
}
bool Compra::Devolver(std::string _entrega) {
	if (status == 3) {
		entrega = _entrega;
		dataDevolucao = std::time(nullptr);
		status = 5;
		return true;
	}
	return false;
}