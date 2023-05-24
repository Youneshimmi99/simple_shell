#include "main.h"

/**
 * execute_command - Executes the given command
 * @command: The command to execute
 *
 * Return: 0 on success, -1 on failure
 */
int execute_command(char *command)
{
    pid_t pid;
    pid = fork();

    if (pid < 0)
    {
        perror("simple_shell");
        return (-1);
    }
    else if (pid == 0)
    {
        if (execve(command, NULL, environ) == -1)
        {
            perror("simple_shell");
            return (-1);
        }
        exit(EXIT_FAILURE);
    }
    else
    {
        wait(NULL);
    }

    return (0);
}
