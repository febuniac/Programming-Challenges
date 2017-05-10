#include <iostream>     
#include <fstream>      
#include <vector>
#include <sstream>
#include <cstring>
using namespace std;
 
// Returns count of all possible parenthesizations that lead to
// result true for a boolean expression with symbols like true
// and false and operators like &, | and ^ filled between symbols
int countParenth(char symb[], char oper[], int num_of_TF)
{
    int F[num_of_TF][num_of_TF], T[num_of_TF][num_of_TF];
 
    // Fill diagonal entries first
    for (int i = 0; i < num_of_TF; i++)
    {
        F[i][i] = (symb[i] == 'F')? 1: 0;// All F[i][i] entries are 1 if symbol[i] is F (False)
        T[i][i] = (symb[i] == 'T')? 1: 0;// All diagonal entries in T[i][i] are 1 if symbol[i] is T (true).
    }
 
    // Filling T[i][i+1], T[i][i+2], T[i][i+3]... in order
    // And F[i][i+1], F[i][i+2], F[i][i+3]... in order
    for (int gap=1; gap<num_of_TF; ++gap)
    {//de gap = 1 até gap menor que n
        for (int i=0, j=gap; j<num_of_TF; ++i, ++j)
        {//de i =0, j sendo ate igual ao gap e menor que n
            T[i][j] = F[i][j] = 0;//zerando
            for (int g=0; g<gap; g++)
            {//de g =0, ate g menor que n
                
                // Find place of parenthesization using current value of gap
                int k = i + g;
 
                // Store Total[i][k] and Total[k+1][j]
                int tik = T[i][k] + F[i][k];
                int tkj = T[k+1][j] + F[k+1][j];
 
                // Follow the recursive formulas according to the current operator
                //No estilo de um switch case
                if (oper[k] == '&')
                {
                    T[i][j] += T[i][k]*T[k+1][j];//regra para simbolo & 'true' 
                    F[i][j] += (tik*tkj - T[i][k]*T[k+1][j]);//regra para simbolo & 'false' 
                }
                if (oper[k] == '|')
                {
                    F[i][j] += F[i][k]*F[k+1][j];//regra para simbolo & 'false'
                    T[i][j] += (tik*tkj - F[i][k]*F[k+1][j]);//regra para simbolo & 'true' 
                }
                if (oper[k] == '^')
                {
                    T[i][j] += F[i][k]*T[k+1][j] + T[i][k]*F[k+1][j];//regra para simbolo & 'true'
                    F[i][j] += T[i][k]*T[k+1][j] + F[i][k]*F[k+1][j];//regra para simbolo & 'false'
                }
            }
        }
    }
    return T[0][num_of_TF-1];//retorna T[primeiro][ultimo]
}
 
// Driver program to test above function
int main()
{
    std::ofstream out("saida.txt");//arquivo de saida
  
  /*Leitura de entrada*/
  char str[256];//def de uma string (vai ser o nome do meu arquivo)
  std::cout << "Enter the name of an existing text file: ";//print para o user
  std::cin.get (str,256);//pega a resp como nome do arquivo
  std::ifstream is(str);  //abre o arquivo com "input" 
  std::string line;

  /*Descobrindo o num de autores*/
  std::string num_TF;//criando people para ser o num de parametros recebido ainda como char
  std::string TF;
  //std::vector<std::string> symbols;//vetor de simbolos

  std::getline(is, num_TF);
  int num_of_TF= atoi(num_TF.c_str());;//transforma em int  
  char symbols = ((*char) malloc(num_TF * sizeof(char)));
    /*Criando Vector de simbolos*/
  for (int i = 0; i < (num_of_TF); i++) {//for que cria vector com os autores em ordem
     std::getline(is, TF);
     symbols[i]=TF;
 }
  std::string num_symb;//criando pairs para ser o num de parametrso recebido ainda como char
  std::getline(is, num_symb);//elimina linha em branco
  int num_of_symbols= atoi(num_symb.c_str());//transforma em int 
  
 
  std::string SY;
  char operators = ((*char) malloc(num_of_symbols * sizeof(char)));
  //std::vector<std::string> operators;//vetor de operadores
 
  for (int j = 0; j < (num_of_symbols); j++) { 
    std::getline(is, SY);
    operators[j]=SY;
    cout<<operators[j];
    }   
    
    // There are 4 ways
    // ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T))
    out << countParenth(symbols, operators, num_of_TF);
    is.close();
    out.close();
    return 0;
}

/*
o formato de entrada, com exemplo;
o formato de saída, com exemplo;
o vetor ou a matriz de programação dinâmica;
a solução de subproblema que um elemento desse vetor ou matriz representa;
quando e como as soluções de subproblema são combinadas.
*/  