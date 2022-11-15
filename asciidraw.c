#include <stdio.h>
#include <string.h>
#include <math.h>

char drawIcon = '*';
char number;

char grid[1001][1001];

int xsize;
int ysize;

int UdeltaX;
int UdeltaY;

int oneX;
int oneY;
int twoX;
int twoY;


char input[200];
char workingInput[200];

int check = 1;
int gridSet = 0;

int main(void){
    while(check >= 1){
        fgets(input, 20, stdin);
        sscanf(input, "%s", workingInput);

        if(strcmp(workingInput, "GRID") == 0){
            if(gridSet == 0){
                sscanf(input, "%*s %d", &xsize);
                sscanf(input, "%*s %*d %d", &ysize);

                for(int i = -1; i <= ysize-1; i++){
                    int tmp = i % 10;
                    char tmp1 = tmp + '0';
                    grid[ysize - i][0] = tmp1;
                }
                gridSet = 1;
            }
            else{
                printf("Grid size has already been set.");
            }
        }

        else if(strcmp(workingInput, "DISPLAY") == 0){
            for(int i = 0; i < ysize + 1; i++){
                for(int j = 0; j < xsize + 1; j++){
                    if(grid[i][j] == '\0'){
                        grid[i][j] = ' ';
                    }
                    printf("%c",grid[i][j]);
                }
                printf("\n");
            }
            printf("%c", ' ');
            for(int i = 0; i < xsize; i++){
                int printVal = i%10;
                printf("%d", printVal);
            }
            printf("\n");
        }

        else if(strcmp(workingInput, "CHAR") == 0){
            sscanf(input, "%*s %c", &drawIcon);
            printf("%c", drawIcon);
        }

        else if(strcmp(workingInput, "RECTANGLE") == 0){
            sscanf(input, "%*s %d,%d %d,%d", &oneX, &oneY, &twoX, &twoY);
            
            if(oneX < twoX){
                for(int i = oneX; i <= twoX; i++){
                    grid[ysize - oneY][i+1] = drawIcon;
                    grid[ysize - twoY][i+1] = drawIcon;
                }
                if(oneY < twoY){
                    for(int i = oneY; i <= twoY; i++){
                        grid[ysize-i][oneX+1] = drawIcon;
                        grid[ysize-i][twoX+1] = drawIcon;
                    }
                }
                if(oneY > twoY){
                    for(int i = oneY; i >= twoY; i--){
                        grid[ysize-i][oneX+1] = drawIcon;
                        grid[ysize-i][twoX+1] = drawIcon;
                    }
                }
            }

            if(oneX > twoX){
                for(int i = oneX; i >= twoX; i--){
                    grid[ysize - oneY][i+1] = drawIcon;
                    grid[ysize - twoY][i+1] = drawIcon;
                }
                if(oneY < twoY){
                    for(int i = oneY; i <= twoY; i++){
                        grid[ysize-i][oneX+1] = drawIcon;
                        grid[ysize-i][twoX+1] = drawIcon;
                    }
                }
                if(oneY > twoY){
                    for(int i = oneY; i >= twoY; i--){
                        grid[ysize-i][oneX+1] = drawIcon;
                        grid[ysize-i][twoX+1] = drawIcon;
                    }
                }
            }
        }

        else if(strcmp(workingInput, "LINE") == 0){
            sscanf(input, "%*s %d,%d %d,%d", &oneX, &oneY, &twoX, &twoY);   //get coordinate values
            int deltaY = twoY - oneY;      //get deltas to calculate value of m
            if(deltaY < 0){
                UdeltaY = deltaY *(-1);
            }
            int deltaX = twoX - oneX;
            if(deltaX < 0){
                UdeltaX = deltaX *(-1);
            }
           // printf("%d \n", deltaY);
           // printf("%d \n", deltaX);

            float m = (double)deltaY/(double)deltaX;   //Set up values for m and c
            //printf("%f \n", m);
            double c = twoY - m*twoX;
            //printf("%f \n", c);

            grid[ysize - oneY][oneX + 1] = drawIcon;        //place user-given coordinates
            grid[ysize - twoY][twoX + 1] = drawIcon;

            if(UdeltaX > UdeltaY){
                if(oneX > twoX){
                    for(int i = oneX; i > twoX; i--){
                        double yVal = (m*i)+c;
                        //printf("%f", yVal);
                        int placementVal = round(yVal);
                        //printf("%d", placementVal);
                        int tmp = i + 1;
                        grid[ysize - placementVal][tmp] = drawIcon;
                    }
                }

                if(oneX < twoX){
                    for(int i = oneX; i < twoX; i++){
                        double yVal = (m*i)+c;
                        int placementVal = round(yVal);
                        int tmp = i + 1;
                        grid[ysize - placementVal][tmp] = drawIcon;
                    }
                }
            }


            if(UdeltaY > UdeltaX){
                if(oneY > twoY){
                    for(int i = oneY; i > twoY; i--){
                        double yVal = (m*i)+c;
                        int placementVal = round(yVal);
                        int tmp = i + 1;
                        grid[ysize - placementVal][tmp] = drawIcon;
                    }
                }

                if(oneX < twoX){
                    for(int i = oneX; i < twoX; i++){
                        double yVal = (m*i)+c;
                        int placementVal = round(yVal);
                        int tmp = i + 1;
                        grid[ysize - placementVal][tmp] = drawIcon;
                    }
                }
            }
        }

        else if(strcmp(workingInput, "CIRCLE") == 0){
            printf("You selected circle.\n");
        }

        else if(strcmp(workingInput, "END") == 0){
            printf("You selected end.\n");
            check = 0;
        }
        
        else{
           printf("Error, did not understand %s", input);
        }
    }
}