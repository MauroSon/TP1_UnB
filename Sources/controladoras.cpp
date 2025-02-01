#include "controladoras.hpp"

// Implementação da CntrApresentacaoAutenticacao
bool CntrApresentacaoAutenticacao::autenticar(Codigo* codigo) {
    Senha senha;
    string entrada;

    while (true) {
        cout << endl << "Autenticacao de usuario." << endl << endl;

        try {
            cout << "Digite o codigo: ";
            cin >> entrada;
            codigo->setCodigo(entrada);
            cout << "Digite a senha: ";
            cin >> entrada;
            senha.setSenha(entrada);
            break;
        } catch (const invalid_argument &exp) {
            cout << endl << "Dado em formato incorreto." << endl;
        }
    }

    bool resultado = cntrServicoAutenticacao->autenticar(*codigo, senha);

    if (resultado) {
        cout << endl << "Autenticacao bem-sucedida!" << endl;
    } else {
        cout << endl << "Falha na autenticacao. Codigo ou senha incorretos." << endl;
    }

    return resultado;
}

void CntrApresentacaoAutenticacao::setCntrServicoAutenticacao(IServicoAutenticacao* cntrServicoAutenticacao) {
    this->cntrServicoAutenticacao = cntrServicoAutenticacao;
}

// Implementação da CntrApresentacaoConta
void CntrApresentacaoConta::criar() {
    Codigo codigo;
    Senha senha;
    string entrada;

    while (true) {
        cout << endl << "Criacao da conta" << endl << endl;

        try {
            cout << "Digite o codigo: ";
            cin >> entrada;
            codigo.setCodigo(entrada);
            cout << "Digite a senha: ";
            cin >> entrada;
            senha.setSenha(entrada);
            break;
        } catch (const invalid_argument &exp) {
            cout << endl << "Dado em formato incorreto." << endl;
        }
    }

    Conta novaConta;
    novaConta.setCodigo(codigo);
    novaConta.setSenha(senha);

    // Criar a conta no ContainerConta
    if (cntrServicoConta->criar(novaConta)) {
        cout << endl << "Conta criada com sucesso!" << endl;
    } else {
        cout << endl << "Erro: Conta com o mesmo codigo ja existe." << endl;
    }
}

void CntrApresentacaoConta::executar(Codigo codigo) {
    cout << endl << "Executando conta com codigo: " << codigo.getCodigo() << endl;
}

void CntrApresentacaoConta::setCntrServicoConta(IServicoConta* cntrServicoConta) {
    this->cntrServicoConta = cntrServicoConta;
}

//Implementação da CntrApresentacaoEntidades
void CntrApresentacaoEntidades::executar(Codigo codigo) {
    int opcao;
    while (true) {
        cout << endl << "Escolha uma entidade para gerenciar:" << endl;
        cout << "1. Viagem" << endl;
        cout << "2. Destino" << endl;
        cout << "3. Atividade" << endl;
        cout << "4. Hospedagem" << endl;
        cout << "5. Voltar" << endl;
        cout << "Opcao: ";
        cin >> opcao;

        try {
            switch (opcao) {
                case 1: { // Viagem
                    cout << endl << "Gerenciamento de Viagens" << endl;
                    cout << "1. Criar Viagem" << endl;
                    cout << "2. Ler Viagem" << endl;
                    cout << "3. Atualizar Viagem" << endl;
                    cout << "4. Excluir Viagem" << endl;
                    cout << "5. Voltar" << endl;
                    cout << "Opcao: ";
                    int opcaoViagem;
                    cin >> opcaoViagem;

                    switch (opcaoViagem) {
                        case 1: { // Criar Viagem
                            Viagem viagem;
                            string entrada;
                            Codigo codigoViagem;
                            Nome nomeViagem;
                            Avaliacao avaliacaoViagem;

                            cout << "Digite o codigo da viagem: ";
                            cin >> entrada;
                            codigoViagem.setCodigo(entrada);
                            viagem.setCodigo(codigoViagem);

                            cout << "Digite o nome da viagem: ";
                            cin >> entrada;
                            nomeViagem.setNome(entrada);
                            viagem.setNome(nomeViagem);

                            cout << "Digite a avaliacao da viagem: ";
                            cin >> entrada;
                            avaliacaoViagem.setAvaliacao(stoi(entrada));
                            viagem.setAvaliacao(avaliacaoViagem);

                            if (cntrServicoEntidades->criar(viagem)) {
                                cout << "Viagem criada com sucesso!" << endl;
                            } else {
                                cout << "Erro ao criar viagem." << endl;
                            }
                            break;
                        }
                        case 2: { // Ler Viagem
                            Viagem viagem;
                            string entrada;
                            Codigo codigoViagem;

                            cout << "Digite o codigo da viagem: ";
                            cin >> entrada;
                            codigoViagem.setCodigo(entrada);
                            viagem.setCodigo(codigoViagem);

                            if (cntrServicoEntidades->ler(&viagem)) {
                                cout << "Viagem encontrada:" << endl;
                                cout << "Codigo: " << viagem.getCodigo().getCodigo() << endl;
                                cout << "Nome: " << viagem.getNome().getNome() << endl;
                                cout << "Avaliacao: " << viagem.getAvaliacao().getAvaliacao() << endl;
                            } else {
                                cout << "Viagem nao encontrada." << endl;
                            }
                            break;
                        }
                        case 3: { // Atualizar Viagem
                            Viagem viagem;
                            string entrada;
                            Codigo codigoViagem;
                            Nome nomeViagem;
                            Avaliacao avaliacaoViagem;

                            cout << "Digite o codigo da viagem: ";
                            cin >> entrada;
                            codigoViagem.setCodigo(entrada);
                            viagem.setCodigo(codigoViagem);

                            cout << "Digite o novo nome da viagem: ";
                            cin >> entrada;
                            nomeViagem.setNome(entrada);
                            viagem.setNome(nomeViagem);

                            cout << "Digite a nova avaliacao da viagem: ";
                            cin >> entrada;
                            avaliacaoViagem.setAvaliacao(stoi(entrada));
                            viagem.setAvaliacao(avaliacaoViagem);

                            if (cntrServicoEntidades->atualizar(viagem)) {
                                cout << "Viagem atualizada com sucesso!" << endl;
                            } else {
                                cout << "Erro ao atualizar viagem." << endl;
                            }
                            break;
                        }
                        case 4: { // Excluir Viagem
                            Viagem viagem;
                            string entrada;
                            Codigo codigoViagem;

                            cout << "Digite o codigo da viagem: ";
                            cin >> entrada;
                            codigoViagem.setCodigo(entrada);
                            viagem.setCodigo(codigoViagem);

                            if (cntrServicoEntidades->excluir(viagem)) {
                                cout << "Viagem excluida com sucesso!" << endl;
                            } else {
                                cout << "Erro ao excluir viagem." << endl;
                            }
                            break;
                        }
                        case 5: { // Voltar
                            break;
                        }
                        default: {
                            cout << "Opcao invalida. Tente novamente." << endl;
                            break;
                        }
                    }
                    break;
                }
                case 2: { // Destino
                    cout << endl << "Gerenciamento de Destinos" << endl;
                    cout << "1. Criar Destino" << endl;
                    cout << "2. Ler Destino" << endl;
                    cout << "3. Atualizar Destino" << endl;
                    cout << "4. Excluir Destino" << endl;
                    cout << "5. Voltar" << endl;
                    cout << "Opcao: ";
                    int opcaoDestino;
                    cin >> opcaoDestino;

                    switch (opcaoDestino) {
                        case 1: { // Criar Destino
                            Destino destino;
                            string entrada;
                            Codigo codigoDestino;
                            Nome nomeDestino;
                            Data dataInicio;
                            Data dataTermino;
                            Avaliacao avaliacaoDestino;

                            cout << "Digite o codigo do destino: ";
                            cin >> entrada;
                            codigoDestino.setCodigo(entrada);
                            destino.setCodigo(codigoDestino);

                            cout << "Digite o nome do destino: ";
                            cin >> entrada;
                            nomeDestino.setNome(entrada);
                            destino.setNome(nomeDestino);

                            cout << "Digite a data de inicio (DD/MM/AAAA): ";
                            cin >> entrada;
                            dataInicio.setData(entrada);
                            destino.setDataInicio(dataInicio);

                            cout << "Digite a data de termino (DD/MM/AAAA): ";
                            cin >> entrada;
                            dataTermino.setData(entrada);
                            destino.setDataTermino(dataTermino);

                            cout << "Digite a avaliacao do destino: ";
                            cin >> entrada;
                            avaliacaoDestino.setAvaliacao(stoi(entrada));
                            destino.setAvaliacao(avaliacaoDestino);

                            if (cntrServicoEntidades->criar(destino)) {
                                cout << "Destino criado com sucesso!" << endl;
                            } else {
                                cout << "Erro ao criar destino." << endl;
                            }
                            break;
                        }
                        case 2: { // Ler Destino
                            Destino destino;
                            string entrada;
                            Codigo codigoDestino;

                            cout << "Digite o codigo do destino: ";
                            cin >> entrada;
                            codigoDestino.setCodigo(entrada);
                            destino.setCodigo(codigoDestino);

                            if (cntrServicoEntidades->ler(&destino)) {
                                cout << "Destino encontrado:" << endl;
                                cout << "Codigo: " << destino.getCodigo().getCodigo() << endl;
                                cout << "Nome: " << destino.getNome().getNome() << endl;
                                cout << "Data de Inicio: " << destino.getDataInicio().getData() << endl;
                                cout << "Data de Termino: " << destino.getDataTermino().getData() << endl;
                                cout << "Avaliacao: " << destino.getAvaliacao().getAvaliacao() << endl;
                            } else {
                                cout << "Destino nao encontrado." << endl;
                            }
                            break;
                        }
                        case 3: { // Atualizar Destino
                            Destino destino;
                            string entrada;
                            Codigo codigoDestino;
                            Nome nomeDestino;
                            Data dataInicio;
                            Data dataTermino;
                            Avaliacao avaliacaoDestino;

                            cout << "Digite o codigo do destino: ";
                            cin >> entrada;
                            codigoDestino.setCodigo(entrada);
                            destino.setCodigo(codigoDestino);

                            cout << "Digite o novo nome do destino: ";
                            cin >> entrada;
                            nomeDestino.setNome(entrada);
                            destino.setNome(nomeDestino);

                            cout << "Digite a nova data de inicio (DD/MM/AAAA): ";
                            cin >> entrada;
                            dataInicio.setData(entrada);
                            destino.setDataInicio(dataInicio);

                            cout << "Digite a nova data de termino (DD/MM/AAAA): ";
                            cin >> entrada;
                            dataTermino.setData(entrada);
                            destino.setDataTermino(dataTermino);

                            cout << "Digite a nova avaliacao do destino: ";
                            cin >> entrada;
                            avaliacaoDestino.setAvaliacao(stoi(entrada));
                            destino.setAvaliacao(avaliacaoDestino);

                            if (cntrServicoEntidades->atualizar(destino)) {
                                cout << "Destino atualizado com sucesso!" << endl;
                            } else {
                                cout << "Erro ao atualizar destino." << endl;
                            }
                            break;
                        }
                        case 4: { // Excluir Destino
                            Destino destino;
                            string entrada;
                            Codigo codigoDestino;

                            cout << "Digite o codigo do destino: ";
                            cin >> entrada;
                            codigoDestino.setCodigo(entrada);
                            destino.setCodigo(codigoDestino);

                            if (cntrServicoEntidades->excluir(destino)) {
                                cout << "Destino excluido com sucesso!" << endl;
                            } else {
                                cout << "Erro ao excluir destino." << endl;
                            }
                            break;
                        }
                        case 5: { // Voltar
                            break;
                        }
                        default: {
                            cout << "Opcao invalida. Tente novamente." << endl;
                            break;
                        }
                    }
                    break;
                }
                case 3: { // Atividade
                    cout << endl << "Gerenciamento de Atividades" << endl;
                    cout << "1. Criar Atividade" << endl;
                    cout << "2. Ler Atividade" << endl;
                    cout << "3. Atualizar Atividade" << endl;
                    cout << "4. Excluir Atividade" << endl;
                    cout << "5. Voltar" << endl;
                    cout << "Opcao: ";
                    int opcaoAtividade;
                    cin >> opcaoAtividade;

                    switch (opcaoAtividade) {
                        case 1: { // Criar Atividade
                            Atividade atividade;
                            string entrada;
                            Codigo codigoAtividade;
                            Nome nomeAtividade;
                            Data dataAtividade;
                            Horario horarioAtividade;
                            Duracao duracaoAtividade;
                            Dinheiro precoAtividade;
                            Avaliacao avaliacaoAtividade;

                            cout << "Digite o codigo da atividade: ";
                            cin >> entrada;
                            codigoAtividade.setCodigo(entrada);
                            atividade.setCodigo(codigoAtividade);

                            cout << "Digite o nome da atividade: ";
                            cin >> entrada;
                            nomeAtividade.setNome(entrada);
                            atividade.setNome(nomeAtividade);

                            cout << "Digite a data da atividade (DD/MM/AAAA): ";
                            cin >> entrada;
                            dataAtividade.setData(entrada);
                            atividade.setData(dataAtividade);

                            cout << "Digite o horario da atividade (HH:MM): ";
                            cin >> entrada;
                            horarioAtividade.setHorario(entrada);
                            atividade.setHorario(horarioAtividade);

                            cout << "Digite a duracao da atividade (em horas): ";
                            cin >> entrada;
                            duracaoAtividade.setDuracao(stoi(entrada));
                            atividade.setDuracao(duracaoAtividade);

                            cout << "Digite o preco da atividade: ";
                            cin >> entrada;
                            precoAtividade.setDinheiro(stof(entrada));
                            atividade.setPreco(precoAtividade);

                            cout << "Digite a avaliacao da atividade: ";
                            cin >> entrada;
                            avaliacaoAtividade.setAvaliacao(stoi(entrada));
                            atividade.setAvaliacao(avaliacaoAtividade);

                            if (cntrServicoEntidades->criar(atividade)) {
                                cout << "Atividade criada com sucesso!" << endl;
                            } else {
                                cout << "Erro ao criar atividade." << endl;
                            }
                            break;
                        }
                        case 2: { // Ler Atividade
                            Atividade atividade;
                            string entrada;
                            Codigo codigoAtividade;

                            cout << "Digite o codigo da atividade: ";
                            cin >> entrada;
                            codigoAtividade.setCodigo(entrada);
                            atividade.setCodigo(codigoAtividade);

                            if (cntrServicoEntidades->ler(&atividade)) {
                                cout << "Atividade encontrada:" << endl;
                                cout << "Codigo: " << atividade.getCodigo().getCodigo() << endl;
                                cout << "Nome: " << atividade.getNome().getNome() << endl;
                                cout << "Data: " << atividade.getData().getData() << endl;
                                cout << "Horario: " << atividade.getHorario().getHorario() << endl;
                                cout << "Duracao: " << atividade.getDuracao().getDuracao() << endl;
                                cout << "Preco: " << atividade.getPreco().getDinheiro() << endl;
                                cout << "Avaliacao: " << atividade.getAvaliacao().getAvaliacao() << endl;
                            } else {
                                cout << "Atividade nao encontrada." << endl;
                            }
                            break;
                        }
                        case 3: { // Atualizar Atividade
                            Atividade atividade;
                            string entrada;
                            Codigo codigoAtividade;
                            Nome nomeAtividade;
                            Data dataAtividade;
                            Horario horarioAtividade;
                            Duracao duracaoAtividade;
                            Dinheiro precoAtividade;
                            Avaliacao avaliacaoAtividade;

                            cout << "Digite o codigo da atividade: ";
                            cin >> entrada;
                            codigoAtividade.setCodigo(entrada);
                            atividade.setCodigo(codigoAtividade);

                            cout << "Digite o novo nome da atividade: ";
                            cin >> entrada;
                            nomeAtividade.setNome(entrada);
                            atividade.setNome(nomeAtividade);

                            cout << "Digite a nova data da atividade (DD/MM/AAAA): ";
                            cin >> entrada;
                            dataAtividade.setData(entrada);
                            atividade.setData(dataAtividade);

                            cout << "Digite o novo horario da atividade (HH:MM): ";
                            cin >> entrada;
                            horarioAtividade.setHorario(entrada);
                            atividade.setHorario(horarioAtividade);

                            cout << "Digite a nova duracao da atividade (em horas): ";
                            cin >> entrada;
                            duracaoAtividade.setDuracao(stoi(entrada));
                            atividade.setDuracao(duracaoAtividade);

                            cout << "Digite o novo preco da atividade: ";
                            cin >> entrada;
                            precoAtividade.setDinheiro(stof(entrada));
                            atividade.setPreco(precoAtividade);

                            cout << "Digite a nova avaliacao da atividade: ";
                            cin >> entrada;
                            avaliacaoAtividade.setAvaliacao(stoi(entrada));
                            atividade.setAvaliacao(avaliacaoAtividade);

                            if (cntrServicoEntidades->atualizar(atividade)) {
                                cout << "Atividade atualizada com sucesso!" << endl;
                            } else {
                                cout << "Erro ao atualizar atividade." << endl;
                            }
                            break;
                        }
                        case 4: { // Excluir Atividade
                            Atividade atividade;
                            string entrada;
                            Codigo codigoAtividade;

                            cout << "Digite o codigo da atividade: ";
                            cin >> entrada;
                            codigoAtividade.setCodigo(entrada);
                            atividade.setCodigo(codigoAtividade);

                            if (cntrServicoEntidades->excluir(atividade)) {
                                cout << "Atividade excluida com sucesso!" << endl;
                            } else {
                                cout << "Erro ao excluir atividade." << endl;
                            }
                            break;
                        }
                        case 5: { // Voltar
                            break;
                        }
                        default: {
                            cout << "Opcao invalida. Tente novamente." << endl;
                            break;
                        }
                    }
                    break;
                }
                case 4: { // Hospedagem
                    cout << endl << "Gerenciamento de Hospedagens" << endl;
                    cout << "1. Criar Hospedagem" << endl;
                    cout << "2. Ler Hospedagem" << endl;
                    cout << "3. Atualizar Hospedagem" << endl;
                    cout << "4. Excluir Hospedagem" << endl;
                    cout << "5. Voltar" << endl;
                    cout << "Opcao: ";
                    int opcaoHospedagem;
                    cin >> opcaoHospedagem;

                    switch (opcaoHospedagem) {
                        case 1: { // Criar Hospedagem
                            Hospedagem hospedagem;
                            string entrada;
                            Codigo codigoHospedagem;
                            Nome nomeHospedagem;
                            Dinheiro diariaHospedagem;
                            Avaliacao avaliacaoHospedagem;

                            cout << "Digite o codigo da hospedagem: ";
                            cin >> entrada;
                            codigoHospedagem.setCodigo(entrada);
                            hospedagem.setCodigo(codigoHospedagem);

                            cout << "Digite o nome da hospedagem: ";
                            cin >> entrada;
                            nomeHospedagem.setNome(entrada);
                            hospedagem.setNome(nomeHospedagem);

                            cout << "Digite o valor da diaria: ";
                            cin >> entrada;
                            diariaHospedagem.setDinheiro(stof(entrada));
                            hospedagem.setDiaria(diariaHospedagem);

                            cout << "Digite a avaliacao da hospedagem: ";
                            cin >> entrada;
                            avaliacaoHospedagem.setAvaliacao(stoi(entrada));
                            hospedagem.setAvaliacao(avaliacaoHospedagem);

                            if (cntrServicoEntidades->criar(hospedagem)) {
                                cout << "Hospedagem criada com sucesso!" << endl;
                            } else {
                                cout << "Erro ao criar hospedagem." << endl;
                            }
                            break;
                        }
                        case 2: { // Ler Hospedagem
                            Hospedagem hospedagem;
                            string entrada;
                            Codigo codigoHospedagem;

                            cout << "Digite o codigo da hospedagem: ";
                            cin >> entrada;
                            codigoHospedagem.setCodigo(entrada);
                            hospedagem.setCodigo(codigoHospedagem);

                            if (cntrServicoEntidades->ler(&hospedagem)) {
                                cout << "Hospedagem encontrada:" << endl;
                                cout << "Codigo: " << hospedagem.getCodigo().getCodigo() << endl;
                                cout << "Nome: " << hospedagem.getNome().getNome() << endl;
                                cout << "Diaria: " << hospedagem.getDiaria().getDinheiro() << endl;
                                cout << "Avaliacao: " << hospedagem.getAvaliacao().getAvaliacao() << endl;
                            } else {
                                cout << "Hospedagem nao encontrada." << endl;
                            }
                            break;
                        }
                        case 3: { // Atualizar Hospedagem
                            Hospedagem hospedagem;
                            string entrada;
                            Codigo codigoHospedagem;
                            Nome nomeHospedagem;
                            Dinheiro diariaHospedagem;
                            Avaliacao avaliacaoHospedagem;

                            cout << "Digite o codigo da hospedagem: ";
                            cin >> entrada;
                            codigoHospedagem.setCodigo(entrada);
                            hospedagem.setCodigo(codigoHospedagem);

                            cout << "Digite o novo nome da hospedagem: ";
                            cin >> entrada;
                            nomeHospedagem.setNome(entrada);
                            hospedagem.setNome(nomeHospedagem);

                            cout << "Digite o novo valor da diaria: ";
                            cin >> entrada;
                            diariaHospedagem.setDinheiro(stof(entrada));
                            hospedagem.setDiaria(diariaHospedagem);

                            cout << "Digite a nova avaliacao da hospedagem: ";
                            cin >> entrada;
                            avaliacaoHospedagem.setAvaliacao(stoi(entrada));
                            hospedagem.setAvaliacao(avaliacaoHospedagem);

                            if (cntrServicoEntidades->atualizar(hospedagem)) {
                                cout << "Hospedagem atualizada com sucesso!" << endl;
                            } else {
                                cout << "Erro ao atualizar hospedagem." << endl;
                            }
                            break;
                        }
                        case 4: { // Excluir Hospedagem
                            Hospedagem hospedagem;
                            string entrada;
                            Codigo codigoHospedagem;

                            cout << "Digite o codigo da hospedagem: ";
                            cin >> entrada;
                            codigoHospedagem.setCodigo(entrada);
                            hospedagem.setCodigo(codigoHospedagem);

                            if (cntrServicoEntidades->excluir(hospedagem)) {
                                cout << "Hospedagem excluida com sucesso!" << endl;
                            } else {
                                cout << "Erro ao excluir hospedagem." << endl;
                            }
                            break;
                        }
                        case 5: { // Voltar
                            break;
                        }
                        default: {
                            cout << "Opcao invalida. Tente novamente." << endl;
                            break;
                        }
                    }
                    break;
                }
                case 5: { // Voltar
                    return;
                }
                default: {
                    cout << "Opcao invalida. Tente novamente." << endl;
                    break;
                }
            }
        } catch (const invalid_argument &exp) {
            cout << "Erro: Dado em formato incorreto." << endl;
        } catch (const runtime_error &exp) {
            cout << "Erro de sistema: " << exp.what() << endl;
        }
    }
}
void CntrApresentacaoEntidades::setCntrServicoEntidades(IServicoEntidades* cntrServicoEntidades) {
    this->cntrServicoEntidades = cntrServicoEntidades;
}
