#include <stdio.h>
#include <string.h>
//library that deals with access to the directory
#include <dirent.h>
#include <stdlib.h>

int lsCommand(char* path)
{
    char *DEST_BASE = realpath("dropbox", NULL);
    char* new_path;

    if (strlen(path))
    {
        DEST_BASE = strcat(DEST_BASE, "/");
    }
    new_path = strcat(DEST_BASE, path);
    //DIR struct is our directory, where we are working
    //opendir(absolut path, relative path)
    //"." is for current directory
    DIR* dir = opendir(new_path);

    //check if this directory actually exists
    if (dir == NULL)
    {
        printf("No such directory!\n");
        return 1;
    }
    //struct dirent
    //structure used to return info about directory entries
    struct dirent* folder;
    folder = readdir(dir);

    while (folder != NULL)
    {
        
        int dtype = folder->d_type;
        char* data_type;
        if (dtype == 8)
        {
            data_type = "";
        }
        else if (dtype == 4)
        {
            data_type = "/";
        }
        if (folder->d_name[0] != '.')
        {
            printf("%s%s\n", folder->d_name, data_type);
        }
        
        folder = readdir(dir);
    }



    //close the directory
    closedir(dir);
    return 0;
}