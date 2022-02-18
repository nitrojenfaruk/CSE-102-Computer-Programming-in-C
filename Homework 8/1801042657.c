#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void menu();
void generate_hofstadters_sequence(int *arr, int n);
int find_max (int arr[], int index, int max_value);
int sum_array (int arr[]);
void fill_zero(int arr[]);
double std_array (int arr[], double *mean, int n, int index);
char* remove_duplicates (char* str);


int main()
{
    menu();
    return 0;
}


void menu(){

    int operation, operation_2, n, i, arr[500], max_num=0, flag=1, index=1;
    double mean=0;
    char dup_sentence[500];

    fill_zero(arr);

    while(flag==1){

    printf("Welcome to Homework 8, please choose one of the parts to continue:\n");
    printf("---------------------\n");
    printf(" 1) Execute Part 1\n");
    printf(" 2) Execute Part 2\n");
    printf(" 3) Execute Part 3\n");
    printf(" 4) Exit\n");
    scanf("%d",&operation);

    switch(operation){

        case 1:

            while(flag==1){

            printf("\nPlease make your choice:\n");
            printf(" -------------------\n");
            printf(" 1) Fill Array\n");
            printf(" 2) Find Biggest Number\n");
            printf(" 3) Calculate Sum\n");
            printf(" 4) Calculate Standard Deviation\n");
            printf(" 5) Exit\n");
            scanf("%d",&operation_2);

            switch(operation_2){

                case 1:   // To generate Hofstadters Sequence.

                    printf("Please enter a value (n) to fill the array up to this number:\n");
                    scanf("%d",&n);
                    generate_hofstadters_sequence(arr,n);
                    for(i=1;i<=n;i++){
                        printf("%d ",arr[i]);
                    }
                    break;

                case 2:   // To find the max number in the sequence.

                    max_num = find_max(arr,n,max_num);
                    printf("Biggest number: %d\n",max_num);
                    break;

                case 3:   // To find the sum of the sequence.

                    printf("Sum: %d\n",sum_array(arr));
                    fill_zero(arr);
                    generate_hofstadters_sequence(arr,n);
                    break;

                case 4:   // To calculate the standard deviation and mean.

                    printf("Standard deviation: %lf\n",std_array(arr, &mean, n, index));
                    printf("Mean: %lf\n",mean);
                    break;

                case 5:    // Exit

                    flag=0;
                    break;

                default:

                    printf("INVALID CHOICE!\n");
                    break;

              }
            }

            flag=1;
            break;


        case 2:

            printf("I COULDN'T...\n");
            break;


        case 3:    // For removing the duplicates from the word or sentence.

            printf("Please enter a sentence or a word to remove the duplicated characters in that string:\n");
            scanf(" %[^\n]s",dup_sentence);
            printf("%s\n",remove_duplicates(dup_sentence));
            break;


        case 4:     // Exit

            flag=0;
            break;


        default:

            printf("INVALID CHOICE\n");
            break;

       }
    }
}


void fill_zero(int array[500]){   // Filling the array with zero.

    for(int i=0;i<500;i++){
        array[i]=0;
    }

}


void generate_hofstadters_sequence(int *arr, int n){

    if (n<3){       // First two value of Hofstadter sequence are 1.
        arr[1] = 1;
        arr[2] = 1;
    }

    else{
        generate_hofstadters_sequence(arr,n-1);   // Recursive part.
        arr[n] = arr[n-arr[n-1]] + arr[n-arr[n-2]];     // For continuity..
    }
}


int find_max (int arr[], int index, int max_value){

    if(index==0)
        return max_value;

    else{
        if(max_value<arr[index])     // If value is smaller than max , the value will be max.
            max_value=arr[index];

        return find_max(arr, index-1, max_value);   // Return to max value thanks to recursion..
    }
}


int sum_array (int arr[]){

    int *sum;
	sum = arr;

	if(sum[1]!=0){ // Recursive part for sum operation.
		sum[1]=sum[0]+sum[1];
		sum++;
		sum_array(sum);
	}

	else
		return sum[0];

}


double sum=0;

double std_array (int arr[], double *mean, int n, int index){

    int i;
    double SD,x;

    if(index==1){
        *mean = (double)(sum_array(arr))/(double)n;
        fill_zero(arr);    // To clear array
		generate_hofstadters_sequence(arr, n);   // To generate new one
    }

    if(arr[index] != 0){
        x = arr[index] - *mean;
        sum += (pow(x,2));
        std_array(arr, mean, n, index+1);   // Recursive part
    }

    else{
        SD = sqrt(sum/n);
        return SD;
    }
}


char* remove_duplicates (char* str){

    int i=0;
	static char arr[500];

	if(str[0]=='\0')  return str;

	if(str[0]==str[1]){    // If the letter was duplicated, this condition remove the duplicated latter
		while(str[i]!='\0'){
			str[i]=str[i+1];
			i++;
		}
		remove_duplicates(str);   // Recursive part for the duplicates
	}

	else if(str[0]!=str[1])  remove_duplicates(str+1);    // Recursive part for non duplicates

	return str;

}
