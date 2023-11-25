#include <stdio.h>
#include <string.h>

int main(){

    int n, q;
    char s[100001], r[101];

    scanf("%d", &n);

    for(int i=0; i<n; i++){

        scanf("%s", &s);

    }

    scanf("%d", &q);

    for(int i=0; i<q; i++){

        scanf("%s", &r);

        if(strstr(s,r) != NULL)
          printf("Yes\n");

        else
          printf("No\n");  

    }

    return 0;
}
