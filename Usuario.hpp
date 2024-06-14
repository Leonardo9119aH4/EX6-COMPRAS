#include <iostream>
#include <vector>
#include "Anuncio.hpp"
#include "Compra.hpp"

class Usuario {
public:
	Usuario(std::string _login, std::string _email, std::string _telefone, std::string _endereco, std::string _cpf, std::string _senha);
	virtual ~Usuario() = default;
	Anuncio* criarAnuncio(Produto produto, std::string _titulo, int _disponibilidade, float _preco, int* _id, std::vector<std::string> _tipo);
	bool deletarAnuncio(int _id);
	bool comprar(Compra* compra, bool avista, char opc, int pagamento, int parcelas);
	bool cancelarCompra(Compra *compraCancelar);
	bool favoritar(Anuncio *anuncioFavoritar);
	bool adicionarAoCarrinho(Anuncio anuncioComrpa, std::string endereco, int* counterIdCompra);
	bool removerDoCarrinho(Compra* compra);
	bool desfavoritarAnuncio(Anuncio anuncioFavorito);
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
	std::string login;
	std::vector<Anuncio> anuncios;
	std::time_t tempoDeBanimento;
protected:
	std::string email;
	std::string telefone;
	std::string endereco;
	std::string cpf;
	std::vector<Anuncio*> favoritos;
	std::vector<Compra> compras;
	int counterIdCompra;
private:
	std::string senha;
};