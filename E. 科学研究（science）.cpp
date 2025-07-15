#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <iostream>
using namespace std;
int funs(char *num, int index, int sum, int deletions) {
    if (num[index] == '\0') {
        return (sum % 3 == 0) ? deletions : INT_MAX;
    }

    int keep = funs(num, index + 1, sum + (num[index] - '0'), deletions);

    int remove = funs(num, index + 1, sum, deletions + 1);

    return (keep < remove) ? keep : remove;
}
char num[20];
int main() {
    
    scanf("%s",num);
//    printf("%d",strlen(num));
    int result = funs(num, 0, 0, 0);
	
    if (result == INT_MAX||result==strlen(num)) {
        printf("-1\n");
    } else {
        printf("%d\n", result); 
    }

    return 0;
}
