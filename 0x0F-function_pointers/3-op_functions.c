#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"
/**
 * op_add - adds five functions
 * @a: first int a
 * @b: second int b
 * Return: sum
 */
int op_add(int a, int b)
{
	return (a + b);
}
/**
 * op_sub - subtracts two
 * @a: first int a
 * @b: second int b
 * Return: difference
 */
int op_sub(int a, int b)
{
	return (a - b);
}
/**
 * op_mul - multiplies two integers
 * @a: first int a
 * @b: second int b
 * Return: multiplication
 */
int op_mul(int a, int b)
{
	return (a * b);
}
/**
 * op_div - division of two numbers
 * @a: first int a
 * @b: second int b
 * Return: division
 */
int op_div(int a, int b)
{
	return (a / b);
}
/**
 * op_mod - modulos of two numbers
 * @a: first int a
 * @b: second int b
 * Return: modulo of integers
 */

int op_mod(int a, int b)
{
	return (a % b);
}
