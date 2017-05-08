#include <iostream>       // std::cout
#include <stack>          // std::stack
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {

ifstream input;
input.open("entrada.txt", ios::in);

char my_character ;
int number_of_lines ;

    while (!input.eof() ) {

    input.get(my_character);
    cout << my_character;
        if (my_character == '\n'){
            ++number_of_lines;
        }
    }
cout << "\n NUMBER OF LINES: " << number_of_lines << endl;

std::stack<int> pilha;                    // empty stack
std::cout << "tamanho da pilha: " << pilha.size() << '\n';
/*switch(my_character) {
      case '&' :
        //stack::pilha.push(55);
        //stack::pilha.push();
        cout << "Excellent!" << endl; 
        //stack::pilha.pop();
        break;
      case '^' :
        cout << "Excellent!" << endl; 
        break;
      case '|' :
        
        break;
      default :
        cout << "Excellent!" << endl; 
   }
  
   cout << " " << input << endl;
 */
   return 0;
}