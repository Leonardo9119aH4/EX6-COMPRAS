#include <iostream>
#include <vector>
#include <limits>
#include "Anuncio.hpp"
#include "Compra.hpp"
#include "Produto.hpp"
#include "Usuario.hpp"
#include "Admin.hpp"
#ifndef OPERACOES_HPP
#define OPERACOES_HPP
namespace Operacoes {
	void OpcUsuario(std::vector<Usuario>* usuarios, std::vector<Admin>* admins,Usuario* usuario, int* countId, std::vector<Anuncio*>* anuncios);
	void OpcUsuario(std::vector<Usuario>* usuarios, std::vector<Admin>* admins, Admin* admin, int* countId, std::vector<Anuncio*>* anuncios);
	void AreaComprador(std::vector<Usuario>* usuarios, Usuario* usuario, int* countId, std::vector<Anuncio*>* anuncios);
	void AreaVendedor(std::vector<Usuario>* usuarios, Usuario* usuario, int* countId, std::vector<Anuncio*>* anuncios);
	void AreaAdmin(std::vector<Usuario>* usuarios, std::vector<Admin>* admins, Admin* admin, std::vector<Anuncio*>* anuncios);
	void NovoAnuncio(Usuario* usuario, int* countId, std::vector<Anuncio*>* anuncios);
	void ViewAnuncio(std::vector<Anuncio*>* anuncios);
	void VerCarrinho(Usuario* usuario);
	void ComprarTudo(Usuario* usuario);
	void pesquisar(std::vector<Anuncio*>* anuncios);
	void ViewCompras(Usuario* usuario);
	void listarUsuarios(std::vector<Usuario>* usuarios, std::vector<Admin>* admins);
	void deletarAds(std::vector<Usuario>* usuarios, std::vector<Admin>* admins, std::vector<Anuncio*>* anuncios);
}
#endif // !OPERACOES_HPP
