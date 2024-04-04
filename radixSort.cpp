#include<stdio.h>

// #include<conio.h>

#include<stdlib.h>                             

int Max_value(int Array[], int n) // This function gives maximum value in array[]

{

    int i;

    int maximum = Array[0];

    for (i = 1; i < n; i++){

        if (Array[i] > maximum)

            maximum = Array[i];

    }

    return maximum;

}

void radixSortalgorithm(int Array[], int n) // Main Radix Sort sort function

{

    int i,digitPlace = 1;

    int result_array[n]; // resulting array

    int largest = Max_value(Array, n); // Find the largest number to know number of digits

    while(largest/digitPlace >0){

        int count_array[10] = {0};

        for (i = 0; i < n; i++) //Store the count of "keys" or digits in count[]

            count_array[ (Array[i]/digitPlace)%10 ]++;

        for (i = 1; i < 10; i++)

            count_array[i] += count_array[i - 1];

        for (i = n - 1; i >= 0; i--) // Build the resulting array

        {

            result_array[count_array[ (Array[i]/digitPlace)%10 ] - 1] = Array[i];

            count_array[ (Array[i]/digitPlace)%10 ]--;

        }

        for (i = 0; i < n; i++) // numbers according to current digit place   

            Array[i] = result_array[i];

            digitPlace *= 10; // Move to next digit place

    }

}

void displayArray(int Array[], int n) // Function to print an array

{

    int i;

    for (i = 0; i < n; i++)

    printf("%d ", Array[i]);

    printf("\n");

}

int main()

{

    int array1[] = {20,30,40,90,60,100,50,70};

    int n = sizeof(array1)/sizeof(array1[0]);

    printf("Unsorted Array is : ");

    displayArray(array1, n);

    radixSortalgorithm(array1, n);

    printf("Sorted Array is: ");

    displayArray(array1, n);

    return 0;

}