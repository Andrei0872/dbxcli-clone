#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cp.h"
#include "mv.h"
#include "utils.h"

int executeCommand (char* rawCommand) {
  char* rootCmd;
  char* cmdArgs;

  getKVPairFromRawString(rawCommand, &rootCmd, &cmdArgs, ' ');

  if (equals(rootCmd, "cp")) {
    cpCommand(cmdArgs);
  }
}