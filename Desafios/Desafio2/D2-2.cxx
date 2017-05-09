#include <iostream>     
#include <fstream>      
#include <vector>
#include <map>
#include <stack>
#include <sstream>// std::istringstream, std::ws

int main () {
  std::ofstream out("saida_erdos.txt");//arquivo de saida
  
  /*Leitura de entrada*/
  char str[256];//def de uma string (vai ser o nome do meu arquivo)
  std::cout << "Enter the name of an existing text file: ";//print para o user
  std::cin.get (str,256);//pega a resp como nome do arquivo
  std::ifstream input(str);  //abre o arquivo com "input" 
  std::string line;

  /*Descobrindo o num de autores*/
  std::string people;//criando people para ser o num de parametros recebido ainda como char
  std::getline(input, people);
  int num_of_people= atoi(people.c_str());;//transforma em int  
  
  std::string authors;
  std::vector<std::string> authors_vec;//vetor de autores
  std::vector<std::string> pairs_vec;//vetor de pares
 
  /*Criando Vector de autores*/
  for (int i = 0; i < (num_of_people); i++) {//for que cria vector com os autores em ordem
     std::getline(input, authors);
     authors_vec.push_back(authors);
  }

  /*Descobrindo o num de pares*/
  std::string pairs;//criando pairs para ser o num de parametrso recebido ainda como char
  std::getline(input, pairs);//elimina linha em branco
  int num_of_pairs= atoi(pairs.c_str());//transforma em int 
  

  int p1;//digito esquerdo do par
  int p2;//digito direito do par
  std::string pair_1;
  std::string pair_2;
  /*Criando vector de distâncias de Erdos e prenchendo com -1*/
  std::vector<int> dist_erdos;//criaçõa do vector que pega as distancias de erdos
  for (int z = 0; z < num_of_people; z++){
    dist_erdos.push_back(-1);//prenche com -1
  }

  /*Escrevendo no arquivo de saída*/
  dist_erdos[0]=0;//valor inicial
  out<<num_of_people<<'\n';//printa o num de autores no arquivo final
  out<<authors_vec[0]<<":"<< dist_erdos[0]<<'\n';//printa o Erdos no arquivo final
 
  /*prints*/
  std::cout<<num_of_people<<'\n';
  std::cout<<authors_vec[0]<<":"<< dist_erdos[0]<<'\n';
  
  
  for (int j = 0; j < (num_of_pairs*2); j++) {
    input>>pair_1;
    input>>pair_2;
    p1 = atoi(pair_1.c_str());//tranformando de string p int
    p2 = atoi(pair_2.c_str());//tranformando de string p int   
    pairs_vec.push_back(pair_1);//adicionando no vector de pares
    pairs_vec.push_back(pair_2);
    
    if (dist_erdos[p2]==-1){//formula de erdos
      dist_erdos[p2]=dist_erdos[p1]+1;//regra
      std::cout << authors_vec[p2]<< ":" <<dist_erdos[p2]<<'\n';
      out<< authors_vec[p2]<< ":" <<dist_erdos[p2]<<'\n';//printando no arquivo
    }
  }
    input.close();
    out.close();
    return 0;
}


