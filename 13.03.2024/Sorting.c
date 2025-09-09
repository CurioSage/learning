#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

// Comparison functions for sorting
int compare_asc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int compare_desc(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    FILE *input, *output;
    int original[SIZE];
    int asc[SIZE], desc[SIZE];
    int i;
    
    // Corrected file opening with proper path and mode
    input = fopen("C:\\Users\\iMAGINE\\Documents\\input.csv", "r"); // Use double backslashes
    if (!input) {
        printf("Error: Could not open input.csv\n");
        printf("Make sure the file exists and is in the correct directory.\n");
        return 1;
    }

    // Read 10 integers from the file
    for (i = 0; i < SIZE; i++) {
        if (fscanf(input, "%d", &original[i]) != 1) {
            printf("Error: Invalid data at position %d in input.csv\n", i+1);
            fclose(input);
            return 1;
        }
    }
    fclose(input);

    // Create sorted copies
    memcpy(asc, original, sizeof(asc));
    memcpy(desc, original, sizeof(desc));

    qsort(asc, SIZE, sizeof(int), compare_asc);
    qsort(desc, SIZE, sizeof(int), compare_desc);

    // Write output to CSV file
    output = fopen("C:\\Users\\iMAGINE\\Documents\\output.csv", "w"); // Output path
    if (!output) {
        printf("Error creating output.csv\n");
        return 1;
    }

    // Write header row
    fprintf(output, "Original,Ascending,Descending\n");

    // Write data rows
    for (i = 0; i < SIZE; i++) {
        fprintf(output, "%d,%d,%d\n", original[i], asc[i], desc[i]);
    }

    fclose(output);
    printf("Success! Check output.csv in Documents folder.\n");
    return 0;
}