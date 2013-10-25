gsl-build()
{
 if test -n "$*"
 then 
    g++ -I/usr/include -lgsl -lgslcblas -lm $*  
 else
    echo Usage: gsl-build [g++ options]
 fi
}
