#include <stdio.h>

unsigned int factorial(unsigned int num)
{
    unsigned int result = 1;
    for (int i = num; i > 0; i--){
        result *= i;
    }

    return result;

}

int main()
{
    unsigned int input;
    
    printf("Enter the number: ");
    scanf("%d", &input);

    printf("Factorial of %d is %d", input, factorial(input));

    return 0;
}