#include "tar.h"

const char *TEMP_FILE_PATH = "Temp";
const int MAX_FILE_NAME = 50;

void printErrorHelp(const char *headerText) {
    printf("%s %s %s", "Error: ", headerText, "You can type -h\n");
}

bool stringEquals(const char *str1, const char *str2) {
    return strcmp(str1, str2) == 0;
}

bool stringNotEquals(const char *str1, const char *str2) {
    return !stringEquals(str1, str2);
}

void printError() {
    perror(strerror(errno));
}

int packArchive(const char *sourceFilePath, const char *destinationFilePath, int depth) {
    int descriptorDestinationFile = open(destinationFilePath, O_CREAT | O_WRONLY | O_APPEND, ALLOW);
    if (descriptorDestinationFile == -1) {
        printf("Error: Couldn't create or open archive!\n");
        printError();
        return -1;
    }

    DIR *sourceFolder = opendir(sourceFilePath);
    if (sourceFolder == NULL) {
        printf("Error: Couldn't open archived sourceFolder!\n");
        printError();
        return -1;
    }   

    
    int chdirResult = chdir(sourceFilePath);
    if (chdirResult == -1) {
        printf("Error: Couldn't change directory!\n");
        printError();
        return -1;
    }

    struct stat statRecord;
    struct dirent *currentRecord = readdir(sourceFolder);

    while (currentRecord != NULL) {
        //. - является записью каталога для текущего каталога
        //
        //.. - является записью каталога для каталога на один уровень выше в иерархии
        if (stringNotEquals(currentRecord->d_name, ".") && stringNotEquals(currentRecord->d_name, "..")) {
            if (stat(currentRecord->d_name, &statRecord) == -1) {
                perror(strerror(errno));
                return -1;
            }
            if (S_ISDIR(statRecord.st_mode)) {
                packDirectory(currentRecord, descriptorDestinationFile, depth);
            } else {
                packFile(currentRecord->d_name, "", descriptorDestinationFile, depth);
            }
        }
        currentRecord = readdir(sourceFolder);
    }

    chdir("..");
    closedir(sourceFolder);
    close(descriptorDestinationFile);

    return 0;
}

void packDirectory(const struct dirent *currentRecord, int descriptorDestinationFile, int depth) {
    packArchive(currentRecord->d_name, TEMP_FILE_PATH, depth + 1);
    packFile(TEMP_FILE_PATH, currentRecord->d_name, descriptorDestinationFile, depth + 1);
    remove(TEMP_FILE_PATH);
}

int packFile(const char *sourceFilePath, const char *destinationFilePath, int descriptorDestinationFile, int depth) {
    if (descriptorDestinationFile == -1) {
        printf("Couldn't create or open archive\n");
        return -1;
    }

    int descriptorSourceFile = open(sourceFilePath, O_RDONLY);
    if (descriptorSourceFile == -1) {
        printf("Error: Couldn't open file\n");
        printError();
        return -1;
    }

    if (stringEquals("", destinationFilePath)) {
        if (write(descriptorDestinationFile, sourceFilePath, MAX_FILE_NAME) == -1) {
            printf("Error occured, some data has not been written\n");
            printError();
        }
    } else {
        if (write(descriptorDestinationFile, destinationFilePath, MAX_FILE_NAME) == -1) {
            printf("Error occured,  some data has been lost due process\n");
            printError();
        }
    }

    struct stat statRecord;
    if (stat(sourceFilePath, &statRecord) == -1) {
        printError();
        return -1;
    }
    int sizeOfFile = statRecord.st_size;

    write(descriptorDestinationFile, &depth, sizeof(int));    //infomation about how deep file was held
    write(descriptorDestinationFile, &sizeOfFile, sizeof(int));     //writing information about the file

    char buff;

    while (sizeOfFile) {
        read(descriptorSourceFile, &buff, sizeof(char));
        write(descriptorDestinationFile, &buff, sizeof(char));
        --sizeOfFile;
    }

    close(descriptorSourceFile);
    return 0;
}


int unpackArchive(const char *sourceFilePath, const char *destinationFilePath, int depth) {
    int descriptorSourceFile = open(sourceFilePath, O_RDONLY);
    if (descriptorSourceFile == -1) {
        printf("Cannot open archive down this path");
        printError();
        return -1;
    }

    struct stat destinationFolderStat;
    if (stat(destinationFilePath, &destinationFolderStat) == -1) {
        mkdir(destinationFilePath,  S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    }

    chdir(destinationFilePath);

    int size;
    int currentDepth;
    char fileName[MAX_FILE_NAME];

    while (read(descriptorSourceFile, fileName, MAX_FILE_NAME)) {
        read(descriptorSourceFile, &currentDepth, sizeof(int));
        read(descriptorSourceFile, &size, sizeof(int));
        if (currentDepth == depth + 1) {
            unpackFile(TEMP_FILE_PATH, size, descriptorSourceFile);
            unpackArchive(TEMP_FILE_PATH, fileName, depth + 1);
            remove(TEMP_FILE_PATH);
        } else if (depth == currentDepth)
            unpackFile(fileName, size, descriptorSourceFile); //files in root folder
        else {
            printf("Error: Depth not matching!\n");
            return -1;
        }
    }

    close(descriptorSourceFile);
    chdir("..");
    remove(sourceFilePath);
    return 0;
}

int unpackFile(const char *destinationFileName, int size, int descriptorSourceFile) {
    int descriptorDestinationFile = open(destinationFileName, O_CREAT | O_WRONLY, S_IREAD | S_IWRITE);

    while (size--) {
        char tempChar;
        read(descriptorSourceFile, &tempChar, sizeof(char));
        write(descriptorDestinationFile, &tempChar, sizeof(char));
    }

    close(descriptorDestinationFile);
    return 0;
}
