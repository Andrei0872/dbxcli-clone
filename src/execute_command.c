#include <stdio.h>

#include "cp.h"
#include "mv.h"

void executeCommand () {
  printf("executing some commands.\n");
  cpCommand();
  mvCommand();
}