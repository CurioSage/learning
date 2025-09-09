#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    int searchElement, value;
    int found = 0;
    char filename[100];

    // Get file path from user
    printf("Enter the full path to the CSV file (e.g., C:\\folder\\file.csv): ");
    scanf("%99s", filename);

    // Open the file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        return 1;
    }

    // Get the element to search
    printf("Enter the number to search: ");
    scanf("%d", &searchElement);

    // Search through the file
    while (fscanf(file, "%d%*[^0-9-]", &value) == 1) {
        if (value == searchElement) {
            found = 1;
            break;
        }
    }

    fclose(file);

    // Show result
    if (found) {
        printf("\nSUCCESS: Element %d was FOUND in the file.\n", searchElement);
    } else {
        printf("\nNOT FOUND: Element %d is NOT present in the file.\n", searchElement);
    }

    return 0;
}