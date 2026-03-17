#ifndef struct_h // permite que eu use essa estrutura em todos os arquivos que eu criar
#define struct_h // header file

typedef struct {
    char cpf[15]; 
    char nome[50];
    int idade;
} Discente;

typedef struct { // typedef fica mais facil pra chamar a struct so pelo nome ao inves de eu ter que colocar struct curso
    int codigo;
    char nome[50];
    int nVaga;
    int nParticipantes;
} Curso;

typedef struct {
    int numero;
    char cpf[15];
    int codigo;
    float nota;
    int ano;
    int hParticipacao;
} Turma;

extern Discente *discentes;
extern int qtdDiscentes;

extern Curso *cursos;
extern int qtdCursos;

extern Turma *turmas;
extern int qtdTurmas;


void cadDiscente();
void pesquisarDiscente();
void editarDiscente();
void atualizarDiscente();
void excluirDiscente();
void carregarDiscentes();


void cadCurso();
void pesquisarCurso();
void editarCurso();
void atualizarCurso();
void excluirCurso();
void carregarCursos();


void cadTurma();
void pesquisarTurma();
void editarTurma();
void atualizarTurmas(); 
void excluirTurma();
void carregarTurmas();


void relatorioDiscentes(); // A
void relatorioCursos();    // B
void relatorioBusca();     // C
void relatorioTurma();     // D
void relatorioTurmas2();   // E
void relatorioNTurma();    // F
void relatorioMedia();     // G

#endif