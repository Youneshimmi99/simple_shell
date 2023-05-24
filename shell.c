#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFSIZE 1024

/**
 * main - Entry point for simple shell
 *
 * Return: Always 0
 */
int main(void)
{
    char buffer[BUFSIZE];

    while (1)
    {
        printf("#cisfun$ ");

        if (fgets(buffer, BUFSIZE, stdin) == NULL)
        {
            if (feof(stdin))
            {
                printf("\n");
                exit(EXIT_SUCCESS);
            }
            else
            {
                perror("simple_shell");
                exit(EXIT_FAILURE);
            }
        }

        buffer[strcspn(buffer, "\n")] = 0;

        pid_t pid;
        pid = fork();

        if (pid < 0)
        {
            perror("simple_shell");
        }
        else if (pid == 0)
        {
            if (execve(buffer, NULL, environ) == -1)
            {
                perror("simple_shell");
            }
            exit(EXIT_FAILURE);
        }
        else
        {
            wait(NULL);
        }
    }

    return (0);
}
