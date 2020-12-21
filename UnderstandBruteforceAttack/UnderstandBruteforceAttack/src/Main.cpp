/* #include <iostream>
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
			std::cout << alpha[i];
			passIndex++;
			i = -1;
		}
		std::cout << "index #: " << passIndex << std::endl;

	}*/	
	/*
	//Second version to match lowercase, uppercase, numbers and symbols individually
	for (int i = 0; i < userpass.length(); i++)
	{
		for (int j = 0; j < sizeof(alpha); j++)
		{
			if (alpha[j] == userpass[i])
			{
				std::cout << alpha[j];
			}
		}
	}
	
	//This version must match 2 characters at a time rather than one
	for (int i = 0; i < userpass.length(); i++)
	{
		for (int j = 0; j < sizeof(alpha); j++)
		{
			if (alpha[j + (j+1)] == userpass[i + (i+1)])
			{
				std::cout << alpha[j+(j++)]; // This causes a crash after matching 2 of the same characters.. eg(abAB) this crashes...(debug assertion failed)
			}
		}
	}
}; */

// Below code matches the complete stick the complexity grows exponentially and takes much longer with each character added 
// If you want to try for youself I would recommend 4-5 characters so it doesn't tak too long
#include <iostream>
#include <ctime>
#include <string>

using namespace std;
string crackPassword(string const& pass);
long long int attempt = 0;
std::clock_t startCrack, endCrack;

int main() {
    string password;

    cout << "Enter the password to crack : ";
    cin >> password;

    cout << "\n\n\n>\n>> CRACKED THE PASSWORD! >>\n>\n\n The password : " << crackPassword(password) << "\n";
    cout << "The number of attempts : " << attempt << endl;
    cout << "The time duration  passed : " << static_cast<double>(endCrack - startCrack) / 1000 << " seconds" << endl << endl;
    return 0;
}

string crackPassword(string const& pass) {
    int digit[7];
    int alphabetSet = 1;
    int passwordLength = 1;
    startCrack = clock();

    string test, alphabet = "";
    while (1) {


        switch (passwordLength) {
        case 1:
            while (alphabetSet < 4) {
                switch (alphabetSet) {
                case 1: alphabet = "-0123456789";
                    cout << endl << endl << "Testing only digits(0123456789) - 10 Characters, please wait\n";  break;
                case 2: alphabet = "-aeioubcdfghjklmnpqrstvwxyz";
                    cout << "Testing only lowercase characters(aeioubcdfghjklmnpqrstvwxyz) - 26 Characters, please wait\n";  break;
                case 3: alphabet = "-AEIOUBCDFGHJKLMNPQRSTVWXYZ";
                    cout <<  "Testing only uppercase characters(AEIOUBCDFGHJKLMNPQRSTVWXYZ) - 26 Characters, please wait\n";  break;
                }

                for (digit[0] = 1; digit[0] < alphabet.length(); digit[0]++) {
                    attempt++;
                    if (attempt % 2500000 == 0) cout << ".";
                    test = alphabet[digit[0]];
                    for (int i = 1; i < passwordLength; i++)
                        if (alphabet[digit[i]] != '-')test += alphabet[digit[i]];
                    if (pass.compare(test) == 0) { endCrack = clock(); return test; }
                }
                alphabetSet++;
            }
            break;
        case 2:
            alphabetSet = 1;
            while (alphabetSet < 6) {
                switch (alphabetSet) {
                case 1: alphabet = "-0123456789";
                    cout << endl << endl << "Testing only digits(0123456789) - 10 Characters, please wait\n";  break;
                case 2: alphabet = "-aeioubcdfghjklmnpqrstvwxyz";
                    cout <<  "Testing only lowercase characters(aeioubcdfghjklmnpqrstvwxyz) - 26 Characters, please wait\n";  break;
                case 3: alphabet = "-AEIOUBCDFGHJKLMNPQRSTVWXYZ";
                    cout <<  "Testing only uppercase characters(AEIOUBCDFGHJKLMNPQRSTVWXYZ) - 26 Characters, please wait\n";  break;
                case 4: alphabet = "-0123456789aeioubcdfghjklmnpqrstvwxyz";
                    cout <<  "Testing lowercase characters and numbers(0123456789aeioubcdfghjklmnpqrstvwxyz) - 36 Characters, please wait\n";  break;
                case 5: alphabet = "-0123456789AEIOUBCDFGHJKLMNPQRSTVWXYZ";
                }


                for (digit[1] = 0; digit[1] < alphabet.length(); digit[1]++)
                    for (digit[0] = 1; digit[0] < alphabet.length(); digit[0]++) {
                        attempt++;
                        if (attempt % 2500000 == 0) cout << ".";
                        test = alphabet[digit[0]];
                        for (int i = 1; i < passwordLength; i++)
                            if (alphabet[digit[i]] != '-')test += alphabet[digit[i]];
                        if (pass.compare(test) == 0) { endCrack = clock(); return test; }
                    }
                alphabetSet++;
            }
            break;
        case 3:
            alphabetSet = 1;
            while (alphabetSet < 8) {
                switch (alphabetSet) {
                case 1: alphabet = "-0123456789";
                    cout << endl << endl << "Testing only digits(0123456789) - 10 Characters, please wait\n";  break;
                case 2: alphabet = "-aeioubcdfghjklmnpqrstvwxyz";
                    cout <<  "Testing only lowercase characters(aeioubcdfghjklmnpqrstvwxyz) - 26 Characters, please wait\n";  break;
                case 3: alphabet = "-AEIOUBCDFGHJKLMNPQRSTVWXYZ";
                    cout <<  "Testing only uppercase characters(AEIOUBCDFGHJKLMNPQRSTVWXYZ) - 26 Characters, please wait\n";  break;
                case 4: alphabet = "-0123456789aeioubcdfghjklmnpqrstvwxyz";
                    cout <<  "Testing lowercase characters and numbers(0123456789aeioubcdfghjklmnpqrstvwxyz) - 36 Characters, please wait\n";  break;
                case 5: alphabet = "-0123456789AEIOUBCDFGHJKLMNPQRSTVWXYZ";
                    cout <<  "Testing uppercase characters and numbers(0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ) - 36 Characters, please wait\n";  break;
                case 6: alphabet = "-aeioubcdfghjklmnpqrstvwxyzAEIOUBCDFGHJKLMNPQRSTVWXYZ";
                    cout <<  "Testing lowercase, uppercase characters(aeioubcdfghjklmnpqrstvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ) - 52 Characters, please wait\n";  break;
                case 7: alphabet = "-0123456789aeioubcdfghjklmnpqrstvwxyzAEIOUBCDFGHJKLMNPQRSTVWXYZ";
                    cout <<  "Testing lowercase, uppercase characters and numbers(0123456789aeioubcdfghjklmnpqrstvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ) - 62 Characters, please wait\n";  break;
                }
                for (digit[2] = 0; digit[2] < alphabet.length(); digit[2]++)
                    for (digit[1] = 0; digit[1] < alphabet.length(); digit[1]++)
                        for (digit[0] = 1; digit[0] < alphabet.length(); digit[0]++) {
                            attempt++;
                            if (attempt % 2500000 == 0) cout << ".";
                            test = alphabet[digit[0]];
                            for (int i = 1; i < passwordLength; i++)
                                if (alphabet[digit[i]] != '-')test += alphabet[digit[i]];
                            if (pass.compare(test) == 0) { endCrack = clock(); return test; }
                        }
                alphabetSet++;
            }
            break;
        case 4:
            alphabetSet = 1;
            while (alphabetSet < 8) {
                switch (alphabetSet) {
                case 1: alphabet = "-0123456789";
                    cout << endl << endl << "Testing only digits(0123456789) - 10 Characters, please wait\n";  break;
                case 2: alphabet = "-aeioubcdfghjklmnpqrstvwxyz";
                    cout <<  "Testing only lowercase characters(aeioubcdfghjklmnpqrstvwxyz) - 26 Characters, please wait\n";  break;
                case 3: alphabet = "-AEIOUBCDFGHJKLMNPQRSTVWXYZ";
                    cout <<  "Testing only uppercase characters(AEIOUBCDFGHJKLMNPQRSTVWXYZ) - 26 Characters, please wait\n";  break;
                case 4: alphabet = "-0123456789aeioubcdfghjklmnpqrstvwxyz";
                    cout <<  "Testing lowercase characters and numbers(0123456789abcdefghijklmnopqrstuvwxyz) - 36 Characters, please wait\n";  break;
                case 5: alphabet = "-0123456789AEIOUBCDFGHJKLMNPQRSTVWXYZ";
                    cout <<  "Testing uppercase characters and numbers(0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ) - 36 Characters, please wait\n";  break;
                case 6: alphabet = "-aeioubcdfghjklmnpqrstvwxyzAEIOUBCDFGHJKLMNPQRSTVWXYZ";
                    cout <<  "Testing lowercase, uppercase characters(abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ) - 52 Characters, please wait\n";  break;
                case 7: alphabet = "-0123456789aeioubcdfghjklmnpqrstvwxyzAEIOUBCDFGHJKLMNPQRSTVWXYZ";
                    cout <<  "Testing lowercase, uppercase characters and numbers(0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ) - 62 Characters, please wait\n";  break;
                }

                for (digit[3] = 0; digit[3] < alphabet.length(); digit[3]++)
                    for (digit[2] = 0; digit[2] < alphabet.length(); digit[2]++)
                        for (digit[1] = 0; digit[1] < alphabet.length(); digit[1]++)
                            for (digit[0] = 1; digit[0] < alphabet.length(); digit[0]++) {
                                attempt++;
                                if (attempt % 2500000 == 0) cout << ".";
                                test = alphabet[digit[0]];
                                for (int i = 1; i < passwordLength; i++)
                                    if (alphabet[digit[i]] != '-')test += alphabet[digit[i]];
                                if (pass.compare(test) == 0) { endCrack = clock(); return test; }
                            }
                alphabetSet++;
            }
            break;
        case 5:
            alphabetSet = 1;
            while (alphabetSet < 8) {
                switch (alphabetSet) {
                case 1: alphabet = "-0123456789";
                    cout << endl << endl << "Testing only digits(0123456789) - 10 Characters, please wait\n";  break;
                case 2: alphabet = "-aeioubcdfghjklmnpqrstvwxyz";
                    cout <<  "Testing only lowercase characters(aeioubcdfghjklmnpqrstvwxyz) - 26 Characters, please wait\n";  break;
                case 3: alphabet = "-AEIOUBCDFGHJKLMNPQRSTVWXYZ";
                    cout <<  "Testing only uppercase characters(AEIOUBCDFGHJKLMNPQRSTVWXYZ) - 26 Characters, please wait\n";  break;
                case 4: alphabet = "-0123456789aeioubcdfghjklmnpqrstvwxyz";
                    cout <<  "Testing lowercase characters and numbers(0123456789abcdefghijklmnopqrstuvwxyz) - 36 Characters, please wait\n";  break;
                case 5: alphabet = "-0123456789AEIOUBCDFGHJKLMNPQRSTVWXYZ";
                    cout <<  "Testing uppercase characters and numbers(0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ) - 36 Characters, please wait\n";  break;
                case 6: alphabet = "-aeioubcdfghjklmnpqrstvwxyzAEIOUBCDFGHJKLMNPQRSTVWXYZ";
                    cout <<  "Testing lowercase, uppercase characters(abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ) - 52 Characters, please wait\n";  break;
                case 7: alphabet = "-0123456789aeioubcdfghjklmnpqrstvwxyzAEIOUBCDFGHJKLMNPQRSTVWXYZ";
                    cout <<  "Testing lowercase, uppercase characters and numbers(0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ) - 62 Characters, please wait\n";  break;
                }
                for (digit[4] = 0; digit[4] < alphabet.length(); digit[4]++)
                    for (digit[3] = 0; digit[3] < alphabet.length(); digit[3]++)
                        for (digit[2] = 0; digit[2] < alphabet.length(); digit[2]++)
                            for (digit[1] = 0; digit[1] < alphabet.length(); digit[1]++)
                                for (digit[0] = 1; digit[0] < alphabet.length(); digit[0]++) {
                                    attempt++;
                                    if (attempt % 2500000 == 0) cout << ".";
                                    test = alphabet[digit[0]];
                                    for (int i = 1; i < passwordLength; i++)
                                        if (alphabet[digit[i]] != '-')test += alphabet[digit[i]];
                                    if (pass.compare(test) == 0) { endCrack = clock(); return test; }
                                }
                alphabetSet++;
            }
            break;
        case 6:
            alphabetSet = 1;
            while (alphabetSet < 8) {
                switch (alphabetSet) {
                case 1: alphabet = "-0123456789";
                    cout << endl << endl << "Testing only digits(0123456789) - 10 Characters, please wait\n";  break;
                case 2: alphabet = "-aeioubcdfghjklmnpqrstvwxyz";
                    cout <<  "Testing only lowercase characters(aeioubcdfghjklmnpqrstvwxyz) - 26 Characters, please wait\n";  break;
                case 3: alphabet = "-AEIOUBCDFGHJKLMNPQRSTVWXYZ";
                    cout <<  "Testing only uppercase characters(AEIOUBCDFGHJKLMNPQRSTVWXYZ) - 26 Characters, please wait\n";  break;
                case 4: alphabet = "-0123456789aeioubcdfghjklmnpqrstvwxyz";
                    cout <<  "Testing lowercase characters and numbers(0123456789abcdefghijklmnopqrstuvwxyz) - 36 Characters, please wait\n";  break;
                case 5: alphabet = "-0123456789AEIOUBCDFGHJKLMNPQRSTVWXYZ";
                    cout <<  "Testing uppercase characters and numbers(0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ) - 36 Characters, please wait\n";  break;
                case 6: alphabet = "-aeioubcdfghjklmnpqrstvwxyzAEIOUBCDFGHJKLMNPQRSTVWXYZ";
                    cout <<  "Testing lowercase, uppercase characters(abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ) - 52 Characters, please wait\n";  break;
                case 7: alphabet = "-0123456789aeioubcdfghjklmnpqrstvwxyzAEIOUBCDFGHJKLMNPQRSTVWXYZ";
                    cout <<  "Testing lowercase, uppercase characters and numbers(0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ) - 62 Characters, please wait\n";  break;
                }
                for (digit[5] = 0; digit[5] < alphabet.length(); digit[5]++)
                    for (digit[4] = 0; digit[4] < alphabet.length(); digit[4]++)
                        for (digit[3] = 0; digit[3] < alphabet.length(); digit[3]++)
                            for (digit[2] = 0; digit[2] < alphabet.length(); digit[2]++)
                                for (digit[1] = 0; digit[1] < alphabet.length(); digit[1]++)
                                    for (digit[0] = 1; digit[0] < alphabet.length(); digit[0]++) {
                                        attempt++;
                                        if (attempt % 2500000 == 0) cout << ".";
                                        test = alphabet[digit[0]];
                                        for (int i = 1; i < passwordLength; i++)
                                            if (alphabet[digit[i]] != '-')test += alphabet[digit[i]];
                                        if (pass.compare(test) == 0) { endCrack = clock(); return test; }
                                    }
                alphabetSet++;
            }
            break;
        case 7:
            alphabetSet = 1;
            while (alphabetSet < 8) {
                switch (alphabetSet) {
                case 1: alphabet = "-0123456789";
                    cout << endl << endl << "Testing only digits(0123456789) - 10 Characters, please wait\n";  break;
                case 2: alphabet = "-aeioubcdfghjklmnpqrstvwxyz";
                    cout <<  "Testing only lowercase characters(aeioubcdfghjklmnpqrstvwxyz) - 26 Characters, please wait\n";  break;
                case 3: alphabet = "-AEIOUBCDFGHJKLMNPQRSTVWXYZ";
                    cout <<  "Testing only uppercase characters(AEIOUBCDFGHJKLMNPQRSTVWXYZ) - 26 Characters, please wait\n";  break;
                case 4: alphabet = "-0123456789aeioubcdfghjklmnpqrstvwxyz";
                    cout <<  "Testing lowercase characters and numbers(0123456789abcdefghijklmnopqrstuvwxyz) - 36 Characters, please wait\n";  break;
                case 5: alphabet = "-0123456789AEIOUBCDFGHJKLMNPQRSTVWXYZ";
                    cout <<  "Testing uppercase characters and numbers(0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ) - 36 Characters, please wait\n";  break;
                case 6: alphabet = "-aeioubcdfghjklmnpqrstvwxyzAEIOUBCDFGHJKLMNPQRSTVWXYZ";
                    cout <<  "Testing lowercase, uppercase characters(abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ) - 52 Characters, please wait\n";  break;
                case 7: alphabet = "-0123456789aeioubcdfghjklmnpqrstvwxyzAEIOUBCDFGHJKLMNPQRSTVWXYZ";
                    cout <<  "Testing lowercase, uppercase characters and numbers(0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ) - 62 Characters, please wait\n";  break;
                }
                for (digit[6] = 0; digit[6] < alphabet.length(); digit[6]++)
                    for (digit[5] = 0; digit[5] < alphabet.length(); digit[5]++)
                        for (digit[4] = 0; digit[4] < alphabet.length(); digit[4]++)
                            for (digit[3] = 0; digit[3] < alphabet.length(); digit[3]++)
                                for (digit[2] = 0; digit[2] < alphabet.length(); digit[2]++)
                                    for (digit[1] = 0; digit[1] < alphabet.length(); digit[1]++)
                                        for (digit[0] = 1; digit[0] < alphabet.length(); digit[0]++) {
                                            attempt++;
                                            if (attempt % 2500000 == 0) cout << ".";
                                            test = alphabet[digit[0]];
                                            for (int i = 1; i < passwordLength; i++)
                                                if (alphabet[digit[i]] != '-')test += alphabet[digit[i]];
                                            if (pass.compare(test) == 0) { endCrack = clock(); return test; }
                                        }
                alphabetSet++;
            }
            break;
        case 8:
            alphabetSet = 1;
            while (alphabetSet < 8) {
                switch (alphabetSet) {
                case 1: alphabet = "-0123456789";
                    cout << endl << endl << "Testing only digits(0123456789) - 10 Characters, please wait\n";  break;
                case 2: alphabet = "-aeioubcdfghjklmnpqrstvwxyz";
                    cout <<  "Testing only lowercase characters(aeioubcdfghjklmnpqrstvwxyz) - 26 Characters, please wait\n";  break;
                case 3: alphabet = "-AEIOUBCDFGHJKLMNPQRSTVWXYZ";
                    cout <<  "Testing only uppercase characters(AEIOUBCDFGHJKLMNPQRSTVWXYZ) - 26 Characters, please wait\n";  break;
                case 4: alphabet = "-0123456789aeioubcdfghjklmnpqrstvwxyz";
                    cout <<  "Testing lowercase characters and numbers(0123456789abcdefghijklmnopqrstuvwxyz) - 36 Characters, please wait\n";  break;
                case 5: alphabet = "-0123456789AEIOUBCDFGHJKLMNPQRSTVWXYZ";
                    cout <<  "Testing uppercase characters and numbers(0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ) - 36 Characters, please wait\n";  break;
                case 6: alphabet = "-aeioubcdfghjklmnpqrstvwxyzAEIOUBCDFGHJKLMNPQRSTVWXYZ";
                    cout <<  "Testing lowercase, uppercase characters(abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ) - 52 Characters, please wait\n";  break;
                case 7: alphabet = "-0123456789aeioubcdfghjklmnpqrstvwxyzAEIOUBCDFGHJKLMNPQRSTVWXYZ";
                    cout <<  "Testing lowercase, uppercase characters and numbers(0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ) - 62 Characters, please wait\n";  break;
                }
                for (digit[7] = 0; digit[7] < alphabet.length(); digit[7]++)
                    for (digit[6] = 0; digit[6] < alphabet.length(); digit[6]++)
                        for (digit[5] = 0; digit[5] < alphabet.length(); digit[5]++)
                            for (digit[4] = 0; digit[4] < alphabet.length(); digit[4]++)
                                for (digit[3] = 0; digit[3] < alphabet.length(); digit[3]++)
                                    for (digit[2] = 0; digit[2] < alphabet.length(); digit[2]++)
                                        for (digit[1] = 0; digit[1] < alphabet.length(); digit[1]++)
                                            for (digit[0] = 1; digit[0] < alphabet.length(); digit[0]++) {
                                                attempt++;
                                                if (attempt % 2500000 == 0) cout << ".";
                                                test = alphabet[digit[0]];
                                                for (int i = 1; i < passwordLength; i++)
                                                    if (alphabet[digit[i]] != '-')test += alphabet[digit[i]];
                                                if (pass.compare(test) == 0) { endCrack = clock(); return test; }
                                            }
                alphabetSet++;
            }
            break;
        }
        cout << endl << endl << endl << endl << "*" << endl;
        cout << "*** Password length is not " << passwordLength << ". Increasing password length! ***";
        cout << endl << "*" << endl << endl;
        passwordLength++;
    }
}