#include "main.h"

int main(void){
  // char *prompt = "(shell) $";
  // char *lineptr = NULL, *lineptr_copy = NULL;
  char *full_command = NULL, *copy_command = NULL;
  size_t n = 0;
  ssize_t nchars_read; /* number of characters the user types */
  const char *delim = " \n";
  char **argv;
  int num_tokens = 0,i=0;
  char *token = NULL;

  // strcpy(command_copy, full_command);
  /* print a prompt for the user to type something */
  printf("$ ");

  /* get the string that the user types in and pass it to full_command */
  nchars_read = getline(&full_command, &n, stdin);

  /* let's allocate space to store the characters read by getline */
  copy_command = malloc(sizeof(char) * nchars_read);

  if (copy_command == NULL){
      perror("tsh: memory allocation error");
      return (-1);
  }

  /* check if the getline function failed or reached EOF or user use CTRL + D */
  if (nchars_read == -1){
      printf("Exiting shell....\n");
      return (-1);
  }
  else {
    /* split the string (full_command) into an array of words */
    token = strtok(full_command, delim);

    /* allocate space to store the variable arguments but before then determine how many tokens are there*/
    while (token != NULL){
        num_tokens++;
        token = strtok(NULL, delim);
    }
    num_tokens++;
    // printf(">>>>> %d \n", num_tokens);

    /* use malloc to allocate enough space for the pointer to the argument variables */
    argv = malloc(sizeof(char *) * num_tokens);

    token = strtok(copy_command, delim);

    for (i = 0; token != NULL; i++){
        argv[i] = malloc(sizeof(char) * strlen(token));
        strcpy(argv[i], token);

        printf(">>>>> %s \n", argv[i]);
        token = strtok(NULL, delim);
    }
    argv[i] = NULL;

    /* execute the commands with execve */


        free(argv);
        free(full_command);
        free(copy_command);
    }

    return (0);
}
