/*
PLAYER: 
O parâmetro player é igual a 0 se o jogador for o primeiro, 
responsável pelas peças pretas, e igual a 1 se o jogador for 
o segundo, responsável pelas peças brancas.

BOARD:
Cada valor board[i][j] da matriz representa o estado da casa na linha i e coluna j do tabuleiro. 
Se for igual a 0, a casa contém uma peça preta. Se for igual a 1, a casa contém uma peça branca. 
Se for igual a -1, a casa está vazia. Suponha que os menores valores de i correspondem às linhas 
mais altas e suponha que os menores valores de j correspondem às colunas mais à esquerda. Ou seja, 
um plano cartesiano com o eixo vertical invertido.

POINTERS:
Os apontadores p_row e p_col tem endereços de variáveis nas quais a linha e a coluna da jogada devem ser escritas.

O valor devolvido pela função deve ser 1 se uma jogada válida de fato existir e deve ser 0 caso contrário. 
No segundo caso, nada específico precisa ser escrito nas variáveis apontadas por p_row e p_col.
*/
#include <stdio.h>

#define jogadasmax 32 //numero max de jogadas do player
#define xy 2 //x e y de cada jogada
#define max_conv 6
int play(int player, int board[8][8], int *p_row, int *p_col) {
	int not_player;
	int jogadas[jogadasmax][xy]= { 0 };
	int contador_jogadas = 0;
	int convertidas[max_conv] = { 0 };

	
	// Criando a variavel not_player  if (board[i+x][j+y] != player && board[i+x][j+y]!=-1)
	if (player == 0){
    	not_player = 1;
  	} 
  	else {
  	  not_player = 0;
  	}

	//Percorrendo tabuleiro inteiro (matriz [8][8])
	for(int i = 0; i < 8 ; i+=1 ){ // laço externo
	    for(int j= 0; j < 8; j+=1 ){   // laço interno
	    	//buscando por uma peça do seu player(valor recebido pelo usuário 0 preta ou 1 branca)->(board[i][j] = cada peça do tabuleiro)
	    	if (board[i][j]== player){
	    	//Procurando todas as peças em volta dessa pedra (um quadrado ao redor desta) para ver se existe alguma peça do outro jogador (jogadas possiveis). 
	    		
	    		//Loop que passa por todas as direções
	    		for(int x = -1; x <=1 ; x+=1 ){ 
	    			for(int y= -1; y <= 1; y+=1) {
	    				//Analisando todas as laterais e diagonais ({*} mostra a ideia distrinchada)
	    				if (board[i+y][j+x] == not_player){
	    					//Seguir na direção até achar uma peça minha (se achar um vazio ou só peça branca deu ruim)
							//definindo  bordas do tabuleiro atraves de i e j (< 0 e >7 excede o tamnho da matriz)
				            for (int anda = 2; i+(y*(anda)) >=0 && i+(y*(anda)) <=7 && j+(x*(anda)) >=0 && j+(x*(anda)) <=7; anda+=1){
				            	//anda pode ser inicializado de 2 pois o valor maximo de x e y é 1 e valor min é -1 entao pegamos ó proximo em direçoes possiveis
				            	//Se entrou nesse for ainda estamos dentro do tabuleiro e vamos andar até achar uma peça da mesma cor do player
				    			convertidas[contador_jogadas] = anda;
				            	printf("%d\n", convertidas);
				            	if (board[i+(y*anda)][j+(x*anda)] == player){
				               		break;
				                }

								if (board[i+(y*anda)][j+(x*anda)] == -1){
								    jogadas[contador_jogadas][0] = i+(y*(anda)); //row q vc vai jogar (x) 
					                jogadas[contador_jogadas][1] = j+(x*(anda));//col que vc vai jogar (somadas row e col sao a cordenanda da sua jogada)(y)
					                //quantas peças eu "comi/converti paraa cor do player"
					                contador_jogadas+=1;//incrementa as jogadas 
					              
					                
					                /*Print Jogadas
					                for(int K=0; K< contador_jogadas ; K++){
    									printf("%d  ", jogadas[K][0]);
    									printf("%d \n ", jogadas[K][1]);
    									*/
    								}
					            }
	    					}
	    				}
	    			}
	    		}
	    	}
	    }
	
	if(convertidas>0){
		//devolver p_row p_col
		*p_row = jogadas[contador_jogadas][0];
		*p_col = jogadas[contador_jogadas][1];
		return 1;//tem jogada possível
	}
	else {
		return 0;
	}
}

//if (board[0][0] == board[*p_row][*p_col] || board[0][7] ==  board[*p_row][*p_col] || board[7][0] == board[*p_row][*p_col] || board[7][7] == board[*p_row][*p_col]){
//					            }



	
/*

 row = valid_plays[i][0];
      								 col = valid_plays[i][1];
							    valid_plays[plays_counter][0] = i+(l*(counter));
				                valid_plays[plays_counter][1] = j+(k*(counter));
				                valid_plays[plays_counter][2] = counter;
								            		*p_row = valid_plays[i][0];
				        							*p_col = valid_plays[i][1];

//Matrix Multiplication (kij) 
//(i,k)=Fixed
//(k,*)= Row wise
//(i,*)= Row wise

for (k=0; k<n; k++) {
	printf("%d \n", k);
  for (i=0; i<n; i++) {
  	printf("%d \n", i);
    r = a[i][k];
    printf("%d \n", r);
    for (j=0; j<n; j++)
    	printf("%d \n", j);
      c[i][j] += r * b[k][j];
} }

{*} 
/Laterais/

	    		//Checando peça da direita
	    		if(board[i+1][j] != player && board[i+1][j]!=-1){}
	    		//Checando peça da esquerda
	    		if(board[i-1][j] != player && board[i-1][j]!=-1){}
	    		//Checando peça de baixo
	    		if(board[i][j+1] != player && board[i][j+1]!=-1){}
	    		//Checando peça de cima
	    		if(board[i][j-1] != player && board[i][j-1]!=-1){}
	    		
	    		/Diagonais/
	    		
	    		//Checando diagonal baixa direita
	    		if(board[i+1][j+1] != player && board[i+1][j+1]!=-1){}
	    		//Checando diagonal topo esquerdo
	    		if(board[i-1][j-1] != player && board[i-1][j-1]!=-1){}
	    		//Checando diagonal topo direita
	    		if(board[i+1][j-1] != player && board[i+1][j-1]!=-1){}
	    		//Checando diagonal baixa esquerda
	    		if(board[i-1][j+1] != player && board[i-1][j+1]!=-1){}	
*/



/*
1-	Percorrer tabuleiro inteiro (matriz [8][8]) buscando por uma peça do seu player(valor recebido pelo usuário 0 preta ou 1 branca) .
	a.	2 fors para percorrer :
		i.	i =0 ate i<8
		ii.	j=0 ate j<8
		iii.	board[i][j] = cada peça do tabuleiro
2-	 Feito {1} Procurar todas as peças em volta dessa pedra (um quadrado ao redor desta) para ver se existe alguma peça do outro jogador . (i+1, i-1; j+1, j-1 (como fazer diagonais)) - 8 ifs contando diagonais

3-	Se nesse quadrado existe uma peça do outro jogador:
	a.	Seguir na direção desta peça até:
		i.	Achar espaço vazio (-1)
		ii.	Chegar ao final do tabuleiro
		iii.	Achar peça do próprio jogador
 
Euristica:num de pecas flipadas 
*/