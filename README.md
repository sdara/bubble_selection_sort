10-07-2004
CSC153-02
Project #04

Psuedocode

Include header files and function prototypes.


In the main program, call the five different functions in a logical order to ensure proper display and calculations. 2 functions will return something to the main program and store these returned values in variables.


Call FillArrayWithRandomNumbers() to fill the arrays with random numbers. We need two matching arrays to account for the two sorting algorithms used.


Call BubbleSortArray() with the first random array as the first parameter and return the number of iterations back to the main program and store it in a variable.

Call SelectionSortArray() with the second random array as the first parameter and return the number of iterations back to the main program and store it in a variable.

Call DisplaySortedArray() with the first random array as the first parameter and display the sorted array. Since both arrays have the same numbers in them, we can just do this to one of the arrays.

Call Output() with the returned number from the BubbleSortArray() function as the first parameter and the returned number from the SelectionSortArray() function as the second parameter. These two values will be printed to the screen.

Source Code

#include <iostream.h>
#include <stdlib.h>
 
//function prototypes
void FillArrayWithRandomNumbers(void);
int BubbleSortArray(int Array[]);
int SelectionSortArray(int Array[]);
void Output(int BSIter, int SSIter);
void DisplaySortedArray(int Array[]);
 
//Globals - make arrays good for all functions
const int ArraySize=20;
int NumberArray1[ArraySize];
int NumberArray2[ArraySize];
 
void main (void)
{
int ExchangesForBubble=0,ExchangesForSelection=0;
	FillArrayWithRandomNumbers();
	ExchangesForBubble=BubbleSortArray(NumberArray1);
	ExchangesForSelection=SelectionSortArray(NumberArray2);
	DisplaySortedArray(NumberArray1);
	Output(ExchangesForBubble,ExchangesForSelection);
}
 
void FillArrayWithRandomNumbers(){
	int seed, x, i;
	seed = 9999;
	cout<<"This program will fill an array with "<< ArraySize << " random numbers."<<endl;
	cout<<"This array will then be sorted using a Bubble Sort and a Selection Sort."<<endl<<endl;
	cout<<"Unsorted Array: "<<endl;
	for (i= 0; i< ArraySize; i++)
	{
		x = rand();
	//make sure both arrays are identical
		NumberArray1[i] = 1 + x % 100;
		NumberArray2[i] = 1 + x % 100;
		//display unsorted random array
		if(i<ArraySize-1)
			cout<<NumberArray1[i]<<", ";
	else
			cout<<NumberArray1[i]<<endl<<endl;
}
}
 
 
//displays the sorted array-since this function is called
//after the sorting algorithms are called, it displays the
//now sorted array,
void DisplaySortedArray(int NumberArray1[])
{
	//begin to sort arrays
int i;
cout<<"Sorted Array: "<<endl;
		for (i= 0; i< ArraySize; i++)
	{	
if(i<ArraySize-1)
			cout<<NumberArray1[i]<<", ";
	else
			cout<<NumberArray1[i]<<endl<<endl;
		}
}
 
//the bubble sort function will take an array and
//sort it, comparing 2 numbers at a time for the amount
//of elements in that array. it will return to the main
//program the number of comparisions (iterations) it made.
int BubbleSortArray(int NumberArray1[]){
	int y=0,swap,counter=0;
long tempNumber;
do{
swap=0;
for(int y=0;y<ArraySize-1;y++){
if(NumberArray1[y]>NumberArray1[y+1])
{
tempNumber=NumberArray1[y];
NumberArray1[y]=NumberArray1[y+1];
NumberArray1[y+1]=tempNumber;
counter++;
swap=1;
}
}
}while(swap!=0);
return counter;
 
}
 
//the selection sort function will take an array and
//sort it, comparing 2 numbers at a time, always finding the
//next lowest number, making it need to do less comparisions
//(for larger arrays). it will return to the main
//program the number of comparisions (iterations) it made.
int SelectionSortArray(int NumberArray2[]){
 
	int startScan,minIndex,minValue,counter=0;
	for(startScan=0;startScan<(ArraySize-1);startScan++)
	{
		minIndex=startScan;
		minValue=NumberArray2[startScan];
		for(int index=startScan+1;index<ArraySize;index++)
		{
			if(NumberArray2[index]<minValue)
			{
				minValue=NumberArray2[index];
				minIndex=index;
				counter++;
			}
		}
		NumberArray2[minIndex]=NumberArray2[startScan];
		NumberArray2[startScan]=minValue;
	}
	return counter;
}
 
 
//output the number of iterations
void Output(int BSIter, int SSIter){
	cout<<"Bubble Sort: "<<BSIter<<" iterations.\n\n";
	cout<<"Selection Sort: "<<SSIter<<" iterations.\n\n";
}

Program Output

This program will fill an array with 20 random numbers.
This array will then be sorted using a Bubble Sort and a Selection Sort.
 
Unsorted Array:
42, 68, 35, 1, 70, 25, 79, 59, 63, 65, 6, 46, 82, 28, 62, 92, 96, 43, 28, 37
 
Sorted Array:
1, 6, 25, 28, 28, 35, 37, 42, 43, 46, 59, 62, 63, 65, 68, 70, 79, 82, 92, 96
 
Bubble Sort: 87 iterations.
 
Selection Sort: 30 iterations.
 
Press any key to continue



