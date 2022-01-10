#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int getIndexOf (char* str, char ch) {
  for (int i = 0, len = strlen(str); i < len; i++) {
    if (str[i] == ch) {
      return i;
    }
  }

  return -1;
}

int equals (char* s1, char* s2) {
  return !strcmp(s1, s2);
}

void getKVPairFromRawString (char* rawStr, char** k, char** v, char delimiter) {
  int delimIdx = getIndexOf(rawStr, delimiter);
  if (delimIdx == -1) 
  {
    return;
  }

  *k = (char*)malloc((delimIdx) * sizeof(char));
  *v = (char*)malloc((strlen(rawStr) - delimIdx) * sizeof(char));

  strncpy(*k, rawStr, delimIdx);
  strcpy(*v, rawStr + delimIdx + 1);
}