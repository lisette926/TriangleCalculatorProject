/*
  Description: This program will calculate the area of a triangle using the information available, which the user will input.
  Area can be found using:
  1 - three sides
  2 - side, angle, side
  3 - side, side, angle
  4 - angle, side, angle
  5 - angle, angle, side
  6 - coordinates of three vertices
  Algorithm:
  1) Display menu/options to user
  2) Read/obtain option from user
  3) For option 1:
     3a) obtain side a, b, and c
     3b) find semiperimeter
     3c) calculate area
  4) for option 2:
     4a) obtain side a, angle c, and side b
     4b) find area
     4c) calculate area
  5) for option 3: SSA
     5a) obtain side a, side b, and angle b from user
     5b) find angle a and angle c
     5c) calculate area
  6) for option 4: ASA
     6a) obtain angle a, side c, and angle b from user
     6b) find angle c
     6c) find side a
     6d) find side b
     6e) calculate area
  7) for option 5: AAS
     7a) obtain angle a, angle b, and side a
     7b) find angle c
     7c) find side b
     7d) calculate area
  8) for option 6: coordinates of three vertices
     8a) obtain coordinates a, b, and c from user
     8b) calculate area
*/

#include <stdio.h>
#include <math.h>
#define PI 3.141593
#define RADS PI/180

int main(void) {
  
  int options;
  float sideA, 
        sideB, 
        sideC,
        angleA,
        angleB,
        angleC,
        semiPerimeter,
        area,
        x1,
        y1,
        x2,
        y2,
        x3,
        y3;

  //asks user for which information they have on triangle
  printf("\t\t\tTriangle Calculator\n\n"
          "Enter 1-6 to calculate the area of a triangle using the following information: \n\n"
          "\t1 - three sides (SSS)\n"
          "\t2 - side, angle, side (SAS)\n"
          "\t3 - side, side, angle (SSA)\n"
          "\t4 - angle, side, angle (ASA)\n"
          "\t5 - angle, angle, side (AAS)\n"
          "\t6 - coordinates of three vertices\n\n"
          ">>");
  
  scanf("%d", &options);

  switch(options)
  {
    //calculates area of triangle using SSS
    case 1: 
      printf("\nEnter side A: ");
      scanf("%f", &sideA);

      printf("Enter side B: ");
      scanf("%f", &sideB);

      printf("Enter side C: ");
      scanf("%f", &sideC);

      if(sideA + sideB > sideC && sideB + sideC > sideA && sideA + sideC > sideB)
      {
        semiPerimeter = (sideA + sideB +sideC) / 2.0;
      
        area = sqrt(semiPerimeter * (semiPerimeter - sideA) * (semiPerimeter -sideB) * (semiPerimeter - sideC));
        
        printf("\nThe area is: %.2f units^2\n\n", area); 
      }
      else
      {
        printf("Error: The sides do not form a triangle");
      }
      break;
    //calculates area of triangle using SAS
    case 2: 
      printf("\nEnter side A: ");
      scanf("%f", &sideA);
      if(sideA < 0)
      {
        printf("\n\tError: Side A should be greater than 0\n\n");
        printf("\nEnter side A: ");
        scanf("%f", &sideA);
      }

      printf("Enter side B: ");
      scanf("%f", &sideB);
      if(sideB < 0)
      {
        printf("\n\tError: Side B should be greater than 0\n\n");
        printf("Enter side B: ");
        scanf("%f", &sideB);
      }

      printf("Enter angle C: ");
      scanf("%f", &angleC);

      if((angleC > 0) && (angleC < 180))
      {
        area = (sideA * sideB * sin(angleC * RADS)) / 2.0;
        printf("\nThe area is: %.2f\n\n", area);
      }
      else
      {
        printf("\n\tError: The angle should be between 1 - 180\n\n");
        printf("Enter angle C: ");
        scanf("%f", &angleC);

        area = (sideA * sideB * sin(angleC * RADS)) / 2.0;
        printf("\nThe area is: %.2f\n\n", area);
      }
      break;
    //calculates area of triangle using SSA
    case 3:
      printf("\nEnter side A: ");
      scanf("%f", &sideA);
      if(sideA < 0)
      {
        printf("\n\tError: Side A should be greater than 0\n\n");
        printf("\nEnter side A: ");
        scanf("%f", &sideA);
      }

      printf("Enter side B: ");
      scanf("%f", &sideB);
      if(sideB < 0)
      {
        printf("\n\tError: Side B should be greater than 0\n\n");
        printf("Enter side B: ");
        scanf("%f", &sideB);
      }

      printf("Enter angle B: ");
      scanf("%f", &angleB);
      
      if((angleB > 0) && (angleB < 180))
      {
        angleA = (asin ((sin(angleB * RADS) * sideA)/sideB)) * (180.0/PI);
        angleC = 180 - angleA - angleB;

        area = (sideA * sideB * sin(angleC * RADS))/2;
        printf("\nThe area is: %.2f\n\n", area);
      }
      else
      {
        printf("\n\tError: The angle should be between 1 - 180\n\n");
        printf("Enter angle B: ");
        scanf("%f", &angleB);

        angleA = (asin ((sin(angleB * RADS) * sideA)/sideB)) * (180.0/PI);
        angleC = 180 - angleA - angleB;

        area = (sideA * sideB * sin(angleC * RADS))/2;
        printf("\nThe area is: %.2f\n\n", area);
      }
      break;
    //calculates area of triangle using ASA
    case 4:
      printf("Enter side C: ");
      scanf("%f", &sideC);
      if(sideC < 0)
      {
        printf("\n\tError: Side C should be greater than 0\n\n");
        printf("Enter side C: ");
        scanf("%f", &sideC);
      }

      printf("\nEnter angle A: ");
      scanf("%f", &angleA);

      if((angleA > 0) && (angleA < 180))
      {
        printf("Enter angle B: ");
        scanf("%f", &angleB);
        if((angleB > 0) && (angleB < 180))
        {
          if((angleA + angleB > 0) && (angleA + angleB < 180))
          {
            angleC = 180 - angleA - angleB;
      
            sideA = (sideC / sin(angleC * RADS)) * sin(angleA * RADS);

            sideB = (sideC / sin(angleC * RADS)) * sin(angleB * RADS);

            area = (sideA * sideB * sin(angleC * RADS))/2.0;
            printf("\nThe area is: %.2f\n\n", area);
           }
        }
        else
        {
          printf("\n\tError: The angle should be between 1 - 180\n\n");
          printf("Enter angle B: ");
          scanf("%f", &angleB);
          if((angleA + angleB > 0) && (angleA + angleB < 180))
          {
             angleC = 180 - angleA - angleB;
      
             sideA = (sideC / sin(angleC * RADS)) * sin(angleA * RADS);

              sideB = (sideC / sin(angleC * RADS)) * sin(angleB * RADS);

              area = (sideA * sideB * sin(angleC * RADS))/2.0;
              printf("\nThe area is: %.2f\n\n", area);
          }
        }
      }
      else
      {
        printf("\n\tError: The angle should be between 1 - 180\n\n");
        printf("\nEnter angle A: ");
        scanf("%f", &angleA);

        printf("Enter angle B: ");
        scanf("%f", &angleB);
        if((angleB > 0) && (angleB < 180))
        {
          if((angleA + angleB > 0) && (angleA + angleB < 180))
          {
            angleC = 180 - angleA - angleB;
      
            sideA = (sideC / sin(angleC * RADS)) * sin(angleA * RADS);

            sideB = (sideC / sin(angleC * RADS)) * sin(angleB * RADS);

            area = (sideA * sideB * sin(angleC * RADS))/2.0;
            printf("\nThe area is: %.2f\n\n", area);
          }
        }
        else
        {
          printf("\n\tError: The angle should be between 1 - 180\n\n");
          printf("Enter angle B: ");
          scanf("%f", &angleB);
          
          if((angleB > 0) && (angleB < 180))
          {
             if((angleA + angleB > 0) && (angleA + angleB < 180))
             {
                angleC = 180 - angleA - angleB;
      
                sideA = (sideC / sin(angleC * RADS)) * sin(angleA * RADS);

                sideB = (sideC / sin(angleC * RADS)) * sin(angleB * RADS);

                area = (sideA * sideB * sin(angleC * RADS))/2.0;
               printf("\nThe area is: %.2f\n\n", area);
              }
          }
        }
      }
      break;
    //calculates area of triangle using AAS
    case 5:
      printf("Enter side A: ");
      scanf("%f", &sideA);
      if(sideA < 0)
      {
        printf("\n\tError: Side A should be greater than 0\n\n");
        printf("Enter side A: ");
        scanf("%f", &sideA);
      }
      
      printf("\nEnter angle A: ");
      scanf("%f", &angleA);

      if((angleA > 0) && (angleA < 180))
      {
        printf("Enter angle B: ");
        scanf("%f", &angleB);
        if((angleB > 0) && (angleB < 180))
        {
          if((angleA + angleB > 0) && (angleA + angleB < 180))
          {
            angleC = 180 - angleA - angleB;
      
            sideB = (sideA / sin(angleA * RADS)) * sin(angleB * RADS);
      
            area = (sideA * sideB * sin(angleC*RADS))/2.0;
            printf("\nThe area is: %.2f\n\n", area);
          }
        }
        else
        {
          printf("\n\tError: The angle should be between 1 - 180\n\n");
          printf("Enter angle B: ");
          scanf("%f", &angleB);
          
          if((angleA + angleB > 0) && (angleA + angleB < 180))
          {
             angleC = 180 - angleA - angleB;
      
             sideB = (sideA / sin(angleA * RADS)) * sin(angleB * RADS);
      
             area = (sideA * sideB * sin(angleC*RADS))/2.0;
             printf("\nThe area is: %.2f\n\n", area);
          }
        }
      }
      else
      {
         printf("\n\tError: The angle should be between 1 - 180\n\n");
         printf("\nEnter angle A: ");
         scanf("%f", &angleA);

         printf("Enter angle B: ");
         scanf("%f", &angleB);
         if((angleB > 0) && (angleB < 180))
         {
           if((angleA + angleB > 0) && (angleA + angleB < 180))
           {
             angleC = 180 - angleA - angleB;
      
             sideB = (sideA / sin(angleA * RADS)) * sin(angleB * RADS);
      
             area = (sideA * sideB * sin(angleC*RADS))/2.0;
             printf("\nThe area is: %.2f\n\n", area);
           }
         }
         else
         {
           printf("\n\tError: The angle should be between 1 - 180\n\n");
           printf("Enter angle B: ");
           scanf("%f", &angleB);

           if((angleA + angleB > 0) && (angleA + angleB < 180))
           {
             angleC = 180 - angleA - angleB;
      
              sideB = (sideA / sin(angleA * RADS)) * sin(angleB * RADS);
      
             area = (sideA * sideB * sin(angleC*RADS))/2.0;
             printf("\nThe area is: %.2f\n\n", area);
            }
         }
      }
      break;
    //calculates area of triangle using coordinats of 3 vertices
    case 6:

      printf("\nEnter coordinate A(ex: x y): ");
      scanf("%f %f", &x1, &y1);

      printf("Enter coordinate B(ex: x y): ");
      scanf("%f %f", &x2, &y2);

      printf("Enter coordinate C(ex: x y): ");
      scanf("%f %f", &x3, &y3);

      area = -((x1 * (y2 - y3)) + (x2 * (y3 - y1)) + (x3 * (y1 - y2)))/2.0;
      
      printf("\nThe area is: %.2f\n\n", area);
      break;
    default : printf("\nERROR: An invalid number was entered");
  }
  return 0;
}