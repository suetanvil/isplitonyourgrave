#/*

# C program to split the arguments on the phrase 'your grave'.
#
# To compile, run as a shell script with bash on a sufficiently
# unix-like machine with gcc installed.

gcc -g -Wall -std=c99 $0 -o ${0%.c}
exit $?

*/


#include <string.h>
#include <stdio.h>
#include <stdlib.h>



static char **
grow(char **result, size_t count, char *ptr) {

    result = realloc(result, (count + 1) * sizeof(char *));
    if (!result) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }

    result[count - 1] = ptr;
    result[count] = NULL;

    return result;
}

char **
isoyg(char *src) {
    const char *PHRASE = "your grave";
    const size_t PHRASE_LEN = strlen(PHRASE);

    int count = 1;
    char **result = grow(NULL, count, src);

    for (char *ptr = src; *ptr; ptr++) {
        if (strncmp(PHRASE, ptr, PHRASE_LEN) == 0) {
            ++count;
            *ptr = '\0';
            ptr += PHRASE_LEN;

            result = grow(result, count, ptr);
        }
    }

    return result;
}


int main(int argc, char *argv[]) {
    for (int n = 1; n < argc; n++) {
        char **tokens = isoyg(argv[n]);

        for (int i = 0; tokens[i]; i++) {
            printf("%s\n", tokens[i]);
        }
        printf("\n");
        free(tokens);
    }

    return 0;
}
