#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	string strOne;
	string strTwo;

	cout<<"Please input first number: ";
	cin>>strOne;
	cout<<"Please input second number: ";
	cin>>strTwo;
	
	int  lenOne = strOne.size();
	cout<<"lenOne = "<<lenOne<<endl;
	int  lenTwo = strTwo.size();
	cout<<"lenTwo = "<<lenTwo<<endl;
	int  lenRes = lenOne + lenTwo;
	int  *result = new int [lenRes];
	
	memset(result, 0, lenRes*sizeof(int));

	int  i,j,k;
	for( i = 0; i < lenOne; i++) {
		for( j = 0; j < lenTwo; j++)
			result[i + j] += (strTwo[lenOne - 1 - i] - '0') * (strOne[lenTwo - 1 -j] - '0');
 	}
	cout<<"result[] = ";
	for( i = 0; i < lenRes; i++)
		cout<<result[i]<<" ";
	cout<<endl;	

	for( i = 0; i < lenRes; i++) {
		while(result[i] >= 10) {
			result[i] -= 10;
			result[i+1]++;
		}
	}

	for( i = lenRes - 1; i > 0; i--) {
		if(result[i] != 0)
			break;
	}
	cout<<"i = "<< i <<endl;
	cout<<strOne<<"*"<<strTwo<<" = "<<endl;
	for(  ; i >= 0; i--)
		cout<<result[i];
	delete [] result;
	cout<<endl;
	return 0;
	
}
