#ifndef CONTROLADORAS_HPP_INCLUDED
#define CONTROLADORAS_HPP_INCLUDED

#include "interfaces.hpp"
#include "entidades.hpp"
#include "dominios.hpp"

#include <stdexcept>
#include <iostream>

using namespace std;

// ---------------------------------------------------------------------------------
// Declaração de classe controladora e implementação de método.

class CntrApresentacaoAutenticacao:public IApresentacaoAutenticacao {
private:
    IServicoAutenticacao *cntrServicoAutenticacao;        // Referência para servidor.
public:
    bool autenticar(Codigo*);
    void setCntrServicoAutenticacao(IServicoAutenticacao*);
};

void inline CntrApresentacaoAutenticacao::setCntrServicoAutenticacao(IServicoAutenticacao *cntrServicoAutenticacao){
        this->cntrServicoAutenticacao = cntrServicoAutenticacao;
}

class CntrIEntidadesServico:public IEntidadesServico {
private:
    ILNEntidadesServico *cntrLNEntidadesServico;

public:
    bool celo();

    void setCntrLNEntidadesServico(ILNEntidadesServico*);
};

void inline CntrIUEntidadesServico::setCntrLNEntidadesServico(ILNEntidadesServico *cntrLNEntidadesServico){
    this->cntrLNEntidadesServico = cntrLNEntidadesServico;
};

#endif // CONTROLADORAS_HPP_INCLUDED
