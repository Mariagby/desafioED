#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

Discente *discentes = NULL;
int qtdDiscentes=0;

void cadDiscente(){
    
    discentes = realloc(discentes, (qtdDiscentes + 1) *sizeof(Discente));
    
    printf("\n\t Insira as informações do discente: ");
    printf("\nCPF: ");
    scanf("%s", discentes[qtdDiscentes].cpf);
    
    printf("\n Nome: ");
    scanf("%[^\n]", discentes[qtdDiscentes].nome);
    
    printf("\n Idade atual: ");
    scanf("%d", &discentes[qtdDiscentes].idade);
    
    
    FILE *file = fopen("discentes.txt", "a");
    
    if(file==NULL){
        printf("Erro ao abrir arquivo para salvar\n");
        
    }else{
        fprintf(file, "%s; %s; %d \n", discentes[qtdDiscentes].cpf, discentes[qtdDiscentes].nome, discentes[qtdDiscentes].idade);
        fclose(file);
        
    }
    qtdDiscentes++;
    printf("Discente cadastrado e salvo em txt!\n");
    
}

void pesquisarDiscente() {
    char cpfBusca[15];
    printf("\n Pesquisar Discente\n");
    printf("Digite o CPF: ");
    scanf("%s", cpfBusca);

    for(int i = 0; i < qtdDiscentes; i++) {
        if(strcmp(discentes[i].cpf, cpfBusca) == 0) { 
            printf("Nome: %s | Idade: %d\n", discentes[i].nome, discentes[i].idade);
            return;
        }
    }
    printf("Nenhum discente %s encontrado \n", cpfBusca);
}

void atualizarDiscente() {
    
    FILE *file = fopen("discentes.txt", "w"); 
    if(file == NULL){
        printf("Erro ao abrir arquivo para atualizar\n");
        return;
    }
    
    for(int i = 0; i < qtdDiscentes; i++){
        fprintf(file, "%s;%s;%d\n", discentes[i].cpf, discentes[i].nome, discentes[i].idade);
    }
    fclose(file);
    
}
void editarDiscente() {
    char cpfBusca[15];
    printf("\n Editar Discente \n");
    printf("Digite o CPF do aluno que deseja editar: ");
    scanf("%s", cpfBusca);

    for(int i = 0; i < qtdDiscentes; i++) {
        if(strcmp(discentes[i].cpf, cpfBusca) == 0) {
            printf("Aluno atual: %s\n", discentes[i].nome);
            
            printf("Novo Nome: ");
            scanf(" %[^\n]", discentes[i].nome);
            
            printf("Nova Idade: ");
            scanf("%d", &discentes[i].idade);

            atualizarDiscente(); 
            printf("Discente atualizado!\n");
            return;
        }
    }
    printf("CPF nao encontrado.\n");
}

void excluirDiscente() {
    char cpfBusca[15];
    printf("\n Excluir Discente \n");
    printf("Digite o CPF do aluno que quer EXCLUIR: ");
    scanf("%s", cpfBusca);

    for(int i = 0; i < qtdDiscentes; i++) {
        if(strcmp(discentes[i].cpf, cpfBusca) == 0) {
            
            for(int j = i; j < qtdDiscentes - 1; j++) {
                discentes[j] = discentes[j + 1];
            }
            
            qtdDiscentes--;

            if (qtdDiscentes > 0) {
                discentes = realloc(discentes, qtdDiscentes * sizeof(Discente));
            } else {
                free(discentes);
                discentes = NULL;
            }

            atualizarDiscente(); 
            printf("Discente excluido com sucesso!\n");
            return;
        }
    }
    printf("CPF nao encontrado.\n");
}

void carregarDiscentes() {
    FILE *file = fopen("discentes.txt", "r");
    if (file == NULL) return; 

    Discente temp;
    while (fscanf(file, " %[^;];%[^;];%d", temp.cpf, temp.nome, &temp.idade) != EOF) {
        discentes = realloc(discentes, (qtdDiscentes + 1) * sizeof(Discente));
        discentes[qtdDiscentes] = temp;
        qtdDiscentes++;
    }
    fclose(file);
}