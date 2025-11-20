#include<iostream>
#include<vector>
#include"Ordenacao.hpp"
#include"Resultados.hpp"    
int main() {
    std::vector<int> vec = {2, 1, 4, 3};
    Resultados resultados;
    resultados.tempo = Ordenacao::medirTempo(Ordenacao::bubbleSort, vec, resultados);
    std::cout << resultados.comparacoes << " comparacoes, " << resultados.trocas << " trocas." << std::endl;
    std::cout << "Tempo de execucao: " << resultados.tempo << " microsegundos." << std::endl;
    for(int num : vec) {
        std::cout << num << " ";
    }
    return 0;
}