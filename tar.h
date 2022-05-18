
#define FLAG_ARGUMENT argv[1]
#define SOURCE_FILE_PATH argv[2]
#define DESTINATION_FILE_PATH argv[3]

#define ARCHIVE_FLAG "-a"
#define UNARCHIVE_FLAG "-u"
#define HELP_FLAG "-h"
#define ALLOW S_IRUSR | S_IWUSR

/*
S_IRUSR
    00400 пользователь имеет права на чтение файла 
S_IWUSR
    00200 пользователь имеет права на запись в файл 
S_IRGRP
    00040 группа имеет права на чтение файла 
S_IWGRP
    00020 группа имеет права на запись в файл 
S_IROTH
    00004 все остальные имеют права на чтение файла 
S_IWOTH
    00002 все остальные имеют права на запись в файл 
*/

#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdbool.h>


void printErrorHelp(const char *headerText);
bool stringEquals(const char *str1, const char *str2);

bool stringNotEquals(const char *str1, const char *str2);
void printError();

int packArchive(const char *sourceFilePath, const char *destinationFilePath, int depth);
void packDirectory(const struct dirent *currentRecord, int descriptorDestinationFile, int depth);
int packFile(const char *sourceFilePath, const char *destinationFilePath, int descriptorDestinationFile, int depth);

int unpackArchive(const char *sourceFilePath, const char *destinationFilePath, int depth);
int unpackFile(const char *destinationFileName, int size, int descriptorSourceFile);