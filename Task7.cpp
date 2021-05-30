#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
	ll n, *a, i, j, t, k, l;
	cin>>n;
	a = (ll *)malloc(n*sizeof(ll));
	for(i=0; i<n; i++)
	{
		cin>>a[i];
		j=i;
		t=a[i];
		while(j>0)
		{
			if(a[(j-1)/2]<a[j])
			{
				a[j]=a[(j-1)/2];
				a[(j-1)/2]=t;
				j = (j-1)/2;
			}else break;
		}
		if(i<2)
		cout<<-1;
		else
		{
			t=0;
			k = max(a[1], a[2]);
			l = min(a[1], a[2]);
			for(j=3; j<=i; j++)
			{
				if(a[j]>t)
				t=a[j];
			}
			cout<<a[0]*k*max(l, t);
		}
		cout<<endl;
	}
	return 0;
}
