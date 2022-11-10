#include <stdio.h>
#include <string.h>

char drawIcon = '*';
char newIcon;

char input[20];

int check = 1;

int main(){
    fgets(input, 20, stdin);
    printf("the string is: %s", input);

    while(check >= 1){
        if(strcmp(input, "GRID\n") == 0){
            printf("You selected grid\n");
            fgets(input, 20, stdin);
        }

        if(strcmp(input, "DISPLAY\n") == 0){
            printf("You selected display\n");
            fgets(input, 20, stdin);
        }

        if(strcmp(input, "CHAR\n") == 0){
            printf("Enter your new icon: ");
            fgets(newIcon, 1, stdin);
            drawIcon = newIcon;
            printf("Your new icon is :%c", drawIcon);
        }

        if(strcmp(input, "RECTANGLE\n") == 0){

        }

        if(strcmp(input, "LINE\n") == 0){
        
        }

        if(strcmp(input, "CIRCLE\n") == 0){

        }

        if(strcmp(input, "END\n") == 0){

        }

        else{
            printf("Error, did not understand %s", input);
            fgets(input, 20, stdin);
        }
    }
}