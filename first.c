#include <stdio.h>

/**
 * main- adds 2 numebers given by user
 *
 * Return: returns 0
 */

int main(void)
{
	int n1, n2;

	printf("Enter two numbers");
	scanf("%d%d", &n1, &n2);

	printf(" The sum of the two numbers is %d\n", n1 + n2);

	return (0);
}
