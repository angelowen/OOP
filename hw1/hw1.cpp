#include <bits/stdc++.h>
#define len 30
using namespace std;

void Add(int a[], int  b[], int c[])
{
		int i;
		for(i=0; i<len; i++)
				c[i]=a[i]+b[i];
		for(i=0; i<len-1; i++) {
				if(c[i]>=10) {
						c[i+1]+=c[i]/10;
						c[i]=c[i]%10;
				}
		}
}
void copy(int a[],int b[]){
	for(int i=0;i<len;i++){
		a[i]=b[i];
	}
}
void fib(int n) {
		int a[len],b[len],tmp[len];
		int cnt=2,i;
		for( i=0; i<len; i++){ 
				a[i]=0;
				b[i]=0;
				tmp[i]=0;
		}
		a[0]=1,b[0]=1;
		while(cnt!=n){
				Add(a,b,tmp);
				copy(a,b);
				copy(b,tmp);
				cnt++;
		}
		//cout<<a<<b<<endl;
		for( i=len-1; i>0; i--)
				if(b[i]!=0) break;
		for( ; i>=0; i--)
				cout<< b[i];
		cout << endl;

		/* if (n == 1 || n == 2) {
		   return 1;
		   }
		   return fib(n - 1) + fib(n - 2);*/
}
int main(int argc, char *argv[]) {
		int  n;
		n=atoi(argv[1]);
		if (n < 1 || n > 99)
				return 0;
		else
				fib(n);
		return 0;
}
