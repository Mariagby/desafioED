#include <stdio.h>
#include <string.h>
#include "struct.h"


void relatorioDiscentes() {//A
    printf("\n Listagem (cpf, nome e idade) dos discentes \n");
    for(int i = 0; i < qtdDiscentes; i++) {
        printf("CPF: %s | Nome: %s | Idade: %d\n", discentes[i].cpf, discentes[i].nome, discentes[i].idade);
    }
}

void relatorioCursos() {//B
    printf("\n Listagem (códigos, nomes, horas e número de vagas) dos cursos \n");
    for(int i = 0; i < qtdCursos; i++) {
        printf("Codigo: %d | Nome: %s | Vagas: %d \n", cursos[i].codigo, cursos[i].nome, cursos[i].nVaga);
    }
}

void relatorioBusca() {//C
    char palavra[50];
    printf("\n Listagem de discentes a partir de uma palavra do nome ");
    scanf(" %[^\n]", palavra);
    
    for(int i = 0; i < qtdDiscentes; i++) {
        if(strstr(discentes[i].nome, palavra) != NULL) { 
            printf("CPF: %s | Nome: %s\n", discentes[i].cpf, discentes[i].nome);
        }
    }
}

void relatorioTurma() {//D
    printf("\n Listagem (número da turma, cpf, nome e nota) do discente \n");
    for(int i = 0; i < qtdTurmas; i++) {
        for(int j = 0; j < qtdDiscentes; j++) {
            if(strcmp(turmas[i].cpf, discentes[j].cpf) == 0) {
                printf("Turma: %d | CPF: %s | Nome: %s | Nota: %.2f\n", turmas[i].numero, turmas[i].cpf, discentes[j].nome, turmas[i].nota);
            }
        }
    }
}

void relatorioTurmas2() {//E
    printf("\n Listagem (números das turmas, cpf, nome, nota, código, nome) do curso.\n");
    for(int i = 0; i < qtdTurmas; i++) {
        for(int j = 0; j < qtdDiscentes; j++) {
            if(strcmp(turmas[i].cpf, discentes[j].cpf) == 0) {
                for(int k = 0; k < qtdCursos; k++) {
                    if(turmas[i].codigo == cursos[k].codigo) {
                        printf("Turma: %d | CPF: %s | Nome: %s | Nota: %.2f | Curso: %s\n", 
                               turmas[i].numero, turmas[i].cpf, discentes[j].nome, turmas[i].nota, cursos[k].nome);
                    }
                }
            }
        }
    }
}

void relatorioNTurma() {//F
    int num;
    printf("\nDigite o numero da turma: ");
    scanf("%d", &num);
    
    for(int i = 0; i < qtdTurmas; i++) {
        if(turmas[i].numero == num) {
            for(int j = 0; j < qtdDiscentes; j++) {
                if(strcmp(turmas[i].cpf, discentes[j].cpf) == 0) {
                    printf("CPF: %s | Nome: %s | Nota: %.2f\n", discentes[j].cpf, discentes[j].nome, turmas[i].nota);
                }
            }
        }
    }
}

void relatorioMedia() {//G
    int num, alunos = 0;
    float soma = 0.0;
    
    printf("\n Digite a turma para ver a media: ");
    scanf("%d", &num);
    
    for(int i = 0; i < qtdTurmas; i++) {
        if(turmas[i].numero == num) {
            soma += turmas[i].nota;
            alunos++;
        }
    }
    
    if(alunos > 0) {
        printf("Media da turma %d: %.2f\n", num, (soma / alunos));
    } else {
        printf("Nenhum aluno cadastrado nesta turma.\n");
    }
}