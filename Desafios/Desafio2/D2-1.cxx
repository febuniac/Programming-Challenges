#include <iostream>     
#include <fstream>      
#include <vector>
#include <map>
#include <stack>

int main () {
  /*dados de saída*/
  int answer;//variavel que irá guardar a saida de cada caso.
  std::ofstream out("saida.txt");//leitura do arquivo de saida
  
  /*criação da pilha*/
  std::stack<int> pilha;// criando uma stack de nome pilha vazia
  std::cout << "tamanho da pilha: " << pilha.size() << '\n';//mostra o tamanho da pilha
  
  /*Dados para leitura de arquivo de entrada*/
  char str[256];//def de uma string (vai ser o nome do meu arquivo)
  std::cout << "Enter the name of an existing text file: ";//print para o user
  std::cin.get (str,256);//pega a resp como nome do arquivo
  std::ifstream is(str);  //abre o arquivo com "is"   
  
  /*criação do mapa*/
  std::map<char, int> associa;//cria um mapa(tipo dicionário) que associa um char à um int

  //std::string ch;//criando people para ser o num de parametros recebido ainda como char
  //std::getline(is, ch);//colocando o primeiro digito do arquivo de entrada em ch
  //int number_of_letters= atoi(ch.c_str());;//transforma em t
  
  /*Pegando o numero de letras*/
  char ch;//criando ch para ser o num de parametros recebido ainda como char
  is >> ch;//colocando o primeiro digito do arquivo de entrada em ch
  int number_of_letters = ch - '0';//transforma em int
  
  /*Variáveis*/
  char caracter;
  int inteiro;
  std::vector<char> letters_vec;//vetor que guarda as letras
  char posic;
  int elem_1;
  int elem_2;
  int operat;
  
  /*Preenchendo vector de letras*/
  for (int i = 0; i < number_of_letters; i++) {
    is >> caracter;//pegando as letras
    letters_vec.push_back(caracter);//colocando as letras em um vector  
  }
  
  /*inicializa o mapa*/
  std::map<char,int>::iterator it = associa.begin();//inicializando o mapa

  /*pegando a operação como string*/
  std::string operation;//pegando a operaçao interia como uma string de uma linha
  is >> operation;//colocando a linha de operação em operation
  
  int num_combinations;
  is >> num_combinations;//vendo as possiveis combinacoes (ex: 000,001...)
  out<<num_combinations<<'\n';//colocando este valor no aqruivo de saida


 while (num_combinations !=  0){

    for (int j = 0; j < number_of_letters; j++) {
      is >> inteiro;//pegando os inteiros e associando as letras colocando isto no map
      associa[letters_vec[j]]=inteiro;//associando dentro do mapa os chars aos ints
    }

    /*Printando o Mapa*/
    std::cout << "nova combinação do mapa"<<'\n';
    for (it=associa.begin(); it!=associa.end(); ++it){
      std::cout << it->first << " => " << it->second << '\n';
    }

    for(std::string::size_type i = 0; i < operation.size(); ++i) {
      posic = operation[i];//pegando cada char da operação que é uma string
      switch (posic) {
        case '&':
          elem_1 = pilha.top();//salva o primeiro da pilha em elem_1
          pilha.pop();//remove este valor
          elem_2 = pilha.top();//salva o novo primeiro da pilha em elem_2
          pilha.pop();//remove este valor
          operat = elem_1 & elem_2;//faz a operação
          pilha.push(operat);//coloca o resultado na pilha
          break;
        case '^':
          elem_1 = pilha.top();
          pilha.pop();
          elem_2 = pilha.top();
          pilha.pop();
          operat = elem_1 ^ elem_2;
          pilha.push(operat);
          break;
        case '|':
          elem_1 = pilha.top();
          pilha.pop();
          elem_2 = pilha.top();
          pilha.pop();
          operat = elem_1 | elem_2;
          pilha.push(operat);
          break;
        default:
          pilha.push(associa[posic]);//coloca o valor da letra na pilha
          break; 
        }
      }
  answer = pilha.top();//pega a resposta
  pilha.pop();//remove da pilha
  out << answer<<'\n';  //escreve no arquivo de saida,
  num_combinations--;
  }      
  is.close();//fecha input
  out.close();//fecha output
  return 0;
}