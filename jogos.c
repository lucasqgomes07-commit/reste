#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void perguntaResposta();
void cobraNaCaixa();
void gousmasWar();

int main() {
    srand(time(NULL));
    int escolha = 0;

    while (escolha != 4) {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1 - Pergunta e Resposta\n");
        printf("2 - Cobra na Caixa!\n");
        printf("3 - Gousmas War\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch(escolha) {
            case 1: perguntaResposta(); break;
            case 2: cobraNaCaixa(); break;
            case 3: gousmasWar(); break;
            case 4: printf("Saindo do jogo...\n"); break;
            default: printf("Opcao invalida! Tente novamente.\n"); break;
        }
    }

    return 0;
}

// ================== PERGUNTA E RESPOSTA ==================
void perguntaResposta() {
    int resposta, pontos, opcao;
    do {
        pontos = 0;
        printf("\n=== JOGO PERGUNTA E RESPOSTA ===\n");
        printf("Voce respondera 5 perguntas sobre a Primeira Guerra Mundial.\nCada acerto vale 1 ponto.\n\n");

        printf("1) Em que ano comecou a Primeira Guerra Mundial?\n1-1910  2-1912  3-1914  4-1916\n");
        scanf("%d", &resposta);
        if(resposta==3){ printf("Correto!\n\n"); pontos++; } else printf("Errado! 1914\n\n");

        printf("2) Qual evento iniciou a guerra?\n1-Invasao da Polonia  2-Assassinato do arquiduque Francisco Ferdinando\n3-Revolucao Francesa  4-Ataque a Pearl Harbor\n");
        scanf("%d", &resposta);
        if(resposta==2){ printf("Correto!\n\n"); pontos++; } else printf("Errado! Assassinato do arquiduque\n\n");

        printf("3) Em que ano terminou a guerra?\n1-1915 2-1916 3-1917 4-1918\n");
        scanf("%d", &resposta);
        if(resposta==4){ printf("Correto!\n\n"); pontos++; } else printf("Errado! 1918\n\n");

        printf("4) Qual pais fazia parte da Triplice Entente?\n1-Alemanha 2-Austria-Hungria 3-Franca 4-Imperio Otomano\n");
        scanf("%d", &resposta);
        if(resposta==3){ printf("Correto!\n\n"); pontos++; } else printf("Errado! Franca\n\n");

        printf("5) Qual tratado encerrou oficialmente a guerra?\n1-Tratado de Roma 2-Tratado de Paris 3-Tratado de Viena 4-Tratado de Versalhes\n");
        scanf("%d", &resposta);
        if(resposta==4){ printf("Correto!\n\n"); pontos++; } else printf("Errado! Tratado de Versalhes\n\n");

        printf("Voce fez %d de 5 pontos!\n", pontos);

        do {
            printf("\n1 - Jogar novamente\n2 - Voltar ao menu\nEscolha: ");
            scanf("%d", &opcao);
        } while(opcao!=1 && opcao!=2);
    } while(opcao==1);
}
void cobraNaCaixa() {
    int jogar = 1;

    while(jogar == 1) {

        int caixas[5] = {0,0,0,0,0}; 
        int abertas[5] = {0,0,0,0,0};
        int botao, cobra;
        int escolha;
        int jogadorAtual;

        char *nomes[7] = {"lucas", "fernando", "ivi", "pedro", "nice", "Fernanda", "rosana"};
        int jogador1, jogador2;

        printf("\n=== COBRA NA CAIXA ===\n");

        int i = 0;
        while(i < 7) {
            printf("%d - %s\n", i, nomes[i]);
            i++;
        }

        printf("Escolha o jogador 1 (0-6): ");
        scanf("%d", &jogador1);

        printf("Escolha o jogador 2 (0-6): ");
        scanf("%d", &jogador2);

        jogadorAtual = rand() % 2;
        
        botao = rand() % 5;
        do {
            cobra = rand() % 5;
        } while(cobra == botao);

        caixas[botao] = 1;
        caixas[cobra] = 2;

        printf("\n%s começa!\n", jogadorAtual == 0 ? nomes[jogador1] : nomes[jogador2]);

        int fim = 0;

        while(fim == 0) {

            printf("\nVez de %s\n", jogadorAtual == 0 ? nomes[jogador1] : nomes[jogador2]);

            printf("Escolha uma caixa (1-5): ");
            scanf("%d", &escolha);

            escolha--;

            if(escolha < 0 || escolha > 4) {
                printf("Escolha invalida! Tente novamente.\n");
                continue;
            }

            if(abertas[escolha] == 1) {
                printf("Essa caixa ja foi aberta! Escolha outra.\n");
                continue;
            }

            abertas[escolha] = 1;

            if(caixas[escolha] == 1) {
                printf("\nBOTAO! %s venceu!\n", jogadorAtual == 0 ? nomes[jogador1] : nomes[jogador2]);
                fim = 1;
            }
            else if(caixas[escolha] == 2) {
                printf("\nCOBRA! %s perdeu!\n", jogadorAtual == 0 ? nomes[jogador1] : nomes[jogador2]);
                fim = 1;
            }
            else {
                printf("Caixa vazia...\n");
                jogadorAtual = 1 - jogadorAtual; 
            }
        }

        printf("\n1 - Jogar novamente\n2 - Voltar ao menu\nEscolha: ");
        scanf("%d", &jogar);

        if(jogar == 2) {
            jogar = 0;
        }
    }
}
// ================== GOUSMAS WAR ==================
void gousmasWar() {
    int jogarNovamente;

    do {
        int g1[2] = {1, 1}; 
        int g2[2] = {1, 1}; 
        int ativo1[2] = {1, 1};
        int ativo2[2] = {1, 1};
        int turno = rand() % 2;
        int jogoAcabou = 0;

        printf("\n=== GOUSMAS WAR ===\n");

        while (!jogoAcabou) {
            int acao;

            printf("\n----------------------\n");
            printf("Jogador 1: G1(%d)%s | G2(%d)%s\n", g1[0], ativo1[0]? "":"[X]", g1[1], ativo1[1]? "":"[X]");
            printf("Jogador 2: G1(%d)%s | G2(%d)%s\n", g2[0], ativo2[0]? "":"[X]", g2[1], ativo2[1]? "":"[X]");

            if(turno==0) printf("\nTurno do Jogador 1\n");
            else printf("\nTurno do Jogador 2\n");

            do {
                printf("1 - Atacar\n2 - Dividir\nEscolha: ");
                scanf("%d", &acao);
            } while(acao!=1 && acao!=2);

            if(acao==1) {
                int atk, alvo;
                do { printf("Escolha sua Gousma (1 ou 2): "); scanf("%d",&atk); }
                while(atk<1 || atk>2 || (turno==0 && !ativo1[atk-1]) || (turno==1 && !ativo2[atk-1]));

                do { printf("Escolha alvo inimigo (1 ou 2): "); scanf("%d",&alvo); }
                while(alvo<1 || alvo>2 || (turno==0 && !ativo2[alvo-1]) || (turno==1 && !ativo1[alvo-1]));

                if(turno==0) g2[alvo-1] += g1[atk-1];
                else g1[alvo-1] += g2[atk-1];
            }
            else {
                int origem, destino, valor;
                do { printf("Escolha Gousma de origem (1 ou 2): "); scanf("%d",&origem); }
                while(origem<1 || origem>2 || (turno==0 && !ativo1[origem-1]) || (turno==1 && !ativo2[origem-1]));

                destino = (origem==1)?2:1;

                do { printf("Quanto transferir (>=1 e nao zerar origem): "); scanf("%d",&valor); }
                while(valor<1 || (turno==0 && valor>=g1[origem-1]) || (turno==1 && valor>=g2[origem-1]));

                if(turno==0) { g1[origem-1]-=valor; g1[destino-1]+=valor; ativo1[destino-1]=1; }
                else { g2[origem-1]-=valor; g2[destino-1]+=valor; ativo2[destino-1]=1; }
            }

            int i=0;
            while(i<2) { if(g1[i]>5) ativo1[i]=0; if(g2[i]>5) ativo2[i]=0; i++; }

            if(!ativo1[0] && !ativo1[1]) { printf("\nJogador 2 VENCEU!\n"); jogoAcabou=1; }
            if(!ativo2[0] && !ativo2[1]) { printf("\nJogador 1 VENCEU!\n"); jogoAcabou=1; }

            turno = 1-turno;
        }

        do {
            printf("\n1 - Jogar novamente\n2 - Voltar ao menu\nEscolha: ");
            scanf("%d", &jogarNovamente);
        } while(jogarNovamente!=1 && jogarNovamente!=2);

    } while(jogarNovamente==1);
    return 0;
}