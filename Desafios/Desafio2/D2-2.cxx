#include <iostream>     
#include <fstream>      
#include <vector>
#include <map>
#include <stack>
#include <sstream>      // std::istringstream, std::ws
int main () {
  std::vector<std::string> authors_vec;
  std::vector<char> pairs_vec;
  char str[256];//def de uma string (vai ser o nome do meu arquivo)

  std::cout << "Enter the name of an existing text file: ";//print para o user
  std::cin.get (str,256);//pega a resp como nome do arquivo

  std::ifstream input(str);  //abre o arquivo com "is" 

  char p;//criando ch para ser o num de parametrso recebido ainda como char
  input >> p;
  int num_of_people= p - '0';//transforma em int  
  std::cout<<num_of_people<< '\n';

  std::string author;
  std::string author1;
  std::string author2;


  for (int i = 0; i < (num_of_people); i++) {//lidar com o espaço
    input >> author;
    //input >> author1;
    input >> author1 >> std::ws >> author2;
    authors_vec.push_back(author1,author2);
  }


  char pairs;//criando ch para ser o num de parametrso recebido ainda como char
  input >> pairs;
  int num_of_pairs= pairs - '0';//transforma em int 

  for (int j = 0; j < (num_of_pairs* 2); j++) {//lidar com o espaço
  input >> pairs;
  pairs_vec.push_back(pairs);
  std::cout<<pairs_vec[j]<<'\n';
  }


    return 0;
}
