#include <stdio.h>

// Function to find length of string
int stringLength(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

// Function to copy string
void stringCopy(char dest[], char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// Function to compare two strings
int stringCompare(char s1[], char s2[]) {
    int i = 0;
    while (s1[i] != '\0' || s2[i] != '\0') {
        if (s1[i] != s2[i])
            return s1[i] - s2[i]; // difference
        i++;
    }
    return 0; // strings are equal
}

// Function to concatenate two strings
void stringConcatenate(char s1[], char s2[]) {
    int i = 0, j = 0;

    // Move to end of s1
    while (s1[i] != '\0') {
        i++;
    }

    // Copy s2 into s1
    while (s2[j] != '\0') {
        s1[i] = s2[j];
        i++;
        j++;
    }

    s1[i] = '\0';
}

int main() {
    char str1[100], str2[100], copyStr[100];
    int choice;

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);

    // Removing newline from fgets
    for (int i = 0; str1[i]; i++) {
        if (str1[i] == '\n') str1[i] = '\0';
    }
    for (int i = 0; str2[i]; i++) {
        if (str2[i] == '\n') str2[i] = '\0';
    }

    printf("\n--- String Operations Menu ---\n");
    printf("1. Compare Strings\n");
    printf("2. Copy String 1 into new string\n");
    printf("3. Find Length of Strings\n");
    printf("4. Concatenate Strings\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: {
            int result = stringCompare(str1, str2);
            if (result == 0)
                printf("Strings are Equal\n");
            else
                printf("Strings are NOT Equal\n");
            break;
        }

        case 2:
            stringCopy(copyStr, str1);
            printf("Copied String: %s\n", copyStr);
            break;

        case 3:
            printf("Length of String 1 = %d\n", stringLength(str1));
            printf("Length of String 2 = %d\n", stringLength(str2));
            break;

        case 4:
            stringConcatenate(str1, str2);
            printf("Concatenated String: %s\n", str1);
            break;

        default:
            printf("Invalid Choice!\n");
    }

    return 0;
}
