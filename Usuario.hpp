#include <iostream>
#include <vector>
#include "Anuncio.hpp"
#include "Compra.hpp"
#ifndef USUARIO_HPP_
#define USUARIO_HPP_

class Usuario {
public:
	Usuario(std::string _login, std::string _email, std::string _telefone, std::string _endereco, std::string _cpf, std::string _senha);
	virtual ~Usuario() = default;
	Anuncio* criarAnuncio(Produto _produto, std::string _titulo, int _disponibilidade, float _preco, int* _id);
	bool deletarAnuncio(int _id);
	bool comprar(int pagamento, int parcelas);
	bool cancelarCompra(Compra* compraCancelar);
	void favoritar(Anuncio* anuncioFavoritar);
	bool adicionarAoCarrinho(Anuncio* anuncioComrpa, std::string endereco);
	bool removerDoCarrinho(Compra* compra);
	bool devolverCompra(Compra* compraDevolver, int _diasDevolucao);
	void desfavoritar(Anuncio* anuncioFavorito);
	void verificarCompras();
	std::vector<Compra>* getCompras();
	std::string getEmail();
	std::string getTelefone();
	std::string getEndereco();
	std::string getCpf();
	std::string getSenha();
	std::vector<Anuncio*> getFavoritos();
	std::vector<Anuncio>* getAnuncios();
	void setSenha(std::string _senha);
	void setEndereco(std::string _endereco);
	void setTempoDeBanimento(time_t dias);
	bool devolverCompra(int idCompra);
	int getTempoDeBanimento();
	std::string login;
	std::vector<Anuncio> anuncios;
protected:
	std::time_t tempoDeBanimento;
	std::string email;
	std::string telefone;
	std::string endereco;
	std::string cpf;
	std::vector<Anuncio*> favoritos;
	std::vector<Compra> compras;
	int counterIdCompra;
	std::string senha;
};
#endif