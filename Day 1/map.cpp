// A simple program to find the largest subarray with equal number of 0s and 1s
#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

void findSubArray(int arr[], int n)
{
  map<int, int> m;
    
    int sum = 0;
    int max_len  = 0;
    int s = 0;
    int e = 0;
    for(int i = 0; i < n;i++){
        if(arr[i]==0)
            arr[i] = -1;
            
        sum+=arr[i];
        
        if(sum == 0){
        	s = 0;
        	e = i;
        
            max_len = i + 1;
        }
        if(m.find(sum)!=m.end()){
 
            int prev = m[sum];
            int ans = i- prev;
            if(ans > max_len){
 
                max_len = ans;
                s = prev+1;
                e = i;
 
            }
 
        }else{
           m[sum] = i; 
        }
       
    }
	cout << "range"<< endl;
	cout << s<<"to"<<e<<endl;
	cout << "max length" << endl;
	cout << max_len << endl;
}

int main()
{
	int arr[] = {1, 1, 1, 1, 1, 1 ,1, 0 ,0, 0 ,0, 1, 1 ,1 ,1, 1 ,1};
	int size = sizeof(arr)/sizeof(arr[0]);

	findSubArray(arr, size);
	getch();
    return 0;
}
