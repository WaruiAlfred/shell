// For functions
#include "main.h"

int main(int ac,char **argv){
  char *prompt = "(shell) $";
  char *lineptr;
  size_t n = 0;

  printf("%s\n",prompt);
  getline(&lineptr, &n, stdin);

  free(lineptr);
  
  return 0;
}