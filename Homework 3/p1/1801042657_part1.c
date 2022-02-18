#include <stdio.h>
#include <stdlib.h>

int sum(int n,int flag){

    int result,i;

    switch(flag){

        case 0:
                result=2;
			    printf("%d",result);

                for(i=4;i<=n;i+=2){       // Even numbers
                printf(" + %d",i);
                result+=i;
                }
                printf(" = %d",result);
                break;

        case 1:
                result=1;
                printf("%d",result);

                for(i=3;i<=n;i+=2){       // Odd numbers
				result+=i;
				printf(" + %d",i);
                }
                printf(" = %d",result);
                break;

        default:
                printf("Invalid value for odd/even selection\n");
                break;

    }

    return result;
}

int mult(int n,int flag){

    int i,result;

	switch(flag){

		case 0:
                result=2;
                printf("%d",result);

                for(i=4;i<=n;i+=2){      // Even numbers
				printf(" * %d",i);
				result*=i;
                }
                printf(" = %d",result);
                break;

		case 1:
                result=1;
                printf("%d",result);

                for(i=3;i<=n;i+=2){      // Odd numbers
				result*=i;
				printf(" * %d",i);
                }
                printf(" = %d",result);
                break;

		default:
                printf("Invalid value for odd/even selection.\n");
                break;
	}

	return result;
}


int main()
{
    int n,flag,operation_flag;

    printf("Enter an integer: ");    // n is an integer which is the top of the range [1,N].
    scanf("%d",&n);

    printf("Please enter '0' for sum, '1' for multiplication:\n");
    scanf("%d",&operation_flag);

    printf("Please enter '0' to work on even numbers, '1' to work on odd numbers:\n");
    scanf("%d",&flag);


    switch(operation_flag){

        case 0:
                sum(n,flag);     // It calculates the sum of the numbers.
                break;

        case 1:
                mult(n,flag);    // It calculates the multiplication of the numbers.
                break;

        default:
                printf("Unsupported operation.");
    }

    return 0;
}
