#include <stdio.h>

int main()
{
    int choice;
    float result;

    printf("========== PROJECT SDF ==========\n");
    printf("1. Currency Converter\n");
    printf("2. Temperature Converter\n");
    printf("3. Length Converter\n");
    printf("4. Calculator\n");
    printf("5. Complex Calculator (Matrix Operations)\n");
    printf("=================================\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // -------------------- CURRENCY CONVERTER --------------------
    if (choice == 1)
    {
        float currency;
        int convert;

        printf("Enter the amount in INR: ");
        scanf("%f", &currency);

        printf("Convert to:\n");
        printf("1. US Dollar\n");
        printf("2. Australian Dollar\n");
        printf("3. Euro\n");
        printf("4. Yen\n");
        scanf("%d", &convert);

        switch (convert)
        {
        case 1:
            result = currency / 83.3;
            printf("Amount in USD: %.2f\n", result);
            break;
        case 2:
            result = currency / 47.7;
            printf("Amount in AUD: %.2f\n", result);
            break;
        case 3:
            result = currency / 90.0;
            printf("Amount in Euro: %.2f\n", result);
            break;
        case 4:
            result = currency / 0.56;
            printf("Amount in Yen: %.2f\n", result);
            break;
        default:
            printf("Invalid currency choice!\n");
            break;
        }
    }

    // -------------------- TEMPERATURE CONVERTER --------------------
    else if (choice == 2)
    {
        float temp;
        int convert;

        printf("Enter the temperature in Celsius: ");
        scanf("%f", &temp);
        printf("Convert to:\n1. Fahrenheit\n2. Kelvin\n");
        scanf("%d", &convert);

        if (convert == 1)
            printf("Temperature in Fahrenheit: %.2f\n", (temp * 9 / 5) + 32);
        else if (convert == 2)
            printf("Temperature in Kelvin: %.2f\n", temp + 273.15);
        else
            printf("Invalid choice!\n");
    }

    // -------------------- LENGTH CONVERTER --------------------
    else if (choice == 3)
    {
        float length;
        int newL;

        printf("Enter the length in meters (m): ");
        scanf("%f", &length);

        printf("Convert to:\n1. Km\n2. cm\n3. mm\n4. inches\n");
        scanf("%d", &newL);

        switch (newL)
        {
        case 1:
            length = length / 1000;
            printf("The converted length is %.4f km\n", length);
            break;
        case 2:
            length = length * 100;
            printf("The converted length is %.2f cm\n", length);
            break;
        case 3:
            length = length * 1000;
            printf("The converted length is %.2f mm\n", length);
            break;
        case 4:
            length = (length * 100) / 2.54;
            printf("The converted length is %.2f inches\n", length);
            break;
        default:
            printf("Wrong choice!\n");
            break;
        }
    }

    // -------------------- BASIC CALCULATOR --------------------
    else if (choice == 4)
    {
        int op;
        float a, b, outcome;

        printf("Enter two numbers: ");
        scanf("%f %f", &a, &b);

        printf("Enter the operation:\n");
        printf("1. +\n2. -\n3. *\n4. /\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            outcome = a + b;
            printf("The Sum is %.2f\n", outcome);
            break;
        case 2:
            outcome = a - b;
            printf("The Difference is %.2f\n", outcome);
            break;
        case 3:
            outcome = a * b;
            printf("The Product is %.2f\n", outcome);
            break;
        case 4:
            if (b != 0)
                outcome = a / b;
            else
            {
                printf("Division by zero is not allowed!\n");
                break;
            }
            printf("The Division Result is %.2f\n", outcome);
            break;
        default:
            printf("Invalid choice!\n");
            break;
        }
    }

    // -------------------- MATRIX CALCULATOR --------------------
    else if (choice == 5)
    {
        int a[3][3], b[3][3], resultMat[3][3];
        int i, j, cOp;

        printf("Matrix Calculator:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Determinant\n");
        printf("Enter your choice: ");
        scanf("%d", &cOp);

        // -------------------- ADDITION OR SUBTRACTION --------------------
        if (cOp == 1 || cOp == 2)
        {
            printf("\nEnter elements of Matrix A (3x3):\n");
            for (i = 0; i < 3; i++)
                for (j = 0; j < 3; j++)
                    scanf("%d", &a[i][j]);

            printf("\nEnter elements of Matrix B (3x3):\n");
            for (i = 0; i < 3; i++)
                for (j = 0; j < 3; j++)
                    scanf("%d", &b[i][j]);

            printf("\nResultant Matrix:\n");
            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    if (cOp == 1)
                        resultMat[i][j] = a[i][j] + b[i][j];
                    else
                        resultMat[i][j] = a[i][j] - b[i][j];

                    printf("%d\t", resultMat[i][j]);
                }
                printf("\n");
            }
        }

        // -------------------- DETERMINANT --------------------
        else if (cOp == 3)
        {
            printf("\nEnter elements of Matrix A (3x3):\n");
            for (i = 0; i < 3; i++)
                for (j = 0; j < 3; j++)
                    scanf("%d", &a[i][j]);

            int det;
            det = a[0][0] * (a[1][1]*a[2][2] - a[1][2]*a[2][1])
                - a[0][1] * (a[1][0]*a[2][2] - a[1][2]*a[2][0])
                + a[0][2] * (a[1][0]*a[2][1] - a[1][1]*a[2][0]);

            printf("\nDeterminant of the matrix is: %d\n", det);
        }

        // -------------------- INVALID CHOICE --------------------
        else
        {
            printf("Invalid matrix operation choice!\n");
        }
    }

    // -------------------- INVALID OPTION --------------------
    else
    {
        printf("Invalid main choice!\n");
    }

    return 0;
}
