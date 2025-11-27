#include "Gerenciador.hpp"
#include <vector>
#include "GeradorVetor.hpp"

std::vector<std::vector<int>> Gerenciador::gerarVetorDeVetores(int tam, std::function<std::vector<int>(int tam)> gerarVetor)
{
    std::vector<std::vector<int>> vetorDeVetores;
    for (int i = 0; i < 10; i++)
    {
        vetorDeVetores.push_back(gerarVetor(tam));
    }
    return vetorDeVetores;
}

void Gerenciador::rodar10vzsMesmoVetor(std::function<void(std::vector<int> &vec)> ordenacao, std::vector<int> vetor)
{
    double somaTempos = 0.0;
    double somaComparacoes = 0.0;
    double somaTrocas = 0.0;
    for (int i = 0; i < 10; i++)
    {
        Ordenacao::zerarDados();
        std::vector<int> copiaVetor = vetor; // cria uma cópia do vetor original para cada iteração
        Ordenacao::medirTempo(ordenacao, copiaVetor);
        somaTempos += Ordenacao::tempoExecucao;
        somaTrocas += Ordenacao::trocas;
        somaComparacoes += Ordenacao::comparacoes;
    }
    std::cout << "Media de Trocas: " << somaTrocas / 10 << "\n";
    std::cout << "Media de Comparacoes: " << somaComparacoes / 10 << "\n";
    std::cout << "Media de Tempo: " << somaTempos / 10 << "\n";
}

std::vector<std::vector<int>> Gerenciador::gerarVetorDeVetoresIguais(int tam, std::function<std::vector<int>(int tam)> gerarVetor)
{
    std::vector<std::vector<int>> vetorDeVetores;
    std::vector<int> vetorInicial = gerarVetor(tam);
    for (int i = 0; i < 5; i++)
    {
        vetorDeVetores.push_back(vetorInicial);
    }
    return vetorDeVetores;
}

void Gerenciador::rodar10vzsVetorAleatorio(std::function<void(std::vector<int> &vec)> ordenacao, std::vector<int> vetor)
{
    double somaTrocas = 0.0;
    double somaComparacoes = 0.0;
    double somaTempo = 0.0;

    for (int i = 0; i < 10; i++)
    {
        std::vector<int> copiaVetor = vetor; // cria uma cópia do vetor original
        Ordenacao::zerarDados(); // zera antes de cada execução
        Ordenacao::medirTempo(ordenacao, copiaVetor);

        somaTrocas += Ordenacao::trocas;
        somaComparacoes += Ordenacao::comparacoes;
        somaTempo += Ordenacao::tempoExecucao;
    }
    Ordenacao::trocas = somaTrocas / 10.0;
    Ordenacao::comparacoes = somaComparacoes / 10.0;
    Ordenacao::tempoExecucao = somaTempo / 10.0;
}


void Gerenciador::testarVetoresAleatorios(std::function<void(std::vector<int> &vec)> ordenacao, std::vector<std::vector<int>> vetor)
{
    double somaMediasTrocas = 0.0;
    double somaMediaTempo = 0.0;
    double somaMediaComparacoes = 0.0;
    for (std::vector<int> vet : vetor)
    {
        rodar10vzsVetorAleatorio(ordenacao, vet);
        // medias do vetor individual da iteração
        double mediaTrocas = Ordenacao::trocas / 10.0;
        double mediaComparacoes = Ordenacao::comparacoes / 10.0;
        double mediaTempo = Ordenacao::tempoExecucao / 10.0;

        somaMediasTrocas += mediaTrocas;
        somaMediaTempo += mediaTempo;
        somaMediaComparacoes += mediaComparacoes;
    }
    std::cout << "Media final de Trocas: " << somaMediasTrocas / 10 << "\n";
    std::cout << "Media final de Comparacoes: " << somaMediaComparacoes / 10 << "\n";
    std::cout << "Media final de Tempo: " << somaMediaTempo / 10 << "\n";
}

std::vector<std::vector<int>> Gerenciador::fazerCopias(const std::vector<int>& vec, int quant) {
    std::vector<std::vector<int>> copias;
    for(int i = 0; i < quant; i++) {
        std::vector<int> copia = vec;
        copias.push_back(copia);
    }
    return copias;
}
void Gerenciador::fazerTestes(int tam) {
    std::vector<int> vetorOrdenado = GeradorVetor::gerarVetorCrescente(tam);
    std::vector<int> vetorInverso = GeradorVetor::gerarVetorDecrescente(tam);
    std::vector<std::vector<int>> vetoresAleatorio = gerarVetorDeVetores(tam, GeradorVetor::gerarVetorAleatorio);
    std::vector<std::vector<int>> vetoresQuaseOrd = gerarVetorDeVetores(tam, GeradorVetor::gerarVetorQuaseOrdenado);
    std::vector<std::vector<int>> copias = fazerCopias(vetorOrdenado, 6);
    std::cout << "-- Vetor ordenado --" << std::endl;
    std::cout << "Bubble Sort" << std::endl;
    rodar10vzsMesmoVetor(Ordenacao::bubbleSort, copias[0]);
    std::cout << std::endl;
    std::cout << "Insert Sort" << std::endl;
    rodar10vzsMesmoVetor(Ordenacao::insertionSort, copias[1]);
    std::cout << std::endl;
    std::cout << "Selection Sort" << std::endl;
    rodar10vzsMesmoVetor(Ordenacao::selectionSort, copias[2]);
    std::cout << std::endl;
    std::cout << "Quick Sort Lomuto" << std::endl;
    rodar10vzsMesmoVetor(Ordenacao::quickSortLomuto, copias[3]);
    std::cout << std::endl;
    std::cout << "Quick Sort Hoare" << std::endl;
    rodar10vzsMesmoVetor(Ordenacao::quickSortHoare, copias[4]);
    std::cout << std::endl;
    std::cout << "Merge Sort" << std::endl;
    rodar10vzsMesmoVetor(Ordenacao::mergeSort, copias[5]);
    std::cout << std::endl;

}

void Gerenciador::executarTestes(int tam)
{ 
    fazerTestes(1000);
    fazerTestes(10000);
    fazerTestes(100000);
    fazerTestes(1000000);
}