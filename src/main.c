#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/* Change this to 500, 1000, 2000, 6000, or 9000 for the different lists*/
#define N 9000

int LinSearch(int array[], int x, int n);
int BinSearch(int array[], int x);

int main(void){
    int x;
    char filename[20];
    FILE *myFile;
    int array[N];
    int k;
    /*change this for more or less runs of the algorithm*/
    int runs = 100;
    int i;

    sprintf(filename, "List%d.txt", N);
    printf("What number are we searching for?\n"); /* Feel free to alter this*/
    scanf("%d", &x);

    myFile = fopen(filename, "r");

    /* List is read into array */
    for (k = 0; k < N; k++){
        fscanf(myFile, "%d", &array[k]);
    }
    fclose(myFile);

    printf("The size of the list is %d\n", N);

    /* start time */
    double startTime = clock();


    for (i = 0; i < runs; i++){
        BinSearch(array, x);
    }

    /* stop time and print */
    double endTime = clock();
    double duration = (endTime - startTime) / CLOCKS_PER_SEC;
    printf("BinSearch needed: %.7fs\n", duration);



    /* start time */
    startTime = clock();
    for (i = 0; i < runs; i++){
        LinSearch(array, x, N);
    }
    /* stop time and print */
    endTime = clock();
    duration = (endTime - startTime) / CLOCKS_PER_SEC;
    printf("LinSearch needed: %.7fs\n", duration);

    /* Prints the result */
    int result=LinSearch(array, x, N);
    if (result == -1){
        printf("LinSearch: %d is not in the list \n",x);
    }
    else {
        printf("LinSearch: %d is in position %d\n",array[result],result+1);
    }

    result=BinSearch(array, x);
    if (result == -1){
        printf("BinSearch: %d is not in the list \n",x);
    }
    else {
        printf("BinSearch: %d is in position %d\n",array[result],result+1);
    }
    printf("Done!\n"); /* Feel free to be more creative here */
    return 0;
}

int LinSearch(int array[], int x, int n){

    int i=n-1;
    /* Fill in your code HERE! */
    while (i > 0 && x != array[i]) {
        i--;
    }

    if (array[i] == x) {
        return i;
    } else {
        return -1;
    }
}

int BinSearch(int array[], int x){
    //sort the array
    //sort the array using bubble sort
    int a, b, temp;
    for (a = 0; a < N; a++) {
        for (b = 0; b < N - 1; b++) {
            if (array[b] > array[b + 1]) {
                //swap
                temp = array[b];
                array[b] = array[b + 1];
                array[b + 1] = temp;
            }
        }
    }

    // search function
    int i=0, j=N-1, mid;
    /* Fill in your code HERE */
    while (i < j) {
        mid = (i + j) / 2;
        if (array[mid] >= x) {
            j = mid;
        } else {
            i = mid + 1;
        }
    }
    if (array[i] == x) {
        return i;
    } else {
        return -1;
    }
}