#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insertionsort(int* A, int n){
    int i,j,key;
    for(i=1;i<n-1;i++){
        key=A[i];
        j=i-1;
        while(j>=0 && A[j]>key){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;
    }
}

int main(int argc, char *argv[]){
    int n,i,d;
    int A[100000];
    int x,y;
    d = atoi(argv[2]) ;
    clock_t t;
    t = clock();
    //Writing the random numbers in file
    FILE *fp = fopen("file.txt","w");
    if(!fp){
        return 0;
    }
    for(i=0;i<100000;i++){
        n = rand();
        fprintf(fp,"%d\n",n);
    }
    fclose(fp);
    // Taking input from user
    //printf("Enter the number of elements: ");
    //scanf("%d",&d);
    //Reading the numbers from same file
    FILE *fp2 = fopen("file.txt","r");
    for(x=0;x<d;x++){
        fscanf(fp2,"%d",&A[x]);
    }
    //Printing the unsorted Array
    //printf("Array:\n");
    //for(y=0;y<d;y++){
        //printf("%d\n",A[y]);
    //}
    insertionsort(A,d);
    //Printing Sorted array using insertion sort
    printf("Array Sorted:\n");
    for(y=0;y<d;y++){
        printf("%d\n",A[y]);
    }
    fclose(fp2);
    FILE *fp3 = fopen("isort.txt","a");
    if(!fp3){
        return 0;
    }
    t = clock()-t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    fprintf(fp3,"%d %.5f\n",d,time_taken);
    fclose(fp3);
    printf("Time taken:%f ",time_taken);
    return 0;  
}