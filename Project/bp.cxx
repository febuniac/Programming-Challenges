#include <iostream>
#include <cstring>
using namespace std;
 

int countParenth(char symb[], char oper[], int n)
{ 
    int F[n][n], T[n][n];
    // prenche a diagonal (inicialmente)
    for (int i = 0; i < n; i++)
    {
        F[i][i] = (symb[i] == 'F')? 1: 0;// Todas as entradas de  F[i][i] entries são 1 caso symbol[i] seja F (False)
        T[i][i] = (symb[i] == 'T')? 1: 0;// Todas as entradas da diagonal de T[i][i] são 1 se symbol[i] é T (true).
    }
 
    // Prencheendo T[i][i+1], T[i][i+2], T[i][i+3]... em ordem
    // Prencheendo F[i][i+1], F[i][i+2], F[i][i+3]... em ordem
    for (int gap=1; gap<n; ++gap)
    {//de gap = 1 até gap menor que n
        for (int i=0, j=gap; j<n; ++i, ++j)
        {//de i =0, j sendo ate igual ao gap e menor que n
            T[i][j] = F[i][j] = 0;//zerando
            for (int g=0; g<gap; g++)
            {//de g =0, ate g menor que n
                
                // Utiliza o gap para saber aonde deve ser colocado os parentehses na ordem corretaF
                int k = i + g;
 
                // Guarda Total[i][k] e Total[k+1][j]
                int tik = T[i][k] + F[i][k];
                int tkj = T[k+1][j] + F[k+1][j];
 
                // Formulas recursivas de com o operador sendo utilizado
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
    return T[0][n-1];//retorna T[primeiro][ultimo]
}
 
// Para testar
int main()
{
    
    
    char symbols[] = "TTFT";//vetor de entrada com T e F
    
    char operators[] = "|&^";//vetor de entrada de operadores
    int n = strlen(symbols);//numero de T e F
 
    // 4 possibilidade
    // ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T))
    cout << countParenth(symbols, operators, n)<<'\n';
    return 0;
}

 