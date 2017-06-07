/*input
2
1 2
*/

#include <bits/stdc++.h>

using namespace std;

int main(){

	int n;
	cin >> n;
	int vet[n];

	for (int i = 0; i < n; i++)
		cin >> vet[i];

	bool ok = true;
 
    for (int i = 0; i < n; i++)
    	for (int j = 0; j < i; j++)
    		if (vet[j] > vet[i])
    			ok = false;

    if (ok)
    	cout << "yes" << endl;
    else
    	cout << "no" << endl;			

	return 0;
}