#include "stubs.hpp"
using namespace std;

const int StubLNEntidadesServico::TRIGGER_FALHA;
const int StubLNEntidadesServico::TRIGGER_ERRO_SISTEMA;

bool StubLNEntidadesServico:://? {

    cout << endl << "StubLNEntidadesServico::criar" << endl;
    //CELO para todos? Ou CELO + identificador?

    switch(viagem.getValor()){
    case TRIGGER_FALHA:
        return false;
    case TRIGGER_ERRO_SISTEMA:
        throw runtime_error("Erro de sistema");
    }

    return true;
}
