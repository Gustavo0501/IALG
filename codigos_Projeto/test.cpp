/*#include <iostream>

using namespace std;

int main() {
    string nome = "Gustavo";
    string digitado;

    cin >> digitado;

    int i = 0;
    while(digitado[i] != '\0')


}*/

#include <iostream>

using namespace std;

// procedimento que converte uma string para maiúsculo
void maiusculo(string s1, char s2[]){
    int i = 0;
    while(s1[i] != '\0'){
        s2[i] = toupper(s1[i]);
        i++;
    }
    s2[i] = '\0'; // caracteer que indica o fim da string
}


int main() {
    string str1 = "Ola. Bom dia.";
    
    for (char& c : str1) {
        c = tolower(c);
    }
    
    cout << str1 << endl;
   


    return 0;
}