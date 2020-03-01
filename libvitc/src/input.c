#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>

#include <vitc.h>
#include <config.h>
#include <input.h>

const char *getExt(const char *filename);

void
vitc_process_user_input(vitc_config *handle)
{


    char **files = vitc_mdim_init();
    size_t numFiles = 0;

    if (strcmp(handle->inputFiles, ".") == 0)
    {
        DIR *dir = opendir(".");
        struct dirent *entry;

        if (dir) {
            while ((entry = readdir(dir)) != NULL)
            {
                if (entry->d_type == DT_REG
                    && strcmp(getExt(entry->d_name), ".graph") == 0)
                {
                    files = realloc(files, (numFiles + 1) * sizeof(char*) + sizeof(size_t*));
                    files[numFiles + 1] = malloc(sizeof(entry->d_name));
                    strncpy(files[numFiles + 1], entry->d_name, sizeof(entry->d_name));

                    ++numFiles;
                }
            }
            closedir(dir);
        }
    }
    else
    {
        size_t sFileList = strlen(handle->inputFiles) + 1;
        char fileList[sFileList];
        strncpy(fileList, handle->inputFiles, sFileList);

        char *part = strtok(fileList, ",");

        while (part != NULL) 
        {
            files = realloc(files, (numFiles + 1) * sizeof(char*) + sizeof(size_t*));
            files[numFiles + 1] = malloc(strlen(part) + 1);
            strncpy(files[numFiles + 1], part, strlen(part) + 1);

            ++numFiles;
            part = strtok(NULL, ";");
        }
    }

    vitc_mdim_setsize(files, numFiles);
    vitc_mdim_resetptr(&files);
    
    vitc_mdim_free(files);
}

const char *
getExt(const char *filename)
{
    char *e = strrchr(filename, '.');
    if (e == NULL)
    {
        e = "";
    }
    return e;
}