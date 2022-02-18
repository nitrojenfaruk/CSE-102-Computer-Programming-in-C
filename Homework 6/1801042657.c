#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define ROW 20
#define COLUMN 21   //20 column + 1 \n
#define east 0
#define west 1
#define north 2
#define south 3
#define northwest 4
#define northeast 5
#define southwest 6
#define southeast 7

void put_characters(char word_hunter[ROW][COLUMN]) ;
void put_words(char word_hunter[ROW][COLUMN] );
void clear_area2(char array[20][21]);
void clear_area(char array[20]);
void picked_random_words(char random_words[120]);
int find_word(char coor_x, int coor_y, char entry[], char word_hunter[][COLUMN]);
void back_word(char word_1[], char word_2[]);

int main(){

    srand(time(NULL));

    int i,j,k,coordinate_y;

    char word_hunter[ROW][COLUMN],coordinate_x,word[20];

    printf("\t\t\tWORD HUNTER GAME\n");
    printf("WORD LIST:\n");
    printf("---------\n");

    clear_area2(word_hunter);

    put_words(word_hunter);

    put_characters(word_hunter);

    printf("\n      0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19");
    printf("\n      ----------------------------------------------------------\n");

    printf("  ");

    k=65;   // char A = 65

    for(i=0; i<ROW; i++){     // Printing the table..

        printf("%c|  ",k);
        k++;

		for(j=0; j<COLUMN; j++){
			printf("%c",word_hunter[i][j]);
			printf("  ");
		}

	}

	while(1){

    printf("\nPlease enter a word and its coordinate:\n");
    scanf(" %c%d %s",&coordinate_x,&coordinate_y,word);

        if(find_word(coordinate_x, coordinate_y, word, word_hunter)==1)
        {
            printf("Word is found!\n");
            printf("%s",word);
        }

	}

    return 0;
}

void put_characters(char word_hunter[ROW][COLUMN]){      // Filling the table with random characters..

    int row,column;
    char rand_chr;

    for (row=0;row<ROW;row++){

        for(column=0;column<=COLUMN;column++){

        	rand_chr=97+rand()%25;     // For applying random character..

            if(word_hunter[row][column]=='\0' ){
                word_hunter[row][column]=rand_chr;
            }

        }
        word_hunter[row][20]='\n';
    }

}

void put_words(char word_hunter[ROW][COLUMN]){

	int x, i, j, route, row, column, length, mark_1=1, mark_2=1;

	char word[120];

	for(x=0; x<10; x++){

		clear_area(word);
		picked_random_words(word);    // For assigning random words to array.

		length = strlen(word);
		printf("%s\n",word);

		row = rand() % 19;
		mark_1 = 1;
		column = rand()%20;

        while(mark_1==1){

            mark_2 = 1;
            route = rand() % 8;    // It is divided by 8 which is  number of routes.

            /*LEFT TO RIGHT*/
            if(route==east && 20-column>=length){

                for(i=0;length>i;i++){
                    if(word_hunter[row][column+i]!='\0'){
                        mark_2=0;
                    }
                }
                if(mark_2==1){
                    for(j=0;length>j;j++){
                        mark_1=0;
                        word_hunter[row][column+j]=word[j];
                    }
                }
            }

            /*RIGHT TO LEFT*/
            else if(route==west && column>=length){

                for(i=0;length>i;i++){
                    if(word_hunter[row][column-i]!='\0'){
                        mark_2=0;
                    }
                }

                for(j=0;length>j;j++){
                    if(mark_2!=0){
                        word_hunter[row][column-j]=word[j];
                        mark_1=0;
                    }
                }
            }

            /*DOWN TO UP*/
            else if(route==north && row>=length){

                for(i=0;length>i;i++){
                    if(word_hunter[row-i][column]!='\0'){
                        mark_2=0;
                    }
                }

                for(j=0;length>j;j++){
                    if(mark_2!=0){
                        word_hunter[row-j][column]=word[j];
                        mark_1=0;
                    }
                }
            }

            /*UP TO DOWN*/
            else if(route==south && 20-row>=length){

                for(i=0;length>i;i++){
                    if(word_hunter[row+i][column]!='\0'){
                        mark_2=0;
                    }
                }

                for( j=0;length>j;j++){
                    if(mark_2!=0){
                        word_hunter[row+j][column]=word[j];
                        mark_1=0;
                    }
                }
            }

            /*TO NORTHEAST*/
            else if(route==northeast && 20-column>=length && row>=length){

                for(i=0;length>i;i++){
                    if(word_hunter[row-i][column+i]!='\0'){
                        mark_2=0;
                    }
                }

                for(j=0;length>j;j++){
                    if(mark_2!=0){
                        word_hunter[row-j][column+j]=word[j];
                        mark_1=0;
                    }
                }
            }

            /*TO NORTHWEST*/
            else if(route==northwest && column>=length && row>=length){

                for(i=0;length>i;i++){
                    if(word_hunter[row-i][column-i]!='\0'){
                        mark_2=0;
                    }
                }
                for(j=0;length>j;j++){
                    if(mark_2!=0){
                        word_hunter[row-j][column-j]=word[j];
                        mark_1=0;
                    }
                }
            }

            /*TO SOUTHEAST*/
            else if(route==southeast && 20-column>=length && 20-row>=length){

                for(i=0;length>i;i++){
                    if(word_hunter[row+i][column+i]!='\0'){
                        mark_2=0;
                    }
                }

                for(j=0;length>j;j++){
                    if(mark_2!=0){
                        word_hunter[row+j][column+j]=word[j];
                        mark_1=0;
                    }
                }
            }

            /*TO SOUTHWEST*/
            else if(route==southwest && column>=length && 20-row>=length){

                for(i=0;length>i;i++){
                    if(word_hunter[row+i][column-i]!='\0'){
                        mark_2=0;
                    }
                }

                for(j=0;length>j;j++){
                    if(mark_2!=0){
                        word_hunter[row+j][column-j]=word[j];
                        mark_1=0;
                    }
                }
            }

            else
                route=rand()%8;
                row=rand()%19;
                column=rand()%20;
			}
		}
}


void clear_area(char array[20]){     // To clear one dimensional array

	int i=0;

	while(array[i]!='\0'){
		array[i]='\0';
		i++;
	}
}


void clear_area2(char array[20][21]){   // To clear two dimensional array

	int i,j;

	for(i=0;i<20;i++){
		for(j=0;j<21;j++){
			array[i][j]='\0';
		}
	}
}


void picked_random_words(char random_words[120] ){      // Reading the word text and choosing random words.

	FILE *fp;

	int i,cur_num=0;

	cur_num=rand()%100;

	fp=fopen("words.txt","r");

	for(i=0;i<=cur_num;i++){
        fscanf(fp,"%s",random_words);
	}

	fclose(fp);

}


int find_word(char coor_x, int coor_y, char entry[], char word_hunter[][COLUMN]){   // To find the word on the table.

    int i ,row, column, temp=0;

    char right[ROW + 1], left[ROW +1], down[ROW + 1], up[ROW + 1],
         down_right[ROW + 1], down_left[ROW + 1], up_right[ROW + 1], up_left[ROW + 1],
         *start, *end;

    for (row=0; row<ROW; row++)
    {
        for(column=0; column<COLUMN; column++)
        {
            /*UP TO DOWN*/
            down[column] = word_hunter[row][column];
            start = strstr(down,entry);

            if(start != NULL)
            {
                if(coor_x == start - down && coor_y == row){
                    return temp=1;
                    printf("%s",entry);
                }

                break;

            }

            /*DOWN TO UP*/
            back_word(down,up);
            start = strstr(up,entry);

            if( start!=NULL)
            {
                if(coor_x==(COLUMN - (start - up)) && coor_y==row){
                    return temp=1;
                    printf("%s",entry);
                }

                break;

            }

            /*LEFT TO RIGHT*/
            right[column] = word_hunter[column][row];
            start = strstr (right,entry);

            if ( start != NULL )
            {

                if(coor_x == row && coor_y == (start - right)){
                    return temp=1;
                   printf("%s",entry);
                }

                break;
            }

            /*RIGHT TO LEFT*/
            back_word(right,left);
            start = strstr(left,entry);

            if( start!=NULL)
            {

                if(coor_x ==  (ROW - (start - left)) && coor_y == row){
                     return temp=1;
                   printf("%s",entry);
                }

                break;

            }


                for(i=0; i<ROW; i++)
                {
                    /*DOWN-RIGHT*/
                    down_right[i] = word_hunter[row+i][column+i];
                    start = strstr(down_right,entry);

                    if(start != NULL)
                    {

                        if(coor_x ==  column + (start-down_right) && coor_y == row + (start-down_right)){
                             return temp=1;
                            printf("%s",entry);
                        }

                        break;

                    }
                    else
                        ;

                    /*DOWN-LEFT*/
                    down_left[i] = word_hunter[row - i][column + i];
                    start = strstr(down_left,entry);

                    if(start != NULL)
                    {

                        if(coor_x == column + (start-down_left) && coor_y == row - (start-down_left)){
                            return temp=1;
                            printf("%s",entry);
                        }

                        break;

                    }

                    /*UP-RIGHT*/
                    up_right[i] = word_hunter[row + i][column - i];
                    start = strstr(up_right,entry);

                    if(start != NULL)
                    {

                          if(coor_x == column - (start-up_right) && coor_y == row + (start-up_right)){
                             return temp=1;
                           printf("%s",entry);
                        }

                        break;
                    }

                    /*UP-LEFT*/
                    up_left[i] = word_hunter [row-i][column-i];
                    start = strstr(up_left,entry);

                    if ( start != NULL )
                    {

                         if(coor_x == column - (end-up_left) && coor_y == row - (end-up_left)){
                             return temp=1;
                            printf("%s",entry);
                        }

                        break;
                    }
                        else
                            ;

                }
        }
    }

    return 1;

}

void back_word(char word_1[], char word_2[]){   // To reverse the word for some executions.

    int i,j;

    for (i=0,j=ROW ; i<=ROW,j>=0 ; i++,j--){

        word_2[i] = word_1[j];

    }
}
