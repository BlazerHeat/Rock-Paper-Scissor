#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<time.h>

char choises[3][8] = {"rock", "paper", "scissor"};

int randInRange(int min, int max)
{
  return (rand() % (max - min + 1)) + min;
}

void decision(char* cpuChoise, char* userChoise){
    if(strcmp(cpuChoise, userChoise) == 0){
        printf("Tie\n");
        return;
    }

    if(strcmp(userChoise, choises[0]) == 0 && strcmp(cpuChoise, choises[1]) == 0){
        printf("You won!");
        return;
    }
    if(strcmp(userChoise, choises[0]) == 0 && strcmp(cpuChoise, choises[2]) == 0){
        printf("You lose!");
        return;
    }

    if(strcmp(userChoise, choises[1]) == 0 && strcmp(cpuChoise, choises[0]) == 0){
        printf("You won!");
        return;
    }
    if(strcmp(userChoise, choises[1]) == 0 && strcmp(cpuChoise, choises[2]) == 0){
        printf("You lose!");
        return;
    }

    if(strcmp(userChoise, choises[2]) == 0 && strcmp(cpuChoise, choises[1]) == 0){
        printf("You won!");
        return;
    }
    if(strcmp(userChoise, choises[2]) == 0 && strcmp(cpuChoise, choises[0]) == 0){
        printf("You lose!");
        return;
    }

    return;
}

int main(){
    
    char userInput[8];

    printf("Rock Paper Scissor\n");
    printf("Enter your choise: ");
    gets(userInput);

    for (int i = 0; i < 8; i++)
    {
        if(userInput[i] == '\0') break;
        userInput[i] = tolower(userInput[i]);
    }
    

    while (strcmp(userInput, choises[0]) != 0 && strcmp(userInput, choises[1]) != 0 && strcmp(userInput, choises[2]) != 0){
        printf("Invaild input, try again.\n");
        printf("Enter your choise: ");
        gets(userInput);
    }

    char cpuChoise[8];
    srand(time(0));
    int random = randInRange(0, 2);
    strcpy(cpuChoise, choises[random]);

    printf("Cpu chosed: %s\n", cpuChoise);

    decision(cpuChoise, userInput);

    return 0;
}