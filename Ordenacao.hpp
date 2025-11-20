#ifndef ORDENACAO_HPP
#define ORDENACAO_HPP
#include <iostream>
#include <vector>
#include "Resultados.hpp"
#include <functional>

class Ordenacao
{
    public:
        static void bubbleSort(std::vector<int>& vec, Resultados& resultados);
        static void selectionSort(std::vector<int>& vec, Resultados& resultados);
        static void insertionSort(std::vector<int>& vec, Resultados& resultados);
        static void quickSortLomuto(std::vector<int>& vec, Resultados& resultados);
        
        static void troca(int &a, int &b, Resultados& resultados);
        //std::function é para receber qualquer função de ordenação, e medir o tempo dela
        static long long medirTempo(std::function<void(std::vector<int>&, Resultados&)> funcaoOrdenacao, std::vector<int>& vec, Resultados& resultados);
    private:
        static int particionaLomuto(std::vector<int>& vec, int inicio, int fim, Resultados& resultados);
        static void quickSortLomutoRec(std::vector<int>& vec, int inicio, int fim, Resultados& resultados);
};

#endif