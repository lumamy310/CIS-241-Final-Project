#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calcDBLMin(double array[]);
int calcDBLMax(double array[]);
int calcINTMin(int array[]);
int calcINTMax(int array[]);
double calcDBLAvg(double array[]);
int calcINTAvg(int array[]);

int main() {

    //structures
    char date[2330][9];
    double pcRatio[2330];
    int spyPuts[2330];
    int spyCalls[2330];
    int spyTotalOptions[2330];
    char buffer[40];

    //open file
    FILE* fptr;
    if((fptr = fopen("data.txt", "r")) == NULL){
        puts("file could not be opened");
        exit(1);
    }
    else{
        //store data in structures
        //use loop to go through each line and store
        int i = 0;
        fscanf(fptr, "%*[^\n]\n");
        while(fgets(buffer, 40, fptr)){

            char *tokenPtr;
            tokenPtr = strtok(buffer, ",");
            int j = 0;
            while(tokenPtr != NULL){
                switch(j){
                    case(0):
                        strcpy(date[i], tokenPtr);
                        break;
                    case(1):
                        pcRatio[i] = strtod(tokenPtr, NULL);
                        break;
                    case(2):
                        spyPuts[i] = atoi(tokenPtr);
                        break;
                    case(3):
                        spyCalls[i] = atoi(tokenPtr);
                        break;
                    case(4):
                        spyTotalOptions[i] = atoi(tokenPtr);
                        break;
                }
                tokenPtr = strtok(NULL, ",");
                j++;
            }
            i++;
        }

    }
    //close file
    fclose(fptr);

    //perform calculations
    //TODO FORMAT OUTPUT SO ITS NOT ONE HUGE BLOCK
    printf("The maximum put/call ratio from 7/6/10 to 10/4/19 was %.2lf on %s.\n", pcRatio[calcDBLMax(pcRatio)], date[calcDBLMax(pcRatio)]);
    printf("The minimum put/call ratio from 7/6/10 to 10/4/19 was %.2lf on %s.\n", pcRatio[calcDBLMin(pcRatio)], date[calcDBLMin(pcRatio)]);
    printf("The average put/call ratio from 7/6/10 to 10/4/19 was %.2lf.\n", calcDBLAvg(pcRatio));
    //TODO WHAT INFERENCE CAN WE MAKE WITH THIS INFO???

    printf("The highest SPY Put Volume was %d and it occurred on %s.\n", spyPuts[calcINTMax(spyPuts)], date[calcINTMax(spyPuts)]);
    printf("The lowest SPY Put Volume was %d and it occurred on %s.\n", spyPuts[calcINTMin(spyPuts)], date[calcINTMin(spyPuts)]);
    printf("The average SPY Put Volume from 7/6/10 to 10/4/19 was %d.\n", calcINTAvg(spyPuts));
    //TODO WHAT INFERENCE CAN WE MAKE WITH THIS INFO???

    printf("The highest SPY Call Volume was %d and it occurred on %s.\n", spyCalls[calcINTMax(spyCalls)], date[calcINTMax(spyCalls)]);
    printf("The lowest SPY Call Volume was %d and it occurred on %s.\n", spyCalls[calcINTMin(spyCalls)], date[calcINTMin(spyCalls)]);
    printf("The average SPY Call Volume from 7/6/10 to 10/4/19 was %d.\n", calcINTAvg(spyCalls));
    //TODO WHAT INFERENCE CAN WE MAKE WITH THIS INFO???

    printf("The highest SPY Options Volume was %d and it occurred on %s.\n", spyTotalOptions[calcINTMax(spyTotalOptions)], date[calcINTMax(spyTotalOptions)]);
    printf("The lowest SPY Options Volume was %d and it occurred on %s.\n", spyTotalOptions[calcINTMin(spyTotalOptions)], date[calcINTMin(spyTotalOptions)]);
    printf("The average SPY Options Volume from 7/6/10 to 10/4/19 was %d.\n", calcINTAvg(spyTotalOptions));
    //TODO WHAT INFERENCE CAN WE MAKE WITH THIS INFO???

}

int calcDBLMax(double array[]){
    double max = 0.0;
    int location = 0;
    for (int i = 0; i <2330; i++){
        if (array[i] > max){
            max = array[i];
            location = i;
        }
    }
    return location;
}

int calcDBLMin(double array[]){
    double min = 9999999.99;
    int location = 0;
    for (int i = 0; i <2330; i++){
        if (array[i] < min){
            min = array[i];
            location = i;
        }
    }
    return location;
}

int calcINTMax(int array[]){
    double max = 0.0;
    int location = 0;
    for (int i = 0; i <2330; i++){
        if (array[i] > max){
            max = array[i];
            location = i;
        }
    }
    return location;
}

int calcINTMin(int array[]){
    double min = 9999999.99;
    int location = 0;
    for (int i = 0; i <2330; i++){
        if (array[i] < min){
            min = array[i];
            location = i;
        }
    }
    return location;
}

double calcDBLAvg(double array[]){
    double avg = 0;
    int loop = 0;
    double sum = 0;

    for(loop = 0; loop < 2330; loop++) {
        sum = sum + array[loop];
    }

    avg = sum / 2330;
    return avg;
}

int calcINTAvg(int array[]){
    double avg = 0;
    int loop = 0;
    double sum = 0;

    for(loop = 0; loop < 2330; loop++) {
        sum = sum + array[loop];
    }

    avg = sum / 2330;
    return avg;
}