#ifndef STUBS_HPP_INCLUDED
#define STUBS_HPP_INCLUDED

#include "interfaces.hpp"
#include <stdexcept>
#include <bits/stdc++.h>
using namespace std;

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

class StubLNEntidadesServico:public ILNEntidadesServico {
private:
    const static int TRIGGER_FALHA = 67890;
    const static int TRIGGER_ERRO_SISTEMA = 78901;

public:

    bool criar(const Viagem&);
    bool excluir(const Viagem&);
    bool ler(const Viagem&);
    bool atualizar(const Viagem&);

    bool criar(const Atividade&);
    bool excluir(const Atividade&);
    bool ler(const Atividade&);
    bool atualizar(const Atividade&);

    bool criar(const Destino&);
    bool excluir(const Destino&);
    bool ler(const Destino&);
    bool atualizar(const Destino&);

    bool criar(const Hospedagem&);
    bool excluir(const Hospedagem&);
    bool ler(const Hospedagem&);
    bool atualizar(const Hospedagem&);
};


#endif // STUBS_HPP_INCLUDED
