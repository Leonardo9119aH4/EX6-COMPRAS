#include <iostream>
#include <vector>
class Usuario {
public:
	Usuario() {};
	~Usuario() {};
	Anuncio criarAnuncio(Produto produto);
	bool deletarAnuncio(Anuncio anuncioDeletar);
	bool comprar(Anuncio anuncioCompra);
	bool cancelarCompra(Compra compraCancelar);
	bool favoritar(Anuncio anuncioFavoritar);
	std::string getEmail();
	std::string getTelefone();
	std::string getEndereco();
	std::string getCpf();
	std::string getSenha();
	std::string login;
	std::vector<Anuncio> favoritos;
	std::vector<Anuncio> anuncios;
	std::vector<Compra> compras;
protected:
	std::string email;
	std::string telefone;
	std::string endereco;
	std::string	cpf;
private:
	std::string senha;
};