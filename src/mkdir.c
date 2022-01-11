#include <stdio.h>
//library with mkdir
#include <sys/stat.h>
#include <string.h>

//to use mkdir to create folder in folder specify as follows:
// mkdir some_existing_folder/your_new_folder
//remark: existing folder should be in the root, otherwise
//you will need to specify the entire path from root (excluding the name of the root folder)

void mkdirCommand(char* folder_name)
{
    //mkdir function returns 0 if created succ
    printf("%s\n", folder_name);
    
    char path_and_folder_name[100] = "dropbox/";
    char* f_name = folder_name;
    strcat(path_and_folder_name,f_name);
    
    int fail = mkdir(path_and_folder_name,0777);
    if (!fail)
    {
        printf("created successfully\n");
    }
    else
    {
        printf("error: could not create a folder\n");
    }
}