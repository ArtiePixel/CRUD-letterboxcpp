#pragma once
#include "Biblioteca.hpp"
#include "Livro.hpp"
#include "HQ.hpp"
#include "Audiobook.hpp"
#include <vector>
#include <string>
#include <memory>  // unique_ptr e make_unique
#include <iostream>
#include <fstream>
#include <sstream>

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

	void adicionarLeitura(int tipo) {
		std::string titulo, autor, editora;
		int data;
		float nota;
		
		std::cout << "Titulo: ";
		std::getline(std::cin, titulo);
		std::cout << "Autor: ";
		std::getline(std::cin, autor);
		std::cout << "Editora: ";
		std::getline(std::cin, editora);
		std::cout << "Ano: ";
		std::cin >> data;
		std::cout << "Nota (0-10): ";
		std::cin >> nota;
		std::cin.ignore();
		
		if (tipo == 1) { // Livro
			std::string genero, edicao;
			int paginas;
			std::cout << "Genero: ";
			std::getline(std::cin, genero);
			std::cout << "Edicao: ";
			std::getline(std::cin, edicao);
			std::cout << "Paginas: ";
			std::cin >> paginas;
			std::cin.ignore();
			leituras.push_back(std::make_unique<Livro>(titulo, autor, editora, data, nota, genero, edicao, paginas));
		} else if (tipo == 2) { // HQ
			std::string colecao, volume;
			std::cout << "Colecao: ";
			std::getline(std::cin, colecao);
			std::cout << "Volume: ";
			std::getline(std::cin, volume);
			leituras.push_back(std::make_unique<HQ>(titulo, autor, editora, data, nota, colecao, volume));
		} else if (tipo == 3) { // Audiobook
			float duracao;
			std::string narrador;
			std::cout << "Duracao (horas): ";
			std::cin >> duracao;
			std::cin.ignore();
			std::cout << "Narrador: ";
			std::getline(std::cin, narrador);
			leituras.push_back(std::make_unique<Audiobook>(titulo, autor, editora, data, nota, duracao, narrador));
		}
		std::cout << "Leitura cadastrada com sucesso!" << std::endl;
	}

    void listarLeitura() {
		if (leituras.empty()) {
			std::cout << "Nenhuma leitura cadastrada." << std::endl;
			return;
		}
		
		std::cout << "\n===== SUAS LEITURAS =====" << std::endl;
		for (size_t i = 0; i < leituras.size(); i++) {
			std::cout << "\n[" << (i + 1) << "] ";
			leituras[i]->exibir();
			std::cout << "-------------------------" << std::endl;
		}
	}

	void exibirLeitura() {
		if (leituras.empty()) {
			std::cout << "Nenhuma leitura cadastrada." << std::endl;
			return;
		}
		
		std::cout << "Digite o titulo da leitura: ";
		std::string titulo;
		std::getline(std::cin, titulo);
		
		for (const auto& leitura : leituras) {
			if (leitura->getTitulo() == titulo) {
				std::cout << "\n===== LEITURA ENCONTRADA =====" << std::endl;
				leitura->exibir();
				std::cout << "==============================" << std::endl;
				return;
			}
		}
		std::cout << "Leitura com titulo '" << titulo << "' nao encontrada." << std::endl;
	}
	
	//para listar vai usar o NomePonteiro->exibir()
	void editarLeitura() {

	}

	void deletarLeitura() {

	}
	
	void salvarLeituras() {
		std::string nomeArquivo = usuario + "_leituras.txt";
		std::ofstream arquivo(nomeArquivo);
		if (!arquivo.is_open()) return;
		
		for (const auto& leitura : leituras) {
			if (auto livro = dynamic_cast<Livro*>(leitura.get())) {
				arquivo << "LIVRO;" << livro->getTitulo() << ";" << livro->getAutor() << ";" 
						<< livro->getEditora() << ";" << livro->getData() << ";" << livro->getNota() 
						<< ";" << livro->getGenero() << ";" << livro->getEdicao() << ";" << livro->getPaginas() << "\n";
			} else if (auto hq = dynamic_cast<HQ*>(leitura.get())) {
				arquivo << "HQ;" << hq->getTitulo() << ";" << hq->getAutor() << ";" 
						<< hq->getEditora() << ";" << hq->getData() << ";" << hq->getNota() 
						<< ";" << hq->getColecao() << ";" << hq->getVolume() << "\n";
			} else if (auto audiobook = dynamic_cast<Audiobook*>(leitura.get())) {
				arquivo << "AUDIOBOOK;" << audiobook->getTitulo() << ";" << audiobook->getAutor() << ";" 
						<< audiobook->getEditora() << ";" << audiobook->getData() << ";" << audiobook->getNota() 
						<< ";" << audiobook->getDuracao() << ";" << audiobook->getNarrador() << "\n";
			}
		}
		arquivo.close();
	}
	
	void carregarLeituras() {
		std::string nomeArquivo = usuario + "_leituras.txt";
		std::ifstream arquivo(nomeArquivo);
		if (!arquivo.is_open()) return;
		
		std::string linha;
		while (std::getline(arquivo, linha)) {
			std::stringstream ss(linha);
			std::string tipo, titulo, autor, editora, temp;
			int data;
			float nota;
			
			std::getline(ss, tipo, ';');
			std::getline(ss, titulo, ';');
			std::getline(ss, autor, ';');
			std::getline(ss, editora, ';');
			std::getline(ss, temp, ';'); data = std::stoi(temp);
			std::getline(ss, temp, ';'); nota = std::stof(temp);
			
			if (tipo == "LIVRO") {
				std::string genero, edicao;
				int paginas;
				std::getline(ss, genero, ';');
				std::getline(ss, edicao, ';');
				std::getline(ss, temp, ';'); paginas = std::stoi(temp);
				leituras.push_back(std::make_unique<Livro>(titulo, autor, editora, data, nota, genero, edicao, paginas));
			} else if (tipo == "HQ") {
				std::string colecao, volume;
				std::getline(ss, colecao, ';');
				std::getline(ss, volume, ';');
				leituras.push_back(std::make_unique<HQ>(titulo, autor, editora, data, nota, colecao, volume));
			} else if (tipo == "AUDIOBOOK") {
				float duracao;
				std::string narrador;
				std::getline(ss, temp, ';'); duracao = std::stof(temp);
				std::getline(ss, narrador, ';');
				leituras.push_back(std::make_unique<Audiobook>(titulo, autor, editora, data, nota, duracao, narrador));
			}
		}
		arquivo.close();
	}
};