#include <iostream>
#include <vector>
#include <limits>
#include "Operacoes.hpp"
#ifndef CONTAS_HPP
#define CONTAS_HPP
void Cadastrar(std::vector<Usuario>* usuarios, std::vector<Admin>* admins, bool cadAdmin);
void Login(std::vector<Usuario>* usuarios, std::vector<Admin>* admins, int* countId, std::vector<Anuncio*>* anuncios);
#endif