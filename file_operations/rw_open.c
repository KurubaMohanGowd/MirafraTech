#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <wait.h>

int main()
{
    char *fname = "example.txt";
    int fd = open(fname,O_WRONLY);
    if(fd == -1) {
	perror("open");
	return 0;
    }
    char data[] = "Hi, I am Mohan Kuruba\nWe are using open() instead of fopen().";
    //fwrite(data,1,strlen(data),fptr);
    write(fd,data,strlen(data));
    close(fd);


    // for reading
    fd = open(fname,O_RDONLY);
    if(fd == -1) {
	perror("file");
	return 0;
    }

    char buffer[100];
    //size_t bytes_read = fread(buffer,1,sizeof(buffer),fptr);
    size_t bytes_read = read(fd, buffer, sizeof(buffer));
    buffer[bytes_read] = '\0';
    printf("File content : \n%s\n",buffer);
    close(fd);


    return 0;
}

