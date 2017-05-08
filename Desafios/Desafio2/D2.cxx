#include <iostream>     
#include <fstream>      
#include <vector>
#include <map>
#include <stack>
int main () {
  int answer;
  std::ofstream out("saida.txt");
  std::stack<int> pilha;                    // empty stack
  std::cout << "tamanho da pilha: " << pilha.size() << '\n';//mostra o tamanho da pilha

  char str[256];//def de uma string (vai ser o nome do meu arquivo)

  std::cout << "Enter the name of an existing text file: ";//print para o user
  std::cin.get (str,256);//pega a resp como nome do arquivo

  std::ifstream is(str);  //abre o arquivo com "is"   
  std::map<char, int> associa;//cria um mapa(tipo dicionário) que associa um char à um int


  char ch;//criando ch para ser o num de parametrso recebido ainda como char
  is >> ch;
  int number_of_letters = ch - '0';//transforma em int
  
  
  char caracter;
  int inteiro;
  std::vector<char> letters_vec;//vetor que guarda as letras
  

  for (int i = 0; i < number_of_letters; i++) {
    is >> caracter;//pegando as letras
    letters_vec.push_back(caracter);//colocando as letras em um vector 
    
    
  }
  /*IMPRIMINDO O MAPA*/
  std::map<char,int>::iterator it = associa.begin();



  std::string operation;//pegando a operaçao interia como uma string de uma linha
  is >> operation;

  int num_combinations;
  is >> num_combinations;//vendo as possiveis combinacoes 
  out<<num_combinations<<'\n';

  
  char posic;
  int elem_1;
  int elem_2;
  int operat;

 while (num_combinations !=  0){

    for (int j = 0; j < number_of_letters; j++) {
      is >> inteiro;//pegando os inteiros e associando as letras colocando isto no map
      associa[letters_vec[j]]=inteiro;
    
    }
    std::cout << "nova combinação do mapa"<<'\n';
    for (it=associa.begin(); it!=associa.end(); ++it){
      std::cout << it->first << " => " << it->second << '\n';
    }

    for(std::string::size_type i = 0; i < operation.size(); ++i) {
      posic = operation[i];//pegando cada char da operação que é uma string
    
      switch (posic) {
        case '&':
          elem_1 = pilha.top();
          pilha.pop();
          elem_2 = pilha.top();
          pilha.pop();
          operat = elem_1 & elem_2;
          pilha.push(operat);
          std::cout << "&";
          break;
        case '^':
          elem_1 = pilha.top();
          pilha.pop();
          elem_2 = pilha.top();
          pilha.pop();
          operat = elem_1 ^ elem_2;
          pilha.push(operat);
          std::cout << "^";
          break;
        case '|':
          elem_1 = pilha.top();
          pilha.pop();
          elem_2 = pilha.top();
          pilha.pop();
          operat = elem_1 | elem_2;
          pilha.push(operat);
          std::cout << "|";
          break;
        default:
          pilha.push(associa[posic]);
          break;
          
          
      }
    }
  answer = pilha.top();
  pilha.pop();
  out << answer<<'\n';  
  num_combinations--;
  }      
  is.close(); 
  out.close();


  return 0;
}