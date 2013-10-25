/**
*
*  Worksheet 1 Solutions: Question 2a
*  
*  Author: Samuel Delacruz
*  Date: 04/10/2013
*
*  Description: Program prints a short greeting message,
*  followed by greeting the user by a name supplied as a command line argument
*
*  Usage: ./[program name] [user name]
*
**/
#include <iostream>

int main(int argc, char* argv[]){

	//Check that user has provided correct command line arguments
	if(argc != 2){
		//Inform the user of correct usage
		std::cout << "Correct Usage: " << argv[0] << " [Your Name]\n";
		
		return 1;
	}

	else{

		std::cout << "Hello World\nMy name is student" << std::endl;
		//print entered name, supplied as command line argument
		std::cout << "your name is " << argv[1] << std::endl;

	}

	return 0;

}
