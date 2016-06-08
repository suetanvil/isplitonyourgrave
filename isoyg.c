
#include <string.h>
#include <stdio.h>



static char **
grow(char **result, size_t count, char *ptr) {

    result = realloc(result, (count + 1) * sizeof(char *));
    if (!result) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }

    result[count - 1] = ptr;
    result[count] = NULL;

    return result
}

char **
isoyg(char *src) {
    const char *PHRASE = "your grave";
    const size_t PHRASE_LEN = strlen(PHRASE);

    int count = 1;
    char **result = grow(NULL, count, src);

    for (char *ptr = src; *ptr; ptr++) {
        if (strcmp(PHRASE, ptr, PHRASE_LEN) == 0) {
            ++count;
            *ptr = '\0';
            ptr += PHRASE_LEN;

            result = grow(result, count, ptr);
        }
    }

    return result;
}


int main(int argc, char *argv[]) {
    


}
