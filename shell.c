#include "main.h"

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
                perror("shell");
                exit(EXIT_FAILURE);
            }
        }

        buffer[strcspn(buffer, "\n")] = 0;

        if (execute_command(buffer) == -1)
        {
            fprintf(stderr, "Error executing command.\n");
        }
    }

    return (0);
}
