#ifndef STUBS_HPP_INCLUDED
#define STUBS_HPP_INCLUDED

#include <stdexcept>
#include <bits/stdc++.h>
using namespace std;

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
