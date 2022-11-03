//Matthew Prindle Homework 1
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <strings.h>

int main(int argc, char** argv)
{
  if(argc > 1) {
    printf("\nI have been run direct from a file\n and passed a termination argument to prevent looping, goodbye!\n");
    exit(0);
  }
  printf("\nI'm gonna run some system calls!\n");
 
  printf("\nCall 1 --getpid--\n");
  printf("\tMy process id is: %d\n",getpid());
  
  printf("\nCall 2 --getppid--\n");
  printf("\tMy parent process id is: %d\n",getppid());
  
  printf("\nCall 3 --fork-- --waitpid-- --exit--\n");
  printf("\tForking this process, spawning a child process!\n");
  int cId = fork();
  if(cId == -1){
    printf("\tForking failed! not sure why");
  }else{
    if(cId != 0){
      printf("\twaiting on child....\n");
      waitpid(cId,0,0);
      printf("\t\tParent process checking in with ID: %d\n",getpid());
    }else{
      printf("\t\tChild process checking in with ID: %d\n",getpid());
      exit(0);
    }
  }
  printf("\nCall 4 --execl--\n");
  printf("\tFilepath: %s\n", __FILE__);
  execl("hw1","-t","-t",(char*)NULL);
  return 0;
}