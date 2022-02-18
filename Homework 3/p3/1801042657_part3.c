#include<stdio.h>

int length(int a)   // It calculates the length of the number.
{
	int num_of_dig=0;   // num_of_dig is the number of digits of the integer.

	while(a>0){
		a/=10;
		num_of_dig++;
	}
	return num_of_dig;
}


int check_binary(int a,int b)
{
	int control = 1;    // Control is used for checking the integers are binary or not.
	while(control==1){  // Looping the operation..
		if((a%10==1 || a%10==0) && (b%10==1 || b%10==0)){   // Binary numbers are consist of 1 and 0 that's why I used mod 10.
			a/=10;
			b/=10;
			if(a<1 || b<1)    // The situation where the remainder less than 1.
			{
				control=0;
			}
		}
		else{
			return 0;   // One or both numbers are not binary.
		}
	}
	return 1;
}


int exponent(int number)   // This function is used to get base of 10.We will use later on AND function.
{
	int exponent=1;
	while(number>1){
		exponent*=10;
		number--;
	}
	return exponent;
}


int andop(int a,int b)    // It is used for implementing logical AND operation on the integers
{
    int conclusion = 0; // The function will return to the conclusion.
	int counter = 1;    // For loop
	int total = a+b;    // Let we consider a=1011 and b=1101.(1011 + 1101 = 2112 = total)

	while(counter<=length(a)){    // It is used to determine how many times we will do the process.
		int i = total % 10;       // 2112 % 10 = 2 (So that i=2)
		if(i==2)
		{
			conclusion += exponent(counter);    /* 1011+1101=2112 -> 10^0+10^3=1001(CONCLUSION) -> Power is determined by (digit-1)
                                                Power of 10 is equal to 0 and 3 because 1.th and 4.th digit is equal to 2.*/
		}
		total/=10;
		counter++;
	}
	return conclusion;
}


int main(){

	int a,b;

	printf("First integer:");   // Entering the 2 binary numbers..
	scanf("%d",&a);
	printf("Second integer:");
	scanf("%d",&b);

    if(check_binary(a,b)==0)   // If the integers are not binary, the function returns the zero(0).
	{
		printf("Integers should be binary, please enter 2 new integers\n");

		printf("First integer: ");
		scanf("%d",&a);
		printf("Second integer: ");
		scanf("%d",&b);
	}


	if(length(a)!=length(b))   // Comparing the length of the integers..
	{
	    printf("Integers should have the same length, please enter 2 new integers.\n");

		printf("First integer: ");
		scanf("%d",&a);
		printf("Second integer: ");
		scanf("%d",&b);

	}

	printf("%d AND %d = %d\n",a,b,andop(a,b));    // Implementing AND operation on the integers.

	return 0;
}

