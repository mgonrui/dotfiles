#include <unistd.h>

// Function to print a character to the standard output
void printChar(char c)
{
    write(1, &c, 1);
}

// Function to print a combination of digits in ascending order
void printCombination(int digits[], int length)
{
    for (int i = 0; i < length; i++)
        printChar(digits[i] + '0'); // Convert digit to character and print

    if (digits[0] < (10 - length))
    {
        printChar(',');
        printChar(' ');
    }
}

// Main function to generate and print combinations of length n
void generateCombinations(int digits[], int n, int index, int start)
{
    if (index == n)
    {
        printCombination(digits, n); // Print the combination
        return;
    }

    for (int i = start; i <= 9; i++)
    {
        digits[index] = i;
        generateCombinations(digits, n, index + 1, i + 1);
    }
}

// Wrapper function to initiate combination generation
void printCombinations(int n)
{
    if (n >= 1 && n <= 9)
    {
        int digits[n];
        generateCombinations(digits, n, 0, 0);
    }
}

// Example usage:
int main()
{
    printCombinations(2); // Print combinations of length 3
    return 0;
}
