#include <iostream>
#include <vector>
#include "Anuncio.hpp"
#include "Compra.hpp"
class Usuario {
public:
	Usuario() {};
	~Usuario() {};
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
	std::string login;
	std::vector<Anuncio> anuncios;
protected:
	std::string email;
	std::string telefone;
	std::string endereco;
	std::string	cpf;
	std::vector<Anuncio*> favoritos;
	std::vector<Compra*> compras;
private:
	std::string senha;
};