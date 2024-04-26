#include <stdio.h>

unsigned int factorial(int num)
{
    int result = 1;
    for (int i = num; i > 0; i--){
        result *= i;
    }

}

int main()
{
    int input;
    
    printf("Enter the number: ");
    scanf("%d", &input);

    printf("Factorial of %d is %d", input, factorial(input));

    return 0;
}