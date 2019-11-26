#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

char ** parse_args( char * line ){
  char ** args = malloc(256);
  char * token;
  int i = 0;
  while (token){
    token = strsep(&line, " "); // assuming 1 space between each argument
    args[i] = token;
    i++;
  }
  return args;
}

int main(int argc, char *argv[]){
  char* str = malloc(50);
  char* str_holder = malloc(50);
  // if there is no command line argument
  if (argc <=  1){
    // asks user for input
    printf("Enter a string to be parsed (example: \"ls -a -l\"):\n");
    fgets(str_holder,50,stdin);
      int j;
      for ( j = 1; j < strlen(str_holder)-2; j++){
        str[j-1] = str_holder[j];
      }
  }
  else{
    str = argv[1];
  }

  printf("----------------------------------------\nLooking through arguments %s\n", str);

  char ** arr = parse_args(str);
  int i = 0;
  while (arr[i]){
    printf("arr[%d]: %s\n", i, arr[i]);
    i++;
  }

  printf("----------------------------------------\nTesting using execvp:\n");
  execvp(arr[0],arr);

  return 0;
}
