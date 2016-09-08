#include <iostream>
#include <string>
#include <sstream>
#include <cstring> 
#include <fstream>
using namespace std;

int main(int argc, char * argv[])
{
int num;
ifstream ifile (argv[1]);
if( ifile.fail() ){ // able to open file?
cout << "Couldn't open file" << endl;
return 1;
}
if ( ifile.fail() ){
cout << "Didn't enter an int and double";
return 1;
}
ifile >> num;
string *myarray = new string[num];
string x;
for (int i = 0; i < num; i++)
{
	ifile >> x;
	myarray[i] = x;
}
for (int g = num-1; g >= 0; g--)
{
	cout << myarray[g] << endl;
}
delete[] myarray;
}
