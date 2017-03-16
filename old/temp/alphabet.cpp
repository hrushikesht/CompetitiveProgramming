#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdbool.h>
#include <string>

using namespace std;

int main()
{	
	string alphabet;
	int len=0,input_length=0;

//	cout<<"Enter known alphabets";
	cin>>alphabet;

	len = alphabet.size();

//	cout<<"Enter the input length: ";
	cin>>input_length;

//	cout<<"Enter words";
	string test[input_length];
	for(int index=0;index<input_length;index++)
	{
		cin>>test[index];
	}

	//cout<<alphabet;

	for(int index=0;index<input_length;index++)
	{
		int yo_index=0;
		int count=0;
		int input_var_legth=0;
		while(test[index][yo_index]!='\0')
		{	
			input_var_legth+=1;

			for(int third_index=0;third_index<len;third_index++)
			{
				if(alphabet[third_index] == test[index][yo_index])
				{
					count+=1;
					break;
				}
			}

			yo_index+=1;

			if(input_var_legth!=count)
			{
				cout<<"No\n";
				break;
			}
		}

		if(count == input_var_legth)
		{
			cout<<"Yes\n";
		}
	}


}