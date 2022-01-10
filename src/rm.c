#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

void rmCommand (char* directoryOrFile) {
  char *fullPath = strcat(strcat(realpath("dropbox", NULL), "/"), directoryOrFile);
  printf("Removing: %s\n", fullPath);

  int isOk = 0;
  if (remove(fullPath) == 0) {
    // Just a file.
    isOk = 1;
  } else if (rmdir(fullPath) == 0) {
    // Empty directory.
    isOk = 1;
  } else {
    // A non-empty directory.
    pid_t pid = fork();
    if (pid < 0) {
      return;
    }
    else if (pid == 0) {
      char* args[] = { "rm", "-rf", fullPath, NULL };
      execve("/usr/bin/rm", args, NULL);
      perror(NULL);
    } else {
      wait(NULL);
    }

    isOk = 1;
  }

  if (isOk) {
    printf("Successfully deleted.\n");
  } else {
    printf("Something went wrong!\n");
  }
}