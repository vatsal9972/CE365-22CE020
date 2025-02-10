#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool validateString(const char *input) {
    int countA = 0;
    int countB = 0;
    int i = 0;

    while (input[i] == 'a') {
        countA++;
        i++;
    }

    while (input[i] == 'b') {
        countB++;
        i++;
    }

    if (countB == 2 && input[i] == '\0') {
        return true;
    }

    return false;
}

int main() {
    char input[100];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    if (validateString(input)) {
        printf("Valid String\n");
    } else {
        printf("Invalid String\n");
    }

    return 0;
}
