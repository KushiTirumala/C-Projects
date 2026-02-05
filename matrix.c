#include <stdio.h>

void inputMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Enter elements:\n");
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            scanf("%d", &matrix[i][j]);
}

void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++)
            printf("%d\t", matrix[i][j]);
        printf("\n");
    }
}

int main() {
    int rows, cols, choice;
    printf("=== Matrix Operations Toolkit ===\n");

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int matrix1[rows][cols], matrix2[rows][cols], result[rows][cols];

    printf("Matrix 1:\n");
    inputMatrix(rows, cols, matrix1);

    printf("Matrix 2:\n");
    inputMatrix(rows, cols, matrix2);

    do {
        printf("\n--- Menu ---\n");
        printf("1. Matrix Addition\n2. Matrix Subtraction\n3. Matrix Multiplication\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                for(int i=0;i<rows;i++)
                    for(int j=0;j<cols;j++)
                        result[i][j] = matrix1[i][j] + matrix2[i][j];
                printf("Result of Addition:\n");
                printMatrix(rows, cols, result);
                break;
            case 2:
                for(int i=0;i<rows;i++)
                    for(int j=0;j<cols;j++)
                        result[i][j] = matrix1[i][j] - matrix2[i][j];
                printf("Result of Subtraction:\n");
                printMatrix(rows, cols, result);
                break;
            case 3:
                if(rows != cols){
                    printf("❌ For multiplication, square matrices are required.\n");
                    break;
                }
                for(int i=0;i<rows;i++)
                    for(int j=0;j<cols;j++){
                        result[i][j] = 0;
                        for(int k=0;k<cols;k++)
                            result[i][j] += matrix1[i][k]*matrix2[k][j];
                    }
                printf("Result of Multiplication:\n");
                printMatrix(rows, cols, result);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("❌ Invalid choice\n");
        }
    } while(choice != 4);

    return 0;
}
