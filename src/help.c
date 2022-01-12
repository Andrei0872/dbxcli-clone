#include <stdio.h>

void helpCommand()
{
    char* help_text = 
    "-------- COMMANDS --------\ncp --> copy files\nls --> list the folders/files inside\nmkdir --> create new folder\nmv --> move folder1/file1 into folder2/file2(creates destination if doesn't exist)\nrm --> remove folder/file\nsearch --> search for files/folders\n";
    printf("%s",help_text);
}
