#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void rmCommand (char* directoryOrFile) {
  directoryOrFile[strlen(directoryOrFile) - 1] = '\0';
  char *fullPath = strcat(strcat(realpath("dropbox", NULL), "/"), directoryOrFile);
  printf("Removing: %s\n", fullPath);

  int isOk = 0;
  if (remove(fullPath) == 0) {
    isOk = 1;
  } else if (rmdir(fullPath) == 0) {
    isOk = 1;
  }

  if (isOk) {
    printf("Successfully deleted.\n");
  }
}