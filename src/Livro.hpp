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
		std::cout << "Gênero: " << genero << "\nEdição: " << edicao << "\nNúmero de páginas: " << paginas << std::endl;
	}
};