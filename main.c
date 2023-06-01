#include "main.h"

int main(int ac,char **argv){
  char *prompt = "(shell) $";
  char *lineptr;
  size_t n = 0;

  /* declaring void variables */
  (void)ac; (void)argv;

  while(1){
    printf("%s ",prompt);
    lineptr = NULL;
    getline(&lineptr, &n, stdin);
    printf("%s\n", lineptr);

    free(lineptr);
  }
  return 0;
}
