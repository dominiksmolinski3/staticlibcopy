// copy.c
#include <fcntl.h>
#include <unistd.h>
#include <sys/sendfile.h>
#include <stdio.h>
#include "copy.h"
#include <sys/stat.h>

int copy_file(const char *src_file, const char *dest_file) {
    int source_fd, dest_fd;
    off_t offset = 0;
    struct stat file_stat;
    
    // open source file
    source_fd = open(src_file, O_RDONLY);
    if (source_fd == -1) {
        perror("Error opening source file");
        return -1;
    }
    
    // get the size of the source file
    if (fstat(source_fd, &file_stat) == -1) {
        perror("Error getting file stats");
        close(source_fd);
        return -1;
    }
    
    // open or create destination file
    dest_fd = open(dest_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd == -1) {
        perror("Error opening destination file");
        close(source_fd);
        return -1;
    }
    
    // copy the file using sendfile()
    if (sendfile(dest_fd, source_fd, &offset, file_stat.st_size) == -1) {
        perror("Error during file copying");
        close(source_fd);
        close(dest_fd);
        return -1;
    }
    
    // close file descriptors
    close(source_fd);
    close(dest_fd);
    
    return 0;
}
