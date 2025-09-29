// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================
//        
// ============================================================================
//
// OBJETIVOS:
// - Modularizar completamente o código em funções especializadas.
// - Implementar um sistema de missões para um jogador.
// - Criar uma função para verificar se a missão foi cumprida.
// - Utilizar passagem por referência (ponteiros) para modificar dados e
//   passagem por valor/referência constante (const) para apenas ler.
// - Foco em: Design de software, modularização, const correctness, lógica de jogo.
//
// ============================================================================

// Inclusão das bibliotecas padrão necessárias para entrada/saída, alocação de memória, manipulação de strings e tempo.
#include <stdio.h>
#include <string.h> 

// --- Constantes Globais ---
// Definem valores fixos para o número de territórios, missões e tamanho máximo de strings, facilitando a manutenção.
#define MAX_TERRITORIOS 5
#define NOME_LEN 30
#define COR_LEN 10 

// --- Estrutura de Dados ---
// Define a estrutura para um território, contendo seu nome, a cor do exército que o domina e o número de tropas.
typedef struct {
    char nome[NOME_LEN];
    char cor[COR_LEN];
    int tropas;
} Territorio;

// --- Protótipos das Funções ---
// Declarações antecipadas de todas as funções que serão usadas no programa, organizadas por categoria.
// Funções de setup e gerenciamento de memória:
// Funções de interface com o usuário:
// Funções de lógica principal do jogo:
// Função utilitária:

// --- Função Principal (main) ---
// Função principal que orquestra o fluxo do jogo, chamando as outras funções em ordem.
int main(void) {
    /* declara um vetor (array) de 5 Territorio */
    Territorio territorios[MAX_TERRITORIOS];

    printf("=== Cadastro de Territórios ===\n");
    printf("Você deverá informar %d territórios.\n\n", MAX_TERRITORIOS);

    /* Laço para ler os 5 territórios */
    for (int i = 0; i < MAX_TERRITORIOS; i++) {
        printf("Território %d de %d\n", i + 1, MAX_TERRITORIOS);

        /* Leitura do nome. */
        printf("  Nome (até %d caracteres): ", NOME_LEN - 1);
        scanf(" %29[^\n]", territorios[i].nome);

        /* Leitura da cor do exército */
        printf("  Cor do exército (até %d caracteres): ", COR_LEN - 1);
        scanf(" %9[^\n]", territorios[i].cor);

        /* Leitura do número de tropas. */
        printf("  Número de tropas (inteiro): ");
        scanf("%d", &territorios[i].tropas);

        /* Limpa o restante da linha do buffer de entrada para evitar problemas
           na próxima iteração (se o usuário tiver digitado mais coisa do que o permitido). */
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { /* limpa até o fim da linha */ }
        printf("\n");
    }

    /* Exibição dos territórios cadastrados */
    printf("=== Territórios cadastrados ===\n");
    for (int i = 0; i < MAX_TERRITORIOS; i++) {
        printf("Território %d:\n", i + 1);
        printf("  Nome   : %s\n", territorios[i].nome);
        printf("  Cor    : %s\n", territorios[i].cor);
        printf("  Tropas : %d\n", territorios[i].tropas);
        printf("-----------------------------\n");
    }

    return 0; /* indica que o programa terminou corretamente */
}

// --- Implementação das Funções ---

// alocarMapa():
// Aloca dinamicamente a memória para o vetor de territórios usando calloc.
// Retorna um ponteiro para a memória alocada ou NULL em caso de falha.

// inicializarTerritorios():
// Preenche os dados iniciais de cada território no mapa (nome, cor do exército, número de tropas).
// Esta função modifica o mapa passado por referência (ponteiro).

// liberarMemoria():
// Libera a memória previamente alocada para o mapa usando free.

// exibirMenuPrincipal():
// Imprime na tela o menu de ações disponíveis para o jogador.

// exibirMapa():
// Mostra o estado atual de todos os territórios no mapa, formatado como uma tabela.
// Usa 'const' para garantir que a função apenas leia os dados do mapa, sem modificá-los.

// exibirMissao():
// Exibe a descrição da missão atual do jogador com base no ID da missão sorteada.

// faseDeAtaque():
// Gerencia a interface para a ação de ataque, solicitando ao jogador os territórios de origem e destino.
// Chama a função simularAtaque() para executar a lógica da batalha.

// simularAtaque():
// Executa a lógica de uma batalha entre dois territórios.
// Realiza validações, rola os dados, compara os resultados e atualiza o número de tropas.
// Se um território for conquistado, atualiza seu dono e move uma tropa.

// sortearMissao():
// Sorteia e retorna um ID de missão aleatório para o jogador.

// verificarVitoria():
// Verifica se o jogador cumpriu os requisitos de sua missão atual.
// Implementa a lógica para cada tipo de missão (destruir um exército ou conquistar um número de territórios).
// Retorna 1 (verdadeiro) se a missão foi cumprida, e 0 (falso) caso contrário.

// limparBufferEntrada():
// Função utilitária para limpar o buffer de entrada do teclado (stdin), evitando problemas com leituras consecutivas de scanf e getchar.
