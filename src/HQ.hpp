#pragma once
#include "Biblioteca.hpp"

class HQ : public Biblioteca{
    private:
    std::string colecao, volume;

    public:
    HQ(std::string t, std::string a, std::string e, int d, float n, std::string c, std::string v) 
        : Biblioteca(t, a, e, d, n) {
        colecao = c;
        volume = v;
    }

    void exibir() override{
        Biblioteca::exibir();
        std::cout << "Colecao: " << colecao << "\nVolume: " << volume << std::endl;
    }
    
    std::string getColecao() const { return colecao; }
    std::string getVolume() const { return volume; }
};