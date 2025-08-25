#include "Usuario.hpp"
#include <vector>
#include <iostream>

class CRUD{
    private:
    std::vector<Usuario> usuarios;

    public:
    void criarUsuario(std::string user, std::string name, std::string password){
        Usuario novoUsuario(user, name, password);
        usuarios.push_back(novoUsuario);
        std::cout << "Usuário criado com sucesso" << std::endl;
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
            user.getNome();
        }
        std::cout << "-------------------------" << std::endl;
    }
    int pesquisarUsuario(std::string name){
        for(int i = 0; i < usuarios.size(); i++){
            if (usuarios[i].getNome() == name){
                return i;
            }
        }
        return -1;
    }
};
