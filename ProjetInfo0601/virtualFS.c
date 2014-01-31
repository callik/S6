#include <stdlib.h>    /* Pour exit, EXIT_FAILURE */
#include <stdio.h>     /* Pour fprintf, printf */
#include <fcntl.h>     /* Pour open */
#include <sys/stat.h>  /* Pour O_WRONLY, O_CREAT, S_IRUSR, S_IWUSR */
#include <unistd.h>    /* Pour lseek */
#include "virtualFS.h"
#include "inode.h"

int main(){
	inode_t *in= inode_creer();
	inode_supprimer(&in);
	printf("lelelelel");
return 0;
}
