#include "DataShell.h"
#include <math.h>

//Function that prints a Matrix
void printMatrix (float **Matrix, int *numLines, int *numElements)
{
    int mitad;
    float prom, x=0, desv;
    
    //CALCULAR MEDIANA
    for(int i = 0; i < *numLines; i++)
    {
        for(int j = 0; j < *numElements; j ++)
        {
            printf("%.6f ", *((*(Matrix+i))+j));
            prom += *((*(Matrix+i))+1);
            x++;
        }
        printf("\n");
    }
    
    
    //CALCULAR DESVIACION ESTANDAR
    for(int i = 0; i < *numLines; i++)
    {
        for(int j = 0; j < *numElements; j ++)
        {
            //printf("%.6f ", *((*(Matrix+i))+j));
            desv += pow( *((*(Matrix+i))+1) - prom,2);
            desv = sqrt(desv);
        }
        printf("\n");
    }
    
    
    prom = prom/x;
    desv = (desv/x)/2;
    printf("\n%lf\n", *((*(Matrix+2))+1));
    printf("\nMedia = %f\n",prom);
    printf("\nDesviación estándar = %f\n",desv);
    
    
}

//Function that reads DB and stores it in a Matrix
void readDB (float **Matrix, char *fileName, int numElements)
{
    char buff[255];
    char * value;
    float *ptr = NULL;
    int cont = 0, n =0;

    FILE *file = openMyfile(fileName);

    while(!feof(file))
    {
        fscanf(file, "%s", buff);

        //numElements = countElements(buff);
        float *ptr = malloc(sizeof(float) * numElements);
        value = strtok(buff, ",");

        while(value != NULL)
        {
            ptr[cont] = atof(value); //Stores it in ptr GUARDO LOS ELEMENTOS EN EL POINTER
            //printf("%.6f ", ptr[cont]);
            cont ++;
            value = strtok(NULL, ",");
        }
        //printf("\n");
        cont = 0;
        Matrix[n] = ptr; //MATRIX AHORA APUNTA A PTR
        n ++;

    }
    closeMyfile(file);
    
    //printf("\n%.6f %.6f\n", *((*(Matrix+49))+0), *((*(Matrix+49))+1) );

    return;
}

//Function that tells how many elements does a csv line has
int countElements(char *fileName)
{
    int numElements = 0;
    char buff[255];

    FILE *file = openMyfile(fileName);
    fscanf(file, "%s", buff);
    char* value = strtok(buff, ",");

    while(value != NULL)
    {
        numElements ++;
        value = strtok(NULL, ",");
    }
    //printf("num = %d ", numElements);
    closeMyfile(file);
    return numElements;
}

//Function that opens a file
FILE* openMyfile (char *fileName)
{
    FILE *file = fopen(fileName, "r");

    if(file == NULL)
    {
        printf("Couln´t open file\n");
        exit(0);
    }
    return file;
}

//Function that closes a file
void closeMyfile(FILE *file)
{
    fclose(file);
}

//Function that return number of lines
int NumberLines(char *fileName)
{
    int numLines = 0;
    char buff[255];

    FILE *file = openMyfile(fileName);

    while(!feof(file))
    {
        fscanf(file, "%s", buff);
        numLines ++;
    }

    closeMyfile(file);

    return numLines;
}
