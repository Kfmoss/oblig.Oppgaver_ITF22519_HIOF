#include <stdio.h>

int main() {
    int a[] = {1, 2, 3, 4, 5, 6};
    int b[] = {2, 3, 5, 6, 1, 4};
    int num_of_elem = 6;

    for (int i = 0; i < num_of_elem; i++) {
        for (int z = 0; z < num_of_elem; z++) {
            if (a[i] == b[z]) {
                printf("%d\n", b[z]);
                // Mark the matched element in b as -1 to avoid duplicates
                b[z] = -1;
            }
        }
    }

    return 0;
}
