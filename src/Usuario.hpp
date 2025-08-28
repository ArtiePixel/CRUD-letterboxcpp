#pragma once
#include "Biblioteca.hpp"
#include <vector>
#include <string>
#include <memory>  // unique_ptr e make_unique

class Usuario{
	private:
	std::string usuario, nome, senha;
	std::vector<std::unique_ptr<Biblioteca>> leituras; 
	// ponteiro inteligente que se deleta qnd sai n é mais usado. Troquei para poder salvar as infos especificas de cada classe 
	// livro e HQ tem especificações diferentes, por exemplo. Como tava antes n salvava essas infos exclusivas da classe :) std::vector<Biblioteca> *livros;
	// ainda temos a opção de usar ponteiro normal, mas ai temos que deletar manualmente, ces que sabem

	public:
	Usuario(){}
	Usuario(std::string u, std::string n, std::string s){
		usuario = u;
		nome = n;
		senha = s;
	}
	
	// Disable copy constructor and copy assignment
	Usuario(const Usuario&) = delete;
	Usuario& operator=(const Usuario&) = delete;
	
	// Enable move constructor and move assignment
	Usuario(Usuario&& other) noexcept
		: usuario(std::move(other.usuario)),
		  nome(std::move(other.nome)),
		  senha(std::move(other.senha)),
		  leituras(std::move(other.leituras)) {}
	
	Usuario& operator=(Usuario&& other) noexcept {
		if (this != &other) {
			usuario = std::move(other.usuario);
			nome = std::move(other.nome);
			senha = std::move(other.senha);
			leituras = std::move(other.leituras);
		}
		return *this;
	}
	
	//getters
	std::string getUsuario() const{return usuario;}
	std::string getNome() const {return nome;}
	std::string getSenha() const {return senha;}

	//setters
	void setUsuario(std::string u){usuario = u;}
	void setNome(std::string n){nome = n;}
	void setSenha(std::string s){senha = s;}

	//ainda implementar:
	void adicionarLeitura();
	//vai ter que usar make_unique (é sobre criar aquele ponteiro que falei la em cima)
    void listarLeitura();
	//para listar vai usar o NomePonteiro->exibir()
	void editarLeitura();
	void deletarLeitura();
};