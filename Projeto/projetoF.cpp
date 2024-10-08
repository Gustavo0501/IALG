//INTEGRANTES DO GRUPO:
//Alexandre Marques Spinola Cardoso
//Gustavo do Carmo Resende
//Gustavo José Rodrigues Pereira

//TEMA: Personagens de desenhos animados

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


// FUNÇAO PARA TRANSFORMAR TODAS AS LETRAS DE UM VETOR DE CHAR EM LETRAS MINÚSCULAS:

char* minusculo(const char* palavra) {
    size_t comprimento = strlen(palavra); // Obter o comprimento da string de entrada
    char* resultado = new char[comprimento + 1]; // Criar um novo vetor para o resultado (mais 1 para o caractere nulo '\0')
    
    for (size_t i = 0; i < comprimento; i++) {
        resultado[i] = tolower(palavra[i]); // Transformar a letra em minúscula e armazená-la no vetor de resultadoado
    }
    
    resultado[comprimento] = '\0'; // Adicionar o caractere nulo para finalizar a string
    
    return resultado;
}

//PROCEDIMENTO PARA SALVAR O ARQUIVO EM .CSV E .BIN

void salvarCSV_BIN(character personagens[], int tamanho, char cabecalho[], string nomeArq) {
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

//PROCEDIMENTO PARA SALVAR O ARQUIVO APENAS EM .BIN

void salvarBIN (character personagens[], int tamanho, char cabecalho[], string nomeArq) {
    ofstream arqBin (nomeArq + ".bin", ios::binary);

    for (int i = 0; i < 80; i++) {
        arqBin.write((char*) &cabecalho[i], sizeof(char));
    }

    for (int i = 0; i < tamanho; i++) {
        arqBin.write((char*) &personagens[i], sizeof(character));
    }
}

//FUNÇÃO PARA PARTICIONAR OS NOMES PARA ORDENAÇÂO QUICK SORT (PARTICIONAMENTO DE LEMUTO)

int particionaNome (character personagens[], int p, int r) {
    char personagemPivo[30];
    strcpy(personagemPivo, personagens[r].nome);
    int j = p;
    int k;
    for (k = p; k < r; k++) {
        if (strcmp(minusculo(personagens[k].nome), minusculo(personagemPivo)) <= 0) {
            swap(personagens[j], personagens[k]);
            swap(personagens[j].identificador, personagens[k].identificador);
            j++; 
        } 
    }
    swap(personagens[j], personagens[r]);
    swap(personagens[j].identificador, personagens[r].identificador);
    return j; 
}

//PROCEDIMENTO PARA ORDENAÇÃO DE NOMES

void quickSortNome(character personagens[], int pos_personagemPivo, int fim) {
    int pos_novo_personagemPivo;
    if (pos_personagemPivo < fim) {
        pos_novo_personagemPivo = particionaNome(personagens, pos_personagemPivo, fim);
        quickSortNome(personagens, pos_personagemPivo, pos_novo_personagemPivo - 1); 
        quickSortNome(personagens, pos_novo_personagemPivo + 1, fim);
    }
}

//FUNÇÃO PARA PARTICIONAR AS ALTURAS PARA ORDENAÇÂO QUICK SORT (PARTICIONAMENTO DE LEMUTO)

int particionaAltura (character personagens[], int p, int r) {
    float personagemPivo;
    personagemPivo = personagens[r].altura;
    int j = p;
    int k;
    for (k = p; k < r; k++) {
        if (personagens[k].altura <= personagemPivo) {
            swap(personagens[j], personagens[k]);
            swap(personagens[j].identificador, personagens[k].identificador);
            j++; 
        } 
    }
    swap(personagens[j], personagens[r]);
    swap(personagens[j].identificador, personagens[r].identificador);
    return j; 
}


// PROCEDIMENTO PARA ORDENAÇÃO DE ALTURA

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
    //Criação de um novo vetor copia de personagens
    character copiaPersonagens[tamanho];
    copy(personagens, personagens + tamanho, copiaPersonagens);
    
    cout << "\n\n\n" << endl;

    int select = 0;

    // Menu de oções de impressão da lista
    cout<<  "[1] - Imprimir um trecho da lista \n"<< 
            "[2] - Imprimir lista em ordem alfabetica \n"<<
            "[3] - Imprimir lista em ordem de altura \n" << 
            "[4] - Imprimir lista original \n\n"<< endl;

    cin >> select;

    //Switch para selecionar a opção desejada
    switch (select) {
        case 1: 
            fflush (stdin);
            cout<< endl << "Digite a posicao inicial do trecho : ";
            int posMin, posMax;
            cin>> posMin;
            cout<< "Digite a posicao final do trecho : ";
            cin>> posMax;
            cout<< endl << endl ;

            //Impressão da lista
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
            
            //Chamada do procedimento para ordenação dos nomes
            quickSortNome(copiaPersonagens, 0, tamanho-1);

            //Impressão da lista
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

            //Chamada do procedimento para ordenação das alturas
            quickSortAltura(copiaPersonagens, 0, tamanho-1);
            
            
            //Impressão da lista
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
            
            //Impressão da lista
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



//PROCEDIMENTO PARA PESQUISAR ATRAVÉS DOS NOME DE CADA PERSONAGEM.

void pesquisarNome(character personagens[], int tamanho){
    //Criação de um novo vetor cópia de personagens
    character copiaPersonagens[tamanho];
    copy(personagens, personagens + tamanho, copiaPersonagens);
    char nomeBusca[50];
    int encontrados[tamanho];
    int j = 0;
    char *ponteiro;

    //Chamada do procedimento para ordenação dos nomes
    quickSortNome(copiaPersonagens, 0, tamanho-1);
    
    fflush(stdin);
    cout << "\n\n\nDigite o nome do personagem que deseja encontrar: ";
    cin.getline(nomeBusca, 50);
    
    //Busca sequencial
    // Essa estrutura foi utilizada para pesquisar uma string dentro de outra string, utilizando a função strstr:
    for (int i = 0; i < tamanho; i++) {
        //ponteiro utilizado para chamar a função e guardar seu valor, ao encontrar retorna um valor verdadeiro
        ponteiro = strstr(minusculo(copiaPersonagens[i].nome), minusculo(nomeBusca));
        
        //Cada personagemn encontrado é armazenado em uma posição do vetor "encontrados"
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

        //Impressão da lista de personagens encontrados
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
    //Criação de um novo vetor cópia de personagens
    character copiaPersonagens[tamanho];
    copy(personagens, personagens + tamanho, copiaPersonagens);
    float alturaMin, alturaMax;
    int encontrados[tamanho], j = 0;

    //Chamada do procedimento para ordenação das alturas
    quickSortAltura(copiaPersonagens, 0, tamanho-1);
    
    cout << endl;
    cout << "Altura minima: ";
    cin >> alturaMin;
    cout << "Altura maxima: ";
    cin >> alturaMax;

    //Busca sequencial
    for (int i = 0; i < tamanho; i++) {
            //Cada personagem encontrado é armazenado em uma posição do vetor "encontrados"
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

            //Impressão da lista de personagens encontrados
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


//PROCEDIMENTO PARA ADICIONAR UM NOVO PERSONAGEM:

void addPersonagem(character personagens[], int& tamanho, char cabecalho[], int& capacidade){
    char nomeAdd[30], tituloAdd[30], criadorAdd[80], bioAdd[500];
    float alturaAdd;
    
    tamanho++; //O tamanho é acrescentado para entrada de um novo personagem no final da lista
    
    //Um redimensionamento é feito para garantir que o vetor tenha espaço suficiente para o novo personagem
    if (tamanho > capacidade) {
        character* temp = new character[capacidade+1];
        for (int i = 0; i < tamanho-1; i++) {
            temp[i] = personagens[i];
        }
        delete[] personagens;
        personagens = temp;
        capacidade+=1;
    }
    

    //Criação de um novo indentificador
    personagens[tamanho-1].identificador = tamanho;
    
    //Entrada do nome
    fflush(stdin);
    cout << "\n\nInforme o nome do personagem que deseja adicionar: ";
    cin.getline(nomeAdd, 30);
    strcpy(personagens[tamanho-1].nome, nomeAdd);

    //Entrada do título do desenho
    fflush(stdin);
    cout << "Informe o título do desenho do personagem: ";
    cin.getline(tituloAdd, 30);
    strcpy(personagens[tamanho-1].tituloDesenho, tituloAdd);

    //Entrada do nome do criador
    fflush(stdin);
    cout << "Informe o criador do personagem: ";
    cin.getline(criadorAdd, 80);
    strcpy(personagens[tamanho-1].criador, criadorAdd);

    //Entrada da altura
    fflush(stdin);
    cout << "Informe a altura do personagem: ";
    cin >> alturaAdd;
    cin.ignore();
    personagens[tamanho-1].altura = alturaAdd;

    //Entrada da descrição
    fflush(stdin);
    cout << "Informe a descricao do personagem: ";
    cin.getline(bioAdd, 500);
    strcpy(personagens[tamanho-1].bio, bioAdd);

    cout << endl;
    
    //Menu para opções de salvamento do arquivo
    cout << "\nOnde deseja salvar as alteracoes? " << endl 
        << "[1] - Arquivo.csv (sera criado um arquivo binario com o mesmo nome)\n"
        << "[2] - Arquivo Binario\n";

    int arquivo;
    cin >> arquivo;

    //Entrada do nome do arquivo
    cout << "Qual o nome do arquivo? (sem a extensao, ex: .csv)" << endl;
    cout <<  "\nATENCAO: Caso o nome do arquivo ja existir, o mesmo sera substituido!" << endl;
    string nomeArq;
    cin >> nomeArq;
    
    //Na opção 1, um arquivo .csv é criado e também um arquivo .bin
    if (arquivo == 1) {
        salvarCSV_BIN(personagens, tamanho, cabecalho, nomeArq);
    }
    //Na opção 2, apenas o arquivo .bin é criado
    else {
        salvarBIN(personagens, tamanho, cabecalho, nomeArq);
    }
    
    cout<< "\nPersonagem adicionado com sucesso!\n\n" << endl;

}


//PROCEDIMENTO PARA EDITAR OS CAMPOS DE UM PERSONAGEM:

void editarPersonagem(character personagens[], int tamanho, char cabecalho[]){
    int identificadorBuscado;
    int select = 0;
    cout << "\n\nDigite o identificador do personagem a ser editado :" <<  endl;
    cin >> identificadorBuscado;

    //Impressão dos dados do personagem escolhido
    cout << "\n\nPERSONAGEM " << personagens[identificadorBuscado-1].identificador << ": \n" << "Nome: " <<  personagens[identificadorBuscado-1].nome << "\n" 
        << "Altura: "<< personagens[identificadorBuscado-1].altura << " metros " << "\n" << "Titulo do Desenho: " 
        <<  personagens[identificadorBuscado-1].tituloDesenho << "\n" << "Criador: " << personagens[identificadorBuscado-1].criador 
        << "\n" << "Descricao: " << personagens[identificadorBuscado-1].bio << "\n" << endl;
    cout << endl;
    cout << "======================================================================================================================="<< "\n" << endl;
    

    //Confirmação da alteração do personagem escolhido
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

            //Menu de edição do personagem, o usuário poderá escolher as informações que deseja editar
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

    //Menu para opções de salvamento do arquivo
    cout << "\nOnde deseja salvar as alteracoes? " << endl 
        << "[1] - Arquivo.csv (sera criado um arquivo binario com o mesmo nome)\n"
        << "[2] - Arquivo Binario\n";

    int arquivo;
    cin >> arquivo;
    
    //Entrada do nome do arquivo
    cout << "Qual o nome do arquivo? (sem a extensao, ex: .csv)" << endl;
    cout <<  "\nATENCAO: Caso o nome do arquivo ja existir, o mesmo sera substituido!" << endl;
    string nomeArq;
    cin >> nomeArq;
    
    //Na opção 1, um arquivo .csv é criado e também um arquivo .bin
    if (arquivo == 1) {
        salvarCSV_BIN(personagens, tamanho, cabecalho, nomeArq);
    }
    //Na opção 2, apenas o arquivo .bin é criado
    else {
        salvarBIN(personagens, tamanho, cabecalho, nomeArq);
    }            
    
    cout << "Edição colcluída com sucesso!\n"<< endl;
    }
    cout << "\n\n" << endl;
}

//PROCEDIMENTO PARA DELETAR UM PERSONAGEM:

void deletarPersonagem(character personagens[], int& tamanho, char cabecalho[]){

    int identificadorBuscado,  numeroDigitado;

    fflush(stdin);
    cout << "Digite o identificador do peronagem que deseja retirar: ";
    cin >> identificadorBuscado;

    cout << "\n\nPERSONAGEM " << personagens[identificadorBuscado-1].identificador << ": \n" << "Nome: " <<  personagens[identificadorBuscado-1].nome << "\n" 
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
        
        //Menu para opções de salvamento do arquivo
        cout << "\nOnde deseja salvar as alteracoes? " << endl 
        << "[1] - Arquivo.csv (sera criado um arquivo binario com o mesmo nome)\n"
        << "[2] - Arquivo Binario\n";

        int arquivo;
        cin >> arquivo;

        //Entrada do nome do arquivo
        cout << "Qual o nome do arquivo? (sem a extensao, ex: .csv)" << endl;
        cout <<  "\nATENCAO: Caso o nome do arquivo ja existir, o mesmo sera substituido!" << endl;
        string nomeArq;
        cin >> nomeArq;
        
        //Na opção 1, um arquivo .csv é criado e também um arquivo .bin
        if (arquivo == 1) {
            salvarCSV_BIN(personagens, tamanho, cabecalho, nomeArq);

        }
        //Na opção 2, apenas o arquivo .bin é criado
        else {
            salvarBIN(personagens, tamanho, cabecalho, nomeArq);

        }

        cout << "\n\nPersonagem removido com sucesso!\n\n" << endl;
    }
}


void exportarArquivo (character personagens[], int tamanho, char cabecalho[]) {
    //Menu para opções de salvamento do arquivo
    cout << "\nEm qual formato deseja exportar o arquivo? " << endl 
        << "[1] - Arquivo.csv (sera criado um arquivo binario com o mesmo nome)\n"
        << "[2] - Arquivo Binario\n";

        int arquivo;
        cin >> arquivo;

        //Entrada do nome do arquivo
        cout << "Qual o nome do arquivo? (sem a extensao, ex: .csv)" << endl;
        cout <<  "\nATENCAO: Caso o nome do arquivo ja existir, o mesmo sera substituido!" << endl;
        string nomeArq;
        cin >> nomeArq;
        
        //Menu de opções de tipos de ordenação
        cout << "[1] - Salvar o arquivo nao ordenado\n"
            << "[2] - Salvar o arquivo em ordem alfabetica\n"
            << "[3] - Salvar o arquivo em ordem de altura\n";

        int arqTipo;
        cin >> arqTipo;

        //Na opção 1, o arquivo é salvo em .csv e .bin
        if (arquivo == 1) {
            //Na opção 1, o arquivo é salvo de forma nao ordenada
            if (arqTipo == 1) {
                salvarCSV_BIN(personagens, tamanho, cabecalho, nomeArq);
            
            }
            //Na opção 2, o arquivo é salvo em ordem alfabética
            else if (arqTipo == 2) {
                character copiaPersonagens[tamanho];
                copy(personagens, personagens + tamanho, copiaPersonagens);

                quickSortNome(copiaPersonagens, 0, tamanho-1);
                
                salvarCSV_BIN(copiaPersonagens, tamanho, cabecalho, nomeArq);
            }

            //Na opção 3, o arquivo é salvo em ordem de altura
            else if (arqTipo == 3) {
                character copiaPersonagens[tamanho];
                copy(personagens, personagens + tamanho, copiaPersonagens);

                quickSortAltura(copiaPersonagens, 0, tamanho-1);
                
                salvarCSV_BIN(copiaPersonagens, tamanho, cabecalho, nomeArq);
            }
        }
        //Na opção 2, o arquivo é salvo apenas em .bin
        else {
            //Na opção 1, o arquivo é salvo de forma nao ordenada
            if (arqTipo == 1) {
                salvarBIN(personagens, tamanho, cabecalho, nomeArq);
            }
            //Na opção 2, o arquivo é salvo em ordem alfabética
            else if (arqTipo == 2) {
                character copiaPersonagens[tamanho];
                copy(personagens, personagens + tamanho, copiaPersonagens);

                quickSortNome(copiaPersonagens, 0, tamanho-1);
                
                salvarBIN(copiaPersonagens, tamanho, cabecalho, nomeArq);
            }
            //Na opção 3, o arquivo é salvo em ordem de altura
            else if (arqTipo == 3) {
                character copiaPersonagens[tamanho];
                copy(personagens, personagens + tamanho, copiaPersonagens);

                quickSortAltura(copiaPersonagens, 0, tamanho-1);
                
                salvarBIN(copiaPersonagens, tamanho, cabecalho, nomeArq);
            }

        }

        cout << "Arquivo exportado com sucesso!\n";

}


int main() {
    //Criação do vetor pra armazenar os dados do arquivo
    int capacidade = 50;
    character* personagens = new character[capacidade];

    char cabecalho[80];
    char lixo;
    int tamanho = 0;

    //Opções de importação de arquivo
    cout << "Informe a opcao de arquivo que deseja ler: " << endl;
    cout << "\n\n\nTipos de arquivo: \n\n"
                << "[1] -  Arquivo .CSV\n"
                << "[2] -  Arquivo Binario \n"; 
    
    int arquivo;
    cin >> arquivo;

    //Entrada do nome do arquivo que deseja importar
    cout << "Informe o nome do arquivo (sem a extensao, ex: .csv): ";
    string nomeArq;
    cin >> nomeArq;

    cout << endl;

    ifstream arqPersonagens;

    //Na opção 1, é aberto um arquivo .csv
    if (arquivo == 1) {
        arqPersonagens.open(nomeArq + ".csv");
    }
    //Na opção 2, é aberto um arquivo .bin
    else {
        arqPersonagens.open(nomeArq + ".bin", ios::binary);
    }

    //Caso não seja possível abrir o arquivo, uma mensagem de erro é exibida e o programa é encerrado
    if (not arqPersonagens){
        cout<< "Arquivo nao encontrado!"<< endl;
    }
    else {
    
        if (arquivo == 1) {
            //Criação de um arquivo binário
            ofstream arqBin (nomeArq + ".bin", ios::binary);
        
            //Lendo um arquivo .csv
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

            //Escreve no arquivo binário
            for (int i = 0; i < 80; i++) {
                arqBin.write((char*) &cabecalho[i], sizeof(char));
            }
            

            for (int i = 0; i < tamanho; i++) {
                arqBin.write((char*) &personagens[i], sizeof(character));
            }
            
            
        }
        else {
            //Le arquivo binario
            
            //Pegando informações de tamanho do arquivo
            arqPersonagens.seekg(0, ios::end);
            int tamanhoArquivo = arqPersonagens.tellg();

            arqPersonagens.seekg(0, ios::beg);

            int tamanhoMax = tamanhoArquivo / sizeof(character);

            //Leitura dos dados do arquivo binário
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
        
        //MENU PRINCIPAL DO PROGRAMA
        
        do {
            switch(select){
                case 0:
                    cout << "\n\n\nMENU PRINCIPAL: \n\n" 
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

    }
    
    cout << "\n\nPrograma Encerrado!" << endl;

    return 0;
}