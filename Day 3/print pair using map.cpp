#include <bits/stdc++.h>
#include <conio.h>
#include <tr1/unordered_map>
using namespace std::tr1;
using namespace std;
void printpairs(vector<int> v )
{
	unordered_map<int,int> hash;
	for(int i=0;i<v.size();i++)
	{
		if(hash.count(-v[i])==1)
			cout<< " pair is : " << v[i] << " and " << -v[i]<< endl;
        hash[v[i]] = 1;
	}
}
void printpairswithDuplicates(std::vector<int> v)
{
	unordered_map<int,int> hash;
    int n = v.size();
	for(int i =0;i<n;i++)
	{
		{
			if(hash.count(-v[i])>0)
                {
                    for(int i =0;i<hash[-v[i]] ; i++)
                    cout<< v[i] << " " <<-v[i] << endl;
                    hash[v[i]] = 1;
                }
            if(hash.count(v[i])>0)
            hash[v[i]] +=1 ;
        else hash[v[i]]=1;
		}
	}
}
int main()
{
	int n;
	cout<<"Enter the number of elements : ";
	cin>> n;
	vector<int> arr;
	int temp;
for(int i =0;i<n;i++)
	{
		cin>> temp;
		arr.push_back(temp);
	}
	printpairs(arr);
	printpairswithDuplicates(arr);
	getch();
	return 0;
}