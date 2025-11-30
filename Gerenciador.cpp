#include "Gerenciador.hpp"
#include <vector>
#include "GeradorVetor.hpp"


/*std::vector<std::vector<int>> Gerenciador::fazerCopias(const std::vector<int> &vec, int quant)
{
    std::vector<std::vector<int>> copias;
    for (int i = 0; i < quant; i++)
    {
        std::vector<int> copia = vec;
        copias.push_back(copia);
    }
    return copias;
}*/

/*std::vector<std::vector<std::vector<int>>> Gerenciador::fazerCopias(const std::vector<std::vector<int>> &vec, int quant)
{
    std::vector<std::vector<std::vector<int>>> copias;
    for (int i = 0; i < quant; i++)
    {
        std::vector<std::vector<int>> copia = vec;
        copias.push_back(copia);
    }
    return copias;
}*/

/*void Gerenciador::vetoresOrdenadosEinversamente(std::vector<std::vector<int>> &copiasVec, const std::vector<std::string> &nomesAlgoritmos, const std::vector<std::function<void(std::vector<int> &vec)>> &vetorDefuncoes, const std::string &cenario)
{
    for (int i = 0; i < nomesAlgoritmos.size(); i++)
    {if ((cenario == "Vetor Ordenado" && copiasVec[i].size() >= 100000 &&
     (nomesAlgoritmos[i] == "Quick Sort Lomuto" || nomesAlgoritmos[i] == "Quick Sort Hoare")) ||
    (cenario == "Vetor Inversamente Ordenado" && copiasVec[i].size() >= 100000 &&
     nomesAlgoritmos[i] == "Quick Sort Lomuto" || nomesAlgoritmos[i] == "Quick Sort Hoare"))
        {
            std::cout << nomesAlgoritmos[i] << ": [Pulado para evitar overflow]\n";
            continue;
        }
        std::cout << "Algoritmo: " << nomesAlgoritmos[i] << std::endl;
        rodar10vzsMesmoVetor(vetorDefuncoes[i], copiasVec[i], cenario, nomesAlgoritmos[i]);
    }
}
*/
/*void Gerenciador::vetoresAleatoriosEquaseOrd(std::vector<std::vector<std::vector<int>>> &copiasVec, const std::vector<std::string> &nomesAlgoritmos, const std::vector<std::function<void(std::vector<int> &vec)>> &vetorDefuncoes, const std::string &cenario)
{
    for (int i = 0; i < nomesAlgoritmos.size(); i++)
    {
        std::cout << "Algoritmo: " << nomesAlgoritmos[i] << std::endl;
        testarVetoresAleatorios(vetorDefuncoes[i], copiasVec[i], cenario, nomesAlgoritmos[i]);
    }
}*/

/*void Gerenciador::rodarTodosOsAlgoritmos(int tam, const std::vector<std::string> &nomesAlgoritmos, const std::vector<std::function<void(std::vector<int> &vec)>> &vetorDefuncoes)
{
    vetorOrdenado = GeradorVetor::gerarVetorCrescente(tam);
    vetorInverso = GeradorVetor::gerarVetorDecrescente(tam);
    vetoresAleatorios = gerarVetorDeVetores(tam, GeradorVetor::gerarVetorAleatorio);
    vetoresQuaseOrd = gerarVetorDeVetores(tam, GeradorVetor::gerarVetorQuaseOrdenado);

    // ------------------- VETORES ORDENADOS -------------------
    std::vector<std::vector<int>> copias = fazerCopias(vetorOrdenado, 6);
    std::cout << "-- TESTES COM VETORES DE TAMANHO " << tam << " --\n\n";
    std::cout << "==================================================================\n";
    std::cout << "                VETORES ORDENADOS\n";
    std::cout << "==================================================================\n\n";
    vetoresOrdenadosEinversamente(copias, nomesAlgoritmos, vetorDefuncoes, "Vetor Ordenado");

    // ------------------- VETORES INVERSAMENTE ORDENADOS -------------------
    copias = fazerCopias(vetorInverso, 6);
    std::cout << "\n==================================================================\n";
    std::cout << "             VETORES INVERSAMENTE ORDENADOS\n";
    std::cout << "==================================================================\n\n";
    vetoresOrdenadosEinversamente(copias, nomesAlgoritmos, vetorDefuncoes, "Vetor Inversamente Ordenado");

    // ------------------- VETORES ALEATORIOS -------------------
    std::vector<std::vector<std::vector<int>>> copiasVetoresDesordenados = fazerCopias(vetoresAleatorios, 6);
    std::cout << "==================================================================\n";
    std::cout << "             VETORES ALEATORIOS\n";
    std::cout << "==================================================================\n";
    vetoresAleatoriosEquaseOrd(copiasVetoresDesordenados, nomesAlgoritmos, vetorDefuncoes, "Vetor aleatório");

    // ------------------- VETORES QUASE ORDENADOS -------------------
    copiasVetoresDesordenados = fazerCopias(vetoresQuaseOrd, 6);
    std::cout << "==================================================================\n";
    std::cout << "             VETORES QUASE ORDENADOS\n";
    std::cout << "==================================================================\n";
    vetoresAleatoriosEquaseOrd(copiasVetoresDesordenados, nomesAlgoritmos, vetorDefuncoes, "Vetor quase ordenado");

    std::cout << std::endl;
}*/

std::ofstream Gerenciador::resultados;

std::vector<std::vector<int>> Gerenciador::gerarVetorDeVetores(int tam, std::function<std::vector<int>(int tam)> gerarVetor)
{
    std::vector<std::vector<int>> vetorDeVetores;
    for (int i = 0; i < 10; i++)
    {
        vetorDeVetores.push_back(gerarVetor(tam));
    }
    return vetorDeVetores;
}

void Gerenciador::rodar10vzsMesmoVetor(std::function<void(std::vector<int> &vec)> ordenacao, std::vector<int> vetor, const std::string &cenario, const std::string &algoritmo)
{
    int tam = vetor.size();
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
    std::cout << "   " << "-Media de Trocas: " << somaTrocas / 10 << "\n";
    std::cout << "   " << "-Media de Comparacoes: " << somaComparacoes / 10 << "\n";
    std::cout << "   " << "-Media de Tempo: " << somaTempos / 10 << " milissegundos" << "\n";
    escrever(algoritmo, cenario, somaTrocas / 10, somaComparacoes / 10, somaTempos / 10, tam);
}

void Gerenciador::rodar10vzsVetorAleatorio(std::function<void(std::vector<int> &vec)> ordenacao, std::vector<int> vetor, double &mediaTrocas, double &mediaComp, double &mediaTempo)
{
    double somaTrocas = 0.0;
    double somaComparacoes = 0.0;
    double somaTempo = 0.0;

    for (int i = 0; i < 10; i++)
    {
        std::vector<int> copiaVetor = vetor; // cria uma cópia do vetor original
        Ordenacao::zerarDados();             // zera antes de cada execução
        Ordenacao::medirTempo(ordenacao, copiaVetor);

        somaTrocas += Ordenacao::trocas;
        somaComparacoes += Ordenacao::comparacoes;
        somaTempo += Ordenacao::tempoExecucao;
    }
    // médias das execuções individual do vetor
    mediaTrocas = somaTrocas / 10.0;
    mediaComp = somaComparacoes / 10.0;
    mediaTempo = somaTempo / 10.0;
}

void Gerenciador::testarVetoresAleatorios(std::function<void(std::vector<int> &vec)> ordenacao, std::vector<std::vector<int>> vetor, const std::string &cenario, const std::string &algoritmo)
{
    int tam = vetor[0].size();
    double somaMediasTrocas = 0.0;
    double somaMediaTempo = 0.0;
    double somaMediaComparacoes = 0.0;
    double mTrocas = 0.0; // vai armazenar a media das trocas da execução de um vetor só
    double mComp = 0.0;
    double mTempo = 0.0;
    for (std::vector<int> vet : vetor)
    {
        rodar10vzsVetorAleatorio(ordenacao, vet, mTrocas, mComp, mTempo);
        somaMediasTrocas += mTrocas;
        somaMediaTempo += mTempo;
        somaMediaComparacoes += mComp;
    }
    std::cout << "   " << "-Media final de Trocas: " << somaMediasTrocas / vetor.size() << "\n";
    std::cout << "   " << "-Media final de Comparacoes: " << somaMediaComparacoes / vetor.size() << "\n";
    std::cout << "   " << "-Media final de Tempo: " << somaMediaTempo / vetor.size() << " milissegundos" << "\n";
    escrever(algoritmo, cenario, somaMediasTrocas / vetor.size(), somaMediaComparacoes / vetor.size(), somaMediaTempo / vetor.size(), tam);
}

void Gerenciador::abrirArq(const std::string &nomeArq)
{
    resultados.open(nomeArq, std::ios::out);
    if (!resultados.is_open())
        std::cerr << "Erro ao abrir arquivo " << nomeArq << std::endl;
    resultados << "Cenario, Tamanho,  Algoritmo, trocas, comparações, tempo" << std::endl;
}

void Gerenciador::fecharArq()
{
    if (resultados.is_open())
        resultados.close();
}

void Gerenciador::escrever(const std::string &algoritmo, const std::string &cenario, double trocas, double comparacoes, double tempo, int tam)
{
    resultados << cenario << "," << tam << "," << algoritmo << "," << trocas << "," << comparacoes << "," << tempo << std::endl;
}
void Gerenciador::executarTestes(const std::string &nomeArq)
{
    abrirArq(nomeArq);
    std::vector<std::string> nomesAlgoritmos = {"Bubble Sort", "Insertion Sort", "Selection Sort", "Quick Sort Lomuto", "Quick Sort Hoare", "Merge Sort"};
    std::vector<std::function<void(std::vector<int> & vec)>> vetorDeFuncoes = {Ordenacao::bubbleSort, Ordenacao::insertionSort, Ordenacao::selectionSort, Ordenacao::quickSortLomuto, Ordenacao::quickSortHoare, Ordenacao::mergeSort};
    std::vector<std::string> cenarios = {"Vetor Ordenado", "Vetor Inversamente Ordenado", "Vetor aleatorio", "Vetor quase ordenado"};

    int tam = 10;
    while (tam <= 100000)
    {
        for (int i = 0; i < nomesAlgoritmos.size(); i++)
        {
             std::cout << "==================================================================\n";
             std::cout << "                " << nomesAlgoritmos[i] << "\n";
            std::cout << "==================================================================\n\n";
            for (const std::string &cenario : cenarios)
            {
                if(((nomesAlgoritmos[i] == "Bubble Sort" || nomesAlgoritmos[i] == "Insertion Sort" || nomesAlgoritmos[i] == "Selection Sort" || nomesAlgoritmos[i] == "Quick Sort Lomuto") && cenario == "Vetor quase ordenado" && tam == 10000) || (nomesAlgoritmos[i] ==  "Merge Sort" && (cenario == "Vetor Ordenado" || cenario == "Vetor Inversamente Ordenado") && tam >= 10000)) {
                    std::cout << "Pulando cenario: " << cenario << " para evitar stack overflow" << std::endl;
                } else {
                   testarAlgoritmoEmCenario(vetorDeFuncoes[i], nomesAlgoritmos[i], tam, cenario);
            
                }    
            }
            
        }

        tam = tam * 10;
    }
    fecharArq();
}
void Gerenciador::testarAlgoritmoEmCenario(const std::function<void(std::vector<int> &)> &algoritmo, const std::string &nomeAlgoritmo, int tam, const std::string &cenario)
{
    if (cenario == "Vetor Ordenado")
    {
        std::cout << cenario << " -- TAM: " << tam << std::endl;
        vetorOrdenado = GeradorVetor::gerarVetorCrescente(tam);
        rodar10vzsMesmoVetor(algoritmo, vetorOrdenado, cenario, nomeAlgoritmo);
    }
    else if (cenario == "Vetor Inversamente Ordenado")
    {
        std::cout << cenario << " -- TAM: " << tam << std::endl;
        vetorInverso = GeradorVetor::gerarVetorDecrescente(tam);
        rodar10vzsMesmoVetor(algoritmo, vetorInverso, cenario, nomeAlgoritmo);
    }
    else if (cenario == "Vetor aleatorio")
    {
        std::cout << cenario << " -- TAM: " << tam << std::endl;
        vetoresAleatorios = gerarVetorDeVetores(tam, GeradorVetor::gerarVetorAleatorio);
        testarVetoresAleatorios(algoritmo, vetoresAleatorios, cenario, nomeAlgoritmo);
    }
    else if (cenario == "Vetor quase ordenado")
    {
        std::cout << cenario << " -- TAM: " << tam << std::endl;
        vetoresQuaseOrd = gerarVetorDeVetores(tam, GeradorVetor::gerarVetorQuaseOrdenado);
        testarVetoresAleatorios(algoritmo, vetoresQuaseOrd, cenario, nomeAlgoritmo);
    }
    else
    {
        std::cout << cenario << " -- TAM: " << tam << std::endl;
    }
}