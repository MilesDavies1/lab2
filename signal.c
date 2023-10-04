/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int signum)
{ // Signal handler
  printf("Hello World!\n");
}

int main(int argc, char *argv[])
{
  signal(SIGALRM, handler); // Register handler to handle SIGALRM

  while (1)
  {
    alarm(1);              // Schedule a SIGALRM for 1 second
    pause();              // Wait for the signal to be delivered
    printf("Turing was right!\n");
  }

  return 0;
}
