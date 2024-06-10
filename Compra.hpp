#include <iostream>
#include <vector>
#include <algorithm>
#include "Anuncio.hpp"
#ifndef COMPRA_HPP
#define COMPRA_HPP
class Compra {
public:
	Compra(std::string entrega);
	~Compra() {};
	std::vector<Anuncio*> getAnuncios();
	void addAnuncio(Anuncio* anuncio);
	bool removeAnuncio(Anuncio* anuncio);
	std::string getEntrega();
	void setEntrega(std::string _entrega);
	int getStatus();
	void setStatus(int Status);
	int getPagamento();
	float getValor();
	float Parcelar(int vezes);
	void Pagar(int _pagamento);
	std::vector<float> getParcelas();

protected:
	std::vector<Anuncio*> anuncios;
	int parcelas, status;
	std::string entrega;
	int pagamento; //id para o tipo de pagamento
	float valor=0;
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
5- Devolvida
*/