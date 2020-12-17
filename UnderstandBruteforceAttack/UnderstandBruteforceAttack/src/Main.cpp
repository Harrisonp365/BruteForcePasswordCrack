#include <iostream>
using namespace std;

char alpha[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '\0' };

int main()
{
	string userpass = "ab";

	for (int i = 0; i < sizeof(alpha); i++)
	{
		cout << alpha[i];
	}
};