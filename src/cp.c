#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#include "utils.h"

void cpCommand (char* args) {
  char *DEST_BASE = strcat(realpath("dropbox", NULL), "/");
  char* src;
  char* dest;
  char* absoluteDestPath;

  getKVPairFromRawString(args, &src, &dest, ' ');

  src = realpath(src, NULL);
  dest = strcat(DEST_BASE, dest);

  printf("src:%s\n", src);
  printf("dest:%s\n", dest);

  pid_t pid = fork();
  if (pid < 0) {
    return;
  }
  else if (pid == 0) {
    char* args[] = {"cp", src, dest, NULL};
    execve("/usr/bin/cp", args, NULL);
    perror(NULL);
  } else {
    wait(NULL);
  }
}