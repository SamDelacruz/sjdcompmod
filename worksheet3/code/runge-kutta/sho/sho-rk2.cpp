/**
*	Name: 		Samuel Delacruz
*	Email:		sjd054@bham.ac.uk
*	Assignment:	Question 5ci of Worksheet 3 - Computational Modelling
*	
*	This program uses Second order Runge-Kutta method to find an approximate solution to the
*	simple harmonic oscillator problem, outputting x and p as a function of t 
*
*	Usage:	Compile using g++, run as follows: > ./sho-rk2.o [t] [n] [filename]
*		Where [t] is the time step between successive iterations, [n] is number of *		iterations and [filename] is the file name to output data to. 
**/

#include<iostream>
#include<iomanip>
#include<cmath>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

void runge_kutta(double, vector<double>&, vector<double>&, int,int);
void saveResults(vector< vector<double> >&, double, string);

const double X_0 = 1.0;//starting point for x
const double P_0 = 0.0;//starting p

int main(int argc, char* argv[]){
	
	//BEGIN COMMAND LINE ARGUMENT CHECKING
	if(argc < 4){
		//inform the user of correct usage
		cout << "Correct usage: " << argv[0] << " [t] [n] [filename]" << endl;
		return -1;
	}
	
	//Parse user input as integer
	double dt = atof(argv[1]);
	int n_max = atoi(argv[2]);
	//set filename
	string filename = argv[3];
	//check for positive N
	if(n_max < 0){
	
		cout << "Error: Positive n only" << endl;
		return -1;
	}
	
	//check for positive dt
	if(dt < 0){
	
		cout << "Error: Positive t only" << endl;
		return -1;
	}
	//END COMMAND LINE ARGUMENT CHECKING
	
	
	vector<double> xs(n_max+1);
	vector<double> ps(n_max+1);
	
	//place starting values
	xs[0]= X_0;
	ps[0]= P_0;
	
	cout << "\n\n|| Starting second order Runge-Kutta method for following params \t||\n";
	cout << "|| \tdt = " << setprecision(15) << dt << " \t\t\t\t\t\t\t||\n";
	cout << "|| \tn_max = " << n_max << " \t\t\t\t\t\t\t||\n";
	cout << "|| \tfilename = " << filename << " \t\t\t\t||\n";
	
	//use i = 1 to start recursive calls from beginning
	runge_kutta(dt,xs,ps,0,n_max);
	cout << "\nRunge-Kutta method complete.\n";
	
	//create vector to hold all results for saving
	vector<vector<double> > results (2);
	results[0] = xs;
	results[1] = ps;
	
	saveResults(results, dt, filename);
	cout << "\nResults saved to " << filename <<"\n";
	return 0;
	

}

//Function fills two results vectors with results, given starting parameters
void runge_kutta(double h, vector<double>& xs, vector<double>& ps, int i, int n_max){
	
	//iterate over all n
	if(i < n_max){
	
		double k1x = ps[i];
		double k1p = -xs[i];
		
		double k2x = ps[i] + h*k1p;
		double k2p = -(xs[i] + h*k1x);
		
		//Put results at end of results files
		xs.at(i+1) = (xs[i] + 0.5*h*(k1x + k2x));
		ps.at(i+1) = (ps[i] + 0.5*h*(k1p + k2p));
		
		//recursive call, advance i
		runge_kutta(h,xs,ps,i+1,n_max);
		
	}
	
	
}

void saveResults(vector< vector<double> >& results, double dt, string fname){

	ofstream dataFile(fname.c_str());

	if(dataFile.is_open()){

		//Iterate over each n value
		for(int n = 0; n < results.at(0).size(); n++){
			
			//print iteration number
			dataFile << setprecision(15) << n*dt << "\t";
			
			//Iterate over columns
			for(int j = 0; j < results.size(); j++){

				dataFile << setprecision(15) << scientific << results.at(j).at(n) << "\t";

			}

			//newline
			dataFile << endl;

		}
	}
	
	dataFile.close();
}
	
	
