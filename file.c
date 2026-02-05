#include <stdio.h>
#include <string.h>

int main() {
    char filename[100];
    FILE *file;
    char ch;
    int lines = 0, words = 0, characters = 0;
    
    printf("=== File Management and Analysis Tool ===\n");
    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if(file == NULL) {
        printf("❌ Could not open file.\n");
        return 1;
    }

    while((ch = fgetc(file)) != EOF) {
        characters++;
        if(ch == '\n') lines++;
        if(ch == ' ' || ch == '\n') words++;
    }
    fclose(file);

    printf("\nFile Analysis of %s\n", filename);
    printf("Lines: %d\nWords: %d\nCharacters: %d\n", lines, words, characters);

    return 0;
}
