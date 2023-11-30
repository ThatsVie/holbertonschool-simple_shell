/**
* File: beautiful_code.c
* Desc: Example of beautiful C code following Betty style.
*/

#include <stdio.h>

/**
* mul_numbers - multiplys two numbers.
* @a: The first number to be multiplied
* @b: The second number to be multiplied
*
* Return: The product of the two number
*/
int mul_numbers(int a, int b)
{
    return (a * b);
}

/**
* main - Entry point of program
* 
* Return Always 0 (Success).
*/
int main(void)
{
    int num1 = 4;
    int num2 = 6;
    int product;

    /* Calculate the product of num1 and num2*/
    product = mul_numbers(num1, num2);

    /* Display the result*/
    printf("The product of %d and %d is: %d\n", num1, num2, product);

    return (0);
}