#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Random number code
int printRandoms(int arr[],int lower, int upper, int count)
{
    int i;
    int num;
    
    srand(time(0));
    for (i = 0; i < count; i++) {
        
        num = (rand() %
        (upper - lower + 1)) + lower;
    
            arr[i]=num;
            printf("%d ",arr[i]);
            
}
             printf("\n"); 
            
}

// **A function to implement bubble sort
void bubbleSort(int arr[], int n)
{  
    printf("\nShorting By Bubble Sort:- \n");
    
    int i, j;
    for (i = 0; i < n - 1; i++)

        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
            {
                for (int k = 0; k < n; k++)
                     { printf("%d ", arr[k]); }
                printf("\n");

                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
       
}
int time_complexity(int a[]){
double tim1[15];
int it=0;
clock_t start, end;
  
        // Bubble sort
        start = clock();
         bubbleSort(a, 15);
        end = clock();
        tim1[it] = ((double)(end - start));
        printf("\nTime Complexity:- ");
        printf("%d ms",tim1);
}

// **A function to implement merge sort
void merge(int arr[], int l, int m, int r)
{   
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
  
   
    int L[n1], R[n2];
  
   
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
        
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
         
    
    i = 0; 
  

    j = 0; 
  

    k = l; 
    while (i < n1 && j < n2) 
    {
        //  printf("\n");
        if (L[i] <= R[j]) 
        {
            arr[k] = L[i];
            i++;
       
        }
        else 
        {
            arr[k] = R[j];
            j++;
            
        }
        k++;
         
       
    }
     
  
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
         
    }
         
  
   
    while (j < n2) 
    {
        arr[k] = R[j];
        j++;
        k++;
         
    }
         
}
void mergeSort(int arr[], int l, int r)
{   
     
    if (l < r) 
    {
       
        int m = l + (r - l) / 2;
  
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
  
        merge(arr, l, m, r);

         int i;
    for (i = 0; i < 15; i++)
        printf("%d ", arr[i]);
    printf("\n");
         
    }
    
}
int time_complexity1(int a[]){
double tim1[15];
int it=0;
clock_t start, end;
  
        // Bubble sort
        start = clock();
         mergeSort(a, 0,15);
        end = clock();
        tim1[it] = ((double)(end - start));
        printf("\nTime Complexity:- ");
        printf("%d ms",tim1);
}

// A function to implement Selection sort
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selectionSort(int array[], int size) 
{  
  printf("\nShorting By Selection Sort:- \n");
  for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < size; i++) {

      // To sort in descending order, change > to < in this line.
      // Select the minimum element in each loop.
      if (array[i] < array[min_idx])
        min_idx = i;
    }

    // put min at the correct position
    swap(&array[min_idx], &array[step]);
      for (int i = 0; i < size; ++i) {
      printf("%d  ", array[i]);
  }
  printf("\n");

  }
}
int time_complexity2(int a[])
{
  double tim1[15];
  int it=0;
  clock_t start, end;
  
        start = clock();
        selectionSort(a,15);
        end = clock();
        tim1[it] = ((double)(end - start));
        printf("\nTime Complexity:- ");
        printf("%d",tim1);
}

 // A function to implement insertion sort
void insertionSort(int array[], int size) {
    printf("\nShorting By Insertion Sort:- \n");
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

}
int time_complexity3(int a[])
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
}

//main code
int main ()
{
  int arr[15];
  int n= sizeof(arr)/sizeof(arr[0]);
  int option;

        printRandoms(arr,0,100,n);
        printf("\nChoose Sorting Technique:- \n 1. Bubble Sort\n 2. Merge Sort\n 3. Selection Sort\n 4. Insertion Sort");
        scanf("%d",&option);

        
        switch (option)
        {
        case 1:
        bubbleSort(arr,n);
        time_complexity(arr);
            break;
        case 2:
        printf("\nShorting By merge Sort:- \n");
        mergeSort(arr,0,n);
        time_complexity1(arr);
            break;
        case 3:
        selectionSort(arr,n);
        time_complexity2(arr);
            break;
        case 4:
        insertionSort(arr,n);
        time_complexity3(arr);
            break;
        
        default:printf("Please Enter Valid Input!!");
            break;
        }
        
        


    
    
    return 0;
}