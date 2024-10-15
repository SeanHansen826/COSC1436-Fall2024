#include <iostream>
#include<iomanip>
#include<string>
#include "Terminal.h"

/// @brief reads an int value
/// @param message Message to display
/// @param minValue Minimum required value
/// @param maxValue Maximum required value
/// @return Input from user
int ReadInt(std::string message, int minValue, int maxValue)
{
    int input;
    do
    {
        std::cout << message;
        std::cin >> input;

        if (input < minValue || input > maxValue)
        {
            std::cout << "ERROR: Value must be between " << minValue << "& " << maxValue << std::endl;
        };
    } while (input < minValue || input > maxValue);

    return input;
}


std::string ReadString(std::string message, bool isRequired)
{
    std::string input;
    do
    {
        std::cout << message;
        getline(std::cin, input);

        if (isRequired && input == "")
            std::cout << "ERROR: Value is required" << std::endl;
    } while (isRequired && input == "");

    return input;
}

/// @brief Reads a string from input
/// @param message Message to display
/// @return Input from user
std::string ReadString(std::string message)
{
    return ReadString(message, false);
};