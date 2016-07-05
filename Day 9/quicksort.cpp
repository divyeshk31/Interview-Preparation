#include <iostream>
using namespace std;

void quickSort(int arr[], int left, int right)
 {
  int i = left, j = right;
  int tmp;
  int pivot = arr[(left + right) / 2];

  /* partition */
  while (i <= j) {
        while (arr[i] < pivot)
              i++;
        while (arr[j] > pivot)
              j--;
        if (i <= j) {
              tmp = arr[i];
              arr[i] = arr[j];
              arr[j] = tmp;
              i++;
              j--;
    }
}
/* recursion */
if (left < j)
    quickSort(arr, left, j);
if (i < right)
        quickSort(arr, i, right);
}

int main(){
	
	int a[]={9,2,3,2,4,2,8,9};
	quickSort(a,0,8);
	
	for(int i=0;i<8;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}