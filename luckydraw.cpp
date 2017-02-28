#include <iostream>
using namespace std;
int arr[10007];
int arr2[10007];
int lis[10007];
int n;
int lis_m(int st){
	for(int i=0;i<n;i++)lis[i]=1;
	int k=0;
	int max=-1;
	for(int i=st;i<n;i++){arr2[i-st]=arr[i];k++;}
	
	for(int i=0;i<st;i++)arr2[k++] = arr[i];
	
	for (int i = 1; i < n; i++ )
    {    for (int j = 0; j < i; j++ ) 
        {
           	if ( arr2[i] > arr2[j] && lis[i] < lis[j] + 1)lis[i] = lis[j] + 1;
        }
	}
	for (int i = 0; i < n; i++ )
    {   
    	if (max < lis[i])max = lis[i];
    }
    return max;
}

int main() {
	int t;
	cin>>t;
	while(t--){
		
		cin>>n;
		for(int i=0;i<n;i++)cin>>arr[i];
		int max = -1;
		for(int i =0;i<n;i++){
			int tem = lis_m(i);
			if(tem>max)max = tem;
		}
		cout<<max<<endl;
	}
	return 0;
}