#include <stdlib.h>    /* Pour exit, EXIT_FAILURE */
#include <stdio.h>     /* Pour fprintf, printf */
#include <fcntl.h>     /* Pour open */
#include <sys/stat.h>  /* Pour O_WRONLY, O_CREAT, S_IRUSR, S_IWUSR */
#include <unistd.h>    /* Pour lseek */
#include <sys/wait.h> /*fonction wait*/


/*typedef struct{
    int in;
    int out;
}tube_t;*/

void fils(int fd) {
    int i;
	int rep = 42;
    read(fd,&i,sizeof(int));
    printf("Entier : %d \n",i);
	write(tubeFils[1],&rep,sizeof(int));
    exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[]){
    int i = 5;
	int rep, fd;
	mkfifo("tubetest", S_IRUSR | S_IWUSR);
	fd = open("tubetest", O_WRONLY);
    if (fork() == 0){
        fils(fd);
    }
    write(tubePere[1],&i,sizeof(int));
	read(tubeFils[0],&rep,sizeof(int));
	printf("Réponse : %d\n",rep);
    //wait (NULL);
    return EXIT_SUCCESS;
}