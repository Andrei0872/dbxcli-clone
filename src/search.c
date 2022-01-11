#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

void scanDirAndAccumulateEntries (char* base, char* pattern, char** results) {
  struct dirent* pDirent;
  char* fullPath = NULL;
  char* newResult = NULL;
  char* next = NULL;

  DIR* pDir = opendir(base);
  if (pDir == NULL) {
    return;
  }

  char copyBase[strlen(base)];

  while ((pDirent = readdir(pDir)) != NULL) {
    if (pDirent->d_name[0] == '.') {
      continue;
    }
    
    int isPatternMatched = strstr(pDirent->d_name, pattern) != NULL;
    if (isPatternMatched) {
      // Computing the new full path.
      fullPath = (char*)malloc((strlen(base) + strlen(pDirent->d_name) + 1) * sizeof(char));
      strcpy(fullPath, base);
      strcpy(fullPath + strlen(base), pDirent->d_name);
      strcpy(fullPath + strlen(fullPath), "\n");

      // Trimming off so that only what's inside the `dropbox` folder remains.
      strcpy(fullPath, strstr(fullPath, "dropbox") + strlen("dropbox") + 1);

      // Adding to the `results` string.
      newResult = (char*)malloc((strlen(*results) + strlen(fullPath)) * sizeof(char));
      strcpy(newResult, *results);
      strcpy(newResult + strlen(*results), fullPath);

      *results = newResult;
    }

    int isDirectory = pDirent->d_type == 4;
    if (isDirectory) {
      if (!isPatternMatched) {
        char newBase[strlen(base)];
        strcpy(newBase, base);

        next = (char*)malloc((strlen(newBase) + strlen(pDirent->d_name) + 1) * sizeof(char));
        strcpy(next, strcat(strcat(newBase, pDirent->d_name), "/"));
        scanDirAndAccumulateEntries(next, pattern, results);
      }
    }
  }

  free(fullPath);
  free(next);
  free(pDirent);
  closedir(pDir);
}

void searchCommand (char* args) {
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