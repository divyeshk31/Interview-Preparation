#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rf(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define s(n)                        scanf("%d",&n)
#define p(n)			    printf("%d\n",n)
#define sl(n)                       scanf("%lld",&n)
#define pl(n)			    printf("%lld\n",n)
#define ll long long int
void merge(int a[],int l, int m, int r)
{
	int n1=m-l+1;
	int n2=r-m;
	int i,j,k;
	int le[n1],re[n2];
	f(i,0,n1)
	le[i]=a[l+i];
	f(j,0,n2)
	re[j]=a[m+1+j];
	 i=0;
	 j=0;
k=l;
	while(i<n1&&j<n2){
		if(le[i]<=re[j]){
			a[k]=le[i];
			i++;
		}
		else{
			a[k]=re[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		a[k]=le[i];
		i++; k++;
	}
	while(j<n2){
		a[k]=re[j];
		j++; k++;
	}
}
void mergesort(int a[],int l, int r){
	if(l<r){
		int m=l+(r-l)/2;
		mergesort(a,l,m);
		mergesort(a,m+1,r);
		merge(a,l,m,r);
	}
}
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
int main()
{
   int arr[] = {12, 11, 13, 5, 0 , 5 , 0};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
 
    printf("Given array is \n");
    printArray(arr, arr_size);
 
    mergesort(arr, 0, arr_size - 1);
 
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}