#include <iostream>
#include <climits>

int main(){

	int i1;

	for(i1 = 1; i1 >= 0; i1*=1000){		
		//loop until i1 value wraps around to negative number
	}

	for(;i1<=0;i1--){
		//decrement i1 until it reaches maximal value	
	}

	int i = i1; 	

	std::cout << "Maximum integer value calculated = " << i << std::endl;
	std::cout << "INT_MAX value = " << INT_MAX << std::endl;

	return 0;

}
