#include <iostream>     
#include <fstream>      
#include <vector>
#include <map>
#include <stack>
#include <sstream>      // std::istringstream, std::ws
void erdos(int p1,int p2){
}
int main () {
  char str[256];//def de uma string (vai ser o nome do meu arquivo)

  std::cout << "Enter the name of an existing text file: ";//print para o user
  std::cin.get (str,256);//pega a resp como nome do arquivo

  std::ifstream input(str);  //abre o arquivo com "input" 
  std::string line;
  char p;//criando p para ser o num de parametros recebido ainda como char
  input >> p;
  int num_of_people= p - '0';//transforma em int  
  std::string authors;
  std::vector<std::string> authors_vec;
  std::vector<std::string> pairs_vec;
  std::map<std::string, int> associa;
  std::map<std::string,int>::iterator it = associa.begin();

  std::getline(input, authors);//elimina linha em branco
  for (int i = 0; i < (num_of_people); i++) {//lidar com o espaço;
     std::getline(input, authors);
     authors_vec.push_back(authors);
     //std::cout<<authors_vec[i]<<'\n'  ;
  }
  
  /*Associando valores aos nomes*/
  for (int j = 0; j < num_of_people; j++) {
    associa[authors_vec[j]]=j;//associando dentro do mapa os chars aos ints
    //std::cout<<authors_vec[j]<<'\n';

  }
  for (it=associa.begin(); it!=associa.end(); ++it){
        std::cout << it->first << " => " << it->second << '\n';
      }


  char pairs;//criando ch para ser o num de parametrso recebido ainda como char
  input >> pairs;
  int num_of_pairs= pairs - '0';//transforma em int 

  std::string pair_1;
  std::string pair_2;
  std::getline(input, pair_1);//elimina linha em branco
  for (int j = 0; j < (num_of_pairs*2); j++) {//lidar com o espaço
    input>>pair_1;
    input>>pair_2;
    int p1 = atoi(pair_1.c_str());
    int p2 = atoi(pair_2.c_str());
    //std::getline(input, pair);
    pairs_vec.push_back(pair_1);
    pairs_vec.push_back(pair_2);
    std::cout<<pairs_vec[j]<<'\n';
  }
  



    return 0;
}

/*
 for (int j = 0; j < (num_of_pairs*2); j++) {//lidar com o espaço
  input >> pairs;
  pairs_vec.push_back(pairs);
  std::cout<<pairs_vec[j]<<'\n';
  }
  */
