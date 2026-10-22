#include <stdio.h>

void printPowerSet(char set[], int n, int index, char subset[], int subsetSize) {
    if (index == n) {

        printf("{ ");
        for (int i = 0; i < subsetSize; i++) {
            printf("%c ", subset[i]);
        }
        printf("}\n");
        return;
    }


    printPowerSet(set, n, index + 1, subset, subsetSize);
    subset[subsetSize] = set[index];
    printPowerSet(set, n, index + 1, subset, subsetSize + 1);
}

int main() {
    int n;
    printf("Enter size of set: ");
    scanf("%d", &n);

    char set[n];
    printf("Enter %d elements (characters): ", n);
    for (int i = 0; i < n; i++) {
        scanf(" %c", &set[i]);
    }

    char subset[n];
    printf("Power set:\n");
    printPowerSet(set, n, 0, subset, 0);

    return 0;
}
