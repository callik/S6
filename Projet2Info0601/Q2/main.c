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

void fils(int tube[2]) {
    int i;
    close (tube[1]);
    read(tube[0],i,sizeof(int));
    printf("Entier : %d \n",i);
    exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[]){
    int i = 5;
    int tube[2];
    pipe(tube);
    if (fork() == 0){
        fils(tube);
    }
    close(tube[0]);
    write(tube[1],i,sizeof(int));
    //wait (NULL);
    return EXIT_SUCCESS;
}