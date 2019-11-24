#include <cstdio>
#include <cstring>
#include <string>
#include <stdio.h>
int main() {
    char* line = NULL;
    size_t len = 0;
    const char* as = "1 2 3 4 5 6 7 8";
    const char* de = "8 7 6 5 4 3 2 1";
    int n = getline(&line, &len, stdin);
    if (strstr(line, as) != 0) printf("ascending\n");
    else if (strstr(line, de) != 0) printf("descending\n");
    else printf("mixed\n");
    free(line);
    return 0;
}
