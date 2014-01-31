#include <stdlib.h>    /* Pour exit, EXIT_FAILURE */
#include <stdio.h>     /* Pour fprintf, printf */
#include <fcntl.h>     /* Pour open */
#include <sys/stat.h>  /* Pour O_WRONLY, O_CREAT, S_IRUSR, S_IWUSR */
#include <unistd.h>    /* Pour lseek */
#include "inode.h"


/**
 * Creation d'un inode alloue et initialise.
 * @return un pointeur vers l'inode
 **/
inode_t *inode_creer(){
	inode_t *inode = (inode_t*)malloc(sizeof(inode_t));
	inode->nom = (char*)malloc(sizeof(char)*(MAX_TAILLE));
	inode->adr = (off_t*)malloc(sizeof(off_t)*MAX_TAILLE_BLOC);
	inode->taille = 0;
	return inode;
}
	
 
/**
 * Supprimer un inode.
 * @param i pointeur vers l'inode
 * */
void inode_supprimer(inode_t **i){
	if (i != NULL){
		(*i)->nom = NULL;
		(*i)->adr = NULL;
		(*i)->taille = 0;
		free((*i)->nom);
		free((*i)->adr);
		free(*i);
	}
		
}
 
/**
 * Afficher un inode a l'ecran.
 * @param i l'inode a afficher
 **/
void inode_afficher(inode_t *i){
	int c =0;
	if (i != NULL ){
		printf("Nom: %s \n", i->nom);
		printf("Taille de l'inode: %d \n", i->taille);
		printf("Adresses:\n");
		while (i->adr[c] != -1 && c < MAX_ADR)
			printf("\t %d \n", (int)i->adr[c]);
	}
}
 
/**
 * Sauvegarder un inode dans un disque virtuel a la position courante.
 * @param fd le descripteur de fichier du disque virtuel
 * @param i l'inode a sauvegarder
 **/
void inode_sauvegarder(int fd, inode_t *i){
    if( write(fd,&i,sizeof(inode_t))==-1){
            perror("Erreur lors de l'ecriture de l'inode ");
            exit(EXIT_FAILURE);
    }
}
 
/**
 * Charger un inode a la position courante depuis un disque virtuel.
 * @param fd le descripteur de fichier du disque virtuel
 * @return l'inode lu
 **/
inode_t *inode_charger(int fd){
    inode_t *in = inode_creer();
    if ( read(fd,&in,sizeof(inode_t)) == -1)
            perror("Erreur lors de la lecture de l'inode ");
            exit(EXIT_FAILURE);
	return in;
}
 
/**
 * Stocker un fichier a la position courante dans le disque virtuel.
 * @param fd le descripteur de fichier du disque virtuel
 * @param nomFichierIn le nom du fichier a charger
 * @param nomFichierOut le nom du fichier dans le disque virtuel
 **/
void inode_stockerFichier(int fd, char *nomFichierIn, char *nomFichierOut){
}
 
/**
 * Extraire le fichier dont l'inode est situe a la position courante.
 * @param fd le descripteur de fichier du disque virtuel
 * @param nomFichierOut le nom du fichier dans lequel sauvegarder le fichier
 **/
void inode_extraireFichier(int fd, char* nomFichierOut){
}
