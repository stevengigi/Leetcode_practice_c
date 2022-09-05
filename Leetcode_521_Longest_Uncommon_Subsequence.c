#define MAX(a, b) ((a) > (b) ? (a) : (b))

int findLUSlength(char* a, char* b) {
    int alen = strlen(a), blen = strlen(b);
    return !strcmp(a, b) ? -1 : MAX(alen, blen);
}