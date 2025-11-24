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

/*Medias Gerenciador::rodar10vzsMesmoVetor(std::function<void(std::vector<int> &vec)> ordenacao, std::vector<int> vetor)
{
    double somaTempos = 0.0;
    double somaComparacoes = 0.0;
    double somaTrocas = 0.0;
    for (int i = 0; i < 10; i++)
    {
        Ordenacao::zerarDados();
        std::vector<int> copiaVetor = vetor; // cria uma cópia do vetor original para cada iteraçã
        somaTempos += Ordenacao::medirTempo(ordenacao, copiaVetor);
        somaTrocas += Ordenacao::getTrocas();
        somaComparacoes += Ordenacao::getComparacoes();
    }
    Medias m{somaTempos / 10, somaTrocas / 10, somaComparacoes / 10};
    return m;
}*/

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

void Gerenciador::executarTestes()
{

}