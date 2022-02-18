#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct card {
const char *face;
const char *suit;
};
struct card deck[52];

void menu();
int numPathsHome(int street, int avenue);
void shuffle_cards();
void display_cards();

int main()
{
    srand(time(NULL));
    menu();
    return 0;
}


void  menu(){

    int choice,street,avenue,i;
    char *suit[]={"Hearts","Diamonds","Clubs","Spades"};
    char *face[]={"Ace","Deuce","Three","Four",
    "Five","Six","Seven","Eight","Nine",
    "Ten","Jack", "Queen", "King"};

    printf("HOMEWORK 9\n----------\n");
    while(1){
    printf("1)Stay Home Problem\n");
    printf("2)COVID-19 Health Coverage\n");
    printf("3)Card Game\n");
    printf("4)Exit\n");
    printf("----------------------\n");
    printf("Please select the part:\n");
    scanf("%d",&choice);

    switch(choice){

        case 1:
            printf("Enter the street number: ");
            scanf("%d",&street);
            printf("street:%d\n",street);
            printf("Enter the avenue number: ");
            scanf("%d",&avenue);
            printf("avenue:%d\n",avenue);

            if(street==1 && avenue==1)
                printf("***You're at home:)\n\n");
            if(street>5 || avenue>5)
                printf("***You entered wrong address:(\n\n");
            else
                printf("Number of optimal paths to take back home: %d\n\n",numPathsHome(street,avenue));

            break;

        case 2:
            printf(">>>I couldn't:(\n\n");
            break;

        case 3:
            for(i=0;i<=51;i++){
                deck[i].face=face[i%13];
                deck[i].suit=suit[i/13];
            }
            shuffle_cards();
            display_cards();
            printf("\n");
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("**INVALID ENTRY!**\n\n");
            break;

    }
  }
}

/*--------PART 1----------*/

int numPathsHome(int street, int avenue){

    double temp;

    /* The idea of this operations is: (x+y)!/(x!)*(y!) */
    if(avenue>street)   // x > y
    {
		temp=(street+avenue)-2;
		if(temp==avenue-1 || street<1)   return 1;
		else    return (temp/(street-1)) * numPathsHome(street-1, avenue);  // Recursive part
	}

    if(avenue<street)   // x < y
    {
		temp=(street+avenue)-2;
		if(temp==street-1 || avenue<1)   return 1;
		else    return (temp/(avenue-1)) * (numPathsHome(street, avenue-1));
	}

	else    // x = y
    {
		temp=(street+avenue)-2;
		return (temp/(street-1)) * numPathsHome(street-1, avenue);
	}

}

/*------PART 3---------*/

void shuffle_cards(){   /* This function is used for shuffling the cards */

    int i,j;
    struct card temp;   // It is used for swapping.

	for(i=0;i<=51;i++){
		j = rand() % 52;
		/* Mixing the cards */
		temp.face = deck[i].face;
		temp.suit = deck[i].suit;
		deck[i].face = deck[j].face;
		deck[i].suit = deck[j].suit;
		deck[j].face = temp.face;
		deck[j].suit = temp.suit;
	}

}

void display_cards(){    /* Printing the shuffled cards */

    int i;

	for(i=0;i<=51;i++){
		printf("%5s of %-10s",deck[i].face, deck[i].suit);
		if((i+1)%2==0)
            printf("\n");
        else
            printf("\t");
	}
}
