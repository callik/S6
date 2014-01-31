#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

#define SPIN			1000000000

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int compteur = 0;
int statut;

void *incr(void *arg){
    int i;
    statut = pthread_mutex_lock(&mutex);
    for (i = 0; i < SPIN/4; i++)
		compteur++;
	statut = pthread_mutex_unlock(&mutex);
    return NULL;
    
}


int main(int argc, char *argv[]) {
	int i, diffTemps, statut;
	time_t temps1, temps2;
	pthread_t thread[4];
	temps1 = time(NULL);
	
	for (i=0; i<4; i++){
	    statut = pthread_create(&thread[i], NULL, incr , NULL );
	    if (statut != 0)
            fprintf(stderr, "Probleme creation thread\n");
	}
	for (i=0; i<4 ; i++){
	    statut = pthread_join(thread[i],NULL);
	    if (statut != 0)
            fprintf(stderr, "Probleme thread join\n");
	}
	temps2 = time(NULL);
	diffTemps = (int) temps2 - (int) temps1;
	printf("Valeur finale du compteur : %d\n", compteur);
	printf("Temps : %d secondes\n", diffTemps);

	return 0;
}