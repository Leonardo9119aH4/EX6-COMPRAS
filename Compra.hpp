#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include "Anuncio.hpp"
#ifndef COMPRA_HPP
#define COMPRA_HPP
class Compra {
public:
	Compra(std::string entrega, Anuncio* _anuncio, int* counter);
	~Compra() {};
	bool operator==(Compra _compra) {
		bool isEqual = (parcelas == _compra.getParcelas()) && (status == _compra.getStatus()) && (entrega == _compra.getEntrega()) && (pagamento == _compra.getPagamento()) && (valor == _compra.getValor()) && (id == _compra.getId()) && (dataCompra == _compra.getDataCompra()) && (anuncio->operator==(_compra.anuncio));
		return isEqual;
	}
	Anuncio* getAnuncio();
	std::string getEntrega();
	void setEntrega(std::string _entrega);
	int getStatus();
	void setStatus(int Status);
	void setParcelas(int _parcelas);
	void setPagamento(int _pagamento);
	void setDataDevolucao(time_t data);
	int getPagamento();
	float getValor();
	int getId();
	int getParcelas();
	time_t getDataCompra();
	time_t getDataEntrega();
	time_t getDataDevolucao();
	float Parcelar(int vezes);
	void Pagar(int _pagamento);
	bool Cancelar();
	bool Devolver(std::string _entrega);
protected:
	Anuncio* anuncio;
	int parcelas, status;
	std::string entrega;
	int pagamento; 
	float valor=0;
	int id;
	time_t dataCompra, dataEntrega, dataDevolucao;
};
#endif // !COMPRA_HPP
/* 
Pagamento:
1- Boleto vista
2- Pix vista
3- Credito vista
4- Debito vista
5- Credito prazo
Status:
1- Carrinho
2- Efetuada
3- Entregue
4- Cancelada
5- Em devolucao
6- Devolvida
*/