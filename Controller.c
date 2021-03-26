#include "DataShell.h"

int main (void)
{
    char* fileName=NULL;
    int numLines = 0, numElements;
    int option;

    //Calling function to get name
    menuOne(&fileName);

    numLines = NumberLines(fileName); //Calling function to count how many lines
    numElements = countElements(fileName); //Calling function to count elements in line

    float **Matrix = malloc(sizeof(float) * numLines * numElements);

    readDB(Matrix, fileName, numElements);

    do{
        option = menuTwo();
        if(option == 1)
        {
            printMatrix(Matrix, &numLines, &numElements);
            printf("\nPress [enter] to go back to the menu.\n");
            fpurge(stdin);
            getchar();
        }
    }while(option != 2);


    free(Matrix);
    return 0;
}
