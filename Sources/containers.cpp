#include "containers.hpp"

// Implementação da classe ContainerViagem
bool ContainerViagem::criar(Viagem viagem) {
    string chave = viagem.getCodigo().getCodigo();
    if (container.find(chave) != container.end()) {
        return false;
    }
    container[chave] = viagem;
    return true;
}

bool ContainerViagem::excluir(Viagem viagem) {
    string chave = viagem.getCodigo().getCodigo();
    auto it = container.find(chave);
    if (it != container.end()) {
        container.erase(it);
        return true;
    }
    return false;
}

bool ContainerViagem::ler(Viagem* viagem) {
    string chave = viagem->getCodigo().getCodigo();
    auto it = container.find(chave);
    if (it != container.end()) {
        *viagem = it->second;
        return true;
    }
    return false;
}

bool ContainerViagem::atualizar(Viagem viagem) {
    string chave = viagem.getCodigo().getCodigo();
    auto it = container.find(chave);
    if (it != container.end()) {
        it->second = viagem;
        return true;
    }
    return false;
}

// Implementação da classe ContainerDestino
bool ContainerDestino::criar(Destino destino) {
    string chave = destino.getCodigo().getCodigo();
    if (container.find(chave) != container.end()) {
        return false;
    }
    container[chave] = destino;
    return true;
}

bool ContainerDestino::excluir(Destino destino) {
    string chave = destino.getCodigo().getCodigo();
    auto it = container.find(chave);
    if (it != container.end()) {
        container.erase(it);
        return true;
    }
    return false;
}

bool ContainerDestino::ler(Destino* destino) {
    string chave = destino->getCodigo().getCodigo();
    auto it = container.find(chave);
    if (it != container.end()) {
        *destino = it->second;
        return true;
    }
    return false;
}

bool ContainerDestino::atualizar(Destino destino) {
    string chave = destino.getCodigo().getCodigo();
    auto it = container.find(chave);
    if (it != container.end()) {
        it->second = destino;
        return true;
    }
    return false;
}

// Implementação da classe ContainerHospedagem
bool ContainerHospedagem::criar(Hospedagem hospedagem) {
    string chave = hospedagem.getCodigo().getCodigo();
    if (container.find(chave) != container.end()) {
        return false;
    }
    container[chave] = hospedagem;
    return true;
}

bool ContainerHospedagem::excluir(Hospedagem hospedagem) {
    string chave = hospedagem.getCodigo().getCodigo();
    auto it = container.find(chave);
    if (it != container.end()) {
        container.erase(it);
        return true;
    }
    return false;
}

bool ContainerHospedagem::ler(Hospedagem* hospedagem) {
    string chave = hospedagem->getCodigo().getCodigo();
    auto it = container.find(chave);
    if (it != container.end()) {
        *hospedagem = it->second;
        return true;
    }
    return false;
}

bool ContainerHospedagem::atualizar(Hospedagem hospedagem) {
    string chave = hospedagem.getCodigo().getCodigo();
    auto it = container.find(chave);
    if (it != container.end()) {
        it->second = hospedagem;
        return true;
    }
    return false;
}

// Implementação da classe ContainerAtividade
bool ContainerAtividade::criar(Atividade atividade) {
    string chave = atividade.getCodigo().getCodigo();
    if (container.find(chave) != container.end()) {
        return false;
    }
    container[chave] = atividade;
    return true;
}

bool ContainerAtividade::excluir(Atividade atividade) {
    string chave = atividade.getCodigo().getCodigo();
    auto it = container.find(chave);
    if (it != container.end()) {
        container.erase(it);
        return true;
    }
    return false;
}

bool ContainerAtividade::ler(Atividade* atividade) {
    string chave = atividade->getCodigo().getCodigo();
    auto it = container.find(chave);
    if (it != container.end()) {
        *atividade = it->second;
        return true;
    }
    return false;
}

bool ContainerAtividade::atualizar(Atividade atividade) {
    string chave = atividade.getCodigo().getCodigo();
    auto it = container.find(chave);
    if (it != container.end()) {
        it->second = atividade;
        return true;
    }
    return false;
}

// Implementação da classe ContainerAutenticacao
bool ContainerAutenticacao::autenticar(const Codigo& codigo, const Senha& senha) {
    auto it = container.find(codigo.getCodigo());
    if (it != container.end() && it->second.getSenha().getSenha() == senha.getSenha()) {
        return true;
    }
    return false;
}

bool ContainerAutenticacao::criar(const Conta& conta) {
    string chave = conta.getCodigo().getCodigo();
    if (container.find(chave) != container.end()) {
        return false;
    }
    container[chave] = conta;
    return true;
}

bool ContainerAutenticacao::atualizar(const Conta& conta) {
    string chave = conta.getCodigo().getCodigo();
    auto it = container.find(chave);
    if (it != container.end()) {
        it->second = conta;
        return true;
    }
    return false;
}

// Implementação da classe ContainerConta
ContainerConta::ContainerConta(ContainerAutenticacao* containerAutenticacao)
    : containerAutenticacao(containerAutenticacao) {}

bool ContainerConta::criar(Conta conta) {
    string chave = conta.getCodigo().getCodigo();
    if (container.find(chave) != container.end()) {
        return false;
    }
    container[chave] = conta;

    if (containerAutenticacao) {
        containerAutenticacao->criar(conta);
    }
    return true;
}

bool ContainerConta::excluir(Codigo codigo) {
    string chave = codigo.getCodigo();
    auto it = container.find(chave);
    if (it != container.end()) {
        container.erase(it);
        return true;
    }
    return false;
}

bool ContainerConta::ler(Conta* conta) {
    string chave = conta->getCodigo().getCodigo();
    auto it = container.find(chave);
    if (it != container.end()) {
        *conta = it->second;
        return true;
    }
    return false;
}

bool ContainerConta::atualizar(Conta conta) {
    string chave = conta.getCodigo().getCodigo();
    auto it = container.find(chave);
    if (it != container.end()) {
        it->second = conta;

        if (containerAutenticacao) {
            containerAutenticacao->atualizar(conta);
        }
        return true;
    }
    return false;
}
