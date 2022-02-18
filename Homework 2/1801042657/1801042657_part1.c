#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int draw_triangle(int side1,int side2,int side3){

    if((abs(side2-side3)<side1 && side1<(side2+side3))){    // The condition to be triangle.

        printf("\nAccording to the triangle inequality theorem, this triangle can be drawn.\n\n");

        return 1;
    }

    else{

        return 0;

    }
}

void type_triangle(int side1,int side2,int side3){

    if(side1==side2 && side2==side3 && side1==side3){

        printf("It is a Equilateral Triangle.\n");    // Length of the three sides of the triangle is same.

    }

    else if(side1 != side2 && side2 != side3 && side1 != side3){

       printf("It is a Scalene Triangle.\n");         // All three sides of the triangle is different.

    }

    else{

        printf("It is a Isosceles Triangle.\n");      // Isosceles triangles have at least two equal sides.

    }
}

int perimeter_triangle(int side1,int side2,int side3){

    printf("The perimeter of the triangle:%d\n",side1+side2+side3);  // The perimeter is equal to the sum of the lengths of all sides.

    return 1;
}

double area_triangle(int side1,int side2,int side3,int perimeter){

    perimeter = side1 + side2 + side3;
    double p;
    p = (double)perimeter/2;

    printf("The area of the triangle:%f\n",sqrt(p*(p-side1)*(p-side2)*(p-side3)));  // Calculating the area by that formula.

    return 1;
}


int main()
{
    int side1,side2,side3,perimeter;

    printf("The length of first side:\n");
    scanf("%d",&side1);
    printf("The length of second side:\n");
    scanf("%d",&side2);
    printf("The length of third side:\n");
    scanf("%d",&side3);

    if(draw_triangle(side1,side2,side3)==1){   // If the triangle can be drawn, we can find the type,the perimeter and the area of the triangle.

    type_triangle(side1,side2,side3);
    perimeter_triangle(side1,side2,side3);
    area_triangle(side1,side2,side3,perimeter);

    }

    else if(draw_triangle(side1,side2,side3)==0){    // The situation where the triangle can not be drawn.

        printf("\nAccording to the triangle inequality theorem, this triangle cannot be drawn.\n");

    }

    return 0;
}
