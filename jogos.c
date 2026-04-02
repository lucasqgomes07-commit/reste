#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// ================== MENU PRINCIPAL ==================
int lerInteiro();
void perguntaResposta();
void cobraNaCaixa();
void gousmasWar();

int main() {
    srand(time(NULL));
    int escolha = 0;

    while(escolha != 4){
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1 - Pergunta e Resposta\n2 - Cobra na Caixa!\n3 - Gousmas War\n4 - Sair\nEscolha uma opcao: ");
        escolha = lerInteiro();

        switch(escolha){
            case 1: perguntaResposta(); break;
            case 2: cobraNaCaixa(); break;
            case 3: gousmasWar(); break;
            case 4: printf("Saindo do jogo...\n"); break;
            default: printf("Opcao invalida! Tente novamente.\n"); break;
        }
    }

    return 0;
}

// ================== FUNÇÃO DE LEITURA ==================
int lerInteiro() {
    int valor;
    int ok;
    while(1) {
        ok = scanf("%d", &valor);
        if(ok == 1) return valor;
        printf("Entrada invalida! Digite um numero: ");
        while(getchar() != '\n'); // limpa buffer
    }
}

// ================== PERGUNTA E RESPOSTA ==================
void perguntaResposta() {
    int resposta, pontos, opcao;
    do {
        pontos = 0;
        printf("\n=== JOGO PERGUNTA E RESPOSTA ===\n");

        printf("1) Em que ano comecou a Primeira Guerra Mundial?\n1-1910 2-1912 3-1914 4-1916\n");
        resposta = lerInteiro();
        if(resposta == 3){ printf("Correto!\n\n"); pontos++; } else printf("Errado! 1914\n\n");

        printf("2) Qual evento iniciou a guerra?\n1-Invasao da Polonia 2-Assassinato do arquiduque\n3-Revolucao Francesa 4-Ataque a Pearl Harbor\n");
        resposta = lerInteiro();
        if(resposta == 2){ printf("Correto!\n\n"); pontos++; } else printf("Errado!\n\n");

        printf("3) Em que ano terminou?\n1-1915 2-1916 3-1917 4-1918\n");
        resposta = lerInteiro();
        if(resposta == 4){ printf("Correto!\n\n"); pontos++; } else printf("Errado!\n\n");

        printf("4) Qual pais da Triplice Entente?\n1-Alemanha 2-Austria 3-Franca 4-Otomano\n");
        resposta = lerInteiro();
        if(resposta == 3){ printf("Correto!\n\n"); pontos++; } else printf("Errado!\n\n");

        printf("5) Qual tratado encerrou?\n1-Roma 2-Paris 3-Viena 4-Versalhes\n");
        resposta = lerInteiro();
        if(resposta == 4){ printf("Correto!\n\n"); pontos++; } else printf("Errado!\n\n");

        printf("Voce fez %d pontos!\n", pontos);

        printf("\n1 - Jogar novamente\n2 - Voltar\n");
        opcao = lerInteiro();
    } while(opcao == 1);
}

// ================== COBRA NA CAIXA ==================
void cobraNaCaixa() {
    int jogar = 1;

    while(jogar == 1) {
        int caixas[5] = {0}, abertas[5] = {0};
        int botao, cobra;
        char *nomes[7] = {"lucas","fernando","ivi","pedro","nice","Fernanda","rosana"};
        int jogador1, jogador2, jogadorAtual, fim = 0, escolha;

        printf("\n=== COBRA NA CAIXA ===\n");

        int i = 0;
        while(i < 7) { printf("%d - %s\n", i, nomes[i]); i++; }

        printf("Jogador 1 (numero do nome): "); jogador1 = lerInteiro();
        printf("Jogador 2 (numero do nome): "); jogador2 = lerInteiro();

        botao = rand() % 5;
        do { cobra = rand() % 5; } while(cobra == botao);
        caixas[botao] = 1;
        caixas[cobra] = 2;

        jogadorAtual = rand() % 2;
        fim = 0;

        while(!fim) {
            printf("\nTurno de %s\n", jogadorAtual == 0 ? nomes[jogador1] : nomes[jogador2]);
            printf("Escolha uma caixa (1-5): ");
            escolha = lerInteiro() - 1;

            if(escolha < 0 || escolha > 4){
                printf("Escolha invalida! Tente novamente.\n");
                continue;
            }
            if(abertas[escolha]){
                printf("Caixa ja aberta! Escolha outra.\n");
                continue;
            }

            abertas[escolha] = 1;

            if(caixas[escolha] == 1){
                printf("BOTAO! %s venceu!\n", jogadorAtual==0 ? nomes[jogador1] : nomes[jogador2]);
                fim = 1;
            } else if(caixas[escolha] == 2){
                printf("COBRA! %s perdeu!\n", jogadorAtual==0 ? nomes[jogador1] : nomes[jogador2]);
                fim = 1;
            } else {
                printf("Caixa vazia. Proximo turno.\n");
                jogadorAtual = 1 - jogadorAtual;
            }
        }

        printf("\n1 - Jogar novamente\n2 - Voltar\n");
        jogar = lerInteiro();
    }
}

// ================== FUNÇÕES AUXILIARES GOUSMAS WAR ==================
void mostrarEstadoGW(int g1[2], int g2[2], int ativo1[2], int ativo2[2]) {
    printf("\n--- Estado Atual ---\n");

    int i=0;
    while(i<2){
        printf("Jogador 1 Gousma %d = ", i+1);
        if(ativo1[i]){
            printf("%d ", g1[i]);
            int j=0; while(j<g1[i]){ printf("¦"); j++; }
        } else printf("morta");
        printf("\n");
        i++;
    }

    i=0;
    while(i<2){
        printf("Jogador 2 Gousma %d = ", i+1);
        if(ativo2[i]){
            printf("%d ", g2[i]);
            int j=0; while(j<g2[i]){ printf("¦"); j++; }
        } else printf("morta");
        printf("\n");
        i++;
    }

    printf("-------------------\n");
}

int escolherGousmaGW(int ativo[2]) {
    int escolha;
    while(1){
        printf("Escolha uma gousma ativa (1 ou 2): ");
        escolha = lerInteiro() - 1;
        if(escolha>=0 && escolha<=1 && ativo[escolha]) return escolha;
        printf("Escolha invalida ou gousma morta! Tente novamente.\n");
    }
}

void verificarDestruicaoGW(int g[2], int ativo[2]) {
    int i=0;
    while(i<2){
        if(g[i]>5 && ativo[i]==1){
            ativo[i] = 0;
            printf("Gousma %d morreu por excesso de fúria!\n", i+1);
        }
        i++;
    }
}

int semGousmasGW(int ativo[2]) {
    return ativo[0]==0 && ativo[1]==0;
}

void dividirGousmaGW(int g[2], int ativo[2]) {
    int origem = escolherGousmaGW(ativo);
    int destino = (origem==0)?1:0;

    if(g[origem]<=1){
        printf("Nao ha fúria suficiente para dividir.\n");
        return;
    }

    int valor;
    while(1){
        printf("Quanto transferir (min 1, sem zerar a gousma de origem): ");
        valor = lerInteiro();
        if(valor<1 || g[origem]-valor<=0 || g[destino]+valor>5){
            printf("Valor invalido! Tente novamente.\n");
            continue;
        }
        g[origem]-=valor;
        g[destino]+=valor;
        if(ativo[destino]==0) ativo[destino]=1;
        verificarDestruicaoGW(g,ativo);
        break;
    }
}

void atacarGousmaGW(int atkG[2], int atkAtivo[2], int defG[2], int defAtivo[2]){
    int atk = escolherGousmaGW(atkAtivo);
    int alvo = escolherGousmaGW(defAtivo);
    defG[alvo] += atkG[atk];
    verificarDestruicaoGW(defG,defAtivo);
}

// ================== GOUSMAS WAR ==================
void gousmasWar() {
    int jogarNovamente;
    char nome1[50], nome2[50];

    printf("Nome do jogador 1: "); getchar(); scanf("%[^\n]", nome1); getchar();
    printf("Nome do jogador 2: "); scanf("%[^\n]", nome2); getchar();

    do {
        int g1[2] = {1,1}, g2[2] = {1,1};
        int ativo1[2] = {1,1}, ativo2[2] = {1,1};
        int turno = rand()%2;
        int fim = 0;

        while(!fim){
            mostrarEstadoGW(g1,g2,ativo1,ativo2);
            printf("\nTurno de %s\n", turno==0?nome1:nome2);
            printf("1 - Atacar\n2 - Dividir\n");

            int acao;
            while(1){
                acao = lerInteiro();
                if(acao==1 || acao==2) break;
                printf("Opcao invalida! Escolha 1 ou 2.\n");
            }

            if(acao==1){
                if(turno==0) atacarGousmaGW(g1,ativo1,g2,ativo2);
                else          atacarGousmaGW(g2,ativo2,g1,ativo1);
            } else{
                if(turno==0) dividirGousmaGW(g1,ativo1);
                else          dividirGousmaGW(g2,ativo2);
            }

            if(semGousmasGW(ativo1)){ 
                printf("\n%s venceu!\n", nome2); 
                fim=1; 
            }
            if(semGousmasGW(ativo2)){ 
                printf("\n%s venceu!\n", nome1); 
                fim=1; 
            }

            turno = 1-turno;
        }

        printf("\n1 - Jogar novamente\n2 - Voltar\n");
        jogarNovamente = lerInteiro();
    } while(jogarNovamente==1);
}
