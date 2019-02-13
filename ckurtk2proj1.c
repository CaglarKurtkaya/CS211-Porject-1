#include <stdio.h>
#include <stdlib.h>

// copy the values from one array to another array. 
void makeArrayCopy (int fromArray[], int toArray[], int size){
	int i;
	for(i=0; i < size; i++){
		toArray[i] = fromArray[i];
	}
}

// swap values function for my favarate sort. 
void swap(int *x, int *y){
	
	int temp = *x;
	*x = *y;
	*y = temp;
	
	return;
}

//sort an array in ascending order(Bubble sort)
//repeatedly swapping the adjacent elements
//if they are in wrong order.
void myFavorateSort (int arr[], int size){
	int i, j;
	for(i = 0; i < size - 1; i++){
		for(j = 0; j < size - i - 1; j++){
			if(arr[j] > arr[j+1]){
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
	
}

//
//Start from the leftmost element of arr[] and one by one compare target with each element 
int linSearch (int arr[], int size, int target, int* numComparisons){
	int i;
	for(i = 0; i < size; i++){
		*numComparisons = i + 1;   // set the number of comparison
		if(arr[i] == target){
			return i;
		}
	}
	// target is not found 
	return -1;
}

//Search a sorted array by repeatedly dividing the search interval in half.
int binSearch (int arr[], int size, int target, int* numComparisons){
	
	int firstIndex = -1; // set the first index to -1 to get right comparisons number if target is not in the array
	int lastIndex = size; // set the last index 
	int count = 0;        // to count comparisons 
	
	
	while(firstIndex <= lastIndex){
		// get the middle index value 
		int middleIndex = (firstIndex + lastIndex) / 2;
		count++;
		*numComparisons = count;
		//If the target is the middle element return its index value.
		if(arr[middleIndex]== target){
			return middleIndex;		
		}
		//If the value of the search key is less than the item in the middle
		//of the interval, narrow the interval to the lower half.
		else if(arr[middleIndex] > target){ 
			lastIndex = middleIndex - 1;			
		}
		//Otherwise narrow it to the upper half
		else{
			firstIndex = middleIndex + 1; 
		}
		
	}
	// target is not found 
	return -1;
	
}

//Prints arrays 
void printArray(int *array, int size) {
	int i = 0;
	for(i=0; i < size; i++) {
    	printf("%d ", array[i]);
	}
	printf("\n");
}

int main (int argc, char** argv)
{
 int val;    // to store user inputs
 int pos = 0;  // for array index 
 int *darr;		// pointer for array
 int allocated = 100;  // array size 
 darr = (int *) malloc (allocated * sizeof(int) );  //dynamic Array Allocation

 /* prompt the user for input */
 printf ("Enter in a list of numbers ito be stored in a dynamic array.\n");
 printf ("End the list with the terminal value of -999\n");
 
 /* loop until the user enters -999 */
 scanf ("%d", &val);
 
 while (val != -999)
   {
   	/* store the value into an array */
   	darr[pos] = val;  
    pos++;  
    
    // increase the size of the array if there is more input than the allocated space.
    if(pos >= allocated){
	
    int *temp = darr;
    int i;
 	darr = (int *) malloc ( allocated * 2 * sizeof(int) ); // double the size 
 	for ( i = 0 ; i < allocated ; i++){
 		darr[i] = temp[i];
 	}
 	free (temp);
 	allocated = allocated * 2;
	}

    /* get next value */
    scanf("%d", &val);
	
   } // end of while
      
   allocated = pos;  // set the size of the array according to user input.
   int toArray[allocated];  // second array to copy values fromArray
   
   
   


 /* call function to make a copy of the array of values */
 	makeArrayCopy(darr, toArray, allocated);
 	printf("\nOriginal array is: ");
 	printArray(toArray, allocated); 	
 	
 	printf("\nCopied array is: ");
  	printArray(toArray, allocated); 	
	

 /* call function to sort one of the arrays */
 	myFavorateSort(darr, allocated);
 	printf("\nSorted array is: ");
  	printArray(darr, allocated); 
 	printf("\n");
 	

 /* loop until the user enters -999 */
 printf ("Enter in a list of numbers to use for searching.  \n");
 printf ("End the list with a terminal value of -999\n");
 scanf ("%d", &val);
 
 while (val != -999)
   {
   	
   	int numComparisons = 0;  // to get number of comparisons
    int index;              // to get values from functions
   	
    /* call function to use the value in a linear search on the unsorted array */
    index = linSearch(toArray, allocated, val, &numComparisons);
    
    
    /* print out info about the linear search results  */
    // target is not found
    if(index == -1){
		printf("\nLinear Search: In the unsorted array target %d is not found. Number of comparisons made is %d\n", val, numComparisons);
	}
	// target is found 
	else{
		printf("\nLinear Search: In the unsorted array target %d is found at index %d. Number of comparisons is %d\n",val, index , numComparisons);
	}
	
	
    /* call function to use the value in a binary search on the sorted array */
    index = binSearch(darr, allocated, val, &numComparisons);

    /* print out info about the binary search results  */
    // target is not found
    if(index == -1){
		printf("\nBinary Search: In the sorted array target %d is not found. Number of comparisons made is %d\n", val, numComparisons);
	}
	// target is found 
	else{
		printf("\nBinary Search: In the sorted array target %d is found at index %d. Number of comparisons is %d\n",val, index , numComparisons);
	}

    /* get next value */
    scanf("%d", &val);
   }


 printf ("Good bye\n");
 return 0;
}  
