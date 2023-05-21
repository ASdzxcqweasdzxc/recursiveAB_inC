#include <stdio.h>
#include <string.h>


// analize words of types: S -> aSb | bSa | ab | ba
void S(const char s[], int i) {
    // debug print
//    printf("inc_word= %s\n", s);
//    printf("first= %c last= %c\n", s[i], s[strlen(s) - 1 - i]);
    if ((s[i] == 'a') & (s[strlen(s) - 1 - i] == 'b')) {
        if (i == ((strlen(s) - 1) / 2)) {
            printf("%s\n", "S -> ab");
        } else {
            printf("%s", "S -> aSb; ");
            S(s, ++i);
        }
    }
    else if ((s[i] == 'b') & (s[strlen(s) - 1 - i] == 'a')) {
        if (i == ((strlen(s) - 1) / 2)) {
            printf("%s\n", "S -> ba");
        } else {
            printf("%s", "S -> bSa; ");
            S(s, ++i);
        }
    }
    else {
        printf("%s\n", "Wrong word!!!");
    }
}


int main() {
    char c[100];
    int i = 0;
    printf("Enter char sequence for {a,b}: ");
    scanf("%s", c);

    if(strlen(c) % 2 != 0){
        printf("%s\n", "Not in lang: wrong length!!!");
    } else {
        S(c, i);
    }
    return 0;
}
