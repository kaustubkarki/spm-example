//Write a programto test the given identidfier is valid or not?

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isValidIdentifier(const char *identifier) {
    // Check if the identifier is empty
    if (strlen(identifier) == 0) {
        return 0; // Invalid if empty
    }

    // Check the first character
    if (!(isalpha(identifier[0]) || identifier[0] == '_')) {
        return 0; // Invalid if not a letter or underscore
    }

    // Check subsequent characters
    int length = strlen(identifier);
    int i;
    for (i = 1; i < length; i++) {
        if (!(isalpha(identifier[i]) || isdigit(identifier[i]) || identifier[i] == '_')) {
            return 0; // Invalid if not a letter, digit, or underscore
        }
    }

    // If all checks pass, the identifier is valid
    return 1;
}

int main() {
    char identifier[100];
    int i;

    printf("Enter an identifier: ");
    scanf("%s", identifier);

    if (isValidIdentifier(identifier)) {
        printf("The identifier '%s' is valid.\n", identifier);
    } else {
        printf("The identifier '%s' is invalid.\n", identifier);
    }

    return 0;
}

