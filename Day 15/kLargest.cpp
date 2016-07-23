#include <stdio.h>

void heapify(int *res, int k, int i)
{
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    
    if( l < k && res[l] < res[smallest])
        smallest = l;
        
    if( r < k && res[r] < res[smallest])
        smallest = r;
        
    if(smallest != i)
    {
        // swap(res[smallest], res[i])
        int temp = res[smallest];
        res[smallest] = res[i];
        res[i] = temp;
        
        heapify(res, k, smallest);
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

int main() {
	int t;
	scanf("%d", &t);
	while(t--)
	{
	    int n,k,i;
	    int arr[100];
	    int result[100];
	    scanf("%d %d",&n,&k);
	    for(i=0;i<n;i++)
	    {
	        scanf("%d",&arr[i]);
	    }
	    
	    findklargest(arr,result,n,k);
	    for(i=0;i<k;i++)
	    {
	        printf("%d ",result[i]);
	    }
	    printf("\n");
	}
	return 0;
}