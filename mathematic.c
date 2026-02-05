#include <stdio.h>
#include <math.h>

int main() {
    int choice;
    double num1, num2;

    printf("=== Mathematical Computation Console ===\n");

    do {
        printf("\n--- Menu ---\n");
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Square Root\n6. Power\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                printf("Result: %.2lf\n", num1 + num2);
                break;
            case 2:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                printf("Result: %.2lf\n", num1 - num2);
                break;
            case 3:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                printf("Result: %.2lf\n", num1 * num2);
                break;
            case 4:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                if(num2 != 0) printf("Result: %.2lf\n", num1 / num2);
                else printf("❌ Cannot divide by zero.\n");
                break;
            case 5:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                if(num1 >= 0) printf("Square Root: %.2lf\n", sqrt(num1));
                else printf("❌ Cannot compute square root of negative number.\n");
                break;
            case 6:
                printf("Enter base and exponent: ");
                scanf("%lf %lf", &num1, &num2);
                printf("Result: %.2lf\n", pow(num1, num2));
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("❌ Invalid choice.\n");
        }

    } while(choice != 7);

    return 0;
}
