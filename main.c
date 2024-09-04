// main.c
#include <stdio.h>
#include <stdlib.h>
#include "copy.h"

int main(int argc, char *argv[]) {
    char src_file[256], dest_file[256];

    // check if program arguments are provided
    if (argc == 3) {
        snprintf(src_file, sizeof(src_file), "%s", argv[1]);
        snprintf(dest_file, sizeof(dest_file), "%s", argv[2]);
    } else {
        // get source and destination file names from input
        printf("Enter the source file: ");
        scanf("%255s", src_file);
        printf("Enter the destination file: ");
        scanf("%255s", dest_file);
    }

    // perform the file copy
    if (copy_file(src_file, dest_file) == 0) {
        printf("File copied successfully.\n");
    } else {
        printf("Error occurred while copying file.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
