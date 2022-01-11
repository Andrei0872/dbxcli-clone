#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "src/execute_command.h"

#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define RESET "\x1B[0m"

int main (int argC, char *args[]) {
  char *rawCommand = NULL;
  size_t len = 0;
  ssize_t read;

 

  // TODO: ensure `dropbox` created
  printf(BOLDGREEN "dbxcli > "   RESET);
  while ((read = getline(&rawCommand, &len, stdin)) != -1) {
    if (read <= 0) {
      continue;
    }
    
    
    if (executeCommand(rawCommand) == 2)
    {
      break;
    }
    printf(BOLDGREEN "dbxcli > "   RESET);
  }

  free(rawCommand);

  return 0;
}