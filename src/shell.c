#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include "shell.h"

/**
 * (ls command) Lists the contents of the current directory.
 * It opens the current directory and prints the name of each file and directory
 * that does not start with a dot ('.'). If the directory cannot be opened, it prints an error message.
 */
void list_directory_contents(void) {
    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    if (d) {
        dir = readdir(d);
        while (dir != NULL) {
            if (dir->d_name[0] != '.') {
                printf("%s\n", dir->d_name);
            }
            dir = readdir(d);
        }
        closedir(d);
    } else {
        perror("opendir");
    }
}

void print_current_directory(void) {
 char cwd[4096];
   if (getcwd(cwd, sizeof(cwd)) != 0) {
       printf("%s\n", cwd);
   } else {
       perror("getcwd() error");
   }
}

void execute_shell(void) {
    char command[50];
    printf("pcshell> ");
    scanf("%s", command);
    while (strcmp(command, "exit") != 0) {
        if (strcmp(command, "ls") == 0) {
            list_directory_contents();
        } else if (strcmp(command, "pwd") == 0) {
            print_current_directory();
        } else {
            printf("\nhello %s\n", command);
        }
        printf("pcshell> ");
        scanf("%s", command);
    }
}
