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
        avaliacao->setAvaliacao(AVALIACAO_VALIDA);
        if (avaliacao->getAvaliacao() != AVALIACAO_VALIDA)
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
    estado = FALHA;
    }
}
void TUAvaliacao::testarCenarioValorInvalido(){
    try{
        avaliacao->setAvaliacao(AVALIACAO_INVALIDA);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (avaliacao->getAvaliacao() == AVALIACAO_INVALIDA)
        estado = FALHA;
    }
}
int TUAvaliacao::run(){
    setUp();
    testarCenarioValorValido();
    testarCenarioValorInvalido();
    tearDown();
    return estado;
}

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

// Teste Unitário Senha:

void TUSenha::setUp(){
    senha = new Senha();
    estado = SUCESSO;
}

void TUSenha::tearDown(){
    delete senha;
}

void TUSenha::testarCenarioSenhaValido(){
    try{
        senha -> setValor(to_string(SENHA_VALIDO));
        cout << "Valor da senha: " << senha->getValor() << endl;
        if(senha -> getValor() != to_string(SENHA_VALIDO))
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUSenha::testarCenarioSenhaInvalido(){
    try{
        senha -> setValor(to_string(SENHA_INVALIDO));
        cout << "Valor da senha: " << senha->getValor() << endl;
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if(senha -> getValor() == to_string(SENHA_INVALIDO))
        estado = FALHA;
    }
}

int TUSenha::run(){
    setUp();
    testarCenarioSenhaValido();
    testarCenarioSenhaInvalido();
    tearDown();
    return estado;
}

// Teste Unitário Data:

void TUData::setUp(){
    data = new Data();
    estado = SUCESSO;

}

void TUData::tearDown(){
    delete data;
}

void TUData::testarCenarioDataValido(){
    try{
            data->setData(DATA_VALIDO);
            if(data->getData() != DATA_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument&execao){
        estado = FALHA;
    }
}

void TUData::testarCenarioDataInvalido(){
    try{
            data->setData(DATA_INVALIDO);
            estado = FALHA;
    }
    catch(invalid_argument&execao){
        if(data->getData()== DATA_INVALIDO)
        estado = FALHA;
    }
}

int TUData::run(){
    setUp();
    testarCenarioDataValido();
    testarCenarioDataInvalido();
    tearDown();
    return estado;
}

// Teste do Dominio Codigo, conforme roteiro do projeto

void TUCodigo::setUp(){
    codigo = new Codigo();
    estado = SUCESSO;
}

void TUCodigo::tearDown(){
    delete codigo;
}

void TUCodigo::testarCodigoCodigoValido(){
    try{
        codigo->setCodigo(CODIGO_VALIDO);
        if (codigo->getCodigo() != CODIGO_VALIDO)
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
 }
}

void TUCodigo::testarCodigoCodigoInvalido(){
    try{
        codigo->setCodigo(CODIGO_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (codigo->getCodigo() == CODIGO_INVALIDO)
        estado = FALHA;
    }
}

int TUCodigo::run(){
    setUp();
    testarCodigoCodigoValido();
    testarCodigoCodigoInvalido();
    tearDown();
    return estado;
}


// Teste Dominio Duracao

void TUDuracao::setUp() {
    duracao = new Duracao();
    estado = SUCESSO;
}

void TUDuracao::tearDown() {
    delete duracao;
}

void TUDuracao::testarCenarioDuracaoValida() {
    try {
        duracao->setDuracao(DURACAO_VALIDA);
        if(duracao->getDuracao() != DURACAO_VALIDA)
            estado = FALHA;
    }
    catch(invalid_argument &excecao) {
        estado = FALHA;
    }
}

void TUDuracao::testarCenarioDuracaoInvalida() {
    try {
        duracao->setDuracao(DURACAO_INVALIDA);
        estado = FALHA;
    }
    catch(invalid_argument &excecao) {
        if(duracao->getDuracao() == DURACAO_INVALIDA)
            estado = FALHA;
    }
}

int TUDuracao::run() {
    setUp();
    testarCenarioDuracaoValida();
    testarCenarioDuracaoInvalida();
    tearDown();
    return estado;
}

void TUDinheiro::setUp() {
    dinheiro = new Dinheiro;
    estado = SUCESSO;
}

void TUDinheiro::tearDown() {
    delete dinheiro;
}

void TUDinheiro::testarCenarioDinheiroValido() {
    try {
        dinheiro->setDinheiro(DINHEIRO_VALIDO);
        if(dinheiro->getDinheiro() != DINHEIRO_VALIDO)
            estado = FALHA;

    }
    catch(invalid_argument &excecao) {
        estado = FALHA;
    }
}

void TUDinheiro::testarCenarioDinheiroInvalido() {
    try {
        dinheiro->setDinheiro(DINHEIRO_INVALIDO);
            estado = FALHA;
    }
    catch(invalid_argument &excecao) {
        if(dinheiro->getDinheiro() == DINHEIRO_INVALIDO)
            estado = FALHA;
    }
}

int TUDinheiro::run() {
    setUp();
    testarCenarioDinheiroValido();
    testarCenarioDinheiroInvalido();
    tearDown();
    return estado;
}
