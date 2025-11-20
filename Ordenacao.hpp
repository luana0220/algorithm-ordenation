#ifndef ORDENACAO_HPP
#define ORDENACAO_HPP
#include <iostream>
#include <vector>
#include "Resultados.hpp"
#include <functional> // biblioteca para std::function

class Ordenacao
{
    public:
        static void bubbleSort(std::vector<int>& vec, Resultados& resultados); //flutua o maior elemento para o final do vetore vai  diminuindo o tamanho do vetor a cada iteração
        static void selectionSort(std::vector<int>& vec, Resultados& resultados); //seleciona o menor elemento e troca com o primeiro elemento do vetor não ordenado
        static void insertionSort(std::vector<int>& vec, Resultados& resultados); //insere o elemento na posição correta do vetor ordenado
        static void quickSortLomuto(std::vector<int>& vec, Resultados& resultados); // usa o método de partição de Lomuto(último elemento como pivô)
        static void quickSortHoare(std::vector<int>& vec, Resultados& resultados);
        static void troca(int &a, int &b, Resultados& resultados); // função implementada para facilitar a contagem de trocas
        //std::function é para receber qualquer função de ordenação, e medir o tempo dela
        static long long medirTempo(std::function<void(std::vector<int>&, Resultados&)> funcaoOrdenacao, std::vector<int>& vec, Resultados& resultados); // calcula o tempo de execução da função de ordenação
    private:
    //funções privadas de quick sort lomuto e hoare
        static int particionaLomuto(std::vector<int>& vec, int inicio, int fim, Resultados& resultados);
        static void quickSortLomutoRec(std::vector<int>& vec, int inicio, int fim, Resultados& resultados);
        static int particionaHoare(std::vector<int>& vec, int inicio, int fim, Resultados& resultados);
        static void quickSortHoareRec(std::vector<int>& vec, int inicio, int fim, Resultados& resultados);
};

#endif