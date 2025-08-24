#include <iostream>

int main(){

    int opcao = 1;

    while(opcao != 0) {

        std::cout << "\n===== DIARIO DE LEITURA =====" << std::endl;
        std::cout << "1 - Cadastrar leitura" << std::endl;
        std::cout << "2 - Listar leituras" << std::endl;
        std::cout << "3 - Exibir uma leitura" << std::endl;
        std::cout << "4 - Editar uma leitura" << std::endl;
        std::cout << "5 - Excluir uma leitura" << std::endl;
        std::cout << "6 - Exibir relarório de leituras" << std::endl;
        std::cout << "0 - Sair\n" << std::endl;

        std::cin >> opcao;

        switch (opcao) {
        case 1:

            std::cout << "\nQual tipo de leitura deseja cadastrar?" << std::endl;
            std::cout << "1 - Livro" << std::endl;
            std::cout << "2 - HQ" << std::endl;
            std::cout << "3 - Audiobook" << std::endl;

            int a;
            std::cin >> a;

            break;
        
        case 2:
            /* code */
            break;
        
        case 3:
            /* code */
            break;
        
        case 4:
            /* code */
            break;
        
        case 5:
            /* code */
            break;

        case 6:
            /* code */
            break;
        
        default:
            std::cout << "Opcao invalida\n" << std::endl;
            break;
        }
    }




    return 0; 
}
