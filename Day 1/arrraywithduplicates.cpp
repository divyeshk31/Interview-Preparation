#include <bits/stdc++.h>

using namespace std;

int remdup(int a[], int size) {
	int elementToBeChecked = 0;
	int availablePosition = 0;
	while (elementToBeChecked < size) {
		bool flag = false;
		for (int i = 0; i < elementToBeChecked; i++) {
			if (a[i] == a[elementToBeChecked]) {
				flag = true;
				break;
			}
		}
		if (flag) {
			elementToBeChecked++;
		} else {
			a[availablePosition] = a[elementToBeChecked];
			availablePosition++;
			elementToBeChecked++;
		}
	}

	return availablePosition;
}
int main()
{
    int n;
    cin>>n;
    int a[n+2];
    for(int i=0;i<n;i++)
        cin>>a[i];
   cout<<remdup(a,n);
    return 0;
}
