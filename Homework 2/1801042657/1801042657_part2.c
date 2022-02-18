#include <stdio.h>
#include <stdlib.h>
#include <math.h>

 int number_length(int number){    // The function that calculates the length of the given number.

 	int temp = log10(number);   // Ex: log10(123456)=5.09

 	return temp+1;        // It is used for rounding up to a big number(5.09->6)

 }


 int find_digit(int number,int index){     // The function that finds the number in the specified index.

 	int length,conclusion,remainder;

 	length = number_length(number);   // By using the length function, we find the length.

 	remainder = index % length;

    conclusion = number / pow(10,(length-remainder));   // In order to obtain the number in a certain index within the number, we can apply this equation.

 	if(conclusion<1){

       return number % 10;   // If the remainder is equal to zero, it must give us the last digit.

 	}

 	return conclusion %= 10;
 }


int main(){

	int number,index,digit;

    printf("Enter a number (maximum 6 digits):\n");
    scanf("%d",&number);

    digit=number_length(number);

    if(digit<=6){

        printf("\nYour number has %d digits.\n",digit);

        printf("\nWhen your number is written 100 times next to each other, which digit of the number would you like to see? :\n");
        scanf("%d",&index);

        printf("\n%d.th digit of the big number sequence: %d\n",index,find_digit(number,index));
    }

    else{

        printf("\nYour number is invalid. Please enter a number which has maximum 6 digits.\n");

    }

    return 0;
}
