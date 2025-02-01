#ifndef CONTAINERS_HPP_INCLUDED
#define CONTAINERS_HPP_INCLUDED

#include <map>
#include <string>
#include "entidades.hpp"
#include "interfaces.hpp"

using namespace std;

// Declaração adiantada (forward declaration) de ContainerAutenticacao
class ContainerAutenticacao;

class ContainerViagem : public IServicoEntidades {
private:
    map<string, Viagem> container;
public:
    bool criar(Viagem viagem) override;
    bool excluir(Viagem viagem) override;
    bool ler(Viagem* viagem) override;
    bool atualizar(Viagem viagem) override;

    // Métodos para outras entidades (não aplicáveis a Viagem)
    bool criar(Atividade atividade) override { return false; }
    bool excluir(Atividade atividade) override { return false; }
    bool ler(Atividade* atividade) override { return false; }
    bool atualizar(Atividade atividade) override { return false; }

    bool criar(Destino destino) override { return false; }
    bool excluir(Destino destino) override { return false; }
    bool ler(Destino* destino) override { return false; }
    bool atualizar(Destino destino) override { return false; }

    bool criar(Hospedagem hospedagem) override { return false; }
    bool excluir(Hospedagem hospedagem) override { return false; }
    bool ler(Hospedagem* hospedagem) override { return false; }
    bool atualizar(Hospedagem hospedagem) override { return false; }
};

class ContainerDestino : public IServicoEntidades {
private:
    map<string, Destino> container;
public:
    bool criar(Destino destino) override;
    bool excluir(Destino destino) override;
    bool ler(Destino* destino) override;
    bool atualizar(Destino destino) override;

    // Métodos para outras entidades (não aplicáveis a Destino)
    bool criar(Viagem viagem) override { return false; }
    bool excluir(Viagem viagem) override { return false; }
    bool ler(Viagem* viagem) override { return false; }
    bool atualizar(Viagem viagem) override { return false; }

    bool criar(Atividade atividade) override { return false; }
    bool excluir(Atividade atividade) override { return false; }
    bool ler(Atividade* atividade) override { return false; }
    bool atualizar(Atividade atividade) override { return false; }

    bool criar(Hospedagem hospedagem) override { return false; }
    bool excluir(Hospedagem hospedagem) override { return false; }
    bool ler(Hospedagem* hospedagem) override { return false; }
    bool atualizar(Hospedagem hospedagem) override { return false; }
};

class ContainerHospedagem : public IServicoEntidades {
private:
    map<string, Hospedagem> container;
public:
    bool criar(Hospedagem hospedagem) override;
    bool excluir(Hospedagem hospedagem) override;
    bool ler(Hospedagem* hospedagem) override;
    bool atualizar(Hospedagem hospedagem) override;

    // Métodos para outras entidades (não aplicáveis a Hospedagem)
    bool criar(Viagem viagem) override { return false; }
    bool excluir(Viagem viagem) override { return false; }
    bool ler(Viagem* viagem) override { return false; }
    bool atualizar(Viagem viagem) override { return false; }

    bool criar(Atividade atividade) override { return false; }
    bool excluir(Atividade atividade) override { return false; }
    bool ler(Atividade* atividade) override { return false; }
    bool atualizar(Atividade atividade) override { return false; }

    bool criar(Destino destino) override { return false; }
    bool excluir(Destino destino) override { return false; }
    bool ler(Destino* destino) override { return false; }
    bool atualizar(Destino destino) override { return false; }
};

class ContainerAtividade : public IServicoEntidades {
private:
    map<string, Atividade> container;
public:
    bool criar(Atividade atividade) override;
    bool excluir(Atividade atividade) override;
    bool ler(Atividade* atividade) override;
    bool atualizar(Atividade atividade) override;

    // Métodos para outras entidades (não aplicáveis a Atividade)
    bool criar(Viagem viagem) override { return false; }
    bool excluir(Viagem viagem) override { return false; }
    bool ler(Viagem* viagem) override { return false; }
    bool atualizar(Viagem viagem) override { return false; }

    bool criar(Destino destino) override { return false; }
    bool excluir(Destino destino) override { return false; }
    bool ler(Destino* destino) override { return false; }
    bool atualizar(Destino destino) override { return false; }

    bool criar(Hospedagem hospedagem) override { return false; }
    bool excluir(Hospedagem hospedagem) override { return false; }
    bool ler(Hospedagem* hospedagem) override { return false; }
    bool atualizar(Hospedagem hospedagem) override { return false; }
};

class ContainerAutenticacao : public IServicoAutenticacao {
private:
    map<string, Conta> container;
public:
    bool autenticar(const Codigo&, const Senha&);
    bool criar(const Conta&);
    bool atualizar(const Conta&);
};

class ContainerConta : public IServicoConta {
private:
    map<string, Conta> container;
    ContainerAutenticacao* containerAutenticacao;
public:
    ContainerConta(ContainerAutenticacao* containerAutenticacao);
    bool criar(Conta);
    bool excluir(Codigo);
    bool ler(Conta*);
    bool atualizar(Conta);
};

class ContainerEntidades : public IServicoEntidades {
private:
    ContainerViagem containerViagem;
    ContainerDestino containerDestino;
    ContainerHospedagem containerHospedagem;
    ContainerAtividade containerAtividade;

public:
    bool criar(Viagem viagem) override {
        return containerViagem.criar(viagem);
    }

    bool excluir(Viagem viagem) override {
        return containerViagem.excluir(viagem);
    }

    bool ler(Viagem* viagem) override {
        return containerViagem.ler(viagem);
    }

    bool atualizar(Viagem viagem) override {
        return containerViagem.atualizar(viagem);
    }

    bool criar(Destino destino) override {
        return containerDestino.criar(destino);
    }

    bool excluir(Destino destino) override {
        return containerDestino.excluir(destino);
    }

    bool ler(Destino* destino) override {
        return containerDestino.ler(destino);
    }

    bool atualizar(Destino destino) override {
        return containerDestino.atualizar(destino);
    }

    bool criar(Hospedagem hospedagem) override {
        return containerHospedagem.criar(hospedagem);
    }

    bool excluir(Hospedagem hospedagem) override {
        return containerHospedagem.excluir(hospedagem);
    }

    bool ler(Hospedagem* hospedagem) override {
        return containerHospedagem.ler(hospedagem);
    }

    bool atualizar(Hospedagem hospedagem) override {
        return containerHospedagem.atualizar(hospedagem);
    }

    bool criar(Atividade atividade) override {
        return containerAtividade.criar(atividade);
    }

    bool excluir(Atividade atividade) override {
        return containerAtividade.excluir(atividade);
    }

    bool ler(Atividade* atividade) override {
        return containerAtividade.ler(atividade);
    }

    bool atualizar(Atividade atividade) override {
        return containerAtividade.atualizar(atividade);
    }
};

#endif // CONTAINERS_HPP_INCLUDED
