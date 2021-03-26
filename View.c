#include "DataShell.h"

void menuOne(char **fileName)
{
    system("clear");
    printf("Name of File: ");
    *fileName = "data.csv";
    //scanf("%m[^\n]", fileName); //Reads until it finds a \n
    printf("Reading from: %s...\n", *fileName);
}

int menuTwo(void)
{
    int option;
    
    system("clear");
    printf("\nWhat do you wanna do?:\n[1] Print data. \n[2] Exit.\nAnswer: ");
    scanf("%d", &option);
    printf("\n");
    system("clear");
    return(option);
}
