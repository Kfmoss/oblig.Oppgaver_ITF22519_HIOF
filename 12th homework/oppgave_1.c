#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char *byte_size(long double n_bytes);

int main() {
    int ptr_size, block_size;
    
    // Leser input fra brukeren
    printf("Ptr.size in bits (32|64)? ");
    scanf("%d", &ptr_size);
    
    printf("Block size in kB (1|2|4|8)? ");
    scanf("%d", &block_size);
    
    // Beregner maksimal diskstørrelse og filstørrelse
    long double max_disk_size, max_file_size;
    long double bytes_in_block = block_size * 1024.0L;
    
    if (ptr_size == 32) {
        max_disk_size = pow(2, 32) * bytes_in_block;
        max_file_size = pow(2, 32);
    } else if (ptr_size == 64) {
        max_disk_size = pow(2, 64) * bytes_in_block;
        max_file_size = pow(2, 42);  // 42 bits for inoden i dette eksemplet
    } else {
        printf("Invalid pointer size\n");
        return 1;
    }

    // Skriver ut resultatene
    printf("\nMax. disk size :  %s\n", byte_size(max_disk_size));
    printf("Max. file size :  %s\n", byte_size(max_file_size));

    return 0;
}

char *byte_size(long double n_bytes) {
   

    char *units[] = {"B", "kB", "MB", "GB", "TB", "PB", "EB", "ZB"};
    int index = 0;
    long double size =n_bytes;

    while (size >= 1024.0 && index < 5) {
        size /= 1024.0;
        index++;
    }

    char *result = malloc(20 * sizeof(char));  // Allocate memory for the result string
    if (result == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    sprintf(result, "%.1Lf %s", size, units[index]);  // Format the size with the appropriate unit

    return result;
}
