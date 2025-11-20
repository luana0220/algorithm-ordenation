#include<iostream>
#include<vector>
#include "Ordenacao.hpp"
#include "Resultados.hpp" 
#include "GeradorVetor.hpp" 

std::vector<std::vector<int>> iteracaoVetorAleatorio(int tam) {
    std::vector<std::vector<int>> vetoresAleatorios;
    for(int i = 0; i < 2; i++) {
        vetoresAleatorios.push_back(GeradorVetor::gerarVetorAleatorio(tam));
    }
    return vetoresAleatorios;
}

double rodar10vzs(std::vector<int> vetor, Resultados& r) {
    double somaTempos = 0.0;
    for(int i = 0; i < 10; i++) {
        std::vector<int> copiaVetor = vetor; // cria uma cópia do vetor original para cada iteração
        r.tempo = Ordenacao::medirTempo(Ordenacao::selectionSort, vetor, r);
        somaTempos += r.tempo;
    }
    return somaTempos / 10.0;
}

int main() {
    /*
    std::vector<int> vec = {2, 1, 4, 3};
    Resultados resultados;
    resultados.tempo = Ordenacao::medirTempo(Ordenacao::bubbleSort, vec, resultados);
    std::cout << resultados.comparacoes << " comparacoes, " << resultados.trocas << " trocas." << std::endl;
    std::cout << "Tempo de execucao: " << resultados.tempo << " microsegundos." << std::endl;
    for(int num : vec) {
        std::cout << num << " ";
    }

    std::vector<int> vecCrescente = GeradorVetor::gerarVetorCrescente(10);
    std::cout << "\nVetor Crescente: "; 
    for(int num : vecCrescente) {
        std::cout << num << " ";
    }
    std::vector<int> vecDecrescente = GeradorVetor::gerarVetorDecrescente(10);
    std::cout << "\nVetor Decrescente: ";   
    for(int num : vecDecrescente) {
        std::cout << num << " ";
    }
    std::vector<int> vecAleatorio = GeradorVetor::gerarVetorAleatorio(10);
    std::cout << "\nVetor Aleatorio: ";
    for(int num : vecAleatorio) {
        std::cout << num << " ";
    }
    std::vector<int> vecQuaseOrdenado = GeradorVetor::gerarVetorQuaseOrdenado(10);
    std::cout << "\nVetor Quase Ordenado: ";
    for(int num : vecQuaseOrdenado) {
        std::cout << num << " ";
    }*/
   double somaSelectionSort = 0.0;
   std::vector<std::vector<int>> vetores = iteracaoVetorAleatorio(1000);
   std::vector<Resultados> resultadosVetorAleatorio(2);
   for(int i = 0; i < vetores.size(); i++) {
       double mediaDeUmVetor = rodar10vzs(vetores[i], resultadosVetorAleatorio[i]);
       somaSelectionSort += mediaDeUmVetor;
   }
   double mediaFinalSelectionSort = somaSelectionSort / vetores.size();
   std::cout << "Media final do Selection Sort para vetores aleatorios de tamanho 10: " << mediaFinalSelectionSort << " microsegundos." << std::endl;
    return 0;
}