#include <iostream>
#include <vector>
#include "Ordenacao.hpp"
#include "Gerenciador.hpp"
#include "GeradorVetor.hpp"


int main() {
   std::cout << "Programa iniciou" << std::endl;
    Gerenciador g;
    g.executarTestes("resultados.csv");
    return 0;
}


