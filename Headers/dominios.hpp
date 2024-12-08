#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

#include <stdexcept>
#include <bits/stdc++.h>
using namespace std;

//---------------------------------------------------------------------
// DOCUMENTAÇÃO FEITA POR MARIANA SOARES OLIVEIRA (231011663) E ISABELA SOARES FURLAN (231013636)

/**
 * @file dominios.hpp
 * @brief Declaração de classes que representam domínios do sistema.
 *
 * Este arquivo define classes que representam informações importantes no sistema, como horários, nomes, senhas, entre outros. Cada classe inclui
 * regras de formato para assegurar a consistência dos dados utilizados no sistema.
 */


// --------------------------------------------------------------------
// DOMÍNIO AVALIAÇÃO
/**
 * @brief Classe que representa uma avaliação de 0 a 5.
 *
 * A classe valida e gerencia avaliações numéricas.
 *
 * **Regras de formato**:
 * - A avaliação deve ser um número inteiro entre 0 e 5.
 *
 * @throw std::invalid_argument Se a avaliação não atender aos requisitos.
 *
 * Desenvolvido por: Mauro Ribeiro da Silva - 231013592
 */
class Avaliacao {
private:
    int avaliacao; ///< Valor da avaliação.
    void validar(int); ///< Valida a avaliação. Lança exceção se inválida.

public:
    void setAvaliacao(int); ///< Define a avaliação, validando as regras.
    int getAvaliacao() const; ///< Obtém a avaliação.
};

inline int Avaliacao::getAvaliacao() const {
    return avaliacao;
}


// --------------------------------------------------------------------
// DOMÍNIO CÓDIGO
/**
 * @brief Classe que representa um código de 6 caracteres.
 *
 * A classe valida e gerencia códigos alfanuméricos de seis dígitos.
 *
 * **Regras de formato**:
 * - O código deve ter exatamente 6 caracteres.
 * - Cada caractere pode ser uma letra (A-Z, a-z) ou um número (0-9).
 *
 * @throw std::invalid_argument Se o código não atender aos requisitos.
 *
 * Desenvolvido por: Mariana Soares Oliveira - 231013663
 */
class Codigo {
private:
    string codigo; ///< Valor do código.
    void validar(string); ///< Valida o código. Lança exceção se inválido.

public:
    void setCodigo(string); ///< Define o código, validando as regras.
    string getCodigo() const; ///< Obtém o código.
};

inline string Codigo::getCodigo() const {
    return codigo;
}


// --------------------------------------------------------------------
// DOMÍNIO DATA
/**
 * @brief Classe que representa uma data no formato DD-MM-AA.
 *
 * A classe gerencia e valida datas, incluindo anos bissextos.
 *
 * **Regras de formato**:
 * - O formato deve ser DD-MM-AA.
 * - DD: entre 01 e 31
 * - MM: entre 01 e 12.
 * - AA: entre 00 e 99.
 * - Levar em consideração anos bissextos.
 *
 * @throw std::invalid_argument Se a data não for válida.
 *
 * Desenvolvido por: Gabriel Balder Oliveira Lemos - 231013618
 */
class Data {
private:
    string data; ///< Valor da data.
    void validar(string); ///< Valida a data. Lança exceção se inválida.

public:
    void setData(string); ///< Define a data, validando o formato e valores.
    string getData() const; ///< Obtém a data.
};

inline string Data::getData() const {
    return data;
}


// --------------------------------------------------------------------
// DOMÍNIO DINHEIRO
/**
 * @brief Classe que representa um valor monetário.
 *
 * A classe valida e gerencia valores em dinheiro.
 *
 * **Regras de formato**:
 * - O valor deve estar entre 0,00 e 200.000,00.
 *
 * @throw std::invalid_argument Se o valor estiver fora do intervalo permitido.
 *
 * Desenvolvido por: Isabela Soares Furlan - 231013636
 */
class Dinheiro {
private:
    float dinheiro; ///< Valor do dinheiro.
    void validar(float); ///< Valida o valor monetário. Lança exceção se inválido.

public:
    void setDinheiro(float); ///< Define o valor monetário, validando o intervalo.
    inline float getDinheiro() const; ///< Obtém o valor monetário.
};

inline float Dinheiro::getDinheiro() const {
    return dinheiro;
}


// --------------------------------------------------------------------
// DOMÍNIO DURAÇÃO
/**
 * @brief Classe que representa uma duração em dias.
 *
 * A classe gerencia a duração de atividades.
 *
 * **Regras de formato**:
 * - A duração deve ser um valor entre 0 e 360.
 *
 * @throw std::invalid_argument Se a duração estiver fora do intervalo permitido.
 *
 * Desenvolvido por: Isabela Soares Furlan - 231013636
 */
class Duracao {
private:
    int duracao; ///< Valor da duração em dias.
    void validar(int); ///<Valida a duração. Lança exceção se inválido.

public:
    void setDuracao(int); ///< Define a duração, validando o intervalo.
    inline int getDuracao() const; ///< Obtém a duração.
};

inline int Duracao::getDuracao() const {
    return duracao;
}


// --------------------------------------------------------------------
// DOMÍNIO HORÁRIO
/**
 * @brief Classe que representa um horário no formato HH:MM.
 *
 * A classe valida e gerencia horários, garantindo que estejam no formato correto.
 *
 * **Regras de formato**:
 * - O horário deve seguir o formato HH:MM.
 * - As horas (HH) devem estar entre 00 e 23.
 * - Os minutos (MM) devem estar entre 00 e 59.
 *
 * @throw std::invalid_argument Se o formato ou valores forem inválidos.
 *
 * Desenvolvido por: João Victor Prata Tavares Pereira - 202028857
 */
class Horario {
private:
    string horario; ///< Valor do horário.
    void validar(string); ///< Valida o horário. Lança exceção se inválido.

public:
    void setHorario(string);  ///< Define o horário, validando o formato e valores.
    string getHorario() const; ///< Obtém o horário.
};

inline string Horario::getHorario() const {
    return horario;
}

// --------------------------------------------------------------------
// DOMÍNIO NOME
/**
 * @brief Classe que representa um nome com até 30 caracteres.
 *
 * A classe assegura que o nome respeite o limite de tamanho e formato esperado.
 *
 * **Regras de formato**:
 * - O nome deve ter até 30 caracteres.
 *
 * @throw std::invalid_argument Se o nome ultrapassar 30 caracteres.
 *
 * Desenvolvido por: João Victor Prata Tavares Pereira - 202028857
 */
class Nome {
private:
    string nome; ///< Valor do nome.
    void validar(string); ///< Valida o nome. Lança exceção se inválido.

public:
    void setNome(string); ///< Define o nome, validando o comprimento.
    string getNome() const; ///< Obtém o nome.
};

inline string Nome::getNome() const {
    return nome;
}

// --------------------------------------------------------------------
// DOMÍNIO SENHA
/**
 * @brief Classe que representa uma senha de cinco dígitos.
 *
 * A classe gerencia senhas de cinco dígitos, validando que atendam aos requisitos definidos.
 *
 * **Regras de formato**:
 * - A senha deve ter exatamente 5 dígitos (0-9).
 * - Não pode conter dígitos repetidos.
 * - Os dígitos não podem estar em sequência crescente (ex: 12345) ou decrescente (ex: 54321).
 *
 * @throw std::invalid_argument Se a senha não atender aos requisitos.
 *
 * Desenvolvido por: Nikolas Negrão Pessoa - 202024722
 */
class Senha {
private:
    string senha; ///< Valor da senha.
    void validar(string); ///< Valida a senha. Lança exceção se inválida.

public:
    void setSenha(string); ///< Define a senha, validando as regras.
    string getSenha() const; ///< Obtém a senha.
};

inline string Senha::getSenha() const {
    return senha;
}

#endif // DOMINIOS_HPP_INCLUDED
