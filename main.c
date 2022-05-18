#include "tar.h"

int main(int argc, char *argv[]) {
    if (argc == 2 && stringEquals(FLAG_ARGUMENT, HELP_FLAG)) {
        printf("%s", "First argument flag:\n");
        printf("%s %s %s", "Unarchive: ", UNARCHIVE_FLAG, "\n");
        printf("%s %s %s", "Archive: ", ARCHIVE_FLAG, "\n");
        printf("%s", "Second argument source directory\n");
        printf("%s", "Third argument source directory\n");
        return -1;
    } else if(argc != 4) {
        printErrorHelp("Uncorrect arguments!");
        return -1;
    }
    

    if (stringEquals(FLAG_ARGUMENT, ARCHIVE_FLAG)) {
        printf("%s", "Archive... Process...\n");
        packArchive(SOURCE_FILE_PATH, DESTINATION_FILE_PATH, 0);
        printf("%s", "Done!\n");
    } else if (stringEquals(FLAG_ARGUMENT, UNARCHIVE_FLAG)) {
        printf("%s", "Unarchive... Process...\n");
        unpackArchive(SOURCE_FILE_PATH, DESTINATION_FILE_PATH, 0);
        printf("%s", "Done!\n");
    }  else {
        printErrorHelp("Uncorrect arguments!");
    }

    return 0;
}

