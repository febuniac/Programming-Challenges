/*
DESCRIÇÃO DO DESAFIO:

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


int play(int player, int board[8][8], int *p_row, int *p_col) {
	int not_player;
	int achou = 0;//Para trocar o valor de return para 1 quando achar
	int valor_mapa = -41;//valor menor possivel que a matriz de valores
	int new_valor_mapa;//contador de valores de mapa
	int X;// valor da corndenada X
	int Y;// valor da corndenada Y
	int valores[8][8] = { {120, -20,  20,   5,   5,  20, -20, 120},   
    {-20, -40,  -5,  -5,  -5,  -5, -40, -20},   
    {20 ,  -5,  15,   3,   3,  15,  -5,  20},   
    {5  ,  -5,   3,   3,   3,   3,  -5,   5},   
    {5  ,  -5,   3,   3,   3,   3,  -5,   5},   
    {20 ,  -5,  15,   3,   3,  15,  -5,  20},   
    {-20, -40,  -5,  -5,  -5,  -5, -40, -20},   
    {120, -20,  20,   5,   5,  20, -20, 120 }}; //Matriz dos valores das posições (diagonais valem muito!)
	int convertidas = 0;//valor inicial de peças que se tornaram do jogador na jogada
	int new_convertidas;//quantas peças foram comidas/convertidas de cor


	// Criando a variavel not_player  (if (board[i+x][j+y] != player && board[i+x][j+y]!=-1))
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
	    					//Seguir na direção até achar uma peça do PLAYER (se achar um vazio ou só peça branca deu ruim)
							//definindo  bordas do tabuleiro atraves de i e j (< 0 e >7 excede o tamnho da matriz)
				            for (int anda = 2; i+(y*(anda)) >=0 && i+(y*(anda)) <=7 && j+(x*(anda)) >=0 && j+(x*(anda)) <=7; anda+=1){
				            	//anda pode ser inicializado de 2 pois o valor maximo de x e y é 1 e valor min é -1 entao pegamos ó proximo em direçoes possiveis
				            	//Se entrou nesse for ainda estamos dentro do tabuleiro e vamos andar até achar uma peça da mesma cor do player

				            	
				            	if (board[i+(y*anda)][j+(x*anda)] == player){//se andar e achar uma peça do player (acabou jogada)
				               		break;
				                }
								

								if (board[i+(y*anda)][j+(x*anda)] == -1){// enquanto achar espaços vazios
								    X = i+(y*(anda));// define o valor da cornedada X de uma jogada possivel
					                Y = j+(x*(anda));// define o valor da cornedada Y de uma jogada possivel
					                new_valor_mapa = valores[X][Y];// Gera um novo valor da matriz de valores a partir das cordenadas x e y					              
					                new_convertidas = anda;// checando peças convertidas
 	
								   	if (new_valor_mapa > valor_mapa && new_convertidas > convertidas ){//checa para ver se o novo valo da posicao de jogada possivel vale mais apena do que o anterior e se houveram mais peças convertidas
								   		*p_row = X;//define a cordenada X da jogada selecionada
								   		*p_col = Y;//define a cordenada Y da jogada selecionada
								   		achou =1;// para retornar 1 
								   		valor_mapa = new_valor_mapa;// salva o novo valor de mapa
								   		convertidas = new_convertidas; // salva o novo valor de convertidas
								   	} 
					                break;
					            }

	    					}
	    				}
	    			}
	    		}
	    	}
	    }
	}

	return achou; // 0 ou 1
}





	
/*


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
 
Euristica:square weights Values by: http://dhconnelly.com/paip-python/docs/paip/othello.html#localmax
*/