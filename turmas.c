#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

Turma *turmas = NULL;
int qtdTurmas=0;

void cadTurma(){
    
    turmas = realloc(turmas, (qtdTurmas + 1) *sizeof(Turma));
    
    printf("\n\tInsira as informações da turma: ");
    printf("\n Número da turma: ");
    scanf("%d", &turmas[qtdTurmas].numero);
    
    printf("\n CPF do discente: ");
    scanf("%s", turmas[qtdTurmas].cpf);
    
    printf("\n Código do curso: ");
    scanf("%d", &turmas[qtdTurmas].codigo);
    
    turmas[qtdTurmas].nota=0.0;
    turmas[qtdTurmas].ano=2026;
    turmas[qtdTurmas].hParticipacao=0;
    
    FILE *file =fopen("turmas.txt", "a" );
    
    if(file==NULL){
        printf("Erro ao abrir arquivo para salvar\n");
    }else{
        fprintf(file, "%d; %s; %d; %.2f; %d; %d ", turmas[qtdTurmas].numero, turmas[qtdTurmas].cpf, turmas[qtdTurmas].codigo, turmas[qtdTurmas].nota, turmas[qtdTurmas].ano, turmas[qtdTurmas].hParticipacao);
        
        fclose(file);
    }
    qtdTurmas++;
    printf("Turma cadastrada e salva em txt!");
    
}

void pesquisarTurma() {
    int numBusca;
    char cpfBusca[15];
    
    printf("\n Pesquisar Matricula na Turma \n");
    printf("Digite o Numero da Turma: ");
    scanf("%d", &numBusca);
    printf("Digite o CPF do Aluno: ");
    scanf("%s", cpfBusca);

    for(int i = 0; i < qtdTurmas; i++) {
        if(turmas[i].numero == numBusca && strcmp(turmas[i].cpf, cpfBusca) == 0) { 
            printf("Codigo Curso: %d | Nota: %.2f | Horas de Participacao: %d\n", turmas[i].codigo, turmas[i].nota, turmas[i].hParticipacao);
            return; 
        }
    }
}

void atualizarTurmas() {
    FILE *file = fopen("turmas.txt", "w"); 
    if(file == NULL){
        printf("Erro ao abrir arquivo turmas.txt\n");
        return;
    }
    for(int i = 0; i < qtdTurmas; i++){
        fprintf(file, "%d; %s; %d; %.2f; %d; %d\n", 
                turmas[i].numero, turmas[i].cpf, turmas[i].codigo, 
                turmas[i].nota, turmas[i].ano, turmas[i].hParticipacao);
    }
    fclose(file);
}

void editarTurma() {
    int numBusca;
    char cpfBusca[15];
    
    printf("\n Editar Dados da Turma \n");
    printf("Digite o Numero da Turma: ");
    scanf("%d", &numBusca);
    printf("Digite o CPF do Aluno: ");
    scanf("%s", cpfBusca);

    for(int i = 0; i < qtdTurmas; i++) {
        if(turmas[i].numero == numBusca && strcmp(turmas[i].cpf, cpfBusca) == 0) {
            printf("Aluno encontrado! Nota atual: %.2f\n", turmas[i].nota);
            
            printf("Digite a nova Nota: ");
            scanf("%f", &turmas[i].nota);
            
            printf("Digite as Horas de Participacao: ");
            scanf("%d", &turmas[i].hParticipacao);

            atualizarTurmas(); 
            printf("Dados da turma atualizados!\n");
            return;
        }
    }
    printf("Registro nao encontrado.\n");
}

void excluirTurma() {
    int numBusca;
    char cpfBusca[15];
    
    printf("\n--- Excluir Aluno da Turma ---\n");
    printf("Digite o Numero da Turma: ");
    scanf("%d", &numBusca);
    printf("Digite o CPF do Aluno para remover: ");
    scanf("%s", cpfBusca);

    for(int i = 0; i < qtdTurmas; i++) {
        if(turmas[i].numero == numBusca && strcmp(turmas[i].cpf, cpfBusca) == 0) {
            
            for(int j = i; j < qtdTurmas - 1; j++) {
                turmas[j] = turmas[j + 1];
            }
            
            qtdTurmas--;

            if (qtdTurmas > 0) {
                turmas = realloc(turmas, qtdTurmas * sizeof(Turma));
            } else {
                free(turmas); 
                turmas = NULL;
            }

            atualizarTurmas(); 
            printf("Aluno removido da turma!\n");
            return;
        }
    }
    printf("Registro nao encontrado.\n");
}
void carregarTurmas() {
    FILE *file = fopen("turmas.txt", "r");
    if (file == NULL) return;

    Turma temp;
    while (fscanf(file, "%d; %[^;]; %d; %f; %d; %d", &temp.numero, temp.cpf, &temp.codigo, &temp.nota, &temp.ano, &temp.hParticipacao) != EOF) {
        turmas = realloc(turmas, (qtdTurmas + 1) * sizeof(Turma));
        turmas[qtdTurmas] = temp;
        qtdTurmas++;
    }
    fclose(file);
}