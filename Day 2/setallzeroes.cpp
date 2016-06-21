#include<bits/stdc++.h>
using namespace std;
#define print(arr,n) for(int i =0;i<n;i++) cout<< arr[i] << " "

vector<vector<int> > ZeroPass(vector<vector<int> > matrix)
{
	int row = matrix.size();
     int col = matrix[0].size();
         bool fc0=false;
        bool fr0=false;
         
        for (int i=0;i<col;i++){
            if (matrix[0][i]==0){fr0 = true;}
        }
         
        for (int i=0;i<row;i++){
            if (matrix[i][0]==0){fc0 = true;}
        }
         
        for (int i=1;i<row;i++){
            for (int j=1;j<col;j++){
                if (matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
         
         
        for (int i=1;i<col;i++){
            if (matrix[0][i]==0){
                for(int j=0;j<row;j++){
                    matrix[j][i]=0;
                }
            }
        }
         
        for (int i=1;i<row;i++){
            if (matrix[i][0]==0){
                for(int j=0;j<col;j++){
                    matrix[i][j]=0;
                }
            }
        }
         
        if (fr0){
            for (int i=0;i<col;i++){matrix[0][i]=0;}
        }
        if (fc0){
            for (int i=0;i<row;i++){matrix[i][0]=0;}
        }
         
        return matrix;
         
    }
int main()
{
	int n,m;
	cin>> n;
	cin>> m;
	vector<vector<int> > arr;
	for(int i =0;i<n;i++)
	{	
		vector<int> row;
		int temp;
		for( int j =0;j<m;j++)
		{
			cin>> temp;
			row.push_back(temp);

		}
		arr.push_back(row);
	
}	arr = ZeroPass(arr);
	for(int i =0;i<n;i++)
		{
			for(int z =0;z<m;z++)
				cout<< arr[i][z] << " ";
		cout<< endl;
		}
		getch();
return 0;
}