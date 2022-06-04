#include <stdio.h>
#include <math.h>

//this function converts octal numbers to binary numbers for my kernel
long ocatlToBinary(int octalnum)
{
    int decimalnum = 0, i = 0;
    long binarynum = 0;

    //this loop conbverts octal number "Octalnum" to the
    //decimal number "decimalnum"
    while(octalnum != 0)
    {
        decimalnum = decimalnum + (octalnum%10) * pow(8,i);
        i++;
        octalnum = octalnum /10;
    }

    //i is re-initialized
    i = 1;

    //this loop converts the decimal number "decimalnum" to the
    //number "binarynum"
    while(decimalnum != 0)
    {
        binarynum = binarynum + (decimalnum % 2) * i;
        decimalnum = decimalnum / 2;
        i = i * 10;
    }
    //returning the binary number that we got from octal number
    return binarynum;
}
int main()
{
    int octalnum;

    printf("Enter an octal number: ");
    scanf("%d", &octalnum);

    //calling the function octalTobinary
    printf("Equivalent binary number is: %ld", octalTobinary(octalnum));

    return 0;
}
