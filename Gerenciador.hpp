#ifndef GERENDIADOR_HPP
#define GERENDIADOR_HPP
#include <iostream>
#include <vector>
#include "Ordenacao.hpp"
#include "GeradorVetor.hpp"
#include <functional>

class Gerenciador
{

public:
    // função geral para executar todos os métodos
    void executarTestes(int tam);

private:
    void rodar10vzsMesmoVetor(std::function<void(std::vector<int> &vec)> ordenacao, std::vector<int> vetor); // retorna a media de tempo do algotitmo para o mesmo vetor executado 10 vzs
    // retorna um vetor de vetores para testar cada um em outra função
    // essa função vai ser usada para os testes com vetores aleatorios e quase ordenados, pois possuem comportamentos não determinísticos
    std::vector<std::vector<int>> gerarVetorDeVetores(int tam, std::function<std::vector<int>(int tam)> gerarVetor);
    // método usado para gerar um vetor que contém cópias de um vetor (ordenado/inversamente ordenado)
    std::vector<std::vector<int>> gerarVetorDeVetoresIguais(int tam, std::function<std::vector<int>(int tam)> gerarVetor);
    void testarVetoresAleatorios(std::function<void(std::vector<int> &vec)> ordenacao, std::vector<std::vector<int>> vetor);
    void rodar10vzsVetorAleatorio(std::function<void(std::vector<int> &vec)> ordenacao, std::vector<int> vetor);
    std::vector<std::vector<int>> fazerCopias(const std::vector<int>& vec, int quant);
    void fazerTestes(int tam);
};

#endif