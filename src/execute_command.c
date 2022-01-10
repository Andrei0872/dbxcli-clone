#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cp.h"
#include "mv.h"
#include "utils.h"
#include "rm.h"

int executeCommand (char* rawCommand) {
  char* rootCmd;
  char* cmdArgs;

  getKVPairFromRawString(rawCommand, &rootCmd, &cmdArgs, ' ');

  if (equals(rootCmd, "cp")) {
    cpCommand(cmdArgs);
  } else if (equals(rootCmd, "mv")) {
    mvCommand(cmdArgs);
  } else if (equals(rootCmd, "rm")) {
    rmCommand(cmdArgs);
  }
}