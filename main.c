#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

void menuDiscentes() {
    int opcao;
    do {
        printf("\n TELA DE DISCENTES \n");
        printf("1- Inserir Discente\n");
        printf("2- Editar Discente\n");
        printf("3- Excluir Discente\n");
        printf("4- Pesquisar Discente\n");
        printf("0- Voltar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: cadDiscente(); break;
            case 2: editarDiscente(); break;
            case 3: excluirDiscente(); break;
            case 4: pesquisarDiscente(); break;
            case 0: break;
            default: printf("Opção inválida!\n");
        }

    } while(opcao != 0);
}

void menuCursos() {
    int opcao;
    do {
        printf("\n  TELA DE CURSOS\n");
        printf("1- Inserir Curso\n");
        printf("2- Editar Curso\n");
        printf("3- Excluir Curso\n");
        printf("4- Pesquisar Curso\n");
        printf("0- Voltar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: cadCurso(); break;
            case 2: editarCurso(); break;
            case 3: excluirCurso(); break;
            case 4: pesquisarCurso(); break;
            case 0: break;
            default: printf("Opção inválida!\n");
        }

    } while(opcao != 0);
}

void menuTurmas() {
    int opcao;
    do {
        printf("\n TELA DE TURMAS\n");
        printf("1- Inserir Turma\n");
        printf("2- Editar Turma\n");
        printf("3- Excluir Turma\n");
        printf("4- Pesquisar Turma\n");
        printf("0- Voltar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: cadTurma(); break;
            case 2: editarTurma(); break;
            case 3: excluirTurma(); break;
            case 4: pesquisarTurma(); break;
            case 0: break;
            default: printf("Opção inválida!\n");
        }

    } while(opcao != 0);
}

void menuRelatorios() {
    int opcao;
    do {
        printf("\n RELATORIOS\n");
        printf("1- Discentes\n");
        printf("2- Cursos\n");
        printf("3- Buscar Discente por Nome\n");
        printf("4- Turmas (Aluno + Nota)\n");
        printf("5- Relatorio Completo\n");
        printf("6- Alunos por Turma\n");
        printf("7- Media da Turma\n");
        printf("0- Voltar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: relatorioDiscentes(); break;
            case 2: relatorioCursos(); break;
            case 3: relatorioBusca(); break;
            case 4: relatorioTurma(); break;
            case 5: relatorioTurmas2(); break;
            case 6: relatorioNTurma(); break;
            case 7: relatorioMedia(); break;
            case 0: break;
            default: printf("Opção inválida!\n");
        }

    } while(opcao != 0);
}

int main() {

    carregarDiscentes();
    carregarCursos();
    carregarTurmas();

    int opcao;

    do {
        printf("\n  SISTEMA ACADEMICO\n");
        printf("1 - Discentes\n");
        printf("2 - Cursos\n");
        printf("3 - Turmas\n");
        printf("4 - Relatorios\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: menuDiscentes(); break;
            case 2: menuCursos(); break;
            case 3: menuTurmas(); break;
            case 4: menuRelatorios(); break;
            case 0: printf("Tchau...\n"); break;
            default: printf("Opção inválida!\n");
        }

    } while(opcao != 0);

    free(discentes);
    free(cursos);
    free(turmas);

    return 0;
}
