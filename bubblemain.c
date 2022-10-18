#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//making this comment change for git assignment
void bubblesort(int* A,int n){
    int i=0;
    int j=0;
    int temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(A[j]>A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

int main(int argc, char *argv[]){
    int n,i,d;
    int A[100000];
    int x,y;
    d = atoi(argv[2]) ;
    printf("You have printed: %d elements\n",d);
    clock_t t;
    t = clock();
    //Writing the random numbers in file
    FILE *fp = fopen(argv[1],"w");
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
    FILE *fp2 = fopen(argv[1],"r");
    for(x=0;x<d;x++){
        fscanf(fp2,"%d",&A[x]);
    }
    //Printing the unsorted Array
    printf("Array:\n");
    for(y=0;y<d;y++){
        printf("%d\n",A[y]);
    }
    bubblesort(A,d);
    //Printing Sorted array
    printf("Array Sorted:\n");
    for(y=0;y<d;y++){
        printf("%d\n",A[y]);
    }

    fclose(fp2);
    FILE *fp3 = fopen("bsort.txt","a");
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
