#include <stdio.h>
#include <string.h>

int main()
{
    char *fname = "example.txt";
    FILE *fptr = fopen(fname,"w");
    if(fptr == NULL) {
	perror("file");
	return 0;
    }
    char name[] = "Hi, I am Mohan Kuruba";
    fwrite(name,1,strlen(name),fptr);
    fclose(fptr);

    // for reading
    fptr = fopen(fname,"r");
    if(fptr == NULL) {
	perror("file");
	return 0;
    }

    char buffer[32];
    size_t bytes_read = fread(buffer,1,sizeof(buffer),fptr);
    buffer[bytes_read] = '\0';
    printf("File content : \n%s\n",buffer);
    fclose(fptr);


    return 0;
}

