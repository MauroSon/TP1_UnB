#ifndef INTERFACES_HPP_INCLUDED
#define INTERFACES_HPP_INCLUDED

#include "dominios.hpp"
#include "entidades.hpp"
#include <stdexcept>

class InterfaceLogicaNegocioEntidadesServico;
class InterfaceEntidadesApresentacao;

class InterfaceEntidadesServico {
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

    virtual void setCntrLogicaNegocioEntidadesServico(InterfaceLogicaNegocioEntidadesServico*) = 0;
    virtual ~InterfaceEntidadesServico(){};
};

class InterfaceLogicaNegocioEntidadesServico {
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

    virtual ~InterfaceLogicaNegocioEntidadesServico(){};
};

// --------------------------------------------------------------------
// CLASSE IEA
/**
 * @brief Classe que representa a interface de entidades na camada de apresentação.
 *
 * A classe gerencia as execuções referentes as entidades.
 *
 *
 * Desenvolvido por: Mauro Ribeiro da Silva - 231013592
 */

class InterfaceEntidadesApresentacao{
public:
    virtual void executar(Codigo) = 0;
    virtual ~InterfaceEntidadesApresentacao(){};
}

#endif // INTERFACES_HPP_INCLUDED
