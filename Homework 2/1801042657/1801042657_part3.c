#include <stdio.h>
#include <stdlib.h>
#define  Euro 6.69
#define  Dollar 6.14

int main()
{
    printf("***** Welcome to ABC Exchange Office *****\n");

    float amount;
    printf("\nEnter your amount:\n");     // Writing the amount of money.
    scanf("%f",&amount);

    int choice_1;
    printf("\nPlease select your currency:\n");
    printf("1. Turkish Lira\n2. Euro\n3. Dollar\n");
    scanf("%d",&choice_1);

    switch(choice_1){         // User is choosing the money type which he/she has.

        case 1:
            printf("\nYou have %f Turkish Liras.\n",amount);
            break;

        case 2:
             printf("\nYou have %f Euro.\n",amount);
             break;

        case 3:
            printf("\nYou have %f Dollar.\n",amount);
            break;

        default:
            printf("\nYour selection is invalid!\n");

    }

    int choice_2;
    printf("Choose which currency you want to convert:\n");
    scanf("%d",&choice_2);

    switch(choice_2){          // Converting the money to the other type.

        case 1:             // Converting the money to Turkish Lira...
            if(choice_1==1){
                printf("\nYou already have %f Turkish Liras.\n",amount);
            }
            else if(choice_1==2){
                printf("\nYou have %f Turkish Liras.\n",amount*Euro);
            }
            else if(choice_1==3){
                 printf("\nYou have %f Turkish Liras.\n",amount*Dollar);
            }
            break;


        case 2:             // Converting the money to Euro...
            if(choice_1==1){
                printf("\nYou have %f Euro.\n",amount/Euro);
            }
            else if(choice_1==2){
                printf("\nYou already have %f Euro.\n",amount);
            }
            else if(choice_1==3){
                 printf("\nYou have %f Euro.\n",(amount/Euro)*Dollar);
            }
            break;


        case 3:             // Converting the money to Dollar...
            if(choice_1==1){
                printf("\nYou have %f Dollar.\n",amount/Dollar);
            }
            else if(choice_1==2){
                printf("\nYou have %f Dollar.\n",(amount/Dollar)*Euro);
            }
            else if(choice_1==3){
                 printf("\nYou already have %f Dollar.\n",amount);
            }
            break;

        default:
            printf("\nYour selection is invalid!\n");

    }

    return 0;
}
