#include <stdio.h>

int main()
{
    FILE *fptr = fopen("example.txt","w");
    if(fptr == NULL) {
	perror("file");
    }
    char name[] = "Mohan Kuruba";
    fwrite(name,1,sizeof(name)-1,fptr);
    fclose(fptr);
    return 0;
}

