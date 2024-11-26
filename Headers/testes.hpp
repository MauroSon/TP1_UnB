#ifndef TESTES_HPP_INCLUDED
#define TESTES_HPP_INCLUDED
include <stdexcept>
#include "dominios.hpp"
using namespace std;

class TUAvaliacao {
    private:
        const static int VALOR_VALIDO = 5;
        const static int VALOR_INVALIDO = 6;
        Avaliacao *avaliacao;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioValorValido();
        void testarCenarioValorInvalido();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};



#endif // TESTES_HPP_INCLUDED
