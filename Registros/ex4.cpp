#include <iostream>

using namespace std;

struct alunos {
    int matricula;
    string nome;
    float nota1, nota2;
    char sexo;
};



int main() {
    int quantidadeAlunos;
    cin >> quantidadeAlunos;

    alunos aluno[quantidadeAlunos];

    float masculino = 0, feminino = 0;
    float somaNotas = 0;
    int m = 0, f = 0;

    for (int i = 0; i < quantidadeAlunos; i++) {
        cin >> aluno[i].matricula >> aluno[i].nome >> aluno[i].nota1 >> aluno[i].nota2 >> aluno[i].sexo;
        somaNotas += (aluno[i].nota1 + aluno[i].nota2) / 2;

        if (aluno[i].sexo == 'M') {
            masculino += (aluno[i].nota1 + aluno[i].nota2) / 2;
            m++;
        }
        else {
            feminino += (aluno[i].nota1 + aluno[i].nota2) / 2;
            f++;
        }
        
    }
    
    cout << somaNotas / quantidadeAlunos << endl;
    cout << masculino / m << endl;
    cout << feminino / f << endl;


    return 0;
}