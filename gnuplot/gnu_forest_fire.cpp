#include <stdio.h>
#include <iostream>

using namespace std;

/*
	The idea of this code is to use a pipe to output directly to gnuplot, as if you were simply typing
	the commands in yourself. Thus you see common commands like 'set terminal' and 'plot' are used below.
	Whatever you can type into gnuplot you can use here. 

	This code shows a guassian curve evolving over time with a varying standard deviation.
*/

int main(){
	// Open a pipe to gnuplot. but we forward the output to a file err
	// and output the errors to that file too. To get output to the screen
	// remove the part '> ./output 2>&1'
	FILE *gnuplotPipe = popen("gnuplot -persist > ./out 2>&1 ","w");  
	
	// If gnuplot is found  
	if (gnuplotPipe) {  
		 
        //By default gnuplot will pick the best terminal output it sees fit.
		//so when running it on the phymat servers it will default to X11 forwarding.
		//you can force it to output to png/jpeg/bmp or whatever you like.
		//fprintf(gnuplotPipe,"set terminal windows \n");  
		//fprintf(gnuplotPipe,"set terminal x11 \n");  

	  //          fprintf(gnuplotPipe, "set term png truecolor\n");
          fprintf(gnuplotPipe, "reset\n");
	  fprintf(gnuplotPipe, "set grid\n");
          fprintf(gnuplotPipe, "set boxwidth 0.95 relative\n");
          fprintf(gnuplotPipe, "set style fill transparent solid 0.5 noborder\n");
	  fprintf(gnuplotPipe, "set style line 1 lt 1 lw 5 pt 1\n");
          fprintf(gnuplotPipe, "set style line 2 lt 3 lw 5 pt 1\n");

		//This is the main loop that updates the graph output
		for (int x=20; x<200; x++){
		  fprintf(gnuplotPipe, "plot sin(x)*exp(-((x/5.0)/(2*%f))**2) with points ls 1, sin(-x)*exp(-((-x/5.0)/(2*%f))**2) with lines ls 2\n",x/100.0,x/100.0);
			// gnuplot pause just slows down the animation so we can see it.	
			// update time in seconds		
			fprintf(gnuplotPipe, "pause 0.02\n");
			// flushing the pipe means that we push the commands straight away to
			//gnuplot rather than waiting for some internal buffer to be filled with
			//a certain number of commands
			fflush(gnuplotPipe);
		}
		
		fprintf(stderr,"Press enter to continue...");  
		fflush(stderr);
		getchar(); //wait for user to press enter  
		
		// exit gnuplot  
		fprintf(gnuplotPipe,"exit \n");  
		pclose(gnuplotPipe);  
	}else{
		cout << endl << "ERROR: Could not open GnuPlot" << endl;
	}
}
