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

int main(){
  return 0;
}
