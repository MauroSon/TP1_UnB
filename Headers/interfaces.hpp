#ifndef INTERFACES_HPP_INCLUDED
#define INTERFACES_HPP_INCLUDED

#include "dominios.hpp"
#include "entidades.hpp"
#include <stdexcept>

using namespace std;

// INL = InterfaceLogicaNegocio

// -------------------------------------------------------------------------------------------
// Declaração adiantada (forward declaration)

class InterfaceLogicaNegocioEntidadesServico;
class InterfaceEntidadesApresentacao;
class ILNContaServico;
class IServicoAutenticacao;

// --------------------------------------------------------------------
// Interface Entidades Servico

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
};

// --------------------------------------------------------------------
// INTERFACE SERVIÇO AUTENTICAÇÃO

/**
 * @brief Classe abstrata Interface Serviço Autenticação
 *
 * Desenvolvido por: Isabela Soares Furlan - 231013636
*/
class IServicoAutenticacao {
    public:
        virtual bool autenticar(const Codigo&, const Senha&) = 0; ///< Autentica a conta verificando código e senha.
        virtual ~IServicoAutenticacao() {} ///< Método destrutor da classe.
};

// --------------------------------------------------------------------
// INTERFACE CONTA SERVIÇO


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

    virtual ~INLContaServico(){};
};

// --------------------------------------------------------------------
// INTERFACE APRESENTACAO AUTENTICACAO 
/**
*@brief Interface para a apresentação da autenticação.
*Camada responsável por lidar com a interação do usuário no processo de autenticação e delegar a validação das credenciais para o serviço correspondente.
*Desenvolvido por: Mariana Soares Oliveira (231013663)
*/

class IApresentacaoAutenticacao {
    public:
        virtual bool autenticar(Codigo*) = 0;
        virtual void setCntrServicoAutenticacao(IServicoAutenticacao*) = 0;
        virtual ~IApresentacaoAutenticacao(){}
};

#endif // INTERFACES_HPP_INCLUDED
