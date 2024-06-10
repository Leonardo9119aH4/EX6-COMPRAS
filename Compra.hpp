#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include "Anuncio.hpp"
#ifndef COMPRA_HPP
#define COMPRA_HPP
class Compra {
public:
	Compra(std::string entrega, Anuncio* _anuncio);
	~Compra() {};
	Anuncio* getAnuncio();
	std::string getEntrega();
	void setEntrega(std::string _entrega);
	int getStatus();
	void setStatus(int Status);
	int getPagamento();
	float getValor();
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