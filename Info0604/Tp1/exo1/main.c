#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

typedef struct {
    int total;
    int actu;
}hello_world;

void *hello_thread(void *arg){
    int statut;
    hello_world *hello;
    hello =(hello_world*)arg;
    sleep(1);
    printf ("\n Hello world ! du thread %d de %d !\n",hello->actu,hello->total );
    fflush(stdout);
    free(hello);
    return NULL;
}


int main(int argc, char *argv[]) {
    int i;
    int statut;
    int nbT =  atoi(argv[1]);
    
    pthread_t *thread= (pthread_t*)malloc(sizeof(pthread_t)*nbT);
    hello_world *hello;
    for (i=1; i<=nbT; i++){
        hello = (hello_world*)malloc(sizeof(hello_world));
        hello->total = nbT;
        hello->actu = i; 
        statut = pthread_create(&thread[i-1], NULL, hello_thread,hello );
        if (statut != 0)
            printf("Probleme creation thread \n");
    }
    for (i=1; i<=nbT; i++){
        statut = pthread_join(thread[i-1],NULL);
        if (statut != 0)
            fprintf(stderr, "Probleme thread join\n");
    }
    free(thread);
    return 0;

}
