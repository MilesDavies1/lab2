/* timer.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int alarm_count = 0;

void alarm_handler(int signum)
{
    alarm_count++;
}

void ctrlc_handler(int signum)
{
    printf("\nTotal alarms occurred: %d\n", alarm_count);
    printf("Total time executed: %d seconds\n", alarm_count);
    exit(0);
}

int main()
{
    signal(SIGALRM, alarm_handler); // Register handler for SIGALRM
    signal(SIGINT, ctrlc_handler);  // Register handler for SIGINT (CTRL-C)

    while (1)
    {
        alarm(1); // Schedule a SIGALRM for 1 second
        pause();  // Wait for the signal to be delivered
    }

    return 0;
}
