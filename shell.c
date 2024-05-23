
#include <stdbool.h>
#include <stdio.h>

int main(void) {
    char command[50];
    printf("pcshell> ");
    scanf("%s", command);
    printf("%s\n", command);
    return 0;
}
