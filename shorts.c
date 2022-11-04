#include <stdio.h>
#include <stdlib.h>
#include <time.h>



 // A function to implement insertion sort
void insertionSort(int array[], int size) {
    int x=1;
    
     printf("\nShorting By Bubble Sort:- \n");
    int z=0; 
  for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;

    
    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;

    for(int i=0;i<size;i++){
        printf("%d ",array[i]);
   
    }
    


    printf("\n");
  
  }
     exit(0);
}

int time_complexity1(int a[])
{
  double tim1[15];
  int it=0;
  clock_t start, end;
  
        start = clock();
        insertionSort(a,15);
        end = clock();
        tim1[it] = ((double)(end - start));
        printf("\nTime Complexity:- ");
        printf("%d",tim1);
         exit(0);
}

int main(){
    int arr[] = {1,34,2,3,65,7,84,2,34,1,54,6,3,78,54};
   
    insertionSort(arr,15);
    time_complexity1(arr);
   
    
       

    return 0;
}