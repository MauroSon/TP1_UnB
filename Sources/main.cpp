#include <bits/stdc++.h>
#include <stdexcept>
#include "dominios.hpp"
#include "entidades.hpp"
#include "testes.hpp"
#include "interfaces.hpp"
#include "stubs.hpp"
#include "controladoras.hpp"

using namespace std;

int main() {

    // Declaração de domínios:
    /*
    Avaliacao avaliacao;

    Codigo codigo;

    Data data;

    Dinheiro dinheiro;

    Duracao duracao;

    Horario horario;

    Nome nome;

    Senha senha;

    */

    // Declaração de entidades:

    /*

    Viagem viagem;

    Destino destino;

    Conta conta;

    Hospedagem hospedagem;

    Atividade atividade;

    */


    // Declaração de testes unitários de domínios:

    TUAvaliacao testeAvaliacao;

    TUCodigo testeCodigo;

    TUData testeData;

    TUDinheiro testeDinheiro;

    TUDuracao testeDuracao;

    TUHorario testeHorario;

    TUNome testeNome;

    TUSenha testeSenha;


    // Declaração de testes unitários de entidades:

    TUConta testeConta;

    TUDestino testeDestino;

    TUAtividade testeAtividade;

    TUViagem testeViagem;

    TUHospedagem testeHospedagem;


    // Testes:

    // Testes de domínios:

    // Teste de classe Avaliacao:

    switch(testeAvaliacao.run()){
        case TUAvaliacao::SUCESSO: cout << "SUCESSO (AVALIACAO)" << endl;
            break;
        case TUAvaliacao::FALHA : cout << "FALHA (AVALIACAO)" << endl;
            break;
    }

    // Teste de classe Codigo:

    switch(testeCodigo.run()){
        case TUCodigo::SUCESSO: cout << "SUCESSO (CODIGO)" << endl;
            break;
        case TUCodigo::FALHA : cout << "FALHA (CODIGO)" << endl;
            break;
    }

    // Testes de classe Data:

    switch(testeData.run()){
        case TUData::SUCESSO: cout << "SUCESSO (DATA)" << endl;
            break;
        case TUData::FALHA: cout << "FALHA (DATA)" << endl;
            break;
    }

    // Teste de classe Dinheiro:

    switch(testeDinheiro.run()) {
        case TUDinheiro::SUCESSO: cout << "SUCESSO (DINHEIRO)" << endl;
            break;
        case TUDinheiro::FALHA: cout << "FALHA (DINHEIRO)" << endl;
            break;
    }

    // Teste de classe Duracao:

    switch(testeDuracao.run()) {
        case TUDuracao::SUCESSO: cout << "SUCESSO (DURACAO)" << endl;
            break;
        case TUDuracao::FALHA: cout << "FALHA (DURACAO)" << endl;
            break;
    }

    // Teste de classe Horario:

    switch(testeHorario.run()){
        case TUHorario::SUCESSO: cout << "SUCESSO (HORARIO)" << endl;
            break;
        case TUHorario::FALHA: cout << "FALHA (HORARIO)" << endl;
            break;
    }

    // Teste de classe Nome:

    switch(testeNome.run()){
        case TUNome::SUCESSO: cout << "SUCESSO (NOME)" << endl;
            break;
        case TUNome::FALHA: cout << "FALHA (NOME)" << endl;
            break;
    }

    // Teste de classe Senha:

    switch (testeSenha.run()) {
        case TUSenha::SUCESSO:cout<<"SUCESSO (SENHA)"<<endl;
            break;
        case TUSenha::FALHA:cout<<"FALHA (SENHA)"<<endl;
            break;
    }


    // Testes de entidades:

    // Teste de classe Conta:

    switch (testeConta.run()) {
        case TUConta::SUCESSO:cout << "SUCESSO (CONTA)" << endl;
            break;

        case TUConta::FALHA:cout << "FALHA (CONTA)" << endl;
            break;
    }

    // Teste de classe Destino:

    switch(testeDestino.run()){
        case TUDestino::SUCESSO: cout << "SUCESSO (DESTINO)" << endl;
            break;
        case TUDestino::FALHA: cout << "FALHA (DESTINO)" << endl;
            break;
    }

    //  Teste de classe Atividade:

    switch(testeAtividade.run()){
        case TUAtividade::SUCESSO: cout << "SUCESSO (ATIVIDADE)" << endl;
            break;
        case TUAtividade::FALHA: cout << "FALHA (ATIVIDADE)" << endl;
            break;
    }

    // Teste de classe Viagem:

    switch(testeViagem.run()){
        case TUViagem::SUCESSO: cout << "SUCESSO (VIAGEM)" << endl;
            break;
        case TUViagem::FALHA: cout << "FALHA (VIAGEM)" << endl;
            break;
    }

    // Teste de classe Hospedagem:

    switch(testeHospedagem.run()){
        case TUHospedagem::SUCESSO: cout << "SUCESSO (HOSPEDAGEM)" << endl;
            break;
        case TUHospedagem::FALHA: cout << "FALHA (HOSPEDAGEM)" << endl;
            break;
    }

    // ---------------------------------------------------------------------------------
    // Tela Inicial do Sistema

    IApresentacaoAutenticacao  *cntrApresentacaoAutenticacao = new CntrApresentacaoAutenticacao();
    IServicoAutenticacao *stubServicoAutenticacao = new StubServicoAutenticacao();

    cntrApresentacaoAutenticacao->setCntrServicoAutenticacao(stubServicoAutenticacao);

    bool resultado;

    Codigo codigo;

    while(true){

        cout << endl << "Tela inicial de sistema." << endl;

        try{

            // Soliciatar serviço de autenticação.

            resultado = cntrApresentacaoAutenticacao->autenticar(&codigo);
        }
        catch(const runtime_error &exp){
                 cout << "Erro de sistema." << endl;
                 break;
        }

        if(resultado) {
            cout << endl << "Sucesso autenticacao." << endl;
            break;
        }
        else {
            cout << endl << "Erro autenticacao." << endl;
            break;
        }
    }

    delete cntrApresentacaoAutenticacao;
    delete stubServicoAutenticacao;

    return 0;
}

