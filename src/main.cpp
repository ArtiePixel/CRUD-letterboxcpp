#include <iostream>
#include <string>
#include <vector>
#include <memory>  // unique_ptr e make_unique

#include "CRUD.hpp"
#include "Usuario.hpp"
#include "Livro.hpp"
#include "HQ.hpp"
#include "Audiobook.hpp"

void menuUsuario(Usuario& usuarioLogado) {
    int opcao = -1;
    while (opcao != 0) {
        std::cout << "\n===== DIARIO DE LEITURA ====="<< std::endl;
        std::cout << "1 - Cadastrar leitura" << std::endl;
        std::cout << "2 - Listar leituras" << std::endl;
        std::cout << "3 - Exibir uma leitura" << std::endl;
        std::cout << "4 - Editar uma leitura" << std::endl;
        std::cout << "5 - Excluir uma leitura" << std::endl;
        std::cout << "6 - Exibir relarório de leituras" << std::endl;
        std::cout << "0 - Deslogar" << std::endl;
        std::cout << "Opcao: ";
        std::cin >> opcao;
        std::cin.ignore();

        switch (opcao) {
            case 0:
                std::cout << "Deslogando..." << std::endl;
                usuarioLogado.salvarLeituras();
                break;

            case 1: {
                std::cout << "\nQual tipo de leitura deseja cadastrar?" << std::endl;
                std::cout << "1 - Livro" << std::endl;
                std::cout << "2 - HQ" << std::endl;
                std::cout << "3 - Audiobook" << std::endl;
                std::cout << "Opcao: ";
                
                int tipoLeitura;
                std::cin >> tipoLeitura;
                std::cin.ignore();
                
                if (tipoLeitura >= 1 && tipoLeitura <= 3) {
                    usuarioLogado.adicionarLeitura(tipoLeitura);
                    usuarioLogado.salvarLeituras();
                } else {
                    std::cout << "Opcao invalida." << std::endl;
                }
                break;
            }

            case 2:
                usuarioLogado.listarLeitura();
                break;
            case 3:
                usuarioLogado.exibirLeitura();
                break;
            case 4:
               usuarioLogado.editarLeitura();
                break;
            case 5:
                /* code */
                break;
            case 6:
                /* code */
                break;
            default:
                std::cout << "Opção inválida." << std::endl;
                break;
        }
    }
}

int main(){
     CRUD gerenciadorUsuarios;
     gerenciadorUsuarios.carregarUsuario();

    int opcao = -1;
    while (opcao != 0) {
        std::cout << "\n===== BEM-VINDO(A) AO DIARIO DE LEITURA =====" << std::endl;
        std::cout << "1 - Fazer login" << std::endl;
        std::cout << "2 - Cadastrar novo usuario" << std::endl;
        std::cout << "3 - Listar usuarios" << std::endl;
        std::cout << "4 - Atualizar usuario" << std::endl;
        std::cout << "5 - Deletar usuario" << std::endl;
        std::cout << "0 - Sair" << std::endl;
        std::cout << "Opcao: ";
        std::cin >> opcao;
        std::cin.ignore();
    
        switch (opcao) {
             case 0: {
                std::cout << "Saindo..." << std::endl;
                gerenciadorUsuarios.salvarUsuario();
                break;
            }
            case 1: {
                std::cout << "\n===== LOGIN =====" << std::endl;
                std::string user, senha;
                std::cout << "Usuario: ";
                std::getline(std::cin, user);
                std::cout << "Senha: ";
                std::getline(std::cin, senha);

                Usuario* usuarioLogado = gerenciadorUsuarios.autenticarUsuario(user, senha);
                if (usuarioLogado != nullptr) {
                    std::cout << "\nLogin bem-sucedido." << std::endl;
                    menuUsuario(*usuarioLogado);
                } else {
                    std::cout << "\nFalha no login." << std::endl;
                }
                break;
            }

            case 2: {
                std::string user, name, senha;
                std::cout << "\n===== CADASTRO =====" << std::endl;
                std::cout << "Usuario: ";
                std::getline(std::cin, user);
                std::cout << "Nome: ";
                std::getline(std::cin, name);
                std::cout << "Senha: ";
                std::getline(std::cin, senha);
                gerenciadorUsuarios.criarUsuario(user, name, senha);
                break;
            }

             case 3: {
                std::cout << "\n===== USUARIOS =====" << std::endl;
                gerenciadorUsuarios.lerListarUsuario();
                break;
            }

            case 4: {
                std::cout << "\n===== ATUALIZAR USUARIO =====" << std::endl;
                gerenciadorUsuarios.atualizarUsuario();
                break;
            }

            case 5: {
                std::cout << "\n=====DELETAR USUARIO =====" << std::endl;
                gerenciadorUsuarios.deletarUsuario();
                break;
            }

            default: {
                std::cout << "Opção invalida." << std::endl;
                break;
            }
        }
    }
    return 0; 
}
