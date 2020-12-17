#include <iostream>
#include <string>
using namespace std;

char alpha[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

int main()
{
	string userpass = "abc abc";


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
};