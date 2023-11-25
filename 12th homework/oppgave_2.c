#include <stdio.h>
#include <sys/stat.h>

int main() {
    char filename1[100], filename2[100];
    struct stat stat1, stat2;

    // Les to filnavn fra brukeren
    printf("Please input two valid file names: ");
    scanf("%s %s", filename1, filename2);

    // Hent metadata for de to filene
    stat(filename1, &stat1);
    stat(filename2, &stat2);

    // Skriv ut i-nodenummer, antall hard links og filstørrelse for hver fil
    printf("\n%s ->  I-node:%ld   Links:%ld   Size:%ld\n", filename1, stat1.st_ino, stat1.st_nlink, stat1.st_size);
    printf("%s ->  I-node:%ld   Links:%ld   Size:%ld\n", filename2, stat2.st_ino, stat2.st_nlink, stat2.st_size);

    // Sjekk om filene er identiske (samme i-node)
    if (stat1.st_ino == stat2.st_ino) {
        printf("\nThe two files are identical\n");
    } else {
        printf("\nThe two files are not identical\n");
    }

    return 0;
}
