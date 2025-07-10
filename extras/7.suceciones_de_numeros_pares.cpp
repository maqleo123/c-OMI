#include <iostream>
using namespace std;

int main(){
	int n;
	cout<<"Ingresa el numero limite : ";
	cin>>n;
	cout<<"La serie numerica es:";
	for(int i=1;i<=n;i++){
		if(i%2==0){
			cout<<" "<<i;
		}
	}
}
