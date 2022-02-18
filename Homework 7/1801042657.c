#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu(char name_of_game[2000][100], char genre_of_game[12][20], char platform_of_game[10][20], float float_data[2000][7]);
void data_of_games(char data_all[2000][200]);
void names_of_games(char data_all[2000][200], char name_of_game[2000][100]);
void genre_of_games(char data_all[2000][200], char genre_of_game[12][20]);
void platform_of_games(char data_all[2000][200],char platform_of_game[10][20]);
void float_data_of_games(float float_data[2000][7], char data_all[2000][200], char genre_of_game[12][20],char platform_of_game[10][20]);

int main()
{
    float float_data[2000][7];
    char name_of_game[2000][100], genre_of_game[12][20], platform_of_game[10][20], data_all[2000][200];

    data_of_games(data_all);
	names_of_games(data_all, name_of_game);

	data_of_games(data_all);
	genre_of_games(data_all, genre_of_game);

	data_of_games(data_all);
	platform_of_games(data_all, platform_of_game);

	data_of_games(data_all);
	float_data_of_games(float_data, data_all, genre_of_game, platform_of_game);

	menu(name_of_game, genre_of_game, platform_of_game, float_data);

    return 0;
}


void menu(char name_of_game[2000][100], char genre_of_game[12][20], char platform_of_game[10][20], float float_data[2000][7])
{
    float average;
    char name[20];
    int i, flag=1, flag_2, operation, operation_2, time, genre, platform;

    while(flag==1){

    printf("0: List of the Genres \n");
    printf("1: List of the Platforms \n");
    printf("2: List of the Games Through the Years \n");
    printf("3: All Informations of a Single Game \n");
    printf("4: Average of the User Scores \n");
    printf("5: Georographical Information of a Single Game \n");
    printf("6: Frequence of the Genres \n");
    printf("7: Frequence of the Platforms \n");
    printf("8: Exit \n");

    printf("\nPlease select an operation: ");
    scanf("%d",&operation);

    switch(operation)
    {
        case 0:
            for(i=0; i<12; i++){
				printf("%s\n",genre_of_game[i]);
			}
			break;

        case 1:
			for(i=0; i<10; i++){
				printf("%s\n",platform_of_game[i]);
			}
			break;

        case 2:
			printf("Enter a year:\n");
			scanf("%d",&time);
			printf("Until(0) or Since(1) %d :",time);
			scanf("%d",&operation_2);
			if(operation_2==1){
				for(i=0; i<2000; i++){
					if(float_data[i][2] >= time)
						printf("%s\n",name_of_game[i] );
					else
						printf("\nTRY AGAIN!!!\n");
						break;
				}
			}

			else if(operation_2==0){
				for(i=0; i<2000; i++){
					if(float_data[i][2] < time)
						printf("%s\n",name_of_game[i] );
					else
						printf("\nTRY AGAIN\n");
						break;
				}
			}

			else
				printf("Invalid operation!\n");

			break;

        case 3:
			printf("Please enter the name of game:\n");
			scanf("%s",&name);

			for(i=0; i<2000; i++){
				if(strcmp(name_of_game[i],name)==0)
					break;
			}

			genre=float_data[i][0];
			platform=float_data[i][1];

			printf("Name :	%s\n",name_of_game[i] );
			printf("Genre :	 %s\n",genre_of_game[genre] );
			printf("Platform :	%s\n",platform_of_game[platform] );
			printf("Year :	%.0lf\n",float_data[i][2] );
			printf("Sales In NA :	%lf\n",float_data[i][3] );
			printf("Sales IN EU :	%lf\n",float_data[i][4] );

			if(float_data[i][5]=='*'){
				printf("Total Sales :	Not_Available\n");
			}
			else{
				printf("Total Sales : 	%lf\n",float_data[i][5] );
			}
			printf("User Score :	%lf\n",float_data[i][6] );

			break;

        case 4:
			average = 0;
			for(i=0; i<2000; i++){
				average += float_data[i][6];
			}
			average/=2000;
			printf("Average :	%lf\n",average);
			break;

        case 5:
			flag_2=0;
			while(flag_2==0){

				printf("Please enter the name of game:\n");
				scanf("%s",&name);

				for(i=0;i<2000;i++){
					if(strcmp(name_of_game[i],name)==0){
						flag_2=1;
						break;
					}
				}

				if(flag_2==1){
					if(float_data[i][3]>float_data[i][4]){
						printf("This game was more popular in North America\n");
					}
					else if(float_data[i][4]>float_data[i][3]){
						printf("This game was more popular in Europe\n");
					}
					else{
						printf("This game was popular in both Europe and North America\n");
					}
				}

			}
			break;

        case 6:
            printf("I can't\n");
			break;

        case 7:
            printf("I can't");
            break;

        case 8:
            flag=0;
            break;

        default:
            printf("\nTRY AGAIN!\n\n");
            break;

    }
  }

}


void data_of_games(char data_all[2000][200]){

	int i=0;
	char temp[1][200];

	FILE *fp = fopen("Video_Games.txt","r");
	fscanf(fp,"%s",temp[0]);

	while(!feof(fp)){
		fscanf(fp,"%s",data_all[i]);
		i++;
	}

	fclose(fp);
}


void names_of_games(char data_all[2000][200], char name_of_game[2000][100])
{
    char *token, *info;
    int i;

    for(i=0;i<2000;i++){
        info = data_all[i];
        token = strtok_r(info,",",&info);
        strcpy(name_of_game[i], token);
    }

}


void genre_of_games(char data_all[2000][200], char genre_of_game[12][20])
{
    char genres[2000][20], *info, *token;
    int i, j=0, ret;

	for(i=0,j=0; i<2000; i++,j++){
		info = data_all[i];
		token = strtok_r(info,",",&info);
		token = strtok_r(info,",",&info);
		strcpy(genres[j], token);
	}

	for(i=0; i<1999; i++){
		for(j=i+1; j<2000; j++){
			ret = strcmp(genres[i], genres[j]);
                if(ret==0){
                    strcpy(genres[j], "*");
                }
		}
	}

	for(i=0,j=0;i<2000;i++){
		if(strcmp(genres[i],"*") != 0){
			strcpy(genre_of_game[j], genres[i]);
			j++;
		}
	}
}

void platform_of_games(char data_all[2000][200],char platform_of_game[10][20])
{
    char platforms[2000][20], *info, *token;
    int i, j=0, ret;

	for(i=0,j=0; i<2000; i++,j++){
		info=data_all[i];
		token =strtok_r(info,",",&info);
		token =strtok_r(info,",",&info);
		token =strtok_r(info,",",&info);
		strcpy(platforms[j],token);
	}

	for(i=0; i<1999; i++){
		for(j=i+1; j<2000; j++){
			ret = strcmp(platforms[i],platforms[j]);
			if(ret==0){
				strcpy(platforms[j], "*");
			}
		}
	}

	for(i=0,j=0; i<2000; i++){
		if(strcmp(platforms[i], "*") != 0){
			strcpy(platform_of_game[j], platforms[i]);
			j++;
		}
	}

}


void float_data_of_games(float float_data[2000][7], char data_all[2000][200], char genre_of_game[12][20],char platform_of_game[10][20])
{
    char *info, *token;
    int i, j, k, l;

	for(i=0,l=0;i<2000;i++,l++){

		info=data_all[i];
		token=strtok_r(info,",",&info);
		token=strtok_r(info,",",&info);

		for(j=0;j<12;j++){
			if(strcmp(token,genre_of_game[j])==0){
				float_data[l][0]=j;
				break;
			}
		}

		token=strtok_r(info,",",&info);
		for(k=0;k<10;k++){
			if(strcmp(token,platform_of_game[k])==0){
				float_data[l][1]=k;
				break;
			}
		}

		token=strtok_r(info,",",&info);
		float_data[l][2]=strtof(token,NULL);
		token=strtok_r(info,",",&info);
		float_data[l][3]=strtof(token,NULL);
		token=strtok_r(info,",",&info);
		float_data[l][4]=strtof(token,NULL);
		token=strtok_r(info,",",&info);

		if(strcmp(token,"not_available")==0){
			float_data[l][5]='*';
		}
		else{
			float_data[l][5]=strtof(token,NULL);
		}

		token=strtok_r(info,",",&info);
		float_data[l][6]=strtof(token,NULL);

	}
}



