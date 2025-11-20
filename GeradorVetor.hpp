#ifndef GERADORVETOR_HPP
#define GERADORVETOR_HPP


#include <vector>
#include <random>
class GeradorVetor
{
    public:
        static std::vector<int> gerarVetorAleatorio(int tamanho);
        static std::vector<int> gerarVetorCrescente(int tamanho);
        static std::vector<int> gerarVetorDecrescente(int tamanho);
        static std::vector<int> gerarVetorQuaseOrdenado(int tamanho);
};  

#endif