/**
 * add_numbers - Add two numbers together
 * @a: The first number to add
 * @b: The second number to add
 *
 * Return: The sum of a and b
 */
int add_numbers(int a, int b)
{
    return a + b;
}

int main(void)
{
    int x, y, z;

    x = 1;
    y = 2;
    z = add_numbers(x, y);

    printf("The sum of %d and %d is %d\n", x, y, z);

    return 0;
}
