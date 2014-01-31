#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h> 
#include <unistd.h>
#include <fcntl.h>
#define min(a,b)( a < b ? a : b)

void RLEcompress(int fdInput){
    
    char a;
    char b;
    int res;
    int n;
    
    if(lseek(fdInput, 0L, SEEK_SET) != -1){
        res = read(fdInput, &a, sizeof(char));
        do {
            res = read(fdInput, &b, sizeof(char));
            if( a == b) {
                n++;
                printf("\n%c%c", a, b);
                printf("\n%d",n);
            } else {
                RLEoutput(n,a);
                n = 0;
            }
            a = b;
        } while(res != 0);
        RLEoutput(n,a);
    }
}

void RLEoutput (int n, char p){
    /*int i;
    int res;
    int k;
    
   if(n < 3) {
        for(i = 0; i<n; i++){
            printf("%c",p);
        }
    } else {
        do {
            k = min(n,255);
            printf("@%d%c", k, p);
            n = n - 255;
        } while(n>0);
        printf("@%d%c", n, p);
    }
    */
}


int main(int argc, char *argv[]) {
    
    int fd;
    fd = open(argv[1], O_RDONLY);
    if(fd == -1) {
        perror("Erreur ouverture fichier ");
        exit(EXIT_FAILURE);
    } 
    RLEcompress(fd);
    close(fd);
    
    return 0;

}