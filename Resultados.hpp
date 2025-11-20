#ifndef RESULTADOS_HPP
#define RESULTADOS_HPP

#include <chrono>
class Resultados
{
	public:
		long long trocas;
        long long comparacoes;
        long long tempo;
        Resultados(): trocas(0), comparacoes(0), tempo(0) {}
};

#endif