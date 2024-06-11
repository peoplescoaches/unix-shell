#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "shell.h"

void execute_shell(void) {
    char command[50];
    printf("pcshell> ");
    scanf("%s", command);
    while (sizeof(command) > 0) {
        printf("%s\n", command);
        printf("pcshell> ");
        scanf("%s", command);
    }
}
