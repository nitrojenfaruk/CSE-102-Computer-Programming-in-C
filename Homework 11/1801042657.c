#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/* ---------- P1  ----------*/
struct node{
    int data;
    struct node* next;
};
typedef struct node *p_node;

int *read_array(char *filename, int *size);
p_node read_linkedlist(char *filename, int *size);
float * stats_array(int *dyn_arr);
float * stats_linkedlist(p_node l_list);

/* ---------- P2 ----------*/
typedef struct num
{
	int n1;
	int n2;
}num;

typedef struct node2{
    int data;
    struct node2* next;
}node2;

int* adding_to_array();
node2* adding_to_llist();
num* diff_dynarr_llist(int *arr, node2 *element, int *n);

/*main*/
int main()
{
    int *fill,*temp, arr_byte, linkedl_byte;
	float *arr, *llist;
	double time=0,time_1=0,time_2=0,time_3=0;
    p_node temp2;
	clock_t Tread_array, Tread_linkedlist, Tstats_array, Tstats_linkedlist;

    int i,count;
    node2 *temp3;
    num *temp4;

            /*PART1*/
        /*TIME CALCULATIONS*/
        for(int i=0;i<4;i++){
        Tread_array = clock();
        temp=read_array("list.txt", &arr_byte);
        Tread_array = clock() - Tread_array;
        time += ((double)Tread_array)/CLOCKS_PER_SEC;
        }
        time/=4;

        for(int i=0;i<4;i++){
        Tread_linkedlist = clock();
        temp2 =read_linkedlist("list.txt", &linkedl_byte);
        Tread_linkedlist=clock()-Tread_linkedlist;
        time_1 += ((double)Tread_linkedlist)/CLOCKS_PER_SEC;
        }
        time_1/=4;

        for(int i=0;i<4;i++){
        Tstats_array=clock();
        arr=stats_array(temp);
        Tstats_array=clock()-Tstats_array;
        time_2 += ((double)Tstats_array)/CLOCKS_PER_SEC;
        }
        time_2/=4;

        for(int i=0;i<4;i++){
        Tstats_linkedlist=clock();
        llist=stats_linkedlist(temp2);
        Tstats_linkedlist=clock()-Tstats_linkedlist;
        time_3 += ((double)Tstats_linkedlist)/CLOCKS_PER_SEC;
        }
        time_3/=4;

        printf("---------------------------------------------------------\n");
        printf("<< (*read_array) >>\n");
        printf("Number of byte was used: %d\n",arr_byte);
        printf("Min    Max        Mean     Standart Deviation\n");
        printf("%.2lf   %.2lf %.2lf %.2lf\n",arr[1],arr[0],arr[2],arr[3] );
        printf("---------------------------------------------------------\n");
        printf("---------------------------------------------------------\n");
        printf("<< (*read_linkedlist) >>\n");
        printf("Number of byte was used: %d\n",linkedl_byte);
        printf("Min    Max        Mean     Standart Deviation\n");
        printf("%.2lf   %.2lf %.2lf %.2lf\n",llist[1],llist[0],llist[2],llist[3] );
        printf("---------------------------------------------------------\n");
        printf("---------------------------------------------------------\n");
        printf("*read_array: %lfs\n",time);
        printf("*stats_array: %lfs\n",time_2);
        printf("*read_linkedlist: %lfs\n",time_1);
        printf("*stats_linkedlist: %lfs\n",time_3);
        printf("---------------------------------------------------------\n");

        /*PART2*/
        printf("\n<<<<<<<P2>>>>>>>\n\n");
        fill=adding_to_array();
        temp3=(node2*)malloc(sizeof(node2));
        temp3=adding_to_llist();
        temp4=diff_dynarr_llist(fill, temp3, &count);
        for(i=0; i<count; i++)   printf("\nDifferences: %d,%d",temp4[i].n2,temp4[i].n1);
}


int *read_array(char *filename, int *size){

    char temp;
	int read_num,count=1;
	int *dyn_arr;

	FILE *fp=fopen(filename,"r");
	dyn_arr=(int*)malloc(sizeof(int));

	while(1){
		fscanf(fp,"%d",&read_num);  // NUMBERS
		fscanf(fp,"%c",&temp);  // ','
		if(feof(fp)){
            *size=(count-1)*(sizeof(int));   // Calculating the used byte..
			break;
		}
		dyn_arr[count-1]=read_num;
		dyn_arr=(int*)realloc(dyn_arr,(count+1)*sizeof(int));     // Re-allocation processing
		count++;
	}
	dyn_arr[count-1]=-1;

	fclose(fp);
	return dyn_arr;
}


p_node read_linkedlist(char *filename, int *size){

    char temp;
	int read_num, count = 1;

	FILE *fp=fopen(filename,"r");

	p_node head=(p_node)malloc(sizeof(p_node)); // Creating head and tail..
	p_node tail;

	fscanf(fp,"%d",&read_num);
	fscanf(fp,"%c",&temp);
	head->data=read_num;    // Transferring numbers to the data
	p_node iter=(p_node)malloc(sizeof(p_node));
	head->next=iter;

	while(1){
		count++;
		fscanf(fp,"%d",&read_num);  //NUMBERS
		fscanf(fp,"%c",&temp);  // ','

		if(feof(fp)){
			iter->data=-1;
			tail=iter;
            *size=(count-2)*(sizeof(p_node));   // Byte calculation
			return head;
		}

		iter->data=read_num;    // Storing the informations..
		iter->next=(p_node)malloc(sizeof(p_node));
		iter=iter->next;
	}
}


float *stats_array(int *dyn_arr){

    float *stats=(float*)malloc(4*sizeof(float));
	int count=1;
	float sum=dyn_arr[0];

	stats[0]=dyn_arr[0]; /*MAX*/
    stats[1]=dyn_arr[1]; /*MIN*/
    stats[2]=dyn_arr[2]; /*MEAN*/
    stats[3]=dyn_arr[3]; /*STANDARD DEVIATION*/

	while(dyn_arr[count]!=-1) {     // TO CALCULATE MEAN
		sum+=dyn_arr[count];
		count++;
	}
    stats[2]=sum/(count);
	count=0;
	stats[3]=0.0;

    /*Max,min,SD Calculation*/
	while(dyn_arr[count] != -1){
		if((stats[0])<dyn_arr[count])   stats[0]=dyn_arr[count];
		if((stats[1])>dyn_arr[count])  stats[1]=dyn_arr[count];
		stats[3] += (dyn_arr[count] - stats[2])*(dyn_arr[count] - stats[2]);
		count++;
	}
	stats[3]=sqrt(stats[3]/count);  // SD Formula
	return stats;
}


float *stats_linkedlist(p_node l_list){

	float sum=0.0;
	float *x=(float*)malloc(4*sizeof(float));
	int count=0;  // For calculations

	p_node temp;
	temp=l_list;

	x[0]=l_list->data;
	x[1]=l_list->data;
	x[3]=0.0;

	while(l_list->data != -1) {
		sum+=l_list->data;
		l_list=l_list->next;
		count++;
	}

	x[2]=sum/count; // Mean

    /* Max,Min,SD Calculations*/
	while(temp->data!=-1){
		if(temp->data>(x[0]))   x[0]=temp->data;
		if(temp->data<(x[1]))   x[1]=temp->data;
		x[3]+=(temp->data - x[2]) * (temp->data - x[2]);
		temp=temp->next;
	}

	x[3]=sqrt(x[3]/count);  // SD Formula

	return x;
}

/*---------P2---------*/

int* adding_to_array(){

	int i, *str, num, count=0;
	str=(int*)malloc(2*sizeof(int));

	printf("Please enter '0' to exit..\n");

	while(num!=0){
		printf("Enter number for array:\n");
		scanf("%d",&num);
		str[count]=num;
		count++;
		str=(int*)realloc(str,(count+2)*sizeof(int));   // Re-allocation process
	}
	printf("Dynamic array:{");

	for(i=0;i<count-1;i++){    // Printing the dynamic array..
		printf("%d",str[i]);
		if(i==count-2)  break;
		else  printf(",");
	}
	printf("}\n");

	return str;
}

node2* adding_to_llist(){

	int num,i;

	node2 *temp;
	node2 *element=(node2*)malloc(sizeof(node2));
	temp=element;

	int sayac=0;
	printf("\nPlease enter '0' to exit..\n");
	while(num!=0){
		printf("Enter number for linked list: \n");
		scanf("%d",&num);
		element->data=num;  // Transferring numbers to the data
		element->next=(node2*)malloc(sizeof(node2));
		element=element->next;  // Skipping..
		sayac++;
	}
	element->next=NULL;
	element=temp;

	printf("Linked List:{");    // Printing the linked list numbers..
	for(i=0;i<sayac-1;i++){
		printf("%d",element->data);
		element=element->next;
		if(i==sayac-2)  break;
		else   printf(",");
	}
	printf("}\n");

	element=temp;
	return element;
}

num* diff_dynarr_llist(int *arr, node2 *element, int *n){

	int i=0,j,count=0;
	node2 *temp1;
	num *result=(num*)malloc(sizeof(num));  // Memory allocation

	while(arr[i]!=0){
		count++;
		arr=(int*)realloc(arr,(count+2)*sizeof(int));
		i++;
	}
	i=j=count=0;

	while(arr[i]!=0){
		if(element->data!=arr[i]){
			result[j].n1=element->data; // Transferring to number 1,number 2..
			result[j].n2=arr[i];
			result=realloc(result,(count+2)*sizeof(num));   // Re-allocation process
			j++;
			count++;
		}
		i++;
		element=element->next;  // Skipping
	}
	*n=count;

	return result;
}
