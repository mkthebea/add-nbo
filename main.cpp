# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <netinet/in.h>

uint32_t readint(char* file) {
    FILE *f;
    uint32_t result;
    f = fopen(file, "r");
    if (f == NULL) {
        fprintf(stderr, "[ERROR] Unable to open file: %s",file);
        exit(-1);
    }
    fread(&result, 1, sizeof (result), f);
    fclose(f);
    result = htonl(result);
    return result;
}

int main(int argc, char *argv[]) {
    if(argc != 3) {
        fprintf(stderr, "[ERROR] Please enter it in the following format: add-nbo <file1> <file2>\n");
        exit(-1);
    }

    uint32_t a, b, c;
    a = readint(argv[1]);
    b = readint(argv[2]);
    c = a + b;

    printf("%d(%#x) + %d(%#x) = %d(%#x)", a,a,b,b,c,c);

    return 0;
}
