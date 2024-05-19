#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [-c | -w] [input_file_name]\n", argv[0]);
        return 1;
    }

    int count = 0;
    int isCountChar = 0;
    if (strcmp(argv[1], "-c") == 0) {
        isCountChar = 1;
    } else if (strcmp(argv[1], "-w") == 0) {
        isCountChar = 0;
    } else {
        printf("Invalid option. Please use -c or -w.\n");
        return 1;
    }

    FILE *file = fopen(argv[2], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int inWord = 0;
    char c;
    while ((c = fgetc(file)) != EOF) {
        if (isCountChar) {
            count++;
        } else {
            if (c == ' ' || c == '\n' || c == '\t') {
                inWord = 0;
            } else if (!inWord) {
                inWord = 1;
                count++;
            }
        }
    }

    fclose(file);

    if (isCountChar) {
        printf("Characters: %d\n", count);
    } else {
        printf("Words: %d\n", count);
    }

    return 0;
}
