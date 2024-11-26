#include "testes.hpp"


// Teste Unitário Avaliacao:

void TUAvaliacao::setUp(){
    avaliacao = new Avaliacao();
    estado = SUCESSO;
}
void TUAvaliacao::tearDown(){
    delete avaliacao;
}
void TUAvaliacao::testarCenarioValorValido(){
    try{
        avaliacao->setAvaliacao(5);
        if (avaliacao->getAvaliacao() != 5)
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
    estado = FALHA;
    }
}
void TUAvaliacao::testarCenarioValorInvalido(){
    try{
        avaliacao->setAvaliacao(6);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (avaliacao->getAvaliacao() == 6)
        estado = FALHA;
    }
}
int TUAvaliacao::run(){
    setUp();
    testarCenarioValorValido();
    testarCenarioValorInvalido();


// Teste Unitário Horario:

void TUHorario::setUp(){
    horario = new Horario();
    estado = SUCESSO;
}

void TUHorario::tearDown(){
    delete horario;
}

void TUHorario::testarCenarioHorarioValido(){
    try{
        horario->setHorario(HORARIO_VALIDO);
        if(horario->getHorario() != HORARIO_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUHorario::testarCenarioHorarioInvalido(){
    try{
        horario->setHorario(HORARIO_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if(horario->getHorario() == HORARIO_INVALIDO)
            estado = FALHA;
    }
}

int TUHorario::run(){
    setUp();
    testarCenarioHorarioValido();
    testarCenarioHorarioInvalido();
    tearDown();
    return estado;
}


// Teste Unitário Nome:

void TUNome::setUp(){
    nome = new Nome();
    estado = SUCESSO;
}

void TUNome::tearDown(){
    delete nome;
}

void TUNome::testarCenarioNomeValido(){
    try{
        nome->setNome(NOME_VALIDO);
        if(nome->getNome() != NOME_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUNome::testarCenarioNomeInvalido(){
    try{
        nome->setNome(NOME_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if(nome->getNome() == NOME_INVALIDO)
            estado = FALHA;
    }
}

int TUNome::run(){
    setUp();
    testarCenarioNomeValido();
    testarCenarioNomeInvalido();
    tearDown();
    return estado;
}
