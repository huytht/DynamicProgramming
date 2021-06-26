#include<bits/stdc++.h>
using namespace std;
int a[100],W,c[100],f[100][100];
int n,i,j,GT;

void nhap(){
	cout<<"nhap n: ";
	cin>>n;
	cout<<"nhap W: ";
	cin>>W;
	for(i=1;i<=n;i++){
		cout<<"nhap khoi luong doi vat thu " << i<< " ";
		cin>>a[i];
	}
	for(i=1;i<=n;i++){
		cout<<"nhap gia tri doi vat thu " << i << " ";
		cin>>c[i];
	}
}
void xuat(){
	cout<<"\n\n---bang---\n";
	for(i = 1; i <= n; i++){
		for(j = 0; j <= W; j++){
			cout << f[i][j];
		}
		cout << "\n";
	}
}
int max(int a,int b){
	return (a > b) ? a : b;
}
int caiTui(){
	for(i=0;i<=n;i++){
		f[i][0]=0;
	}
	for(j=0;j<=W;j++){
		f[0][j]=0;	
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=W;j++){
			if(a[i]<=j){
				f[i][j]=max(f[i-1][j],f[i-1][j-a[i]]+c[i]);
			}
			else{
				f[i][j]=f[i-1][j];
			}
		}
	}
}
int luuVet(){
	i=n;
	j=W;
	while((i!=0)&&(j!=0)){
		if(f[i][j]!=f[i-1][j]){
			cout<<i<<" ";
			GT+=c[i];
			j-=a[i];
		}
		i--;
	}
}
int main(){
	nhap();
	cout<<"\n------cac gia tri sau khi nhap------";
	caiTui();
	cout<<"\n cac do vat duoc chon: ";
	luuVet();
	cout<<"\n\n tong gia tri cua do vat cho vao tui la: "<<GT<<" ";

	return 0;
}

