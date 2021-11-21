#include <stdio.h>
#include <string.h>
int decimali = 0; float decimal = 0;
void binarytodecimal()
{
    char binary[20],decimalstr[10];
    int bpoint = -1, error = 0, basei = 1;
    float base = 2;

    printf("\nEnter a binary value : ");
    scanf("\n");
    gets(binary);

    for (int i = 0; binary[i] != '\0'; i++)
    {
        if (binary[i] == '.')
            bpoint = i;
        if (!(binary[i] == '1' || binary[i] == '0' || binary[i] == '.'))
            error++;
    }
    if (error == 0)
    {
        if (bpoint == -1)
        {
            for (int i = (strlen(binary) - 1); i >= 0; i--)
            {
                decimali += ((binary[i] - '0') * basei);
                basei *= 2;
            }
            printf("The Decimal of %s is %d %c\n\n", binary, decimali, 1);
            
        }
        else
        {
            for (int i = bpoint + 1; i < strlen(binary); i++)
            {
                decimal += ((binary[i] - '0') / base);
                base *= 2;
            }
            base = 1;
            for (int i = bpoint - 1; i >= 0; i--)
            {
                decimal += ((binary[i] - '0') * base);
                base *= 2;
            }
            printf("The Decimal value of %s is %f %c\n\n", binary, decimal, 1);
        }
    }
    else
        printf("Invalid Input");
}

int main()
{
    int inputchoice, outputchoice;
    printf("\n\n   Pick your choice : \n");
    printf(">>------------------<<<\n\n");
    printf("Enter 1 for Binary Number \n");
    printf("Enter 2 for Octal Number \n");
    printf("Enter 3 for Decimal Number  \n");
    printf("Enter 4 for Hexa Decimal Number \n\n");
    scanf("%d", &inputchoice);
    switch (inputchoice)
    {
    case 1:
        printf("\nEnter 1 if you want to convert Binary into Octal \n");
        printf("Enter 2 if you want to convert Binary into Decimal \n");
        printf("Enter 3 if you want to convert Binary into Hexa-Decimal \n\n");
        scanf("%d", &outputchoice);
        switch (outputchoice)
        {
        case 1:
            printf("Case 1");
            break;
        case 2:
            binarytodecimal();
            break;
        case 3:
            printf("Case 3");
            break;

        default:
            break;
        }
        break;

    case 2:
        printf("Enter 1 if you want to convert Octal into Decimal \n");
        printf("Enter 2 if you want to convert Octal into  Hexa-Decimal \n");
        printf("Enter 3 if you want to convert Octal into  Binary \n");
        break;

    case 3:
        printf("Enter 1 if you want to convert Decimal into Hexa-Decimal \n");
        printf("Enter 2 if you want to convert Decimal into Binary \n");
        printf("Enter 3 if you want to convert Decimal into Octal\n");
        break;

    case 4:
        printf("Enter 1 if you want to convert Hexa-Decimal into Binary \n");
        printf("Enter 2 if you want to convert Hexa-Decimal into Decimal \n");
        printf("Enter 3 if you want to convert Hexa-Decimal into Octal \n");
        break;

    default:
        printf("Invalid Input");
    }
    return 0;
}