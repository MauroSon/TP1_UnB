#ifndef STUBS_HPP_INCLUDED
#define STUBS_HPP_INCLUDED

#include "interfaces.hpp"

// -------------------------------------------------------------------------------------------
// Declaração de classe stub.
//
// Classe StubServicoAutenticacao implementa a interface IServicoAutenticacao.

class StubServicoAutenticacao:public IServicoAutenticacao{

private:

    const static string TRIGGER_FALHA_AUTENTICACAO;
    const static string TRIGGER_ERRO_SISTEMA_AUTENTICACAO;

public:

    bool autenticar(const Codigo&, const Senha&);
};

// Classe StubContaServiço implementa a interface IContaServiço.

class StubContaServico:public IContaServico{

private:

    const static string TRIGGER_FALHA_AUTENTICACAO;
    const static string TRIGGER_ERRO_SISTEMA_AUTENTICACAO;

public:

    bool criar(Conta*);
    bool excluir(Codigo*);
    bool ler(Conta*);
    bool atualizar(Conta*);
};

#endif // STUBS_HPP_INCLUDED
