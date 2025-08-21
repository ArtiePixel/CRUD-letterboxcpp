#include "Biblioteca.hpp"
#pragma once

class Audiobook : public Biblioteca {
    private:
    float duracao;
    std::string narrador;

    public:
    Audiobook(){}

    void exibir(){
        Biblioteca::exibir();
        std::cout << "Duração: " << duracao << std::endl;
        std::cout << "Narrador: " << narrador << std::endl;
    }
};
