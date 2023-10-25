#include <stdio.h>

struct Triple {
    int row;
    int column;
    int value;
};

int main() {
    // Replace these values with your sparse matrix datat
    int data[] = {1, 2, 3, 4};
    int row_indices[] = {0, 1, 2, 3};
    int column_indices[] = {1, 3, 0, 2};
    int num_non_zero_elements = 4;

    struct Triple triples[num_non_zero_elements];

    for (int i = 0; i < num_non_zero_elements; i++) {
        triples[i].row = row_indices[i];
        triples[i].column = column_indices[i];
        triples[i].value = data[i];
    }

    // Print the triples
    for (int i = 0; i < num_non_zero_elements; i++) {
        printf("Triple %d: (%d, %d, %d)\n", i + 1, triples[i].row, triples[i].column, triples[i].value);
    }

    return 0;
}
