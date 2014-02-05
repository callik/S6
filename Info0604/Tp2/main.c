#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

typedef struct{
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int valeur;
}int_p;

int_p element = {PTHREAD_MUTEX_INITIALIZER,PTHREAD_COND_INITIALIZER,0};

void *incr(void *arg){
    int statut;
    printf("Je suis le thread incrémenteur\n");
    statut = pthread_mutex_lock(&element.mutex);
    element.valeur = element.valeur+1;
    statut = pthread_mutex_unlock(&element.mutex);
    sleep(2);
}

void *affiche(void *arg){
    int statut;
    if(element.valeur%2 == 0){
        statut = pthread_mutex_lock(&element.mutex);
        printf("Je suis le thread afficheur\n");
        printf("Valeur du compteur : %d\n", element.valeur);
        statut = pthread_mutex_unlock(&element.mutex);
        sleep(1);
    }    
}

void *raz(void *arg){
    int statut;
    if(element.valeur == 9){
        printf("je suis le thread RaZ\n");
        statut = pthread_mutex_lock(&element.mutex);
        element.valeur = 0;
        statut = pthread_mutex_unlock(&element.mutex);
    }
}

int main(int argc, char *argv[]) {
	pthread_t compteur;
	pthread_t afficher;
	pthread_t razth;
	int statut;

	while(1){
	   statut = pthread_create(&compteur, NULL, incr , NULL );
	    if (statut != 0)
            fprintf(stderr, "Probleme creation thread\n");
        statut = pthread_create(&afficher, NULL, affiche , NULL );
	    if (statut != 0)
            fprintf(stderr, "Probleme creation thread\n");
        statut = pthread_create(&razth, NULL, raz , NULL );
	    if (statut != 0)
            fprintf(stderr, "Probleme creation thread\n");
        statut = pthread_join(compteur,NULL);
	    if (statut != 0)
            fprintf(stderr, "Probleme thread join\n");
        statut = pthread_join(afficher,NULL);
	    if (statut != 0)
            fprintf(stderr, "Probleme thread join\n");
        statut = pthread_join(razth,NULL);
	    if (statut != 0)
            fprintf(stderr, "Probleme thread join\n");
	}

	return 0;
}