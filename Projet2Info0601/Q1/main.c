#include <stdlib.h>    /* Pour exit, EXIT_FAILURE */
#include <stdio.h>     /* Pour fprintf, printf */
#include <fcntl.h>     /* Pour open */
#include <sys/stat.h>  /* Pour O_WRONLY, O_CREAT, S_IRUSR, S_IWUSR */
#include <unistd.h>    /* Pour lseek */
#include <sys/wait.h> /*fonction wait*/


void fils() {
    printf("Fils, PID = %d Père, PID=%d\n", getpid(), getppid());
    exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[]){
    int nbFils, i;
    int statut;
    //Vérification du nombre d'arguments
    if (argc < 2 ){
        perror("Pas d'argument");
        exit(EXIT_FAILURE);
    }
    nbFils = atoi(argv[1]);
    //printf("Argument %d\n",i);
    pid_t pid;
    for (i = 0 ; i<nbFils; i++){
        pid = fork();
        if (pid ==0)
            fils();
    }
    for (i = 0; i<nbFils; i++){
        if(wait(&statut) ==-1 ){
            perror("Erreur lors de l'attente d'un fils");
            exit(EXIT_FAILURE);
        }
    }
    
}