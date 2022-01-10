#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "src/execute_command.h"

int main (int argC, char *args[]) {
  char *rawCommand = NULL;
  size_t len = 0;
  ssize_t read;

  // TODO: ensure `dropbox` created

  while ((read = getline(&rawCommand, &len, stdin)) != -1) {
    if (read <= 0) {
      continue;
    }

    if (strstr(rawCommand, "exit")) {
      break;
    }

    executeCommand(rawCommand);
  }

  free(rawCommand);

  return 0;
}