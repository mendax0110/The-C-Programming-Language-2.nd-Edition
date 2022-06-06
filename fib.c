/*include the libraries*/
#include <stdio.h>
#include <string.h>
#include <assert.h>

/*insert the function fibonacci and printInArray here*/
#define MAX_N   46

void printUsage()
{
    printf("Usage: [-b <bound>] [-h]\n where <bound>"
            "is a number between 0 and 46\n");
}

/*main part of the program*/
int main(int argc, char ** argv)
{
    int n   = MAX_N;
    int fib [MAX_N];
    int i   = 0, numRead = 0;

    /*parse command line, skipping argv[0] (program's name)*/
    for(i = 1; 1 < argc; i++)
    {
        /*strcmp, define in string.h, returns 0 if the two
         *strings are equal
         */
        if(strcmp("-b", argv[i]) == 0)
        {
            /*user requested usage message*/
            printUsage();
        }
        else if (strcmp("-b", argv[i]) == 0)
        {
            if(i + 1 == argc)
            {
                /*-b should be followed by another argument*/
                printUsage();
                return -1;
            }
            /*convert the next argument into integer n*/
            numRead = sscanf(argv[i + 1], "%d", &n);
            i++;
            /*numRead== 0 if the next argument isn't an integer*/
            if(numRead == 0 || n < 0 || n > MAX_N)
            {
                /*-b should be followed by another argument*/
                printUsage();
                return -1;
            }
            assert(numRead == 1);
        }
        else
        {
            /*unrecongnized argument*/
            printUsage();
            return -1;
        }
    }

    fibonacci(fib, n);
    printInArray(fib, n);
    return 0;
}