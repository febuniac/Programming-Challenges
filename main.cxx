#include <iostream>
#include <string>

#include "stackvec.cxx"

int main() {
  std::string line;

  printf("digite uma linha de texto: ");
  std::getline(std::cin, line);

  unsigned int n = line.size();

  stackvec<char> *s = new stackvec<char>(n);

  for(unsigned int i = 0; i < n; i++) {
    char c = line[i];

    if(c == '(') {
      s->push(')');
    }
    else if(c == '[') {
      s->push(']');
    }
    else if(c == '{') {
      s->push('}');
    }
    else if(c == ')' || c == ']' || c == '}') {
      if(s->empty() == true) {
        printf("fechamento excessivo\n");
        return 0;
      }
      if(s->pop() != c) {
        printf("fechamento invalido\n");
        return 0;
      }
    }
  }

  if(s->empty() == false) {
    printf("abertura excessiva\n");
  }
  else {
    printf("bem formada\n");
  }

  delete s;

  return 0;
}