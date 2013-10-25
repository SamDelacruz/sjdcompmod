/**
* Solution to Question 7 part (iii) of Worksheet 1
* Program solves for x, x^3 + 7x^2 - 6x + 15 = 0
* using the Bisection Method
*
* User should supply number of iterations, upper and lower bounds and file output name
* as a command line arguments when executing the program. 
* Eg) > ./q7.o 100 15.0 -15.0 q7_bm_100_15_-15.dat
* 
* Name:		Samuel Delacruz
* ID:		1090154
* Email:	SJD054@bham.ac.uk
* Date:		20-10-2013
**/
#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

//BEGIN FUNCTION DECLARATIONS
double f_x(double);
void printMultiple(vector< vector<double> >&);
vector<vector<double> > calculateResults(int);
void fileMultiple(vector< vector<double> >&, string);
//END FUNCTION DECLARATIONS

//BEGIN CONSTANTS

double START_UPPER = 15.0;//Starting upper bound value of x to try
double START_LOWER = -15.0f;//Starting lower bound value of x to try

string DATA_FILENAME = "q7_bm.dat";
//END CONSTANTS

//BEGIN MAIN
int main(int argc, char* argv[]){
	
	//BEGIN COMMAND LINE ARGUMENT CHECKING
	if(argc < 5){
		//inform the user of correct usage
		cout << "Correct usage: " << argv[0] << " N x_t x_b {FILENAME}" << endl;
		return -1;
	}
	
	//Parse user input as integer
	int N = atoi(argv[1]);
	START_UPPER = atof(argv[2]);
	START_LOWER = atof(argv[3]);
	DATA_FILENAME = argv[4];
	//check for positive N
	if(N < 0){
	
		cout << "Error: Positive N only" << endl;
		return -1;
	}
	//END COMMAND LINE ARGUMENT CHECKING
	
	vector<vector<double> > results = calculateResults(N);
	printMultiple(results);
	fileMultiple(results, DATA_FILENAME);
	return 0;

}
//END MAIN

//BEGIN HELPER FUNCTION IMPLEMENTATIONS

/*
* Function to calculate table of results of theta
* and corresponding uncertainty, given number of iterations to perform
*/
vector<vector<double> > calculateResults(int n){
	//Set initial upper and lower bound values
	double xt = START_UPPER;
	double xb = START_LOWER;
	
	//create data structures to hold values calculated
	vector<double> xs(n);
	vector<double> errors(n);
	vector<vector<double> > table(2);
	
	for(int i = 0; i < n; i++){
		
		double xm = (xb + xt)*0.5f;
		double error = xt - xb;
		
		
		xs.at(i) = xm;
		errors.at(i) = error;
		
		if(f_x(xt)*f_x(xm) < 0.0f){
			xb = xm;
		}
		
		else{
			xt = xm;
		}
		
		
	}
	
	table.at(0) = xs;
	table.at(1) = errors;
	
	return table;
}

/*
* Function for printing multiple data sets, tabulated
* Must use equal sized data sets
*/
void printMultiple(vector< vector<double> >& results){

	//print headers
	cout << "\nIteration\tx_n\tError_n\n";
	
	//Iterate over each n value
	for(int n = 0; n < results.at(0).size(); n++){
		
		//print iteration number
		cout << n+1 << "\t";
		
		//Iterate over columns
		for(int j = 0; j < results.size(); j++){

			cout << setprecision(15) << scientific << results.at(j).at(n) << "\t";

		}

		//newline
		cout << endl;

	}
}

/*
* Function for printing multiple data sets, tabulated
* Must use equal sized data sets
*/
void fileMultiple(vector< vector<double> >& results, string fname){

	ofstream dataFile(fname.c_str());

	if(dataFile.is_open()){

		//print headers
		dataFile << "\nIteration\tx_n\tError_n\n";
		
		//Iterate over each n value
		for(int n = 0; n < results.at(0).size(); n++){
			
			//print iteration number
			dataFile << n+1 << "\t";
			
			//Iterate over columns
			for(int j = 0; j < results.size(); j++){

				dataFile << setprecision(15) << scientific << results.at(j).at(n) << "\t";

			}

			//newline
			dataFile << endl;

		}
	}
}

/*
* Function to calculate f(x)
*/
double f_x(double x){

	return (x*x*x) + (7.0f*x*x) - (6.0f*x) + 15.0f;
}

//END HELPER FUNCTION IMPLEMENTATIONS
