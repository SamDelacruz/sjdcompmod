#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main(){

	//Define some output constants
	const int width = 12;
	
	//Define constants for our value to compare to
	const double DBL_ONE = 1.0f;
	const float FLT_ONE = 1.0f;
	
	//Number of iterations to perform
	const int FLT_ITER = 10;
	const int DBL_ITER = 20;
	
	//BEGIN FLOAT CALCULATIONS
	float value;

	cout << setw(20) << left << "Float Value" << setw(20) << left << "Value-1" << endl;
	
	for(int i = 0; i < FLT_ITER; i++){
		
		value = 1.0f + (0.1f * pow(10.0f, -1 * i));

		cout 	<< setw(20) << left << setprecision(15) << fixed << value 
			<< setw(20) << left << setprecision(8) << scientific << value - FLT_ONE << endl;

	}

	//BEGIN DOUBLE CALCULATIONS
	double value2;
	
	cout << setw(20) << left << "Double Value" << setw(20) << left << "Value-1" << endl;
	
	for(int j = 0; j < DBL_ITER; j++){
		
		value2 = 1.0f + (0.1f * pow(10.0f, -1 * j));

		cout 	<< setw(20) << left << setprecision(15) << fixed << value2 
			<< setw(20) << left << setprecision(8) << scientific << value2 - DBL_ONE << endl;

	}

	return 0;
}
