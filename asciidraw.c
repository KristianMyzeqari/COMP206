#include <stdio.h>
#include <string.h>

char drawIcon = '*';
char newIcon;

char grid[1000][1000];

char input[200];
char workingInput[200];

int check = 1;

int main(){
    fgets(input, 200, stdin);
    sscanf(input, "%s", workingInput);

    while(check >= 1){
        fgets(input, 20, stdin);
        sscanf(input, "%s", workingInput);

        if(strcmp(workingInput, "GRID") == 0){
            printf("You selected grid\n");
        }

        if(strcmp(workingInput, "DISPLAY") == 0){
            printf("You selected display\n");
        }

        if(strcmp(workingInput, "CHAR") == 0){
            sscanf(input, "%*s %c", &drawIcon);
            printf("%c", drawIcon);
        }

        if(strcmp(workingInput, "RECTANGLE") == 0){
            printf("You selected rectangle\n");
        }

        if(strcmp(workingInput, "LINE") == 0){
            printf("You selected line\n");
        }

        if(strcmp(workingInput, "CIRCLE") == 0){
            printf("You selected circle\n");
        }

        if(strcmp(workingInput, "END") == 0){
            printf("You selected circle\n");
            check = 0;
        }

        else{
            printf("Error, did not understand %s", input);
        }
    }
}