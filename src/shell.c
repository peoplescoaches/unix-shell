#include <stdbool.h>
#include <stdio.h>
#include "shell.h"

void execute_shell(void) {
    char command[50];
    printf("pcshell> ");
    scanf("%s", command);
    printf("%s\n", command);
}
