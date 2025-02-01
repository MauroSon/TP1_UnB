#ifndef CONTROLADORAS_HPP_INCLUDED
#define CONTROLADORAS_HPP_INCLUDED

#include "interfaces.hpp"
#include "entidades.hpp"
#include "dominios.hpp"

#include <stdexcept>
#include <iostream>

using namespace std;

// Controladora de Apresentação de Autenticação
class CntrApresentacaoAutenticacao : public IApresentacaoAutenticacao {
private:
    IServicoAutenticacao* cntrServicoAutenticacao;
public:
    bool autenticar(Codigo*);
    void setCntrServicoAutenticacao(IServicoAutenticacao*);
};

// Controladora de Apresentação de Conta
class CntrApresentacaoConta : public IApresentacaoConta {
private:
    IServicoConta* cntrServicoConta;
public:
    void criar();
    void executar(Codigo);
    void setCntrServicoConta(IServicoConta*);
};

// Controladora de Apresentação de Entidades
class CntrApresentacaoEntidades : public IApresentacaoEntidades {
private:
    IServicoEntidades* cntrServicoEntidades;
public:
    void executar(Codigo);
    void setCntrServicoEntidades(IServicoEntidades* cntrServicoEntidades);
};
#endif // CONTROLADORAS_HPP_INCLUDED
