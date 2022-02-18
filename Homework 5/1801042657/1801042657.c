#include <stdio.h>
#include <stdlib.h>

void read_news(char buffer[500], char file_path[20], int is_Only_Title);
void clear_buffer(char area[500]);
int read_control(char *file_path, char c);

void append_file(char *file_path, char c);
void read_news_id(char *file_path);

double f_func(int x);
double g_func(double f(int x), int a);
void read_magic_numbers(char buffer_magic[10], char buffer_news[500]);

void menu();

int main()
{
    menu();
    return 0;
}

void menu(){

    int choice;
    char choice_2,choice_3,operation,news[500],*path,*file_path,c,buffer_magic[100];

    clear_buffer(news);
    file_path="readed_news_id.txt";

    printf("*********Daily Press*********\n\n");
    printf("Today's news are listed for you :\n\n");

    path="news/1.txt";              // Displaying the titles of news..
    printf("Title of 1. news:");
    read_news(news,path,1);
    puts(news);

    path="news/2.txt";
    printf("Title of 2. news:");
    read_news(news,path,1);
    puts(news);

    path="news/3.txt";
    printf("Title of 3. news:");
    read_news(news,path,1);
    puts(news);

    path="news/4.txt";
    printf("Title of 4. news:");
    read_news(news,path,1);
    puts(news);

    while(1){

    printf("\nWhat do you want to do?\n");
    printf("a.Read a new\nb.List the readed news\nc.Get decrypted information from the news\n");
    scanf(" %c",&operation);

    switch(operation){

        case 'a':

            printf("Which news do you want to read?\n");
            scanf(" %c",&c);

            switch(c){
                case '1':
                    path="news/1.txt";        // Assigning the locations of news to the path.
                    break;
                case '2':
                    path="news/2.txt";
                    break;
                case '3':
                    path="news/3.txt";
                    break;
                case '4':
                    path="news/4.txt";
                    break;
                default:
                    printf("Invalid choice!");
                    exit(0);
            }

            /* To check whether the news is read or not*/

            if(read_control(file_path,c)==0){    // If the news is read before,this process works like this:

                printf("This new is readed. Do you want to read again? Yes(1)/No(0):\n");
                scanf("%d",&choice);

                if(choice==1){
                    read_news(news,path,0);    // Reading the news again.
                    puts(news);
                }
            }

            else{     // If the news is not read before, id of news is added to the file when it is first read.
                read_news(news,path,0);
                append_file(file_path,c);
                puts(news);
            }
            break;

        case 'b':
					read_news_id(file_path);    // Reading the "readed_news_id.txt" and printing the readed news.

					printf("\nDou you want to continue? Yes(y)/No(n) \n");
					scanf(" %c",&choice_2);

					if(choice_2=='n'){
                        printf("Good bye!");
						exit(0);
					}
                    break;

        case 'c':
                    printf("Which news would you like to decrypt?\n");
                    scanf(" %c",&c);

                    switch(c){
                        case '1':
                            path="news/1.txt";      // Assigning the locations of the news to the path.
                            read_news(news,path,0);
                            puts(news);
                            printf("\nThe number of tests performed: ");
                            break;
                        case '2':
                            path="news/2.txt";
                            read_news(news,path,0);
                            puts(news);
                            printf("\nThe number of sick people: ");
                            break;
                        case '3':
                            path="news/3.txt";
                            read_news(news,path,0);
                            puts(news);
                            printf("\nThe number of deaths: ");
                            break;
                        case '4':
                            path="news/4.txt";
                            read_news(news,path,0);
                            puts(news);
                            printf("\nThe expected number of sick people: ");
                            break;
                        default:
                            printf("Invalid choice!");
                            exit(0);
                    }

                    read_magic_numbers(buffer_magic,news);

                    printf("\nDo you want to continue? Yes(y)/No(n) \n");
                    scanf(" %c",&choice_3);

                    if(choice_3=='n'){
                        printf("Good bye!");
						exit(0);
                    }

        break;

        default:
					printf("Invalid choice!\n");

        }
     }
}


void read_news(char buffer[500], char file_path[20], int is_Only_Title){

    char read_c;
    int i=0;

    FILE *fp=fopen(file_path,"r");
    clear_buffer(buffer);

	if(is_Only_Title==1){   // Reading the only titles of news.

        while(!feof(fp)){

            fscanf(fp,"%c",&read_c);

            if(read_c=='\n'){
                buffer[i]='\0';
                break;
            }


            buffer[i]=read_c;
            i++;
        }
    }

	else if(is_Only_Title==0){    // Reading the whole news.

        fscanf(fp,"%c",&read_c);

        while(!feof(fp)){

            buffer[i]=read_c;
            buffer[i+1]='\0';
            i++;
            fscanf(fp,"%c",&read_c);
		}
	}
	fclose(fp);
}

/* Clearing the buffer for continuity*/
void clear_buffer(char area[500]){

	int i=0;

	while(area[i]!='\0'){
        area[i]='\0';
		i++;
	}
}

/* To check whether the news is read or not*/
int read_control(char *file_path, char c){

	char old_new;

	FILE *fp = fopen(file_path,"r");

	while(!feof(fp)){
        fscanf(fp,"%c",&old_new);
		if(old_new==c)   // The news is read before.
            return 0;
    }

    fclose(fp);
	return 1;    // The news is not read before.
}


void append_file(char *file_path, char c){

	char old_new;

	FILE *fp=fopen(file_path,"r+");

	while(!feof(fp)){
		fscanf(fp,"%c",&old_new);   // For pre_added news
	}

	fprintf(fp,"\n%c",c);   // Adding the id of news which has just read to the file.
	fclose(fp);
}


/*Listing the id of readed news*/
void read_news_id (char *file_path){

    printf("\nReaded news are listed below:\n");

	int new_no;

    FILE *fp=fopen(file_path,"r");

    while(!feof(fp)){
        fscanf(fp,"%d",&new_no);
        printf("%d. new is readed\n",new_no);
    }
    fclose(fp);
}


void read_magic_numbers(char buffer_magic[10],char buffer_news[500]){

	int i=0,j=0,temp;
	double conclusion=0;

	while(buffer_news[i]!='\0'){    // It will continue until the array is finished.

		if(buffer_news[i]=='#'){

			buffer_magic[j] = buffer_news[i+1];    // i+1=after(#)
			temp = buffer_magic[j]-48;    // Converting to integer..
			j++;
			f_func(temp);   // Applying the f function..
			conclusion += g_func(f_func,temp);
		}
		i++;
	}
	printf("%lf",conclusion);
}


double f_func(int x){

	return (x*x*x)-(x*x)+2;

}


double g_func(double f(int x),int a){

    return f(a)*f(a);

}
