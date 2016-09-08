/**
 * Incorrect code to identify palindromes
 */

#include <iostream>
#include <sstream>
#include <cstring> 

using namespace std;

bool helper (stringstream &input, int len)
{
	char prev;

	//if we are at the midpoint of the string, return true.
	if (len == 0) return true;
	/**
	 * If the length of the string is odd, and the next
	 * character is the midpoint of the string, consume it
	 * and return true.
	 */
	cout << &input << "input" << endl;
	input >> prev;
	cout << prev << "prev" << endl;
	if (len == 1) return true;
cout << len << "len" << endl;
	bool val = helper(input, len-2);
cout << val << "val" << endl;

	//make your changes only below this line.
	char next;
	if (!val){
		return false;
	}
	input >> next;
	if (next == prev) {
		return true;
	}
	else {

		return false;
	}
	//if (val) return true;
	//return false;
}

//do not change the main function.
int main (int argc, char* argv[])
{
  if(argc < 2){
    cerr << "Please provide a string of characters." << endl;
    return 1;
  }
  stringstream ss;
  ss << argv[1];
  if(helper(ss, strlen(argv[1])))
	  cout << "Palindrome" << endl;
  else cout << "Not a Palindrome" << endl;
  return 0;
}
