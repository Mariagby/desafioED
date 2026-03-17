#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

Curso *cursos = NULL;
int qtdCursos = 0;

void cadCurso(){
    cursos = realloc(cursos, (qtdCursos + 1) *sizeof(Curso));
    
    printf("\n\t Insira as informações do curso: ");
    printf("\n Código: ");
    scanf("%d", &cursos[qtdCursos].codigo);
    
    printf("\n Nome: ");
    scanf("%[^\n]", cursos[qtdCursos].nome);
    
    printf("\n Número de vagas: ");
    scanf("%d", &cursos[qtdCursos].nVaga);
    
    cursos[qtdCursos].nParticipantes=0;
    
    FILE *file = fopen("cursos.txt", "a" );
    
    if(file==NULL){
        printf("Erro ao abrir arquivo para salvar\n");
        
    }else{
        fprintf(file, "%d; %s; %d; %d \n ", cursos[qtdCursos].codigo, cursos[qtdCursos].nome, cursos[qtdCursos].nVaga, cursos[qtdCursos].nParticipantes);
        
        fclose(file);
    }
    
    qtdCursos++;
    printf("Curso cadastrado e salvo em txt!");
    
}

void pesquisarCurso() {
    int codigoBusca;
    printf("\n Pesquisar Curso \n");
    printf("Digite o Codigo do curso: ");
    scanf("%d", &codigoBusca);

    for(int i = 0; i < qtdCursos; i++) {
        if(cursos[i].codigo == codigoBusca) { 
            printf("Nome: %s | Vagas: %d | Participantes matriculados: %d\n", cursos[i].nome, cursos[i].nVaga, cursos[i].nParticipantes);
            return;
        }
    }
    
    printf("Nenhum curso encontrado com o codigo %d.\n", codigoBusca);
}

void atualizarCurso() {
    
    FILE *file = fopen("cursos.txt", "w"); 
    if(file == NULL){
        printf("Erro ao abrir arquivo cursos.txt\n");
        return;
    }
    for(int i = 0; i < qtdCursos; i++){
        fprintf(file, "%d; %s; %d; %d \n", cursos[i].codigo, cursos[i].nome, cursos[i].nVaga, cursos[i].nParticipantes);
    }
    fclose(file);
}

void editarCurso() {
    int codigoBusca;
    printf("\n Editar Curso \n");
    printf("Digite o Codigo do curso que deseja editar: ");
    scanf("%d", &codigoBusca);

    for(int i = 0; i < qtdCursos; i++) {
        if(cursos[i].codigo == codigoBusca) {
            printf("Curso atual: %s\n", cursos[i].nome);
            
            printf("Novo Nome: ");
            scanf(" %[^\n]", cursos[i].nome);
            
            printf("Novo Numero de Vagas: ");
            scanf("%d", &cursos[i].nVaga);

            atualizarCurso(); 
            printf("Curso atualizado!\n");
            return;
        }
    }
    printf("Codigo nao encontrado.\n");
}

void excluirCurso() {
    int codigoBusca;
    printf("\n Excluir Curso \n");
    printf("Digite o Codigo do curso que quer EXCLUIR: ");
    scanf("%d", &codigoBusca);

    for(int i = 0; i < qtdCursos; i++) {
        if(cursos[i].codigo == codigoBusca) {
            
            for(int j = i; j < qtdCursos - 1; j++) {
                cursos[j] = cursos[j + 1];
            }
            
            qtdCursos--;

            if (qtdCursos > 0) {
                cursos = realloc(cursos, qtdCursos * sizeof(Curso));
            } else {
                free(cursos);
                cursos = NULL;
            }

            atualizarCurso();
            printf("Curso excluido!\n");
            return;
        }
    }
    printf("Codigo nao encontrado.\n");
}

void carregarCursos() {
    FILE *file = fopen("cursos.txt", "r");
    if (file == NULL) return;

    Curso temp;
    while (fscanf(file, "%d;%[^;];%d;%d", &temp.codigo, temp.nome, &temp.nVaga, &temp.nParticipantes) != EOF) {
        cursos = realloc(cursos, (qtdCursos + 1) * sizeof(Curso));
        cursos[qtdCursos] = temp;
        qtdCursos++;
    }
    fclose(file);
}