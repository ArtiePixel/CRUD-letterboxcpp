#pragma once
#include "Biblioteca.hpp"

class Livro : public Biblioteca{
	private:
	std::string genero, edicao;
	int paginas;

	public:
	Livro(std::string t, std::string a, std::string e, int d, float n, std::string g, std::string ed, int p)
		: Biblioteca(t, a, e, d, n) {
		genero = g;
		edicao = ed;
		paginas = p;
	}

	void exibir() override {
		Biblioteca::exibir();
		std::cout << "Genero: " << genero << "\nEdicao: " << edicao << "\nNumero de paginas: " << paginas << std::endl;
	}
	
	std::string getGenero() const { return genero; }
	std::string getEdicao() const { return edicao; }
	int getPaginas() const { return paginas; }
};