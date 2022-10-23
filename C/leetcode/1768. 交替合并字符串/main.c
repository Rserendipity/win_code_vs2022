#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* mergeAlternately(char* word1, char* word2) {
    int sz1 = strlen(word1);
    int sz2 = strlen(word2);
    char* ans = (char*)calloc(sz1 + sz2 + 1, 1);
    int i = 0;
    while (*word1 && *word2) {
        ans[i++] = *word1++;
        ans[i++] = *word2++;
    }
    char* temp = *word1 == NULL ? word2 : word1;
    strcat(ans, temp);
    return ans;
}

int main()
{
    printf("%s", mergeAlternately("ab", "defg"));
    return 0;
}
