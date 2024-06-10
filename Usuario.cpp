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

bool Usuario::deletarAnuncio(Anuncio *anuncioDeletar) {
	for (int i = 0; i < anuncios.size(); i++) {
		if (anuncioDeletar->operator==(anuncios.at(i))) {
			anuncios.erase(anuncios.begin() + i);
			return true;
		}
	}
	return false;
}

bool Usuario::comprar(Anuncio *anuncioCompra) {
	char opc;
	int pagamento;
	int parcelas;
	bool avista;
	std::cout << "Voce ira pagar a vista? (S/N)";
	std::cin >> opc;
	if (opc == 's' || opc == 'S') {
		avista = true;
	}
	else {
		avista = false;
	}
	if (avista) {
		std::cout << "Qual sera o metodo de pagamento: \n1 - Boleto\n2 - Pix\n3 - Credito\n4 - Debito";
		std::cin >> pagamento;
		parcelas = 0;
	}
	else {
		std::cout << "Qual sera o metodo de pagamento: \n1 - Credito\n2 - Debito\n";
		std::cin >> pagamento;
	}
	if (!avista) {
		pagamento += 2;
		std::cout << "Digite a quantidade de parcelas: ";
		std::cin >> parcelas;
		if (parcelas <= anuncioCompra->parcelas) {
			std::cout << "" << parcelar(parcelas);
		};
		pagar(pagamento, )
	}
	compras.push_back(anuncioCompra);
	
	return true;
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