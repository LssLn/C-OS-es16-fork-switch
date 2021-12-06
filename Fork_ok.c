#include <sys/types.h>
#include <unistd.h> /* fornisce l’accesso alle API di POSIX */
#include <stdio.h>

int main(){

    pid_t pid;
    char *message;
    int n;
    
    printf("fork starting\n");
    pid=fork();
    //printf("%d",pid);
    switch(pid){
        case -1:
            perror("fork failed"); //perror : printf error
            exit(1); //exit status wrong
        case 0:
            //figlio
            message = "Child";
            n=5;
            break;
        default:
            //padre
            message="Father";
            n=3;
            break;
    }
    
    for(;n>0;n--){
    puts(message);
    sleep(2);
    }    
     
    exit(0);
    
    
}



