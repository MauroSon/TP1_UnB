#ifndef INTERFACES_HPP_INCLUDED
#define INTERFACES_HPP_INCLUDED

#include "dominios.hpp"
#include "entidades.hpp"
#include <stdexcept>

using namespace std;

// -------------------------------------------------------------------------------------------
// Declaração adiantada (forward declaration)

class IServicoEntidades;
class IServicoConta;
class IServicoAutenticacao;

//----------------------------------------------------------------------------------------------------------------------
// Declarações das interfaces da camada de apresentação.

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

// --------------------------------------------------------------------
// INTERFACE APRESENTAÇÃO ENTIDADES
/**
 * @brief Classe que representa a interface de entidades na camada de apresentação.
 *
 * A classe gerencia as execuções referentes as entidades.
 *
 *
 * Desenvolvido por: Mauro Ribeiro da Silva - 231013592
 */

class IApresentacaoEntidades{
public:
    virtual void executar(Codigo) = 0;
    virtual ~IApresentacaoEntidades(){};
};

//----------------------------------------------------------------------------------------------------------------------
// Declarações das interfaces da camada de Serviço.

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
// INTERFACE SERVIÇO CONTA

class IServicoConta{
public:
    virtual bool criar(Conta) = 0;
    virtual bool excluir(Codigo) = 0;
    virtual bool ler(Conta*) = 0;
    virtual bool atualizar(Conta) = 0;

    virtual ~IServicoConta(){};
};

// --------------------------------------------------------------------
// INTERFACE SERVIÇO ENTIDADES

class IServicoEntidades {
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

    virtual void setCntrServicoEntidades(IServicoEntidades*) = 0;
    virtual ~IServicoEntidades(){};
};

#endif // INTERFACES_HPP_INCLUDED
