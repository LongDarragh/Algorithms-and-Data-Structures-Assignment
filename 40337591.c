#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


//save the square into the board
char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

int checkwin();
void board();


//use for loop to reset the square every time when the game is finsih
void clearsquare()
{
    for(int i = 0; i<10; i++){
        square[i] = '0' +i;
    }
            
}

//Menu
enum GameMenu {GAME, COMPUTER, HISTORY, EXIT};

//Title
int GameTitle()
{
    char buf[100];
    int menu = -1;

    printf("\n\n＊＊＊Tic Tac Toe＊＊＊\n\n");

    printf("Menu\n");
    printf("%d:Game\n", GAME);
    printf("%d:Computer\n", COMPUTER);
    printf("%d:History\n", HISTORY);
    printf("%d:Finish\n", EXIT);

    printf("Choose the menu:");

    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &menu);

    while(menu < 0 || menu > EXIT)
    {
        printf("Input error:");
        fgets(buf, sizeof(buf), stdin);
        sscanf(buf, "%d", &menu);
    }

    return menu;
}



int TacGame(int Game)
{
    int player = 1, i, choice;
    
    printf("\n\n＊＊＊Tic Tac Toe＊＊＊\n\n");

    char mark;
    clearsquare();
    

    do
    {
        
        board();
        player = (player % 2) ? 1 : 2;

        printf("Player %d, enter a number:  ", player);
        scanf("%d", &choice);

        mark = (player == 1) ? 'X' : 'O';

        if (choice == 1 && square[1] == '1')
            square[1] = mark;
            
        else if (choice == 2 && square[2] == '2')
            square[2] = mark;
            
        else if (choice == 3 && square[3] == '3')
            square[3] = mark;
            
        else if (choice == 4 && square[4] == '4')
            square[4] = mark;
            
        else if (choice == 5 && square[5] == '5')
            square[5] = mark;
            
        else if (choice == 6 && square[6] == '6')
            square[6] = mark;
            
        else if (choice == 7 && square[7] == '7')
            square[7] = mark;
            
        else if (choice == 8 && square[8] == '8')
            square[8] = mark;
            
        else if (choice == 9 && square[9] == '9')
            square[9] = mark;
            
        else
        {
            printf("Invalid move ");

            player--;
            getch();
        }
        i = checkwin();

        player++;
    }while (i ==  - 1);
    
    board();
    
    if (i == 1)

        printf("==>\aPlayer %d win ", --player);
    else    
        printf("==>\aGame draw");

    getch();

    return 0;
}


//main part for the Tic tac toe.
int main(void)
{
    int menu;
    int Game;
    int Computer;
    int History;

    while(1)
    {
        menu =  GameTitle();
        printf("\n");

        if(menu == EXIT)
        {
            break;
        }
        else
        {
            switch(menu)
            {
            case GAME:
              Game = 0;
              break;

            case COMPUTER:
              Computer = 1;
              break;

            case HISTORY:
              History = 2;
              break;      
            }
        }

        TacGame(Game);
    }

    return 0;
}


//Check the square in the board if the square have been mark
int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
        
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
        
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
        
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
        
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
        
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
        
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
        
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
        
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] 
        != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return  -1;
}




//Draw the game board for Tic Tac Toe 
void board()
{
    system("cls");
    printf("\n\n\tTic Tac Toe\n\n");

    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");


    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

    printf("     |     |     \n\n");
}
