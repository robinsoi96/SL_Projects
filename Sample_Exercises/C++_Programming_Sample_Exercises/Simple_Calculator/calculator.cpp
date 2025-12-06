#include <iostream>
#include <cmath>
#include <string>

float performCalculation(float num1, float num2, std::string operation)
{
    float total;
    if (operation == "Add"){
        std::cout << "Performing Addition ..." << std::endl;
        total = num1 + num2;
        return total;
    } else if (operation == "Subtract"){
        std::cout << "Performing Subtraction ..." << std::endl;
        total = num1 - num2;
        return total;
    } else if (operation == "Multiply"){
        std::cout << "Performing Multiplication ..." << std::endl;
        total = num1 * num2;
        return total;
    } else if (operation == "Divide"){
        std::cout << "Performing Division ..." << std::endl;
        total = num1 / num2;
        return total;
    } else {
        std::cout << "The correct operation option is not given. Hence, calculation is not performing" << std::endl;
        std::cout << std::endl;
        exit(1);
    }
}

int main()
{
    float inputNum1, inputNum2;
    std::string operation;

    std::cout << "Enter 1st number: ";
    std::cin >> inputNum1;

    std::cout << "Enter 2nd number: ";
    std::cin >> inputNum2;

    std::cout << "Provide operations [Add | Subtract | Multiply | Divide ]: ";
    std::cin >> operation;

    std::cout << std::endl;

    float result = performCalculation(inputNum1, inputNum2, operation);
    std::cout << std::endl;
    std::cout << "Result: " << result << std::endl;

    return 0;
}