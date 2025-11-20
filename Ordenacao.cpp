#include "Ordenacao.hpp"

void Ordenacao::troca(int& a, int& b, Resultados& resultados)
{
    int temp = a;
    a = b;
    b = temp;
    resultados.trocas++;
}

//metodos privados quick Sort Lomuto
int Ordenacao::particionaLomuto(std::vector<int>& vec, int inicio, int fim, Resultados& resultados)
{
   int pivo = vec[fim];
   int i = inicio - 1;
   for(int j = inicio; j < fim; j++)

   {
       resultados.comparacoes++;
       if(vec[j] <= pivo)
       {
           i++;
           troca(vec[i], vec[j], resultados);
       }
   }
   troca(vec[i + 1], vec[fim], resultados);
   return i + 1;
}

void Ordenacao::quickSortLomutoRec(std::vector<int>& vec, int inicio, int fim, Resultados& resultados)
{
   if(inicio < fim)
   {
       int pivoIndice = particionaLomuto(vec, inicio, fim, resultados);
       quickSortLomutoRec(vec, inicio, pivoIndice - 1, resultados);
       quickSortLomutoRec(vec, pivoIndice + 1, fim, resultados);
   }
}

// metodo public quick Sort Lomuto
void Ordenacao::quickSortLomuto(std::vector<int>& vec, Resultados& resultados)
{
   quickSortLomutoRec(vec, 0, vec.size() - 1, resultados);
}

void Ordenacao::selectionSort(std::vector<int> &vec, Resultados& resultados)
{
    int tam = vec.size();
    for (int i = 0; i < tam - 1; i++)
    {
        int indiceMenor = i;
        for (int j = i + 1; j < tam; j++)
        {
            resultados.comparacoes++;
            if (vec[j] < vec[indiceMenor])
            {
                indiceMenor = j;
            }
        }
        if (indiceMenor != i)
        {
            troca(vec[i], vec[indiceMenor], resultados);
        }
    }
}

void Ordenacao::bubbleSort(std::vector<int> &vec, Resultados& resultados)
{
    int tam = vec.size();
    for (int i = 0; i < tam - 1; i++)
    {
        bool trocou = false;
        for (int j = 0; j < tam - i - 1; j++)
        {
            resultados.comparacoes++;
            if (vec[j] > vec[j + 1])
            {
                troca(vec[j], vec[j + 1], resultados);
                trocou = true;
            }
        }
        if (!trocou)
            break;
    }
}

void Ordenacao::insertionSort(std::vector<int> &vec, Resultados& resultados)
{
    int tam = vec.size();
    for (int i = 1; i < tam; i++)
    {
        int chave = vec[i];
        int j = i - 1;
        resultados.comparacoes += 2; // +=2 porque são feitas duas comparações no while
        while (j >= 0 && vec[j] > chave)
        {
            vec[j + 1] = vec[j];
            resultados.trocas++; // na vdd são movimentações, mas para simplificar, contamos como trocas
            j--;
        }
        vec[j + 1] = chave;
        resultados.trocas++; //na vdd é uma movimentação, mas para simplificar, contamos como troca
    }
}

//função para medir tempo de execução
long long Ordenacao::medirTempo(std::function<void(std::vector<int>&, Resultados&)> funcaoOrdenacao, std::vector<int>& vec, Resultados& resultados)
{
    auto inicio = std::chrono::high_resolution_clock::now();
    funcaoOrdenacao(vec, resultados);
    auto fim = std::chrono::high_resolution_clock::now();
    auto duracao = std::chrono::duration_cast<std::chrono::microseconds>(fim - inicio).count();
    resultados.tempo = duracao;
    return duracao;
}