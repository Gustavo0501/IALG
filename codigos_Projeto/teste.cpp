//Banco de dados de personagens de desenhos animados
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <iomanip>

using namespace std;

struct character{
    int identificador;
    string name;
    string creator;
    string tituloDesenho;
    float height;
    float heightMin;
    float heightMax;
    string bio;
};

void imprimirLista(character personagens[], int tamanho) {
    cout << "\n\n\n" << endl;
    
    for (int i = 0; i < tamanho; i++){
        cout << "PERSONAGEM " << personagens[i].identificador << ": \n" << "Nome: " <<  personagens[i].name << "\n" << "Altura: "<< personagens[i].height << " metros " << "\n" << "Titulo do Desenho: " <<  personagens[i].tituloDesenho << "\n" << "Criador: " << personagens[i].creator << "\n" << "Descricao: " << personagens[i].bio << "\n" << endl;
        cout << endl;
        cout << "======================================================================================================================="<< "\n" << endl;
    }
    
}

void searchName(character personagens[], int tamanho){
    string nomeBusca;
    int encontrados[tamanho] = {0};
    int select;
    int j = 0;
    
    cout << "Selecione a opcao que deseja buscar: " << endl;
    cout << "[1] - Buscar por nome do Personagem\n" << "[2] - Buscar por nome do Criador:\n" << "[3] - Buscar por titulo do desenho:\n" << endl;
    
    cin >> select;

    switch (select) {
    case 1:
        fflush(stdin);
        cout << "\n\n\nDigite o nome do personagem que deseja encontrar: ";
        getline(cin, nomeBusca);

        for (int i = 0; i < tamanho; i++) {
            if (personagens[i].name == nomeBusca) {
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
                cout << "PERSONAGEM " <<personagens[encontrados[i]].identificador << ": \n" << "Nome: " <<  personagens[encontrados[i]].name << "\n" << "Altura: "<< personagens[encontrados[i]].height << " metros "   << 
                "\n" << "Titulo do Desenho: " <<  personagens[encontrados[i]].tituloDesenho << "\n" << "Criador: " << personagens[encontrados[i]].creator << "\n" << "Descricao: " << personagens[i].bio << "\n" << endl;
                cout << endl;
                cout << "=======================================================================================================================";
                
            }
            
        }
        

        break;
    case 2:
        fflush(stdin);
        cout << "\n\n\nDigite o nome do criador do personagem que deseja encontrar: ";
        getline(cin, nomeBusca);

        for (int i = 0; i < tamanho; i++) {
            if (personagens[i].creator == nomeBusca) {
                encontrados[j] = i;
                j++;
            }
            
        }

        if (j == 0) {
            cout << "Nenhum personagem foi encontrado com o nome de criador" << nomeBusca << endl;
        }
        else {
            cout << "\nLista de personagens encontrados com o nome do criador " << nomeBusca << ":" << endl;

            for (int i = 0; i < j; i++) {
                cout << "\n" << endl; 
                cout << "PERSONAGEM " <<personagens[encontrados[i]].identificador << ": \n" << "Nome: " <<  personagens[encontrados[i]].name << "\n" << "Altura: "<< personagens[encontrados[i]].height << " metros "  <<
                "\n" << "Titulo do Desenho: " <<  personagens[encontrados[i]].tituloDesenho << "\n" << "Criador: " << personagens[encontrados[i]].creator << "\n" << "Descricao: " << personagens[i].bio << "\n" << endl;
                cout << endl;
                cout << "=======================================================================================================================";
            }
            
        }

        break;
    case 3:
        fflush(stdin);
        cout << "\n\n\nDigite o titulo do desenho do personagem que deseja encontrar: ";
        getline(cin, nomeBusca);

        for (int i = 0; i < tamanho; i++) {
            if (personagens[i].tituloDesenho == nomeBusca) {
                encontrados[j] = i;
                j++;
            }
            
        }

        if (j == 0) {
            cout << "Nenhum personagem foi encontrado com o titulo de desenho " << nomeBusca << endl;
        }
        else {
            cout << "\nLista de personagens encontrados com o tiulo de desenho " << nomeBusca << ":" << endl;

            for (int i = 0; i < j; i++) {
                cout << "\n" << endl; 
                cout << "PERSONAGEM " <<personagens[encontrados[i]].identificador << ": \n" << "Nome: " <<  personagens[encontrados[i]].name << "\n" << "Altura: "<< personagens[encontrados[i]].height << " metros "  <<
                "\n" << "Titulo do Desenho: " <<  personagens[encontrados[i]].tituloDesenho << "\n" << "Criador: " << personagens[encontrados[i]].creator << "\n" << "Descricao: " << personagens[i].bio << "\n" << endl;
                cout << endl;
                cout << "=======================================================================================================================";
                
            }
            
        }

        break;
    
    default:
        cout << "Opcao invalida!" << endl;
        break;
    }
    
    
    cout << "\n";               
}   


void searchHeight(character personagens[], int tamanho){

    float heightMin, heightMax;
    int encontrados[tamanho], j = 0;
    
    cout << "Altura minima: ";
    cin >> heightMin;
    cout << "Altura maxima: ";
    cin >> heightMax;

    for (int i = 0; i < tamanho; i++) {
            if (personagens[i].height >= heightMin and personagens[i].height <= heightMax) {
                encontrados[j] = i;
                j++;
            }
            
        }

        if (j == 0) {
            cout << "Nenhum personagem foi encontrado com a altura entre " << heightMin << " e " << heightMax << endl;
        }
        else {
            cout << "\nLista de personagens encontrados com a altura entre " << heightMin << " e " << heightMax << endl;

            for (int i = 0; i < j; i++) {
                cout << "\n" << endl; 
                cout << "PERSONAGEM " <<personagens[encontrados[i]].identificador << ": \n" << "Nome: " <<  personagens[encontrados[i]].name << "\n" << "Altura: "<< personagens[encontrados[i]].height << " metros " <<
                "\n" << "Titulo do Desenho: " <<  personagens[encontrados[i]].tituloDesenho << "\n" << "Criador: " << personagens[encontrados[i]].creator << "\n" << "Descricao: " << personagens[i].bio << "\n" << endl;
                cout << endl;
                cout << "=======================================================================================================================";
                
            }
            
        }
    
    cout << "\nLista de personagens encontrados que tem altura de no minimo: " << heightMin << " e no maximo:" << heightMax << " :" << endl;
    cout << "\n!Lista!" << endl;
    cout << "\n";
}

void addChar(character personagens[], int& tamanho, string cabecalho){
    string nomeAdd, tituloAdd, criadorAdd;
    
    tamanho++;

    personagens[tamanho-1].identificador = tamanho;
    
    fflush(stdin);
    cout << "Informe o nome do personagem que deseja adicionar: ";
    getline(cin, nomeAdd);
    personagens[tamanho-1].name = nomeAdd;

    fflush(stdin);
    cout << "Informe o titulo do desenho do personagem: ";
    getline(cin, tituloAdd);
    personagens[tamanho-1].tituloDesenho = tituloAdd;

    fflush(stdin);
    cout << "Informe o criador do personagem: ";
    getline(cin, criadorAdd);
    personagens[tamanho-1].creator = criadorAdd;

    cout<< "Personagem adicionado com sucesso!\n" << endl;
    
    ofstream arquivoAdd ("personagens.csv");
    
    arquivoAdd << cabecalho << endl;
    for (int i = 0; i < tamanho; i++){
        arquivoAdd << personagens[i].identificador << ',' <<  personagens[i].name << "," << '"' <<  personagens[i].tituloDesenho << '"' << ',' << '"' <<  personagens[i].creator << '"' << "\n";
    }
    

                
}

void delChar(character remPerso){
    fflush(stdin);
    cout << "Digite o nome do peronagem que deseja retirar: ";
    getline(cin,remPerso.name);
    cout << "Personagem removido com sucesso!\n";
}


int main(){

    //variaveis para pesquisa dos personagens
    character personagens[100];
    character height;
    character novoPerso;
    character remPerso;

    string cabecalhoLixo;
    char lixo;
    int i = 0, tamanho =0;

    ifstream arquivoPerso("personagens.csv");

    getline(arquivoPerso, cabecalhoLixo);

    while (arquivoPerso >> personagens[i].identificador) {
        arquivoPerso >> lixo;
        getline(arquivoPerso, personagens[i].name, ';');
        getline(arquivoPerso, personagens[i].tituloDesenho, ';');
        getline(arquivoPerso, personagens[i].creator, ';');
        arquivoPerso >> personagens[i].height;
        arquivoPerso >> lixo;
        getline(arquivoPerso, personagens[i].bio);
        i++;
        tamanho++;
        fflush(stdin);
    }

    


    int select = 0;
    
    do {
        //executando os comandos
        switch(select){
            case 0:
                cout << "\n\n\nMetodos de Pesquisa: \n\n" 
                    << "[1] - Mostrar lista completa \n"
                    << "[2] - Pesquisar por nome \n" 
                    << "[3] - Pesquisar por altura \n" 
                    << "[4] - Adicionar personagem \n"
                    << "[5] - Retirar personagem \n\n" 
                    << "[-1] - Para encerrar\n" << endl;
                break;
            case 1:
                imprimirLista(personagens, tamanho);
                break;

            case 2:
                searchName(personagens, tamanho);
                break;

            case 3:
                searchHeight(personagens, tamanho);
                break;

            case 4:
                addChar(personagens, tamanho, cabecalhoLixo);
                break;

            case 5:
                delChar(remPerso);
                break;

            
            default:
                cout << "Programa encerrado";
                break;
        }

        if (select != -1 and select != 0) {
            cout << "[0] - Para voltar ao menu" << endl;
            cout << "[-1] - Para encerrar" << endl;
            cin >> select;
        }
        else {
            cin >> select;
        }

    } while (select != -1);

    cout << "\n\nPrograma Encerrado!" << endl;

    return 0;
} 