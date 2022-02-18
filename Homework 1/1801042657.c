#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* PART 1 */

// The roots of the given equation is calculated by this function:

void find_root(){

    int co_1,co_2,co_3;

    printf("Please enter the first coefficient:\n");
    scanf("%d",&co_1);                                     // co_1 is the coefficient of x^2.

    printf("Please enter the second coefficient:\n");
    scanf("%d",&co_2);                                     // co_2 is the coefficient of x.

    printf("Please enter the third coefficient:\n");
    scanf("%d",&co_3);                                     // co_3 is the fixed number.

    float delta,root_1,root_2;

    delta=co_2*co_2-4*co_1*co_3;             // We use the delta to guess the roots of the equation.
    root_1=((-co_2+sqrt(delta))/(2*co_1));   // root_1 and root_2 are the roots of the equation.
    root_2=((-co_2-sqrt(delta))/(2*co_1));

    // If d>0, the equation has two different real roots(root_1,root_2).
    if(delta>0){
        printf("Your equation %dx^2 + %dx + %d have real roots {%.1f,%.1f}.\n\n",co_1,co_2,co_3,root_1,root_2);
    }

    // If d=0, the equation has two real roots, but they are the same(root_1=root_2).
    else if(delta==0){
        printf("Your equation %dx^2 + %dx + %d have a real root {%.1f}.\n\n",co_1,co_2,co_3,root_1);
    }

    //If d<0, the equation has *no* real root, but it has complex roots.
    else {
        printf("Your equation %dx^2 + %dx + %d does not have any real roots.\n\n",co_1,co_2,co_3);
    }
}

/* PART 2 */

// Iterative root-finding algorithm - Newton's Algorithm

void find_newtonian_root(){

    int a,b,c,x0;

    printf("Please enter the first coefficient:\n");
    scanf("%d",&a);                                   // a is the coefficient of x^2.

    printf("Please enter the second coefficient:\n");
    scanf("%d",&b);                                   // b is the coefficient of x.

    printf("Please enter the third coefficient:\n");
    scanf("%d",&c);                                   // c is the fixed number.

    printf("Please enter the initial:\n");
    scanf("%d",&x0);                                  // x0 is the initial guess which is written by user.


float x,x1,x2,x3,x4,x5;      // These are used for estimating actual root by using Newton's Algorithm.
float f1,f2,actualroot,d;    // f1 is the given function, f2 is the derivative of f1, d is the delta of the equation.

x=x0;                        // x0(initial guess) is transferred to x which is in the given function.
f1=a*(pow(x,2)) + b*x + c;   // Given function(f1)
f2=2*a*x + b;                // Derivative of given function(f2)
x1=x-(f1/f2);                // Formula of the Newton's Algorithm

x=x1;                        // Applying the same step 4 more time.
f1=a*(pow(x,2)) + b*x + c;
f2=2*a*x + b;
x2=x1-(f1/f2);

x=x2;
f1=a*(pow(x,2)) + b*x + c;
f2=2*a*x + b;
x3=x2-(f1/f2);

x=x3;
f1=a*(pow(x,2)) + b*x + c;
f2=2*a*x + b;
x4=x3-(f1/f2);

x=x4;
f1=a*(pow(x,2)) + b*x + c;
f2=2*a*x + b;
x5=x4-(f1/f2);

d=pow(b,2)-4*a*c;                // Using delta for calculating the real root.
actualroot=(-b+sqrt(d))/(2*a);   // Calculating the real root to compare with the estimated root.

// Printing the results...
printf("Step \t   x \t\t  f(x)\t\tDifference \n");
printf("x1\t %.4f \t",x1);                        // x1 is the estimated root, but it differs from actual root.
printf("%.5f \t",a*(pow(x1,2))+ b*x1 + c);        // x1 is putting into the function.
printf("%.4f \n",x1-actualroot);                  // Difference between the actual root and the estimated root.

printf("x2\t %.4f \t",x2);
printf("%.5f \t",a*(pow(x2,2))+ b*x2 + c);
printf("%.4f \n",x2-actualroot);              // These steps are repeated until we reach the actual root.

printf("x3\t %.4f \t",x3);
printf("%.5f \t",a*(pow(x3,2))+ b*x3 + c);
printf("%.4f \n",x3-actualroot);

printf("x4\t %.4f \t",x4);
printf("%.5f \t",a*(pow(x4,2))+ b*x4 + c);
printf("%.4f \n",x4-actualroot);

printf("x5\t %.4f \t",x5);
printf("%.5f \t",a*(pow(x5,2))+ b*x5 + c);
printf("%.4f \n\n",x5-actualroot);

}


/* PART 3 */

//Divisibility of the first integer by the second one is controlled by this function:

int find_multiple_closest(int n1, int n2)
{
    printf("Enter the first integer:\n");
    scanf("%d",&n1);                        // n1 is the first integer which will be tested its divisibility.
    printf("Enter the second integer:\n");
    scanf("%d",&n2);                        // n2 is the second integer which is used for divisibility test.

	int remaining_num,nearest_num;     // remaining_num is the remainder of division.
                                       // nearest_num is the nearest number to n1 and it is multiple of n2.

	if(n1 % n2 == 0)      // If remainder is equal to zero, n1 is multiple of n2.
    {
		printf("Closest number to %d that is multiple of %d is itself.",n1,n2);
    }

	else                // If n1 is not multiple of n2, there must be a remainder.
	{
	    remaining_num = n1 % n2;

    if(remaining_num > n2 / 2)     // If the remainder is greater than half of the second integer, we make this assignment.
    {
        nearest_num = n1 + (n2 - remaining_num);

        printf("Closest number to %d that is multiple of %d is %d.\n",n1,n2,nearest_num);
    }

    else if(remaining_num < n2 / 2)    // If the remainder is smaller than half of the second integer, nearest_num is smaller than half of the second integer.
    {
        nearest_num = n1 - remaining_num;

        printf("Closest number to %d that is multiple of %d is %d.\n",n1,n2,nearest_num);
    }

    else
    {
        nearest_num = n1 + remaining_num;

        printf("Closest number to %d that is multiple of %d is %d.\n",n1,n2,nearest_num);
    }
}

return 1;
}


int main()
{
    printf("\t\t\t\t\t CSE102 Homework #1 \n");

    /* PART 1 */

    printf("PART 1:\n");

    find_root();


    /* PART 2 */

    printf("PART 2:\n");

    find_newtonian_root();


    /* PART 3 */

    printf("PART 3:\n");

    int n1,n2;

    find_multiple_closest(n1,n2);

    return 0;
}

