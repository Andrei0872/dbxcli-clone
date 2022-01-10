#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cp.h"
#include "mv.h"
#include "utils.h"
#include "rm.h"
#include "ls.h"

int executeCommand (char* rawCommand) {
  
  char* rootCmd = rawCommand;
  char* cmdArgs;


  getKVPairFromRawString(rawCommand, &rootCmd, &cmdArgs, ' ');
  return 0;
  //
  //printf("%s  -> %s\n", rootCmd, cmdArgs);

  if (equals(rootCmd, "cp")) 
  {
    cpCommand(cmdArgs);
  } 
  else if (equals(rootCmd, "mv")) 
  {
    mvCommand(cmdArgs);
  } 
  else if (equals(rootCmd, "rm")) 
  {
    rmCommand(cmdArgs);
  }
  else if (equals(rootCmd, "ls"))
  {

    lsCommand(cmdArgs);
  }
}