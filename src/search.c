#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

void searchCommand (char* args) {
  printf("SEARCHING FOR: %s\n", args);

  char *DEST_BASE = strcat(realpath("dropbox", NULL), "/");

  if (!strlen(args)) {
    printf("You have to provide something to search for!\n");
    return;
  }

  char* results = (char*)malloc(0 * sizeof(char));
  strcpy(results, "");
  scanDirAndAccumulateEntries(DEST_BASE, args, &results);

  if (strlen(results)) {
    printf("Found results: \n%s\n", results);
  } else {
    printf("Nothing found!\n");
  }

  free(results);
}