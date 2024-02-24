#include <unistd.h>

// Function to print a character to the standard output
void printChar(char c)
{
    write(1, &c, 1);
}

// Helper function to print a combination if it's in ascending order
void printCombination(int *digits, int length)
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
void printCombinations(int n)
{
    int digits[n];

    // Initialize array with zeros
    for (int i = 0; i < n; i++)
        digits[i] = 0;

    // Generate and print combinations
    while (digits[0] <= (10 - n) && n >= 1 && n < 10)
    {
        printCombination(digits, n); // Print the combination

        // Increment last digit and handle carry-over
        digits[n - 1]++;
        int i = n - 1;

        while (i && n > 1)
        {
            if (digits[i] > 9)
            {
                digits[i - 1]++;
                digits[i] = 0;
            }
            i--;
        }
    }
}

// Example usage:
int main()
{
    printCombinations(3); // Print combinations of length 3
    return 0;
}
