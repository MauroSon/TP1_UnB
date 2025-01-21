#ifndef INTERFACES_HPP_INCLUDED
#define INTERFACES_HPP_INCLUDED

#include "dominios.hpp"
#include "entidades.hpp"
#include <stdexcept>

// INL = InterfaceLogicaNegocio

class ILNEntidadesServico;

class IEntidadesServico {
public:
    virtual bool criar(Viagem) = 0;
    virtual bool excluir(Viagem) = 0;
    virtual bool ler(Viagem*) = 0;
    virtual bool atualizar(Viagem) = 0;

    virtual bool criar(Atividade) = 0;
    virtual bool excluir(Atividade) = 0;
    virtual bool ler(Atividade*) = 0;
    virtual bool atualizar(Atividade) = 0;

    virtual bool criar(Destino) = 0;
    virtual bool excluir(Destino) = 0;
    virtual bool ler(Destino*) = 0;
    virtual bool atualizar(Destino) = 0;

    virtual bool criar(Hospedagem) = 0;
    virtual bool excluir(Hospedagem) = 0;
    virtual bool ler(Hospedagem*) = 0;
    virtual bool atualizar(Hospedagem) = 0;

    virtual void setCntrLNEntidadesServico(ILNEntidadesServico*) = 0;
    virtual ~IEntidadesServico(){};
};

class ILNEntidadesServico {
public:
    virtual bool criar(const Viagem&) = 0;
    virtual bool excluir(const Viagem&) = 0;
    virtual bool ler(const Viagem&) = 0;
    virtual bool atualizar(const Viagem&) = 0;

    virtual bool criar(const Atividade&) = 0;
    virtual bool excluir(const Atividade&) = 0;
    virtual bool ler(const Atividade&) = 0;
    virtual bool atualizar(const Atividade&) = 0;

    virtual bool criar(const Destino&) = 0;
    virtual bool excluir(const Destino&) = 0;
    virtual bool ler(const Destino&) = 0;
    virtual bool atualizar(const Destino&) = 0;

    virtual bool criar(const Hospedagem&) = 0;
    virtual bool excluir(const Hospedagem&) = 0;
    virtual bool ler(const Hospedagem&) = 0;
    virtual bool atualizar(const Hospedagem&) = 0;

    virtual ~ILNEntidadesServico(){};
};


class ILNContaServico; 

class IContaServico{
public:
    virtual bool criar(Conta) = 0;
    virtual bool excluir(Codigo) = 0;
    virtual bool ler(Conta) = 0;
    virtual bool atualizar(Conta) = 0;

    virtual void setCntrLNContaServico(ILNContaServico*) = 0;
    virtual ~IContaServico(){};
};

class INLContaServico{
public:
    virtual bool criar(const Conta&) = 0;
    virtual bool excluir(const Codigo&) = 0;
    virtual bool ler(const Conta&) = 0;
    virtual bool atualizar(const Conta&) = 0;

    virtual ~INEContaServico(){};
};

class IContaApresentacao{
    virtual void criar(codigo) = 0;
    virtual void executar(codigo) =0;

    virtual void criar(senha) = 0;
    virtual void executar(senha) =0;
};

    

#endif // INTERFACES_HPP_INCLUDED
