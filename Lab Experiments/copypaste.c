#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFFER_SIZE 1024
int main() 
{
    int in_fd, out_fd;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;
    in_fd = open("input.txt", O_RDONLY);
    if (in_fd == -1) 
    {
        perror("open");
        exit(EXIT_FAILURE);
    }
    out_fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (out_fd == -1) 
    {
        perror("open");
        exit(EXIT_FAILURE);
    }
    while ((bytes_read = read(in_fd, buffer, BUFFER_SIZE)) > 0) 
    {
        if (write(out_fd, buffer, bytes_read) != bytes_read) 
        {
            perror("write");
            exit(EXIT_FAILURE);
        }
    }
    printf("Copied Successfully\n");
    close(in_fd);
    close(out_fd);
    return 0;
}