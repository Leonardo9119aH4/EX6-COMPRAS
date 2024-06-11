#include <iostream>
#include <vector>
#include "Anuncio.hpp"
#include "Compra.hpp"

class Usuario {
public:
	Usuario(std::string _login, std::string _email, std::string _telefone, std::string _endereco, std::string _cpf, std::string _senha);
	virtual ~Usuario() = default;
	Anuncio criarAnuncio(Produto *produto);
	bool deletarAnuncio(Anuncio *anuncioDeletar);
	bool comprar(Compra *anuncioCompra, bool avista, char opc, int pagamento, int parcelas);
	bool cancelarCompra(Compra *compraCancelar);
	bool favoritar(Anuncio *anuncioFavoritar);
	std::string getEmail();
	std::string getTelefone();
	std::string getEndereco();
	std::string getCpf();
	std::string getSenha();
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
	std::vector<Compra*> compras;
private:
	std::string senha;
};