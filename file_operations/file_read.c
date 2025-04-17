#include <stdio.h>

int main()
{
    FILE *fptr = fopen("example.txt","r");
    if(fptr == NULL) {
	perror("file");
    }
    //char name[] = "Mohan Kuruba";
    //fwrite(name,1,sizeof(name)-1,fptr);
    char ch;
    while((ch = getc(fptr)) != EOF)
	putc(ch,stdout);

    printf("\n");
    fclose(fptr);
    return 0;
}

