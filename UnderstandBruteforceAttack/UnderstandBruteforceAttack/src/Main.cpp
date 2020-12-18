#include <iostream>
#include <string>
using namespace std;

char alpha[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 
				'A','B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 
				'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '!', '@', '#', '$', '%', '|' };

int main()
{
	string userpass = "aAbB";


	/* // Initial version
 	size_t passIndex = 0;
	for (int i = 0; i < sizeof(alpha); i++)
	{
		if (passIndex >= 3)
			return 0;

		if (alpha[i] == userpass[passIndex])
		{
			cout << alpha[i];
			passIndex++;
			i = -1;
		}
		cout << "index #: " << passIndex << endl;

	}*/	
	/*
	//Second version to match lowercase, uppercase, numbers and symbols individually
	for (int i = 0; i < userpass.length(); i++)
	{
		for (int j = 0; j < sizeof(alpha); j++)
		{
			if (alpha[j] == userpass[i])
			{
				cout << alpha[j];
			}
		}
	}
	*/
	//This version must match 2 characters at a time rather than one
	for (int i = 0; i < userpass.length(); i++)
	{
		for (int j = 0; j < sizeof(alpha); j++)
		{
			if (alpha[j + (j+1)] == userpass[i + (i+1)])
			{
				cout << alpha[j+(j++)]; // This causes a crash after matching 2 of the same characters.. eg(abAB) this crashes...(debug assertion failed)
			}
		}
	}
};