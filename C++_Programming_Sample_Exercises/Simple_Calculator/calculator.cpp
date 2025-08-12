#include <iostream>
#include <cmath>

using namespace std;

float performCalculation(float num1, float num2, string operation)
{
    float total;
    if (operation == "Add"){
        cout << "Performing Addition ..." << endl;
        total = num1 + num2;
        return total;
    } else if (operation == "Subtract"){
        cout << "Performing Subtraction ..." << endl;
        total = num1 - num2;
        return total;
    } else if (operation == "Multiply"){
        cout << "Performing Multiplication ..." << endl;
        total = num1 * num2;
        return total;
    } else if (operation == "Divide"){
        cout << "Performing Division ..." << endl;
        total = num1 / num2;
        return total;
    } else {
        cout << "The correct operation option is not given. Hence, calculation is not performing" << endl;
        cout << endl;
        exit(1);
    }
}

int main()
{
    float inputNum1, inputNum2;
    string operation;

    cout << "Enter 1st number: ";
    cin >> inputNum1;

    cout << "Enter 2nd number: ";
    cin >> inputNum2;

    cout << "Provide operations [Add | Substract | Multiply | Divide ]: ";
    cin >> operation;

    cout << endl;

    float result = performCalculation(inputNum1, inputNum2, operation);
    cout << endl;
    cout << "Result: " << result << endl;

    return 0;
}