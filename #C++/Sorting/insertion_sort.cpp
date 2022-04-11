#include <bits/stdc++.h>
using namespace std;
 
  // Insertion Sort: consider ([current array] = [sorted array][unsorted array]) & insert elements from right to left
  
void swap(int *arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp; 
}
 
void insertionSort(int *arr, int n)                                                                                  
{ 
	for(int i=0; i<n; i++)
	{ 
		for(int j=i; j>=0; j--)
		{
			if(arr[j-1] > arr[j])
			swap(arr, j-1, j);
			else
			break; 
		}
		  
	}
	 
}


int main()
{
	
   int arr[10] = {3,37,41,14,22,7,9,0,2,53};
 
   insertionSort(arr, 10);            // sorting given array { O(n�) }  
   
   for(int i=0; i<10; i++)
   cout<<arr[i]<<" "; 
   
}











