//Banco de dados de personagens de desenhos animados
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <cctype>
#include <cstring>
#include <string.h>

using namespace std;



// NA ESTRUTURA STRUCT ESTAO OS CAMPOS QUE UTILIZAREMOS NESTRE PROJETO.

struct character{
    int identificador;
    char nome[30];
    char criador[80];
    char tituloDesenho[30];
    float altura;
    char bio[500];
};


// FUNÇAO PARA TRANSFORMAR TODAS AS LETRAS DE UMA STRING EM LETRAS MINUSCULAS:

char* minusculo(const char* palavra) {
    size_t comprimento = strlen(palavra); // Obter o comprimento da string de entrada
    char* resultado = new char[comprimento + 1]; // Criar um novo vetor para o resultadoado (mais 1 para o caractere nulo '\0')
    
    for (size_t i = 0; i < comprimento; i++) {
        resultado[i] = tolower(palavra[i]); // Transformar a letra em minúscula e armazená-la no vetor de resultadoado
    }
    
    resultado[comprimento] = '\0'; // Adicionar o caractere nulo para finalizar a string
    
    return resultado;
}

int particionaNome (character personagens[], int p, int r) {
    char personagemPivo[30];
    strcpy(personagemPivo, personagens[r].nome);
    int j = p;
    int k;
    for (k = p; k < r; k++) {
        if (strcmp(minusculo(personagens[k].nome), minusculo(personagemPivo)) <= 0) {
            swap(personagens[j].nome,personagens[k].nome);
            swap(personagens[j].tituloDesenho,personagens[k].tituloDesenho);
            swap(personagens[j].criador,personagens[k].criador);
            swap(personagens[j].altura,personagens[k].altura);
            swap(personagens[j].bio,personagens[k].bio);
            j++; 
        } 
    }
    swap(personagens[j].nome,personagens[r].nome);
    swap(personagens[j].tituloDesenho,personagens[r].tituloDesenho);
    swap(personagens[j].criador,personagens[r].criador);
    swap(personagens[j].altura,personagens[r].altura);
    swap(personagens[j].bio,personagens[r].bio);
    return j; 
}

void quickSortNome(character personagens[], int pos_personagemPivo, int fim) {
    int pos_novo_personagemPivo;
    if (pos_personagemPivo < fim) {
        pos_novo_personagemPivo = particionaNome(personagens, pos_personagemPivo, fim);
        quickSortNome(personagens, pos_personagemPivo, pos_novo_personagemPivo - 1); 
        quickSortNome(personagens, pos_novo_personagemPivo + 1, fim);
    }
}

int particionaAltura (character personagens[], int p, int r) {
    float personagemPivo;
    personagemPivo = personagens[r].altura;
    int j = p;
    int k;
    for (k = p; k < r; k++) {
        if (personagens[k].altura <= personagemPivo) {
            swap(personagens[j].nome,personagens[k].nome);
            swap(personagens[j].tituloDesenho,personagens[k].tituloDesenho);
            swap(personagens[j].criador,personagens[k].criador);
            swap(personagens[j].altura,personagens[k].altura);
            swap(personagens[j].bio,personagens[k].bio);
            j++; 
        } 
    }
    swap(personagens[j].nome,personagens[r].nome);
    swap(personagens[j].tituloDesenho,personagens[r].tituloDesenho);
    swap(personagens[j].criador,personagens[r].criador);
    swap(personagens[j].altura,personagens[r].altura);
    swap(personagens[j].bio,personagens[r].bio);
    return j; 
}


void quickSortAltura(character personagens[], int pos_personagemPivo, int fim) {
    int pos_novo_personagemPivo;         
    if (pos_personagemPivo < fim) {  
        pos_novo_personagemPivo = particionaAltura(personagens, pos_personagemPivo, fim);
        quickSortAltura(personagens, pos_personagemPivo, pos_novo_personagemPivo - 1); 
        quickSortAltura(personagens, pos_novo_personagemPivo + 1, fim);
    }
}


//PROCEDIMENTO PARA IMPRIMIR TODOS OS PERSONAGENS DO NOSSO ARQUIVO CSV:

void imprimirLista(character personagens[], int tamanho) {
    character copiaPersonagens[tamanho];
    copy(personagens, personagens + tamanho, copiaPersonagens);
    
    cout << "\n\n\n" << endl;

    int select = 0;
    cout<<  "[1] - Imprimir um trecho da lista \n"<< 
            "[2] - Imprimir lista em ordem alfabetica \n"<<
            "[3] - Imprimir lista em ordem de altura \n" << 
            "[4] - Imprimir lista original \n\n"<< endl;

    cin >> select;

    switch (select) {
        case 1: 
            fflush (stdin);
            cout<< endl << "Digite a posicao inicial do trecho : ";
            int posMin, posMax;
            cin>> posMin;
            cout<< "Digite a posicao final do trecho : ";
            cin>> posMax;
            cout<< endl << endl ;


            for (int i = posMin-1; i < posMax; i++){
                cout << "PERSONAGEM " << copiaPersonagens[i].identificador << ": \n" << "Nome: " <<  copiaPersonagens[i].nome << "\n"  <<
                "Titulo do Desenho: " <<  copiaPersonagens[i].tituloDesenho << "\n" << "Altura: "<< copiaPersonagens[i].altura << " metros " << 
                "\n" << "Criador: " << copiaPersonagens[i].criador << "\n" << "Descricao: " << copiaPersonagens[i].bio << "\n" << endl;
                cout << endl;
                cout << "======================================================================================================================="<< "\n" << endl;
            }

            break;

        case 2:
            fflush (stdin);
            quickSortNome(copiaPersonagens, 0, tamanho-1);

            for (int i = 0; i < tamanho; i++){
                cout << "PERSONAGEM " << copiaPersonagens[i].identificador << ": \n" << "Nome: " <<  copiaPersonagens[i].nome << "\n"  <<
                "Titulo do Desenho: " <<  copiaPersonagens[i].tituloDesenho << "\n" << "Altura: "<< copiaPersonagens[i].altura << " metros " << 
                "\n" << "Criador: " << copiaPersonagens[i].criador << "\n" << "Descricao: " << copiaPersonagens[i].bio << "\n" << endl;
                cout << endl;
                cout << "======================================================================================================================="<< "\n" << endl;
            }

            break;

        case 3:
            fflush (stdin);

            quickSortAltura(copiaPersonagens, 0, tamanho-1);
            
            for (int i = 0; i < tamanho; i++){
                cout << "PERSONAGEM " << copiaPersonagens[i].identificador << ": \n" << "Nome: " <<  copiaPersonagens[i].nome << "\n"  <<
                "Titulo do Desenho: " <<  copiaPersonagens[i].tituloDesenho << "\n" << "Altura: "<< copiaPersonagens[i].altura << " metros " << 
                "\n" << "Criador: " << copiaPersonagens[i].criador << "\n" << "Descricao: " << copiaPersonagens[i].bio << "\n" << endl;
                cout << endl;
                cout << "======================================================================================================================="<< "\n" << endl;
            }
            
            break;
        
        case 4:
            fflush (stdin);
            
            for (int i = 0; i < tamanho; i++){
                cout << "PERSONAGEM " << personagens[i].identificador << ": \n" << "Nome: " <<  personagens[i].nome << "\n"  <<
                "Titulo do Desenho: " <<  personagens[i].tituloDesenho << "\n" << "Altura: "<< personagens[i].altura << " metros " << 
                "\n" << "Criador: " << personagens[i].criador << "\n" << "Descricao: " << personagens[i].bio << "\n" << endl;
                cout << endl;
                cout << "======================================================================================================================="<< "\n" << endl;
            }
            
            break;
        
        default:
            break;
        }
}



//PROCEDIMENTO PARA PESQUISAR ATRAVÉS DOS CAMPOS STRING, NOME, TITULO E CRADOR DE CADA PERSONAGEM.

void pesquisarNome(character personagens[], int tamanho){
    character copiaPersonagens[tamanho];
    copy(personagens, personagens + tamanho, copiaPersonagens);
    char nomeBusca[50];
    int encontrados[tamanho];
    int j = 0;
    char *ponteiro;

    quickSortNome(copiaPersonagens, 0, tamanho-1);
    
    fflush(stdin);
    cout << "\n\n\nDigite o nome do personagem que deseja encontrar: ";
    cin.getline(nomeBusca, 50);
    
    //Busca sequencial
    // ESSA ESTRURA FOI UTILIZADA PARA PESQUISAR UMA STRING DENTRO DE UMA STRING, POR ISSO A UTILIZAÇAO DE strstr:
    for (int i = 0; i < tamanho; i++) {
        ponteiro = strstr(minusculo(copiaPersonagens[i].nome), minusculo(nomeBusca));
        if (ponteiro) {
            encontrados[j] = i;
            j++;
        }           
    }

    if (j == 0) {
        cout << "Nenhum personagem foi encontrado com o nome " << nomeBusca << endl;
    }
    else {
        cout << "\nLista de personagens encontrados com o nome " << nomeBusca << ":" << endl;

        for (int i = 0; i < j; i++) {
            cout << "\n" << endl; 
            cout << "PERSONAGEM " <<copiaPersonagens[encontrados[i]].identificador << ": \n" << "Nome: " <<  copiaPersonagens[encontrados[i]].nome << "\n" << "Altura: "<< copiaPersonagens[encontrados[i]].altura << " metros "   << 
            "\n" << "Titulo do Desenho: " <<  copiaPersonagens[encontrados[i]].tituloDesenho << "\n" << "Criador: " << copiaPersonagens[encontrados[i]].criador << "\n" << "Descricao: " << copiaPersonagens[encontrados[i]].bio << "\n" << endl;
            cout << endl;
            cout << "=======================================================================================================================";               
        }
        cout << endl;            
    }     
    
    cout << "\n";               
}   


// PRCEDIMENTO PARA PESQUISAR UM PERSONAGEM QEU ESTA DENTRO DE UMA ALTURA MÍNIMA DIGITADA ATÉ UMA ALTURA MÁXIMA DIGITADA:

void pesquisarAltura(character personagens[], int tamanho){
    character copiaPersonagens[tamanho];
    copy(personagens, personagens + tamanho, copiaPersonagens);
    float alturaMin, alturaMax;
    int encontrados[tamanho], j = 0;

    quickSortAltura(copiaPersonagens, 0, tamanho-1);
    
    cout << endl;
    cout << "Altura minima: ";
    cin >> alturaMin;
    cout << "Altura maxima: ";
    cin >> alturaMax;

    //Busca sequencial
    for (int i = 0; i < tamanho; i++) {
            if (copiaPersonagens[i].altura >= alturaMin and copiaPersonagens[i].altura <= alturaMax) {
                encontrados[j] = i;
                j++;
            }            
    }

        if (j == 0) {
            cout << "Nenhum personagem foi encontrado com a altura entre " << alturaMin << " e " << alturaMax << endl;
        }
        else {
            cout << "\nLista de personagens encontrados com a altura entre " << alturaMin << " metros e " << alturaMax << " metros : " << endl;

            for (int i = 0; i < j; i++) {
                cout << "\n" << endl; 
                cout << "PERSONAGEM " <<copiaPersonagens[encontrados[i]].identificador << ": \n" << "Nome: " <<  copiaPersonagens[encontrados[i]].nome 
                    << "\n" << "Altura: "<< copiaPersonagens[encontrados[i]].altura << " metros " <<"\n" << "Titulo do Desenho: " 
                    <<  copiaPersonagens[encontrados[i]].tituloDesenho << "\n" << "Criador: " << copiaPersonagens[encontrados[i]].criador << "\n" 
                    << "Descricao: " << copiaPersonagens[encontrados[i]].bio << "\n" << endl;
                cout << endl;
                cout << "=======================================================================================================================";                
            }            
        }
    
    cout << "\n";
    cout << endl;
}


//PROCEDIMNETO PARA ADICIONAR UM NOVO PERSONAGEM:

void addPersonagem(character personagens[], int& tamanho, char cabecalho[], int& capacidade){
    char nomeAdd[30], tituloAdd[30], criadorAdd[80], bioAdd[500];
    float alturaAdd;
    
    tamanho++;
    character* temp = new character[capacidade+1];
    for (int i = 0; i < tamanho-1; i++) {
        temp[i] = personagens[i];
    }
    delete[] personagens;
    personagens = temp;
    capacidade+=1;


    personagens[tamanho-1].identificador = tamanho;
    
    fflush(stdin);
    cout << "\n\nInforme o nome do personagem que deseja adicionar: ";
    cin.getline(nomeAdd, 30);
    strcpy(personagens[tamanho-1].nome, nomeAdd);

    fflush(stdin);
    cout << "Informe o título do desenho do personagem: ";
    cin.getline(tituloAdd, 30);
    strcpy(personagens[tamanho-1].tituloDesenho, tituloAdd);

    fflush(stdin);
    cout << "Informe o criador do personagem: ";
    cin.getline(criadorAdd, 80);
    strcpy(personagens[tamanho-1].criador, criadorAdd);

    fflush(stdin);
    cout << "Informe a altura do personagem: ";
    cin >> alturaAdd;
    cin.ignore();
    personagens[tamanho-1].altura = alturaAdd;

    fflush(stdin);
    cout << "Informe a descricao do personagem: ";
    cin.getline(bioAdd, 500);
    strcpy(personagens[tamanho-1].bio, bioAdd);

    cout << endl;
    cout<< "Personagem adicionado com sucesso!\n\n" << endl;
    
    cout << "\nOnde deseja salvar as alteracoes? " << endl 
        << "[1] - Arquivo.csv (sera criado um arquivo binario com o mesmo nome)\n"
        << "[2] - Arquivo Binario\n";

    int arquivo;
    cin >> arquivo;

    cout << "Qual o nome do arquivo? (sem a extensao, ex: .csv)" << endl;
    cout <<  "\nATENCAO: Caso o nome do arquivo ja existir, o mesmo sera substituido!" << endl;
    string nomeArq;
    cin >> nomeArq;
    
    if (arquivo == 1) {
        ofstream arquivoAdd (nomeArq + ".csv");
    
        arquivoAdd << cabecalho << endl;
        for (int i = 0; i < tamanho; i++){
            arquivoAdd << personagens[i].identificador << ';' <<  personagens[i].nome << ";" <<  personagens[i].tituloDesenho <<
            ';'<<  personagens[i].criador << ';' << personagens[i].altura << ';' << personagens[i].bio << "\n";
        }

        ofstream arqBin (nomeArq + ".bin", ios::binary);

        for (int i = 0; i < 80; i++) {
            arqBin.write((char*) &cabecalho[i], sizeof(char));
        }
        
        for (int i = 0; i < tamanho; i++) {
            arqBin.write((char*) &personagens[i], sizeof(character));
        }
    }
    else {
        ofstream arqBin (nomeArq + ".bin", ios::binary);

        for (int i = 0; i < 80; i++) {
            arqBin.write((char*) &cabecalho[i], sizeof(char));
        }
        
        for (int i = 0; i < tamanho; i++) {
            arqBin.write((char*) &personagens[i], sizeof(character));
        }
    }
    

}


//PROCEDIMENTO PARA EDITAR OS CAMPOS DE UM PERSONAGEM:

void editarPersonagem(character personagens[], int tamanho, char cabecalho[]){
    int identificadorBuscado;
    int select = 0;
    cout << "\n\nDigite o identificador do personagem a ser editado :" <<  endl;
    cin >> identificadorBuscado;

    cout << "PERSONAGEM " << personagens[identificadorBuscado-1].identificador << ": \n" << "Nome: " <<  personagens[identificadorBuscado-1].nome << "\n" 
        << "Altura: "<< personagens[identificadorBuscado-1].altura << " metros " << "\n" << "Titulo do Desenho: " 
        <<  personagens[identificadorBuscado-1].tituloDesenho << "\n" << "Criador: " << personagens[identificadorBuscado-1].criador 
        << "\n" << "Descricao: " << personagens[identificadorBuscado-1].bio << "\n" << endl;
    cout << endl;
    cout << "======================================================================================================================="<< "\n" << endl;
    

    cout << "Voce deseja alterar os dados desse identificador ? \n"<<
    "[1]- Sim " << endl << "[2]- Nao" << endl;

    cout << "\n\n";

    int numeroDigitado;
    cin >> numeroDigitado;

    cout << endl;

    if (numeroDigitado==1){

        do{
            char novoNome [30];
            float novaAltura;
            char novoTitulo[30];
            char novoCriador[30];
            char novaDescricao[30];

            switch (select)
            {
            case 0:
                cout<< "[1] - Editar nome do personagem \n"<<
                "[2] - Editar Altura \n"<<
                "[3] - Editar o Titulo \n"<< 
                "[4] - Editar o nome do criador \n"<<
                "[5] - Editar Descricao \n\n"<<
                "[-1] - Para sair da edicao\n" << endl;
                break;

            case 1:
                fflush (stdin);
                cout<< "Digite o novo nome do personagem : ";
                cin.getline(novoNome, 30);
                strcpy(personagens[identificadorBuscado-1].nome, novoNome);
                cout << "\nNome do personagem alterado com sucesso!\n" << endl;
                
                break;

            case 2:
                fflush (stdin);
                cout<< "Digite a nova altura do personagem : ";
                cin  >> novaAltura;
                cin.ignore();
                personagens[identificadorBuscado-1].altura= novaAltura;
                cout << "\nAltura do personagem alterada com sucesso!\n" << endl;
                
                break;

            case 3:
                fflush (stdin);
                cout<< "Digite o novo titulo do desenho : ";
                cin.getline(novoTitulo, 30);
                strcpy(personagens[identificadorBuscado-1].tituloDesenho, novoTitulo);
                cout << "\nTítulo do desenho do personagem alterado com sucesso!\n" << endl;
                
                break;
            
            case 4:
                fflush (stdin);
                cout<< "Digite o novo criador do personagem : ";
                cin.getline(novoCriador, 80);
                strcpy(personagens[identificadorBuscado-1].criador, novoCriador);
                cout << "\nCriador do personagem alterado com sucesso!\n" << endl;
                
                break;

            case 5:
                fflush (stdin);
                cout<< "Digite a nova descriacao personagem : ";
                cin.getline(novaDescricao, 500);
                strcpy(personagens[identificadorBuscado-1].bio, novaDescricao);
                cout << "\nDescrição do personagem alterada com sucesso!\n" << endl;
                
                break;
            
            default:
                break;
            }
            if (select != -1 and select != 0) {
                cout << "[0] - Para voltar ao menu de edicao" << endl;
                cout << "[-1] - Para encerrar a edicao" << endl;
                cin >> select;
                cin.ignore();
            }
            else {
                cin >> select;
                cin.ignore();
            }
        }while(select!= -1);

    cout << "\nOnde deseja salvar as alteracoes? " << endl 
        << "[1] - Arquivo.csv (sera criado um arquivo binario com o mesmo nome)\n"
        << "[2] - Arquivo Binario\n";

    int arquivo;
    cin >> arquivo;

    cout << "Qual o nome do arquivo? (sem a extensao, ex: .csv)" << endl;
    cout <<  "\nATENCAO: Caso o nome do arquivo ja existir, o mesmo sera substituido!" << endl;
    string nomeArq;
    cin >> nomeArq;
    
    if (arquivo == 1) {
        ofstream arquivoAdd (nomeArq + ".csv");
    
        arquivoAdd << cabecalho << endl;
        for (int i = 0; i < tamanho; i++){
            arquivoAdd << personagens[i].identificador << ';' <<  personagens[i].nome << ";" <<  personagens[i].tituloDesenho <<
            ';'<<  personagens[i].criador << ';' << personagens[i].altura << ';' << personagens[i].bio << "\n";
        }

        ofstream arqBin (nomeArq + ".bin", ios::binary);

        for (int i = 0; i < 80; i++) {
            arqBin.write((char*) &cabecalho[i], sizeof(char));
        }
        
        for (int i = 0; i < tamanho; i++) {
            arqBin.write((char*) &personagens[i], sizeof(character));
        }
    }
    else {
        ofstream arqBin (nomeArq + ".bin", ios::binary);

        for (int i = 0; i < 80; i++) {
            arqBin.write((char*) &cabecalho[i], sizeof(char));
        }
        
        for (int i = 0; i < tamanho; i++) {
            arqBin.write((char*) &personagens[i], sizeof(character));
        }
    }            
    
    }
    cout << "\n" << endl;
}

//PROCEDIMENTO PARA DELETAR UM PERSONAGEM:

void deletarPersonagem(character personagens[], int& tamanho, char cabecalho[]){

    int identificadorBuscado,  numeroDigitado;

    fflush(stdin);
    cout << "Digite o identificador do peronagem que deseja retirar: ";
    cin >> identificadorBuscado;

    cout << "PERSONAGEM " << personagens[identificadorBuscado-1].identificador << ": \n" << "Nome: " <<  personagens[identificadorBuscado-1].nome << "\n" 
        << "Altura: "<< personagens[identificadorBuscado-1].altura << " metros " << "\n" << "Titulo do Desenho: " 
        <<  personagens[identificadorBuscado-1].tituloDesenho << "\n" << "Criador: " << personagens[identificadorBuscado-1].criador 
        << "\n" << "Descricao: " << personagens[identificadorBuscado-1].bio << "\n" << endl;

    cout << "Voce deseja remover os dados desse identificador ? \n"<<
    "[1]- Sim " << endl << "[2]- Nao" << endl;

    cin >> numeroDigitado;

    if (numeroDigitado == 1){
        for (int i = identificadorBuscado; i < tamanho; i++){
            strcpy(personagens[i-1].nome, personagens[i].nome);
            strcpy(personagens[i-1].tituloDesenho, personagens[i].tituloDesenho);
            personagens[i-1].altura = personagens[i].altura;
            strcpy(personagens[i-1].criador, personagens[i].criador);
            strcpy(personagens[i-1].bio, personagens[i].bio);
        }
        tamanho--;
        

        cout << "\nOnde deseja salvar as alteracoes? " << endl 
        << "[1] - Arquivo.csv (sera criado um arquivo binario com o mesmo nome)\n"
        << "[2] - Arquivo Binario\n";

        int arquivo;
        cin >> arquivo;

        cout << "Qual o nome do arquivo? (sem a extensao, ex: .csv)" << endl;
        cout <<  "\nATENCAO: Caso o nome do arquivo ja existir, o mesmo sera substituido!" << endl;
        string nomeArq;
        cin >> nomeArq;
        
        if (arquivo == 1) {
            ofstream arquivoAdd (nomeArq + ".csv");
        
            arquivoAdd << cabecalho << endl;
            for (int i = 0; i < tamanho; i++){
                arquivoAdd << personagens[i].identificador << ';' <<  personagens[i].nome << ";" <<  personagens[i].tituloDesenho <<
                ';'<<  personagens[i].criador << ';' << personagens[i].altura << ';' << personagens[i].bio << "\n";
            }

            ofstream arqBin (nomeArq + ".bin", ios::binary);

            for (int i = 0; i < 80; i++) {
                arqBin.write((char*) &cabecalho[i], sizeof(char));
            }

            for (int i = 0; i < tamanho; i++) {
                arqBin.write((char*) &personagens[i], sizeof(character));
            }

        }
        else {
            ofstream arqBin (nomeArq + ".bin", ios::binary);

            for (int i = 0; i < 80; i++) {
                arqBin.write((char*) &cabecalho[i], sizeof(char));
            }
            
            for (int i = 0; i < tamanho; i++) {
                arqBin.write((char*) &personagens[i], sizeof(character));
            }

        }

        cout << "Personagem removido com sucesso!\n";
    }
}

void exportarArquivo (character personagens[], int tamanho, char cabecalho[]) {
    cout << "\nEm qual formato deseja exportar o arquivo? " << endl 
        << "[1] - Arquivo.csv (sera criado um arquivo binario com o mesmo nome)\n"
        << "[2] - Arquivo Binario\n";

        int arquivo;
        cin >> arquivo;

        cout << "Qual o nome do arquivo? (sem a extensao, ex: .csv)" << endl;
        cout <<  "\nATENCAO: Caso o nome do arquivo ja existir, o mesmo sera substituido!" << endl;
        string nomeArq;
        cin >> nomeArq;
        
        cout << "[1] - Salvar o arquivo nao ordenado"
            << "[2] - Salvar o arquivo em ordem alfabetica"
            << "[3] - Salvar o arquivo em ordem de altura\n";

        int arqTipo;
        cin >> arqTipo;

        if (arquivo == 1) {
            if (arqTipo == 1) {
                ofstream arquivoAdd (nomeArq + ".csv");
            
                arquivoAdd << cabecalho << endl;
                for (int i = 0; i < tamanho; i++){
                    arquivoAdd << personagens[i].identificador << ';' <<  personagens[i].nome << ";" <<  personagens[i].tituloDesenho <<
                    ';'<<  personagens[i].criador << ';' << personagens[i].altura << ';' << personagens[i].bio << "\n";
                }

                ofstream arqBin (nomeArq + ".bin", ios::binary);

                for (int i = 0; i < 80; i++) {
                    arqBin.write((char*) &cabecalho[i], sizeof(char));
                }

                for (int i = 0; i < tamanho; i++) {
                    arqBin.write((char*) &personagens[i], sizeof(character));
                }
            
            }

            else if (arqTipo == 2) {
                character copiaPersonagens[tamanho];
                copy(personagens, personagens + tamanho, copiaPersonagens);

                quickSortNome(copiaPersonagens, 0, tamanho-1);
                
                ofstream arquivoAdd (nomeArq + ".csv");
            
                arquivoAdd << cabecalho << endl;
                for (int i = 0; i < tamanho; i++){
                    arquivoAdd << copiaPersonagens[i].identificador << ';' <<  copiaPersonagens[i].nome << ";" <<  copiaPersonagens[i].tituloDesenho <<
                    ';'<<  copiaPersonagens[i].criador << ';' << copiaPersonagens[i].altura << ';' << copiaPersonagens[i].bio << "\n";
                }

                ofstream arqBin (nomeArq + ".bin", ios::binary);

                for (int i = 0; i < 80; i++) {
                    arqBin.write((char*) &cabecalho[i], sizeof(char));
                }

                for (int i = 0; i < tamanho; i++) {
                    arqBin.write((char*) &copiaPersonagens[i], sizeof(character));
                }
            }

            else if (arqTipo == 3) {
                character copiaPersonagens[tamanho];
                copy(personagens, personagens + tamanho, copiaPersonagens);

                quickSortAltura(copiaPersonagens, 0, tamanho-1);
                
                ofstream arquivoAdd (nomeArq + ".csv");
            
                arquivoAdd << cabecalho << endl;
                for (int i = 0; i < tamanho; i++){
                    arquivoAdd << copiaPersonagens[i].identificador << ';' <<  copiaPersonagens[i].nome << ";" <<  copiaPersonagens[i].tituloDesenho <<
                    ';'<<  copiaPersonagens[i].criador << ';' << copiaPersonagens[i].altura << ';' << copiaPersonagens[i].bio << "\n";
                }

                ofstream arqBin (nomeArq + ".bin", ios::binary);

                for (int i = 0; i < 80; i++) {
                    arqBin.write((char*) &cabecalho[i], sizeof(char));
                }

                for (int i = 0; i < tamanho; i++) {
                    arqBin.write((char*) &copiaPersonagens[i], sizeof(character));
                }
            }
        }
        else {
            if (arqTipo == 1) {
                ofstream arqBin (nomeArq + ".bin", ios::binary);

                for (int i = 0; i < 80; i++) {
                    arqBin.write((char*) &cabecalho[i], sizeof(char));
                }
                
                for (int i = 0; i < tamanho; i++) {
                    arqBin.write((char*) &personagens[i], sizeof(character));
                }
            }
            else if (arqTipo == 2) {
                character copiaPersonagens[tamanho];
                copy(personagens, personagens + tamanho, copiaPersonagens);

                quickSortNome(copiaPersonagens, 0, tamanho-1);
                
                ofstream arqBin (nomeArq + ".bin", ios::binary);

                for (int i = 0; i < 80; i++) {
                    arqBin.write((char*) &cabecalho[i], sizeof(char));
                }
                
                for (int i = 0; i < tamanho; i++) {
                    arqBin.write((char*) &copiaPersonagens[i], sizeof(character));
                }
            }
            else if (arqTipo == 3) {
                character copiaPersonagens[tamanho];
                copy(personagens, personagens + tamanho, copiaPersonagens);

                quickSortAltura(copiaPersonagens, 0, tamanho-1);
                
                ofstream arqBin (nomeArq + ".bin", ios::binary);

                for (int i = 0; i < 80; i++) {
                    arqBin.write((char*) &cabecalho[i], sizeof(char));
                }
                
                for (int i = 0; i < tamanho; i++) {
                    arqBin.write((char*) &copiaPersonagens[i], sizeof(character));
                }
            }

        }

        cout << "Arquivo exportado com sucesso!\n";

}


int main(){
    int capacidade = 50;
    character* personagens = new character[capacidade];

    char cabecalho[80];
    char lixo;
    int tamanho = 0;

    cout << "Informe a opcao de arquivo que deseja ler: " << endl;
    cout << "\n\n\nTipos de arquivo: \n\n"
                << "[1] -  Arquivo .CSV\n"
                << "[2] -  Arquivo Binario \n"; 
    
    int arquivo;
    cin >> arquivo;

    cout << "Informe o nome do arquivo (sem a extensao, ex: .csv):\n" << endl;
    string nomeArq;
    cin >> nomeArq;

    ifstream arqPersonagens;

    if (arquivo == 1) {
        arqPersonagens.open(nomeArq + ".csv");
    }
    else {
        arqPersonagens.open(nomeArq + ".bin", ios::binary);
    }

    if (not arqPersonagens){
        cout<< "Arquivo nao encontrado!"<< endl;
    }
    else {
    
        if (arquivo == 1) {
            ofstream arqBin (nomeArq + ".bin", ios::binary);
        
            arqPersonagens.getline(cabecalho, 80);

            while (arqPersonagens >> personagens[tamanho].identificador) {
                if (tamanho >= capacidade - 1) {
                    character* temp = new character[capacidade+10];
                    for (int i = 0; i < capacidade; i++) {
                        temp[i] = personagens[i];
                    }
                    delete[] personagens;
                    personagens = temp;
                    capacidade+=10;
                }

                arqPersonagens >> lixo;
                arqPersonagens.getline(personagens[tamanho].nome, 30, ';');
                arqPersonagens.getline(personagens[tamanho].tituloDesenho, 30, ';');
                arqPersonagens.getline(personagens[tamanho].criador, 80, ';');
                arqPersonagens >> personagens[tamanho].altura;
                arqPersonagens >> lixo;
                arqPersonagens.getline(personagens[tamanho].bio, 500);
                tamanho++;
                fflush(stdin);
            }

            //escreve arquivo binário
            for (int i = 0; i < 80; i++) {
                arqBin.write((char*) &cabecalho[i], sizeof(char));
            }
            

            for (int i = 0; i < tamanho; i++) {
                arqBin.write((char*) &personagens[i], sizeof(character));
            }
            
            
        }
        else {
            //Le arquivo binario
            arqPersonagens.seekg(0, ios::end);
            int tamanhoArquivo = arqPersonagens.tellg();

            arqPersonagens.seekg(0, ios::beg);

            int tamanhoMax = tamanhoArquivo / sizeof(character);

            for (int i = 0; i < 80; i++) {
                arqPersonagens.read((char*) &cabecalho[i], sizeof(char));
            }
            

            while (tamanho < tamanhoMax and arqPersonagens.read((char*)&personagens[tamanho], sizeof(character))) {
                if (tamanho >= capacidade - 1) {
                    character* temp = new character[capacidade+10];
                    for (int i = 0; i < capacidade; i++) {
                        temp[i] = personagens[i];
                    }
                    delete[] personagens;
                    personagens = temp;
                    capacidade+=10;
                }
                
                tamanho++;
            }

        }

        int select = 0;
        
        do {
            switch(select){
                case 0:
                    cout << "\n\n\nMetodos de Pesquisa: \n\n" 
                        << "[1] - Mostrar lista completa \n"
                        << "[2] - Pesquisar por nome \n" 
                        << "[3] - Pesquisar por altura \n" 
                        << "[4] - Adicionar personagem \n"
                        << "[5] - Editar personagem \n"
                        << "[6] - Retirar personagem \n"
                        << "[7] - Exportar arquivo\n\n" 
                        << "[-1] - Para encerrar o programa\n" << endl;
                    break;
                case 1:
                    imprimirLista(personagens, tamanho);
                    break;

                case 2:
                    pesquisarNome(personagens, tamanho);
                    break;

                case 3:
                    pesquisarAltura(personagens, tamanho);
                    break;

                case 4:
                    addPersonagem(personagens, tamanho, cabecalho, capacidade);
                    break;

                case 5:
                    editarPersonagem(personagens, tamanho, cabecalho);
                    break;

                case 6:
                    deletarPersonagem(personagens, tamanho, cabecalho);
                    break;

                case 7:
                    exportarArquivo(personagens, tamanho, cabecalho);
                    break;

                default:
                    cout << "Programa encerrado";
                    break;
            }

            if (select != -1 and select != 0) {
                cout << "[0] - Para voltar ao menu principal" << endl;
                cout << "[-1] - Para encerrar o programa" << endl;
                cin >> select;
                cin.ignore();
            }
            else {
                cin >> select;
                cin.ignore();
            }

        } while (select != -1);

        cout << "\n\nPrograma Encerrado!" << endl;
    }

    return 0;
}