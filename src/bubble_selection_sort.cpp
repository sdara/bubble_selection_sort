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