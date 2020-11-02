//Scott Hawley
//Test for palindrome property.
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string reverse(string s);
//Returns a copy of s but with characters in reverse order.

string removePunct(string s, string punct);
//Returns a copy of s with any occurrences of characters
//in the string punct removed.

string makeLower(string s);
//Returns a copy of s that has all upper case
//characters changed to lower case, other characters unchanged.

bool isPal(string s);
//Returns true if s is a palindrome, false otherwise.

int main()
{
	string str;
	//read in a candiate for palindron test
	cout << "Enter a candidate for palindrome test: ";
	getline(cin, str);

	if (isPal(str))
	{
		cout << "\"" << str + "\" is a palindrome.";
	}
	else
	{
		cout << "\"" << str + "\" is not a palindrome.";
	}
	cout << endl;

	system("pause");
	return 0;
}


string reverse(string s)
{
	int length = s.size();
	for (unsigned int i = 0; i < length/2; i++)
	{
		swap(s[i], s[length - 1 - i]);
	}
	//cout << s << endl;
	return s;
}

//Uses <cctype> and <string>
string makeLower(string s)
{
	for (unsigned int i = 0; i < s.length(); i++)
	{
		s[i] = tolower(s[i]);
	}
	//cout << s << endl;
	return s;
}

string removePunct(string s, string punct)
{
	//create an loop of size s
	int length = s.size();
	for (unsigned int i = 0; i < length; i++)
	{
		//check if array space is punctuation
	    if (ispunct(s[i]))
		{
			//remove punctuation, then decrement, and remove possibility for additional loops
			s.erase(i--, 1);	
			length = s.size();
		}
		//check if array space is space
		else if (s[i] == ' ')
		{
			s.erase(i--, 1);
			length = s.size();
		}
	}
	//return string
	//cout << s << endl;
	return s;

	/*second solution
	int length = s.size();
	int punctPosition;
	for (unsigned int i = 0; i < length; i++)
	{
		punctPosition = s[i].find(punct);
		if (punctPosition != string::npos)
		{
			s.erase(punctPosition, 1);
			i--;
			length = s.size();
		}
	}
	cout << s << endl;
	return s;*/
}

//uses functions makeLower, removePunct.
bool isPal(string s)
{
	string punct(",;:.?!'\" "); //includes a blank
	s = makeLower(s);
	s = removePunct(s, punct);
	return (s == reverse(s));
}