#include "stubs.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

// -------------------------------------------------------------------------------------------
// Definições de constantes.

const string StubServicoAutenticacao::TRIGGER_FALHA_AUTENTICACAO = "%*/*";
const string StubServicoAutenticacao::TRIGGER_ERRO_SISTEMA_AUTENTICACAO = "7891011";

// -------------------------------------------------------------------------------------------
// Implementação de método.

bool StubServicoAutenticacao::autenticar(const Codigo &codigo, const Senha &senha) {

    std::string codigoValor = codigo.getCodigo();

    if(codigo.getCodigo() == TRIGGER_FALHA_AUTENTICACAO) {
            return false;
    }
    if(codigo.getCodigo() == TRIGGER_ERRO_SISTEMA_AUTENTICACAO) {
            throw runtime_error("Erro de sistema");
    }
    return true;
}
