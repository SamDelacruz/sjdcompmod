/**
* Solution to Question 7 c of Worksheet 2
* Program uses the GSL QAWO integration routine to approximate a given integral
* Data is output to file (name defined in command line arguments).
* 
* User must supply output file name in the following format:
* Eg) > ./q6a.o q6a-01.dat
* 
* Name:		Samuel Delacruz
* ID:		1090154
* Email:	SJD054@bham.ac.uk
* Date:		03-11-2013
**/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//GSL Headers
#include <gsl/gsl_errno.h>//GSL status return values and convenience functions
#include <gsl/gsl_integration.h>//GSL Integration routines
#include <gsl/gsl_math.h> //defines the values of certain mathematical constants

int f_counter = 0;//counter for number of function calls to f(x)

//Function to be integrated. Params is needed by GSL, but unused in this case
double f (double x, void * params) {
	
	f_counter++;//increment counter for function call
	return x*cos(x);
}

int main(int argc, char* argv[]){

	//BEGIN COMMAND LINE ARGUMENT CHECKING
	if(argc < 2){
		//inform the user of correct usage
		cout << "Correct usage: " << argv[0] << " output_file_name" << endl;
		return -1;
	}
	
	//Parse user input
	string filename = argv[1];//will use later to output to file
	//END COMMAND LINE ARGUMENT CHECKING
	
	//Set up variables for integration
	double lower_lim 	= 0.0f;//lower integration limit
	double rel_error 	= 1e-10;//Relative error
	double abs_error	= 1e-10;//Absolute error
	double expected		= -0.209672479661165; //analytic value of integral to 15dp
	double result, error; // results of integration will be stored here
	double omega 		= 30.0;//from w(x) = sin(\omega*x)
	double L 			= 2.0 * M_PI;//Size of region to integrate over
	
	gsl_integration_workspace *w = gsl_integration_workspace_alloc (1000);
	
	//Set up qawo table - W(x) = sin(30x) in our case
	gsl_integration_qawo_table* t =  gsl_integration_qawo_table_alloc(
										omega,
										L,
										GSL_INTEG_SINE,
										1000 );
	
	gsl_function F;
	
	F.function = &f;//uses definition of f(x) for integration function
	
	//Perform integration routine
	gsl_integration_qawo (	&F, lower_lim, abs_error,
							rel_error, 1000, w,
							t, &result, &error);
	
	cout.setf (ios::fixed, ios::floatfield);	// output in fixed format
  	cout.precision (15);		// 18 digits in doubles
  	
  	//output results to screen
	int width = 20;  // setw width for output
	cout << "result				= " << setw(width) << result << endl;
	cout << "exact result		= " << setw(width) << expected << endl;
	cout << "estimated error	= " << setw(width) << error << endl;
	cout << "actual error		= " << setw(width) << result - expected << endl;
	cout << "f(x) calls			=  " << f_counter << endl;
	
	//write data to file
	ofstream dataFile(filename.c_str());

	if(dataFile.is_open()){
		dataFile << "result				= " << setw(width) << result << endl;
		dataFile << "exact result		= " << setw(width) << expected << endl;
		dataFile << "estimated error	= " << setw(width) << error << endl;
		dataFile << "actual error		= " << setw(width) << result - expected << endl;
		dataFile << "f(x) calls			=  " << f_counter << endl;
	}
	//free up memory
	gsl_integration_qawo_table_free (t);
	gsl_integration_workspace_free (w);
	
	return 0;
}
