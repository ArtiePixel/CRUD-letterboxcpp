#pragma once
#include "Usuario.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>   //  pro arquivo txt
#include <sstream>   //  pro arquivo txt


class CRUD{
    private:
    std::vector<Usuario> usuarios;
    std::string arquivoUsuarios = "usuarios.txt"; // arquivo txt

    public:

    int pesquisarUsuario(std::string usuario){
        for(int i = 0; i < (int)usuarios.size(); i++){
            if (usuarios[i].getUsuario() == usuario){
                return i;
            }
        }
        return -1;
    }

    Usuario* autenticarUsuario(const std::string& username, const std::string& senha) {
        int i = pesquisarUsuario(username);

        if (i != -1) {
            if (usuarios[i].getSenha() == senha) {
                return &usuarios[i];
            }
        }
        return nullptr;
    }

    void criarUsuario(std::string user, std::string name, std::string password){
        if (pesquisarUsuario(user) != -1) {
            std::cout << "Erro: Nome de usuario '" << user << "' já existe." << std::endl;
            return;
        }
        usuarios.emplace_back(user, name, password);
        std::cout << "Usuario criado com sucesso" << std::endl;
    }

    void atualizarUsuario(){
        std::string user;
        std::cout << "Digite o usuario a ser atualizado: ";
        std::getline(std::cin, user);
        
        int i = pesquisarUsuario(user);
        if (i == -1) {
            std::cout << "Usuario nao encontrado." << std::endl;
            return;
        }
        
        std::string novoUsuario, novoNome, novaSenha;
        std::cout << "Novo usuario (atual: " << usuarios[i].getUsuario() << "): ";
        std::getline(std::cin, novoUsuario);
        
        if (!novoUsuario.empty() && pesquisarUsuario(novoUsuario) != -1 && novoUsuario != usuarios[i].getUsuario()) {
            std::cout << "Erro: Nome de usuario '" << novoUsuario << "' ja existe." << std::endl;
            return;
        }
        
        std::cout << "Novo nome (atual: " << usuarios[i].getNome() << "): ";
        std::getline(std::cin, novoNome);
        std::cout << "Nova senha: ";
        std::getline(std::cin, novaSenha);
        
        if (!novoUsuario.empty()) usuarios[i].setUsuario(novoUsuario);
        if (!novoNome.empty()) usuarios[i].setNome(novoNome);
        if (!novaSenha.empty()) usuarios[i].setSenha(novaSenha);
        
        std::cout << "Usuario atualizado com sucesso." << std::endl;
    }

    void deletarUsuario(){
        std::string user;
        std::cout << "Digite o usuario a ser deletado: ";
        std::getline(std::cin, user);
        
        int i = pesquisarUsuario(user);
        if (i == -1) {
            std::cout << "Usuario nao encontrado." << std::endl;
            return;
        }
        
        std::cout << "Tem certeza que deseja deletar o usuario '" << usuarios[i].getNome() 
                  << "' (@" << usuarios[i].getUsuario() << ")? (s/n): ";
        std::string confirmacao;
        std::getline(std::cin, confirmacao);
        
        if (confirmacao == "s" || confirmacao == "S") {
            usuarios.erase(usuarios.begin() + i);
            std::cout << "Usuario deletado com sucesso." << std::endl;
        } else {
            std::cout << "Operacao cancelada." << std::endl;
        }
    }

    void lerListarUsuario(){
        if (usuarios.empty()){
            std::cout << "Nenhum usuário cadastrado" << std::endl;
            return ;
        }
        std::cout << "--- Lista de Usuários ---" << std::endl;
        for (const auto& user : usuarios){
            std::cout << "Nome: " << user.getNome() << " (@" << user.getUsuario() << ")" << std::endl;
        }
        std::cout << "-------------------------" << std::endl;
    }

    void carregarUsuario() {
        std::ifstream arquivo(arquivoUsuarios);
        if (!arquivo.is_open()) {
            return;
        }

        std::string linha, user, nome, senha;
        while (std::getline(arquivo, linha)) {
            std::stringstream ss(linha);
            std::getline(ss, user, ';');
            std::getline(ss, nome, ';');
            std::getline(ss, senha, ';');
            
            usuarios.emplace_back(user, nome, senha); 
        }
        arquivo.close();
    }

    void salvarUsuario() {
        std::ofstream arquivo(arquivoUsuarios);
        if (!arquivo.is_open()) {
            std::cerr << "Erro ao abrir o arquivo." << std::endl;
            return;
        }

        for (const auto& user : usuarios) {
            arquivo << user.getUsuario() << ";" << user.getNome() << ";" << user.getSenha() << "\n";
        }
        arquivo.close();
    }
};