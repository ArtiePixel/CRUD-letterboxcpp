#include "Biblioteca.hpp"
#include <string>
#pragma once

class Audiobook : public Biblioteca{
    private:
    std::string narrador;
    float duracao;

    public:
    Audiobook(){}

    void exibir() override{
        Biblioteca::exibir();
        std::cout << "Narrador: " << narrador << std::endl;
        std::cout << "Duração: " << duracao << std::endl;
    }

};