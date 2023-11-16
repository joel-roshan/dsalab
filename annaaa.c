#include <stdio.h>

int main() {
    int n, m;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &n, &m);

    int sparse[n][3];
    printf("Enter the sparse matrix:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &sparse[i][0], &sparse[i][1], &sparse[i][2]);
    }

    int transpose[m][3];
    int count[m] = {0};
    for (int i = 0; i < n; i++) {
        int col = sparse[i][1];
        transpose[count[col]][0] = col;
        transpose[count[col]][1] = sparse[i][0];
        transpose[count[col]][2] = sparse[i][2];
        count[col]++;
    }

    int isSymmetric = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < count[i]; j++) {
            if (transpose[j][0] != i || transpose[j][1] != i || transpose[j][2] != transpose[count[i]-j-1][2]) {
                isSymmetric = 0;
                break;
            }
        }
        if (!isSymmetric) {
            break;
        }
    }

    if (isSymmetric) {
        printf("The sparse matrix is symmetric.\n");
    } else {
        printf("The sparse matrix is not symmetric.\n");
    }

    return 0;
}
