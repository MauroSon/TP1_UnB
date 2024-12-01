#include <bits/stdc++.h>
#include <stdexcept>
#include "dominios.hpp"
#include "entidades.hpp"
#include "testes.hpp"

using namespace std;

int main() {

    // Declaração de domínios:

    Avaliacao avaliacao;

    Codigo codigo;

    Data data;

    Dinheiro dinheiro;

    Duracao duracao;

    Horario horario;
    Horario *horario_ptr;

    Nome nome;
    Nome *nome_ptr;

    Senha senha;
    Senha *senha_ptr;


    // Declaração de entidades:

    Viagem viagem;

    Destino destino;

    Conta conta;

    Hospedagem hospedagem;

    Atividades atividades;


    // Declaração de testes unitários de domínios:

    TUHorario testeHorario;

    TUAvaliacao testeAvaliacao;

    TUNome testeNome;

    TUSenha testeSenha;
    
    TUData testeData;

    // Testes:

    // Teste de classe Horario:

    switch(testeHorario.run()){
        case TUHorario::SUCESSO: cout << "SUCESSO (HORARIO)" << endl;
        break;
    case TUHorario::FALHA: cout << "FALHA (HORARIO)" << endl;
        break;
    }

    try {
        horario.setHorario("12:53");
    }
    catch(invalid_argument &exp){
        cout << "Excecao (Horario): " << exp.what() << endl;
    }

    try {
        horario.setHorario("1A:53");
    }
    catch(invalid_argument &exp) {
        cout << "Excecao (Horario): " << exp.what() << endl;
    }


    // Teste de classe Nome:

    switch(testeNome.run()){
        case TUNome::SUCESSO: cout << "SUCESSO (NOME)" << endl;
        break;
    case TUNome::FALHA: cout << "FALHA (NOME)" << endl;
        break;
    }

    try {
        nome.setNome("Pedro");
    }
    catch(invalid_argument &exp){
        cout << "Excecao (Nome): " << exp.what() << endl;
    }

    try {
        nome.setNome("Pedro de Alcântara João Carlos Leopoldo Salvador Bibiano Francisco Xavier de Paula Leocádio Miguel Gabriel Rafael Gonzaga");
    }
    catch(invalid_argument &exp) {
        cout << "Excecao (Nome): " << exp.what() << endl;
    }

    //Testes de classe Senha

    switch (testeSenha.run())
    {
    case TUSenha::SUCESSO:cout<<"SUCESSO"<<endl;
        break;
    
    case TUSenha::FALHA:cout<<"FALHA"<<endl;
        break;
    }

    try{
        senha.setSenha("21345");       
    }
    catch(invalid_argument&exp){
        cout<<"Excecao:"<<exp.what()<<endl;
    }

    try{
        senha.setSenha("12345");      
    }
    catch(invalid_argument&exp){
        cout<<"Excecao:"<<exp.what()<<endl;
    }
    
    // Testes de classe Data

    switch(testeData.run()){
        case TUData::SUCESSO: cout<<"SUCESSO (DATA)"<<endl;
        break;
    case TUData::FALHA: cout<<"FALHA (DATA)" <<endl;
        break;
    }

    try{
        data.setData("11-09-01");       //Escolher valor válido
    }
    catch(invalid_argument&exp){
        cout<<"Excecao:"<<exp.what()<<endl;
    }

    try{
        data.setData("30-02-05");      //Escolher valor inválido
    }
    catch(invalid_argument&exp){
        cout<<"Excecao:"<<exp.what()<<endl;
    }


    // Teste de classe Senha
    try{
        senha.setSenha("21345");
    }

    catch(invalid_argument &exp){
        cout << "Excecao : " << exp.what()<<endl;
    }

    try{
        senha.setSenha("12345");
    }

    catch(invalid_argument &exp){
        cout << "Excecao : " << exp.what()<<endl;
    }

    // Teste do Código, feito conforme roteiro do projeto
    TUCodigo testeCodigo;
    switch(testeCodigo.run()){
        case TUCodigo::SUCESSO: cout << "SUCESSO (CODIGO)" << endl;
        break;
    case TUCodigo::FALHA : cout << "FALHA (CODIGO)" << endl;
        break;

    }

    try {
        codigo.setCodigo("ABC123");
    }
    catch(invalid_argument & exp) {
        cout << "Excecao :" << exp.what() << endl;
    }
     try {
        codigo.setCodigo("!2*08");
    }
    catch(invalid_argument & exp) {
        cout << "Excecao :" << exp.what() << endl;
    }

    // Teste da Avaliação, feito conforme roteiro do projeto
    switch(testeAvaliacao.run()){
        case TUAvaliacao::SUCESSO: cout << "SUCESSO (AVALIACAO)" << endl;
            break;
        case TUAvaliacao::FALHA : cout << "FALHA (AVALIACAO)" << endl;
            break;
    }

    // Teste de Duracao e Dinheiro conforme o roteiro

    // Entrada de uma duração específica válida
    try {
        duracao.setDuracao(200);
    } catch (const invalid_argument &exp) {
        cout << "Exceção: " << exp.what() << endl;
    }
    // Entrada de uma duração específica inválida
    try {
        duracao.setDuracao(3610);
    } catch (const invalid_argument &exp) {
        cout << "Exceção: " << exp.what() << endl;
    }

    // Entrada de um valor específico válido
    try {
        dinheiro.setDinheiro(200.00);
    } catch (const invalid_argument &exp) {
        cout << "Exceção: " << exp.what() << endl;
    }
    // Entrada de um valor específico inválido
    try {
        dinheiro.setDinheiro(300000.00);
    } catch (const invalid_argument &exp) {
        cout << "Exceção: " << exp.what() << endl;
    }


    // Testes com entidades:

    // Viagem:

    viagem.setCodigo(codigo);
    viagem.setNome(nome);
    viagem.setAvaliacao(avaliacao);


    cout<< viagem.getCodigo().getCodigo() <<endl;
    cout<< viagem.getNome().getNome() <<endl;
    cout<< viagem.getAvaliacao().getAvaliacao() <<endl;


    // Destino:

    codigo.setCodigo("A1B2CE");
    destino.setCodigo(codigo);

    nome.setNome("Batman");
    destino.setNome(nome);

    data.setData("01-01-01");
    destino.setDataInicio(data);

    data.setData("09-09-09");
    destino.setDataTermino(data);

    avaliacao.setAvaliacao(5);
    destino.setAvaliacao(avaliacao);

    cout << destino.getCodigo().getCodigo() << endl;
    cout << destino.getNome().getNome() << endl;
    cout << destino.getDataInicio().getData() << endl;
    cout << destino.getDataTermino().getData() << endl;
    cout << destino.getAvaliacao().getAvaliacao() << endl;

    // Conta

    conta.setCodigo(codigo);
    conta.setSenha(senha);

    cout << conta.getCodigo().getCodigo() << endl;
    cout << conta.getSenha().getSenha() << endl;

    // Hospedagem:

    hospedagem.setCodigo(codigo);
    hospedagem.setNome(nome);
    hospedagem.setDinheiro(dinheiro);
    hospedagem.setAvaliacao(avaliacao);


    cout<< hospedagem.getCodigo().getCodigo() <<endl;
    cout<< hospedagem.getNome().getNome() <<endl;
    cout<< hospedagem.getDinheiro().getDinheiro() <<endl;
    cout<< hospedagem.getAvaliacao().getAvaliacao() <<endl;

    //Atividades

    atividades.setCodigo(codigo);
    atividades.setNome(nome);
    atividades.setData(data);
    atividades.setHorario(horario);
    atividades.setDuracao(duracao);
    atividades.setDinheiro(dinheiro);
    atividades.setAvaliacao(avaliacao);

    cout<< atividades.getCodigo().getCodigo() <<endl;
    cout<< atividades.getNome().getNome() <<endl;
    cout<< atividades.getData().getData() <<endl;
    cout<< atividades.getHorario().getHorario() <<endl;
    cout<< atividades.getDuracao().getDuracao() <<endl;
    cout<< atividades.getDinheiro().getDinheiro() <<endl;
    cout<< atividades.getAvaliacao().getAvaliacao() <<endl;

    return 0;
}
