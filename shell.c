#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * main - Shell program that read user input and executes commands.
 *
 * Return: Always 0.
 */
int main(void)
{
    char *line = NULL;
    size_t line_size = 0;

    while (1)
    {
        printf("#cisfun$ ");

        if (getline(&line, &line_size, stdin) < 0)
            break;

        line[strcspn(line, "\n")] = '\0';

        if (access(line, X_OK) == 0)
        {
            pid_t pid = fork();
            if (pid == 0)
            {
                char *args[] = {line, NULL};
                execve(line, args, environ);
                fprintf(stderr, "Error: failed to execute command '%s'\n", line);
                exit(EXIT_FAILURE);
            }
            else if (pid < 0)
            {
                fprintf(stderr, "Error: failed to fork process\n");
                exit(EXIT_FAILURE);
            }
            else
            {
                wait(NULL);
            }
        }
        else
        {
            fprintf(stderr, "Error: command '%s' not found\n", line);
        }
    }

    free(line);

    return 0;
}
