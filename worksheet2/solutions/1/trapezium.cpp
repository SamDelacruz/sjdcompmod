#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include <iomanip>

using namespace std;

double f(double);
double trapezium(double,double,int);
vector<vector<double> > getResults(int,int,double,double,double);
//void resultsToFile(vector<vector<double> >*);
void resultsToScreen(vector<vector<double> >*);

int main(int argc, char* argv[]){
	
	//BEGIN COMMAND LINE ARGUMENT CHECKING
	if(argc < 6){
		//inform the user of correct usage
		cout << "Correct usage: " << argv[0] << " n_min n_max x_min x_max expected_value" << endl;
		return -1;
	}
	
	//Parse user input
	int n_min = atoi(argv[1]);
	int n_max = atoi(argv[2]);
	double x_min = atof(argv[3]);
	double x_max = atof(argv[4]);
	double expected = atof(argv[5]);
	
	//check for positive N
	if(n_min < 0 || n_max < 0){
	
		cout << "Error: Positive n only" << endl;
		return -1;
	}
	//END COMMAND LINE ARGUMENT CHECKING
	
	vector<vector<double> > results = getResults(n_min,n_max,x_max,x_min,expected);
	
	resultsToScreen(results);
	//resultsToFile(results);
	
	return 0;

}

void resultsToScreen(vector< vector<double> >& results){

	//print headers
	cout << "\nh\tResult\tError\n";
	
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

vector < vector <double> > getResults(int n_min, int n_max, double x_n, double x_0, double expected){

	vector<double> hs(n_max - n_min + 1);
	vector<double> is(hs.size());
	vector<double> errors(hs.size);
	
	for(int n = n_min; n < n_max + 1; n++){
	
		hs.at(n) = (x_n - x_0) / (double)n;
		is.at(n) = trapezium(x_n,x_0,n);
		errors.at(n) = expected - is.at(n);
	
	}
	
	vector<vector<double> > toret(3);
	
	toret.at(0) = hs;
	toret.at(1) = is;
	toret.at(2) = errors;
	
	return toret;
}

double trapezium (double x_n, double x_0, int n){

	double h = (x_n - x_0) / (double)n;
	
	double result = 0.0f;
	
	for(int i = 1; i < n-1; i++){
	
		result += f(x_0+((double)i*h));
	
	}
	
	result = h*(2.0f*f(x_0) + 2.0f*f(x_n) + result);
	
	return result;

}

double f(double x){

	return pow(1.0f+x,2.0f);
	
}
