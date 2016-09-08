#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char* argv[])
{
  if(argc < 3){
    cerr << "Please provide an input and output file." << endl;
    return 1;
  }
  ifstream input(argv[1]);
  ofstream output(argv[2]);

  int constructionspots;
  int *buildingheights;
  string **skyline;
  string curr;

  input >> constructionspots;
  getline(input, curr); //consume the newline character for the first line.
  skyline = new string*[constructionspots];

  //you will need to keep track of the height of each building
  buildingheights = new int[constructionspots];

  for (int i = 0; i < constructionspots; i++) {
	  buildingheights[i] = 0;
	  skyline[i] = NULL;
  }
  while(getline(input, curr)) {
	  stringstream ss;
	  ss << curr;
	  ss >> curr;
	  if (curr == "BUILD") {
		  int x,y;
		  string c;
		  ss >> x;
		  ss >> y; 
		  ss >> c;
		  if (ss.fail() || skyline[x] != NULL or buildingheights[x] > 0 or y <= 0 or x >= constructionspots or x < 0) {
			  output << "Error - incorrect command" << endl;
		  }
		  else {
		  	string d;
		  	ss >> d;
		  	if (!ss.fail()){
		  		output << "Error - incorrect command" << endl;
		  	}
		  	else{
		  		buildingheights[x] = y;
		  		skyline[x] = new string[y];
		  		for (int i = 0; i < y; i++) {
		  		skyline[x][i] = c;
		  		}
		  	}
		  }
	  }
	  else if (curr == "EXTEND") {
		  int x,y;
		  string c;
		  ss >> x;
		  ss >> y;
		  ss >> c;
		  if (ss.fail() || skyline[x] == NULL or y <= 0 or c.size() > 20 or x >= constructionspots or x < 0) 
		  {
			output << "Error - incorrect command" << endl;
		  }
		  else {
		  	string d;
		  	ss >> d;
		  	if (!ss.fail()){
		  		output << "Error - incorrect command" << endl;
		  	}
		  	else{
		  		int oldHeight = buildingheights[x];
		  		int newHeight = oldHeight + y;
		  		string *tmpArray = new string[newHeight];
		  		for (int i = 0; i < oldHeight; i++){
		  			tmpArray[i] = skyline[x][i];
		  		}
		  		for (int j = oldHeight; j < newHeight; j++){
					tmpArray[j] = c;
		  		}
		  		delete[] skyline[x];
		  		skyline[x] = tmpArray;
		  		buildingheights[x] += y;
		  	}
		  }
		}
	  else if (curr == "DEMOLISH") {
		int x;
		ss >> x;
		if (buildingheights[x] == 0 or x >= constructionspots or x < 0)
		{
			output << "Error - incorrect command" << endl;
		}
		else 
		{
			string d;
		  	ss >> d;
		  	if (!ss.fail()){
		  		output << "Error - incorrect command" << endl;
		  	}
		  	else {
				buildingheights[x] = 0;
				delete[] skyline[x];
				skyline[x] = NULL;
			}
		}
	  }
	  else if (curr == "SKYLINE") {
	  		int y;
	  		ss >> y;
	  		string d;
		  	ss >> d;
		  	if (!ss.fail() or y <= 0){
		  		output << "Error - incorrect command" << endl;
		  	}
		  	else {
	  			for (int i = 0; i < constructionspots; i++){
	  				if (skyline[i] == NULL or buildingheights[i] < y){
	  					output << " SKY";
	  				}
	  				else {
	  					output << " " << skyline[i][y-1];
	  				}
	  			}
	  			output << endl;
	  		}
	  }
	  else {
	  	output << "Error - incorrect command" << endl;
	  }
	  
	}
	for (int bye = 0; bye < constructionspots; bye++) {
		delete[] skyline[bye];
	}
	delete skyline;
	delete[] buildingheights;
  return 0;
  }
