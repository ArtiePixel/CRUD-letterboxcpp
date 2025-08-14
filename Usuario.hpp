#include "CRUD.hpp"

class Usuario{
	private:
	std::string usuario, nome, senha;

	public:
	Usuario(){}
	
	std::string getUsuario(){
		return usuario;
	}
	std::string getNome(){
		return nome;
	}
	std::string getSenha(){
		return senha
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
