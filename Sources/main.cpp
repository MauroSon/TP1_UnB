#include <bits/stdc++.h>
#include <stdexcept>
#include "dominios.hpp"
#include "entidades.hpp"
#include "interfaces.hpp"
#include "controladoras.hpp"
#include "containers.hpp"

using namespace std;

int main() {
    // Instanciar controladoras e containers
    IApresentacaoAutenticacao* cntrApresentacaoAutenticacao = new CntrApresentacaoAutenticacao();
    ContainerAutenticacao* containerAutenticacao = new ContainerAutenticacao();

    IApresentacaoConta* cntrApresentacaoConta = new CntrApresentacaoConta();
    IServicoConta* containerConta = new ContainerConta(containerAutenticacao);

    IApresentacaoEntidades* cntrApresentacaoEntidades = new CntrApresentacaoEntidades();
    IServicoEntidades* containerEntidades = new ContainerEntidades();

    // Ligar controladoras aos containers
    cntrApresentacaoAutenticacao->setCntrServicoAutenticacao(containerAutenticacao);
    cntrApresentacaoConta->setCntrServicoConta(containerConta);
    cntrApresentacaoEntidades->setCntrServicoEntidades(containerEntidades);

    Codigo codigo;

    cout << endl << "Bem-vindo ao sistema!" << endl;

    while (true) {
        cout << endl << "Escolha uma opcao:" << endl;
        cout << "1. Autenticar" << endl;
        cout << "2. Criar conta" << endl;
        cout << "3. Executar conta" << endl;
        cout << "4. Gerenciar entidades" << endl;
        cout << "5. Sair" << endl;
        cout << "Opcao: ";

        int opcao;
        cin >> opcao;

        try {
            switch (opcao) {
                case 1: { // Autenticar
                    cntrApresentacaoAutenticacao->autenticar(&codigo);
                    break;
                }

                case 2: { // Criar conta
                    cntrApresentacaoConta->criar();
                    break;
                }

                case 3: { // Executar conta (menu de operações)
                    string entrada;
                    cout << endl << "Digite o codigo da conta: ";
                    cin >> entrada;
                    codigo.setCodigo(entrada);

                    while (true) {
                        cout << endl << "Escolha uma operacao:" << endl;
                        cout << "1. Alterar senha" << endl;
                        cout << "2. Excluir conta" << endl;
                        cout << "3. Ler conta" << endl;
                        cout << "4. Voltar" << endl;
                        cout << "Opcao: ";

                        int opcaoOperacao;
                        cin >> opcaoOperacao;

                        try {
                            switch (opcaoOperacao) {
                                case 1: { // Alterar senha
                                    string novaSenha;
                                    cout << "Digite a nova senha: ";
                                    cin >> novaSenha;

                                    Senha senhaAtualizada;
                                    try {
                                        senhaAtualizada.setSenha(novaSenha);
                                    } catch (const invalid_argument &exp) {
                                        cout << "Erro: Senha invalida. " << exp.what() << endl;
                                        break;
                                    }

                                    Conta contaAtualizada;
                                    contaAtualizada.setCodigo(codigo);
                                    contaAtualizada.setSenha(senhaAtualizada);

                                    // Atualizar a conta no ContainerConta
                                    if (containerConta->atualizar(contaAtualizada)) {
                                        cout << "Senha alterada com sucesso!" << endl;
                                    } else {
                                        cout << "Falha ao alterar a senha. Conta nao encontrada." << endl;
                                    }
                                    break;
                                }

                                case 2: { // Excluir conta
                                    if (containerConta->excluir(codigo)) {
                                        cout << "Conta excluida com sucesso!" << endl;
                                        break;
                                    } else {
                                        cout << "Falha ao excluir a conta. Conta nao encontrada." << endl;
                                    }
                                    break;
                                }

                                case 3: { // Ler conta
                                    Conta conta;
                                    conta.setCodigo(codigo);

                                    if (containerConta->ler(&conta)) { // Passar o objeto Conta
                                        cout << "Conta encontrada:" << endl;
                                        cout << "Codigo: " << conta.getCodigo().getCodigo() << endl;
                                        cout << "Senha: " << conta.getSenha().getSenha() << endl;
                                    } else {
                                        cout << "Conta nao encontrada." << endl;
                                    }
                                    break;
                                }

                                case 4: { // Voltar
                                    break;
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

                        if (opcaoOperacao == 4) {
                            break;
                        }
                    }
                    break;
                }

                case 4: { // Gerenciar entidades
                    cntrApresentacaoEntidades->executar(codigo);
                    break;
                }

                case 5: { // Sair
                    cout << endl << "Saindo do sistema..." << endl;
                    delete cntrApresentacaoAutenticacao;
                    delete containerAutenticacao;
                    delete cntrApresentacaoConta;
                    delete containerConta;
                    delete cntrApresentacaoEntidades;
                    delete containerEntidades;
                    return 0;
                }

                default: {
                    cout << endl << "Opcao invalida. Tente novamente." << endl;
                    break;
                }
            }
        } catch (const invalid_argument &exp) {
            cout << endl << "Erro: Dado em formato incorreto." << endl;
        } catch (const runtime_error &exp) {
            cout << endl << "Erro de sistema: " << exp.what() << endl;
        }
    }

    return 0;
}
