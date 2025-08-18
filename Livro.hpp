#include "Biblioteca.hpp"

class Livro : public Biblioteca{
	private:
	std::string genero, edicao;
	int paginas;

	public:
	Livro(){}

	void exibir(){
		Biblioteca::exibir();
		std::cout << "Gênero: " << genero << "\nEdição: " << edicao << "\nNúmero de páginas: " << paginas << std::endl;
	}
};
