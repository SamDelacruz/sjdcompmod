/**
* Solution to Question 4a of Worksheet 1
* Program calculates a user-specified power N of the Silver Ratio,
* by direct multiplication, and outputs tabulated results to q4a.dat
*
* User should supply desired power of Silver Ratio as a command line argument
* when executing the program. Eg) > ./q4a.o 6
* 
* Name:		Samuel Delacruz
* ID:		1090154
* Email:	SJD054@bham.ac.uk
* Date:		17-10-2013
**/

#include <iostream>
//Include fstream for file manipulation
#include <fstream>
#include <math.h>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

//Function declarations
vector<double> multiplySilver(int);
void printResults(vector<double>&);
void resultsToFile(vector<double>&, string fname);

//Define Silver Ratio as a constant
const double THI = ((-1.0f)+sqrt(5.0f))*0.5f;
//filename for data output
const string filename ("q4a.dat");

int main(int argc, char *argv[]){

		
	
	//Check that user has supplied a power argument
	if(argc < 2){
		//inform the user of correct usage
		cout << "Correct usage: " << argv[0] << " N" << endl;
		return -1;
	}
	
	//Parse user input as integer
	int N = atoi(argv[1]);
	//check for positive N
	if(N < 0){
	
		cout << "Error: Positive N only" << endl;
		return -1;
	}
	
	//Calculate our set of results
	vector<double> results = multiplySilver(N);

	printResults(results);
	resultsToFile(results,filename);
	return 0;

}

/*Function to return a set of results after calculating
* The nth power of the Silver Ratio, by direct multiplication
*/
vector<double> multiplySilver(int n){

	//need size n+1 for n = {1..100}
	vector<double> results(n+1);
	
	for(int i=1; i<results.size(); i++){

		results.at(i) = pow(THI,(double)i);

	}

	return results;

}


/*
* Basic function for printing a set of results to terminal
*/
void printResults(vector<double>& results){
	
	cout << "n\tDirect\n";
	for(int i = 1; i < results.size(); i++){

		cout << i << "\t" << setprecision(15) << scientific << results.at(i) << endl;	

	}

}

/*
* Function to save our one column of results to file, of a given name
*/
void resultsToFile(vector<double>& results, string fname){

	ofstream dataFile(fname.c_str());

	if(dataFile.is_open()){
		
		dataFile << "n\tDirect\n";
		
		for(int i = 1; i < results.size(); i++){
		
			dataFile << i << "\t" << setprecision(15) << scientific << results.at(i) << endl;

		}

	dataFile.close();
	
	}

	else {
	
		cout << "\nError writing to file\n";

	}

}

