#include "Biblioteca.hpp"
#include <vector>
#pragma once

class Usuario{
	private:
	std::string usuario, nome, senha;
	std::vector<Biblioteca> *livros;

	public:
	Usuario(){}
	Usuario(std::string u, std::string n, std::string s){
		usuario = u;
		nome = n;
		senha = s;
	}
	
	std::string getUsuario(){
		return usuario;
	}
	std::string getNome(){
		return nome;
	}
	std::string getSenha(){
		return senha;
	}

	void setUsuario(std::string u){
		usuario = u;
	}
	void setNome(std::string n){
		nome = n;
	}
	void setSenha(std::string s){
		senha = s;
	}
};
