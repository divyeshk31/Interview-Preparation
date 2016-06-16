/*
Question
1
You are given with a NxN matrix which contains only 0s and 1s. e.g.
1 0 1 1 0
0 1 1 1 0
1 1 1 1 1
1 0 1 1 1
1 1 1 1 1
Your job is to write a function which will set every row that contains a 0 to all 0s and set every
column that contains a 0 to all 0s. The output for the above input matrix will be:
0 0 0 0 0
0 0 0 0 0
0 0 1 1 0
0 0 0 0 0
0 0 1 1 0
Fucntion
Prototype:
Int[][] ZeroPass(int[][] inputMatrix)
*/

#include<iostream>
using namespace std;
#include<vector>
#include<conio.h>
#include<cstdio>
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
	cout<<"Enter the row size of input matrix : ";
	cin>> n;
	cout<<"Enter the column size of input matrix : ";
	cin>> m;

	cout<<"Enter the matrix : \n" ;
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
	}

	arr = ZeroPass(arr);

	cout<<"The required matrix is : " << endl;
	for(int i =0;i<n;i++)
		{
			for(int z =0;z<m;z++)
				cout<< arr[i][z] << " ";
		cout<< endl;
		}
		getch();
return 0;
}