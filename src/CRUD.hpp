#include "Usuario.hpp"
#include <vector>
#include <iostream>
#include <fstream>   //  leitura/escrita de arquivos
#include <sstream>   //  parsear linhas


class CRUD{
    private:
    std::vector<Usuario> usuarios;
    std::string arquivoUsuarios = "usuarios.txt"; // arquivo

    public:
    int pesquisarUsuario(std::string usuario){
        for(int i = 0; i < usuarios.size(); i++){
            if (usuarios[i].getUsuario() == usuario){
                return i;
            }
        }
        return -1;
    }
    void criarUsuario(std::string user, std::string name, std::string password){
        if (pesquisarUsuario(user) != -1) {
        std::cout << "Erro: Nome de usuário '" << user << "' já existe." << std::endl;
        return;
        Usuario novoUsuario(user, name, password);
        usuarios.push_back(novoUsuario);
        std::cout << "Usuário criado com sucesso" << std::endl;
        }
    }
    void atualizarUsuario(){}
    void deletarUsuario(){}
    void lerListarUsuario(){
        if (usuarios.empty()){
            std::cout << "Nenhum usuário cadastrado" << std::endl;
            return ;
        }
        std::cout << "--- Lista de Usuários ---" << std::endl;
        for (auto user : usuarios){
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