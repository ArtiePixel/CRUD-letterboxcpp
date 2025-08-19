#include "Biblioteca.hpp"
#pragma once

class HQ : public Biblioteca{
    private:
    std::string colecao, volume;

    public:
    HQ(){}

    void exibir() override{
        Biblioteca::exibir();
        std::cout << "Colecao: " << colecao << "\nVolume: " << volume << std::endl;
    }

};