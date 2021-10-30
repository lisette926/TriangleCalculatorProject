# TriangleCalculatorProject

Description: This program will calculate the area of a triangle using the information available, which the user will input.

  Area can be found using:
  1 - three sides
  2 - side, angle, side
  3 - side, side, angle
  4 - angle, side, angle
  5 - angle, angle, side
  6 - coordinates of three vertices

  Formulas:
  1 - three sides
      KNOWN: sideA, sideB, sideC
      a) find semiperimeter:
         SemiPerimeter = (SideA + SideB + SideC) / 2
      b) find area = 
          sqrt(semiperimeter * (semiperimeter - sideA) * (semiperimeter - SideB) * 
          (semiperimeter - sideC))
  
  2 - side, angle, side 
      KNOWN: sideA, angleC, sideB
      a) find area: 
         (sideA * sideB * sin(angleC))/2
  
  3 - side, side, angle 
      KNOWN: sideA, sideB, angleB
      a) find other two angles: 
          angleA = arcsin ((sin(angleB) * sideA)/ 
                   sideB)
          angleC = 180 - angleA - angleB
      b) find area:
          (sideA * sideB * sin(angleC))/2
  
  4 - angle, side, angle 
      KNOWN: angleA, sideC, angleB
      a) find angleC:
         angleC = 180 - angleA - angleB
      b) find sideA:
         sideA = (sideC / sin(angleC)) * sin(angleA)
      c) find sideB:
         sideB = (sideC / sin(angleC)) * sin(angleB)
      b) find area:
         (sideA * sideB * sin(angleC))/2
  
  5 - angle, angle, side 
      KNOWN: angleA, angleB, sideA
      a) find angleC
         angleC = 180 - angleA - angleB
      b) find sideB:
         sideB = (sideA / sin(angleA)) * sin(angleB)
      c) find area:
         (sideA * sideB * sin(angleC))/2

  6 - coordinates of three vertices 
      KNOWN: coordinates A, B, and C
      area = 1/2((x1 * (y2 - y3)) + (x2 * (y3-y1)) + 
      (x3 * (y1-y2))
