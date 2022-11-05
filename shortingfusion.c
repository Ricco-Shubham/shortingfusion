#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Random number code
int printRandoms(int arr[], int lower, int upper, int count)
{
    int i;
    int num;

    srand(time(0));
    for (i = 0; i < count; i++)
    {

        num = (rand() %
               (upper - lower + 1)) +
              lower;

        arr[i] = num;
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// get time at instance
long gettime()
{
    struct timeval start;
    mingw_gettimeofday(&start, NULL);
    return start.tv_sec * 1000000 + start.tv_usec;
}

// **A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    long start = gettime();

    int i, j;
    for (i = 0; i < n - 1; i++)

        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                for (int k = 0; k < n; k++)
                {
                    printf("%d ", arr[k]);
                }
                printf("\n");
                

                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    long end = gettime();
    float count = end - start;
    count = count / 1000000;
    printf("\nTime Taken to sort an array: %fs", count);  
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

    while (i < n1)
    {
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

// A function to implement Selection sort
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selectionSort(int array[], int size)
{
    long start = gettime();
    for (int step = 0; step < size - 1; step++)
    {
        int min_idx = step;
        for (int i = step + 1; i < size; i++)
        {

            // To sort in descending order, change > to < in this line.
            // Select the minimum element in each loop.
            if (array[i] < array[min_idx])
                min_idx = i;
        }

        // put min at the correct position
        swap(&array[min_idx], &array[step]);
        for (int i = 0; i < size; ++i)
        {
            printf("%d ", array[i]);
        }
        printf("\n");
    }
    long end = gettime();
    float count = end - start;
    count = count / 1000000;
    printf("\nTime Taken to sort an array: %fs", count);
}

// A function to implement insertion sort
void insertionSort(int array[], int size)
{
    long start = gettime();
    int z = 0;
    for (int step = 1; step < size; step++)
    {
        int key = array[step];
        int j = step - 1;

        while (key < array[j] && j >= 0)
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;

        for (int i = 0; i < size; i++)
        {
            printf("%d ", array[i]);
        }
        printf("\n");
    }
    long end = gettime();
    float count = end - start;
    count = count / 1000000;
    printf("\nTime Taken to sort an array: %fs", count);
}


// A function to implement Quick sort
int partition(int arr[], int low, int high)
{
  int pivot = arr[high];
  int i = low - 1;
  for (int j = low; j <= high - 1; j++)
  {
    if (arr[j] < pivot)
    {
      i++;
      swap(&arr[j], &arr[i]);
    }
  }
  swap(&arr[i + 1],&arr[high]);
  return i + 1;

}
void quickSort(int arr[], int low, int high)
{



  if (low < high)
  {
  
    int pi = partition(arr, low, high);
  
  for (int i = 0; i < 15; i++)
    {
      printf("%d ", arr[i]);
    }
  printf("\n");

    quickSort(arr, low, pi - 1);
     for (int i = 0; i < 15; i++)
    {
      printf("%d ", arr[i]);
    }
  printf("\n");
    quickSort(arr, pi + 1, high);
  }

   
}

// A function to implement Radix sort
int getMax(int arr[],int n){
  int mx=arr[0];
  for(int i=0;i<n;i++){
    if(arr[i]>mx)
      mx=arr[i];
  }
  return mx;
}
void countingSort(int array[], int size, int place) {
  int output[size + 1];
  int max = (array[0] / place) % 10;

  for (int i = 1; i < size; i++) {
    if (((array[i] / place) % 10) > max)
      max = array[i];
  }
  int count[max + 1];

  for (int i = 0; i < max; ++i)
    count[i] = 0;

  // Calculate count of elements
  for (int i = 0; i < size; i++)
    count[(array[i] / place) % 10]++;
    
  // Calculate cumulative count
  for (int i = 1; i < 10; i++)
    count[i] += count[i - 1];

  // Place the elements in sorted order
  for (int i = size - 1; i >= 0; i--) {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
  }

  for (int i = 0; i < size; i++)
    array[i] = output[i];

  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}
void radixSort(int array[], int size) {
  // Get maximum element
  long start = gettime();
  int max = getMax(array, size);

  // Apply counting sort to sort elements based on place value.
  for (int place = 1; max / place > 0; place *= 10)
    countingSort(array, size, place);
    long end = gettime();
    float count = end-start;
    count = count/1000000;
    printf("Time Taken to sort array:- %fs",count);

}


// main code
int main()
{
    int arr[15];
    int n = sizeof(arr) / sizeof(arr[0]);
    int option;

    printRandoms(arr, 0, 100, n);
    printf("\nChoose Sorting Technique:- \n 1. Bubble Sort\n 2. Merge Sort\n 3. Selection Sort\n 4. Insertion Sort\n 5. Quick Sort\n 6. Radix Sort\n");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        printf("\nShorting By Bubble Sort:- \n");
        bubbleSort(arr, n);

        break;
    case 2:
        printf("\nShorting By merge Sort:- \n");
        long start = gettime();
        mergeSort(arr, 0, n);
        long end = gettime();
        float count = end - start;
        count = count / 1000000;
        printf("\nTime Taken to sort an array: %fs", count);

        break;
    case 3:
        printf("\nShorting By Selection Sort:- \n");
        selectionSort(arr, n);

        break;
    case 4:
        printf("\nShorting By Insertion Sort:- \n");
        insertionSort(arr, n);

        break;
    case 5:
        printf("\nShorting By Quick Sort:- \n");
        long start1 = gettime();
        quickSort(arr,0,14);
        long end1 = gettime();
        float count1 = end1 - start1;
        count1 = count1 / 1000000;
        printf("\nTime Taken to sort an array: %fs", count1);
        break;

         case 6:
        printf("\nShorting By Radix Sort:- \n");
        radixSort(arr, n);

        break;

    default:
        printf("Please Enter Valid Input!!");
        break;
    }

    return 0;
}
