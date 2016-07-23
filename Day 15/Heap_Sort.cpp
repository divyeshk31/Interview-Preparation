#include <stdio.h>
#include <conio.h>
#include <bits/stdc++.h>
using namespace std;

void heapify(int *res, int k, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    
    if( l < k && res[l] > res[largest])
    largest = l;
        
    if( r < k && res[r] > res[largest])
        largest = r;
        
    if(largest != i)
    {
        // swap(res[smallest], res[i])
        int temp = res[largest];
        res[largest] = res[i];
        res[i] = temp;
        
        heapify(res, k, largest);
    }
    
}

void findklargest(int *arr,int *res, int n, int k)
{
    int i;
    // Copy the first k element into res array
    for(i=0;i<k;i++)
    {
        res[i] = arr[i];
    }
    
    // Build heap of the res array
    // by calling heapify on every parent node
    for(i=k/2-1;i>=0;i--)
        heapify(res,k,i);
        
    
    // Now check wheteher any element present in arr is
    // greater than the smallest element(root) of all the element
    // present in min heap.
    for(i=k;i<n;i++)
    {
        // If any element is greater then replace the root 
        // with this element
        if(arr[i] > res[0])
        {
            res[0] = arr[i];
            heapify(res,k,0);
        }
         
    }
    
    // now sort the min heap to get resultant array
    for(i=k-1;i>=0;i--)
    {
        //swap(res[0], res[i]);
        int temp = res[0];
        res[0] = res[i];
        res[i] = temp;
        
        heapify(res,i,0);
    }
    
    
}
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--)
	{
	    int n,k,i;
	    cin>>n;
        //cin>>n>>k;
        int arr[n+2];
        int result[n+2];
	    for(i=0;i<n;i++)
	    {
	        scanf("%d",&arr[i]);
	    }
	    
	    //findklargest(arr,result,n,k);
        heapSort(arr,n);
        printArray(arr,n);
	    /*for(i=0;i<k;i++)
	    {
	        printf("%d ",result[i]);
	    }
	    printf("\n"); */
	}
    getch();
	return 0;
}