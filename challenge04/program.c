#include <stdio.h>

int main() {
    float expense;
    float smalltotal = 0, mediumtotal = 0, largetotal = 0;
    float total = 0, average;

    int smallcount = 0, mediumcount = 0, largecount = 0;
    int validcount = 0;
    int ch;

    while (1) {
        printf("ENTER EXPENSE (0 TO STOP): ");

        if (scanf("%f", &expense) != 1) {
            if (feof(stdin)) {
                break;
            }

            printf("Invalid input! Please enter a number.\n");

            while ((ch = getchar()) != '\n' && ch != EOF);

            continue;
        }

        if (expense == 0) {
            break;
        }
        else if (expense < 0) {
            printf("ENTERED NEGATIVE OR INVALID AMOUNT\n");
            continue;
        }
        else {
            validcount++;
            total = total + expense;

            if (expense < 100) {
                smallcount++;
                smalltotal = smalltotal + expense;
                printf("Category: Small\n");
            }
            else if (expense < 500) {
                mediumcount++;
                mediumtotal = mediumtotal + expense;
                printf("Category: Medium\n");
            }
            else {
                largecount++;
                largetotal = largetotal + expense;
                printf("Category: Large\n");
            }
        }
    }

    printf("\nNumber of valid expenses: %d\n", validcount);
    printf("Total of valid expenses: Rs. %.2f\n", total);

    printf("Number of small expenses: %d\n", smallcount);
    printf("Total of small expenses: Rs. %.2f\n", smalltotal);

    printf("Number of medium expenses: %d\n", mediumcount);
    printf("Total of medium expenses: Rs. %.2f\n", mediumtotal);

    printf("Number of large expenses: %d\n", largecount);
    printf("Total of large expenses: Rs. %.2f\n", largetotal);

    if (validcount > 0) {
        average = total / validcount;
        printf("Average expense = Rs. %.2f\n", average);
    }
    else {
        printf("No valid expenses were entered.\n");
    }

    return 0;
}
