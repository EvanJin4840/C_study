#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    pid_t child_pid = fork();
    if(child_pid == 0){
        printf("Parent!\n");
        exit(0);
    }
    else{
        printf("Child!\n");
    }
}