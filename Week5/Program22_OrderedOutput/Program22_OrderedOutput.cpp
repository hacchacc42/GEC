#include <iostream>
using namespace std;
//The clasic bubble sort Algorithm, the worst but the fastest to learn.
void bubbleSort(int a[], int length);
//Function that will swap 2 variable using pointers.
void Swap(int* x, int* y);
//Function that will output the whole array, it requires the array, the array length and if you want the array to be output in reverse.
void OutputArray(int a[], int length,bool reverse);
//Function that will search for the biggest number, normally after the bubbleSort we can pick the biggest number pretty quick, but the document states that this should be a function.
//It requier an array and it's length.
int FindingTheBiggestNumber(int a[], int length);

int main()
{
	//The main array, a is a common variable name for array.
	int a[5];
	cout << "You will input 5 numbers." << endl;
	//Loop that will go through each position of the array and the player will input for each one a value.
	for (int i = 0; i < 5; i++)
	{
		cout << "Input the number on position " << i << " :";
		cin >> a[i];
	}
	cout << "Your array is : ";
	OutputArray(a, 5, false);
	bubbleSort(a, 5);
	cout << "The sorrted array is : ";
	OutputArray(a, 5, false);
	cout << "The backwards array is : ";
	OutputArray(a, 5, true);
	//The hardcoded firs position is made, beacuse we already sorted the array and output it in the reverse order, so the biggest number is in the first position
	cout << "The biggest number is " << FindingTheBiggestNumber(a, 5) << " and it is found on the first position(0).";

}

//BubbleSort Sorting Algorithm.
void bubbleSort(int a[], int length)
{
	//Bubble sort goes through an list for (lenght of the list -1) number of times, that is done to be sure that everything is in place.
	for (int i = 0; i < length - 1; i++)
	{
		//The second loop of BubbleSort will go from the first element to the (lenght of the list - i - 1) and it will push the biggest number to the right.
		//The (lenght of the list - i - 1) is choosen, because the i represent the numbers that were already sorted.
		for (int j = 0; j < length - i - 1; j++)
		{
			//If an value is bigger that the value to it's right, they will swap and will push the bigger value to the right.
			if (a[j] > a[j + 1])
			{
				//Calling the swap function, using value adresses.
				Swap(&a[j], &a[j+1]);
			}
		}
	}
}

//Swap Function using pointers.
void Swap(int* x, int* y)
{
	//Creating a temporary variable to store one pointer.
	int temp = *x;
	//The pointer stored in the temporary variable will get the value of the second pointer.
	*x = *y;
	//The second pointer will get the initial value of the first pointer, that is stored in the temporary variable.
	*y = temp;
}

//
void OutputArray(int a[], int length, bool reverse)
{
	if (!reverse)
	{
		for (int i = 0; i < length; i++)
		{
			cout << a[i] << " ";
		}
	}
	else
	{
		for (int i = length - 1; i >= 0; i--)
		{
			cout << a[i] << " ";
		}
	}
	cout << endl;
}

//Function that will find the biggest number.
int FindingTheBiggestNumber(int a[], int length)
{
	//First it assign a max value to the first item of the array.
	int max = a[0];
	//The loop goes from the second item, because the first one is already assigned.
	for (int i = 1; i < length; i++)
	{
		//If the curent value is bigger than the max one, the curent value will be assigned to the max.
		if (max < a[i])
		{
			max = a[i];
		}
	}
	return max;
}