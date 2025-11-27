#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include<stdbool.h>


void setup();
void welcomeMessage();
void printInGameScreen();
void gameEngine();
void setCursor(short x, short y);
void hideCursor();
void inputFunction();
void title();
void snakeHeadMovement();
void instruction();
void checkCollision();
void gameOver();


const int boundaryStartY = 0;
const int boundaryEndY = 20;
const int boundaryStartX = 0;
const int boundaryEndX = 40;

char boundaryChar = '#';
char snakeHeadChar = 'x';
char snakeBodyChar =  '*';
char foodChar =  'o';
char spaceChar = ' ';

int snakeHeadY = 20 / 2;
int snakeHeadX =  40 / 2;

char keyInput = 'w';
int refreshRate = 500;
int score = 0;

//shohans code 

int foodX, foodY;
int snakeLength = 1;

int tailX[200];
int tailY[200];
    //function for checking sap er matha 
int overlapsWithBody(int x, int y) {
    for(int i = 0; i < snakeLength; i++){
        if(tailX[i] == x && tailY[i] == y){
            return 1;   
        }
    }
    return 0; 
}

 
//shohans code ends here 


//start of main function--------------------------------------------------------------------------
int main(){

    setup();
    getch(); 

    return 0;
}


void setup(){ //----------------------------------------------------------------------------------


    //shohans code 
    srand(time(NULL));
    foodX = rand() % (boundaryEndX - 1) + 1;
    foodY = rand() % (boundaryEndY - 1) + 1;
    //ends here 

    hideCursor(); //for hiding the blinking cursor

    welcomeMessage();
    getch();

    gameEngine();

}

void welcomeMessage(){ //--------------------------------------------------------------------------
    
    //to add any line in welcome message, add a string here;
    char wlc[35] = "Welcome";
    char gameName[35] = "Console-Based Snake Game";
    char startGameInstruction[35] = "Press any key to start";

    //to add any line in welcome message, add a XLine and XMargine variable to store line number and indentation;
    int firstLine = 8;
    int firstMargine = strlen(wlc) / 2 * -1;

    int secondLine = 9;
    int secondMargine = strlen(gameName) / 2 * -1;

    int thirdLine = 12;
    int thirdMargine = strlen(startGameInstruction) / 2 * -1;

    //to add any line in welcome message, add a else if and print the string and increase the value of j;
    for(int i = boundaryStartY; i <= boundaryEndY; i++){
        for(int j = boundaryStartX; j <= boundaryEndX; j++){

            if(i == boundaryStartY || i == boundaryEndY || j == boundaryStartX || j == boundaryEndX){
                printf("%c", boundaryChar);
            }

            else if(i == boundaryStartY + firstLine && j == boundaryEndX / 2 + firstMargine){
                printf("%s", wlc);
                j += strlen(wlc) - 1;
            }

            else if(i == boundaryStartY + secondLine && j == boundaryEndX / 2 + secondMargine){
                printf("%s", gameName);
                j += strlen(gameName) - 1;
            }

            else if(i == boundaryStartY + thirdLine && j == boundaryEndX / 2 + thirdMargine){
                printf("%s", startGameInstruction);
                j += strlen(startGameInstruction) - 1;
            }

            else{
                printf("%c", spaceChar);
            }

        }
        printf("\n");
    }

}


void gameEngine(){ //-------------------------------------------------------------------------------------
    
    setCursor(boundaryStartY, boundaryStartX);
    printInGameScreen();

    while(1){
        
        inputFunction();
        snakeHeadMovement();
        checkCollision();
        setCursor(boundaryStartY, boundaryStartX);
        printInGameScreen();
        Sleep(refreshRate);
    }
}

void inputFunction(){
    int temp = keyInput;
    if(_kbhit()){
        keyInput = _getch();
        if(keyInput != 'w' && keyInput != 'a' && keyInput != 's' && keyInput != 'd') keyInput = temp;
    }
}

void snakeHeadMovement(){


    // shohans code for the tail
            // shift tail
        for(int i = snakeLength - 1; i > 0; i--){
        tailX[i] = tailX[i-1];
        tailY[i] = tailY[i-1];
        }

        tailX[0] = snakeHeadX;
        tailY[0] = snakeHeadY;

    //ends here 


    if(keyInput == 'w'){
        snakeHeadY--;
       
    }else if(keyInput == 'a'){
        snakeHeadX--;
  
        //snakeHeadX--;
    }else if(keyInput == 's'){
        snakeHeadY++;
       
    }else if(keyInput == 'd'){
        snakeHeadX++;
        
        //snakeHeadX++;
    }

    //shohans code 
    if(snakeHeadX == foodX && snakeHeadY == foodY){
    snakeLength++;
    score++;
    Beep(750, 100);

    // spawn new food
    do {
        foodX = rand() % (boundaryEndX - 1) + 1;
        foodY = rand() % (boundaryEndY - 1) + 1;
    } while(overlapsWithBody(foodX, foodY) || 
        (foodX == snakeHeadX && foodY == snakeHeadY));
    }

}

void title(){
    printf("Snake Game");
    for(int i = 0; i < boundaryEndX - 19; i++) printf(" ");
    printf("Score: %3d\n", score);
}

void instruction(){
    printf("Press w, a, s, d to change the snake direction. Happy gaming :)");
}

void printInGameScreen(){ //print every frame --------------------------------------------------------------

    title();
    for(int i = boundaryStartY; i <= boundaryEndY; i++){
        for(int j = boundaryStartX; j <= boundaryEndX; j++){

            if(i == boundaryStartY || i == boundaryEndY || j == boundaryStartX || j == boundaryEndX){
                printf("%c", boundaryChar);
            }
            
            else if(i == snakeHeadY && j == snakeHeadX){
                printf("%c", snakeHeadChar);
            }
            //shohans code 
            else if(i == foodY && j == foodX){
                printf("%c", foodChar);
                }
            else {
                int printed = 0;
                for(int k = 0; k < snakeLength - 1; k++){
                if(tailX[k] == j && tailY[k] == i){
                printf("%c", snakeBodyChar);
                printed = 1;
                break;
                }
                }
                if(!printed) printf("%c", spaceChar);
            }

            //else{
                //printf("%c", spaceChar);
            //}
        }

        printf("\n");
    }
    instruction();
    // snakeHeadY++;
}

// shohans code for checking collision and printing game over screen  

void checkCollision() {
    if (snakeHeadX <= boundaryStartX || snakeHeadX >= boundaryEndX ||
        snakeHeadY <= boundaryStartY || snakeHeadY >= boundaryEndY) {
        gameOver();
    }
}

void gameOver() {
    system("cls"); // clear the screen
    Beep(500, 300); 
    Beep(400, 300);
    printf("\n\n");
    printf("#############################\n");
    printf("#                           #\n");
    printf("#        GAME OVER!         #\n");
    printf("#      Final Score: %d      #\n", score);
    printf("#                           #\n");
    printf("#############################\n");
    printf("\nPress any key to exit...");
    getch(); // wait for keypress
    exit(0); // terminate the program
}


void hideCursor(){ //ChatGPT generated ----------------------------------------------------------------
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor;
    GetConsoleCursorInfo(out, &cursor);
    cursor.bVisible = FALSE;
    SetConsoleCursorInfo(out, &cursor);
}

void setCursor(short x, short y){ //ChatGPT generated -------------------------------------------------------
    COORD position = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}