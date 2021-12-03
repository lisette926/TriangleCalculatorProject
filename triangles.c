//function definitions

#include <stdio.h>
#include <math.h>
#define PI 3.141593
#define RADS PI/180

void printMenu(void)
{
  printf("\t\t\tTriangle Calculator\n\n"
          "Enter 1-6 to calculate the area of a triangle using the following information: \n\n"
          "\t1 - three sides (SSS)\n"
          "\t2 - side, angle, side (SAS)\n"
          "\t3 - side, side, angle (SSA)\n"
          "\t4 - angle, side, angle (ASA)\n"
          "\t5 - angle, angle, side (AAS)\n"
          "\t6 - coordinates of three vertices\n\n"
          ">>");
}

float areaSSS(float sideA, float sideB, float sideC)
{
  float semiPerimeter;

  semiPerimeter = (sideA + sideB +sideC) / 2.0;

  return sqrt(semiPerimeter * (semiPerimeter - sideA) * (semiPerimeter -sideB) * (semiPerimeter - sideC));;
}

float areaSAS(float sideA, float sideB, float angleC)
{
  return (sideA * sideB * sin(angleC * RADS)) / 2.0;;
}

float areaSSA(float sideA, float sideB, float angleB)
{
  float angleA,
        angleC;
  
  angleA = (asin ((sin(angleB * RADS) * sideA)/sideB)) * (180.0/PI);        
  angleC = 180 - angleA - angleB;  
  return (sideA * sideB * sin(angleC * RADS))/2;
}

float areaASA(float sideC, float angleA, float angleB)
{
  float angleC,
        sideA,
        sideB;
  
  angleC = 180 - angleA - angleB;
      
  sideA = (sideC / sin(angleC * RADS)) * sin(angleA * RADS);

  sideB = (sideC / sin(angleC * RADS)) * sin(angleB * RADS);

  return (sideA * sideB * sin(angleC * RADS))/2.0;
}

float areaAAS(float sideA, float angleA, float angleB)
{
  float angleC = 180 - angleA - angleB;
  float sideB = (sideA / sin(angleA * RADS)) * sin(angleB * RADS);

  return (sideA * sideB * sin(angleC*RADS))/2.0;
}

float areaVertices(float x1, float y1, float x2, float y2, float x3, float y3)
{
  return -((x1 * (y2 - y3)) + (x2 * (y3 - y1)) + (x3 * (y1 - y2)))/2.0;
}