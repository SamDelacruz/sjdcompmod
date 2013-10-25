#include <iostream>
#include <cfloat>
#include <math.h>

int main(){

	double x = 1.0f;
	int i = 0;

	while(isfinite(x) != 0){
		
		x *= 1.1f;
		i++;
	}

	x = 1.0f;

	for(int j = 0; j < i-1; j++){
	
		x *= 1.1f;

	}
	
	std::cout<<x<<std::endl;
	std::cout<<DBL_MAX<<std::endl;
	return 0;

}
