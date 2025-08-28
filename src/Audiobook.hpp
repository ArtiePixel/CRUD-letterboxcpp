#pragma once
#include "Biblioteca.hpp"

class Audiobook : public Biblioteca {
    private:
    float duracao;
    std::string narrador;

    public:
    Audiobook(std::string t, std::string a, std::string e, int d, float n, float du, std::string na)
    : Biblioteca(t, a, e, d, n) {
        duracao = du;
        narrador = na;
    }

    void exibir() override {
        Biblioteca::exibir();
        std::cout << "Duracao: " << duracao << std::endl;
        std::cout << "Narrador: " << narrador << std::endl;
    }
    
    float getDuracao() const { return duracao; }
    std::string getNarrador() const { return narrador; }
};