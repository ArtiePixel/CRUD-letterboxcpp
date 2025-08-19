#include <iostream>

class Biblioteca{
    protected:
    std::string titulo, autor, editora;
    int data;
    float nota;

    public:
    Biblioteca(){}

    virtual void exibir(){
        std::cout << "Titulo: " << titulo << "\nAutor: " << autor << "\nEditora: " << editora << "\nAno: " << data << "\nNota: " << nota << std::endl;
    }

};