#include <stdio.h>
#include <math.h>

double distCalc(double vertex_one[3], double vertex_two[3]){
    double square = 0;
    for (int i=0;i<3;i++){
        double diff = vertex_one[i] - vertex_two[i];
        square += pow(diff, 2);
    }
    return sqrt(square); 
}

char* outcome(double dist1, double dist2, double dist3) {
    double sq1 = pow(dist1, 2);
    double sq2 = pow(dist2, 2);
    double sq3 = pow(dist3, 2);
    
    if (sq1 + sq2 == round(sq3) || sq1 + sq3 == round(sq2) || sq2 + sq3 == round(sq1)){
        return "It is a Right Triangle";
    }
    
    else if  (dist1 == dist2 && dist1==dist3) {
        return "The triangle is Equilateral";
    }

    else if (dist1 == dist2 && dist1 != dist3 || dist1 == dist3 && dist3 != dist2 || dist2 == dist3 && dist2 != dist1 ){
        return "The triangle is isoceles";
    }

    else {
        return "Its frikin Scalene";
    }

}

int main() {

    double vert1[3],vert2[3],vert3[3];
   
    printf("Enter vertex1 <x y z>:\n");
    scanf("%lf %lf %lf", &vert1[0], &vert1[1], &vert1[2]);

    printf("Enter vertex2 <x y z>:\n");
    scanf("%lf %lf %lf", &vert2[0], &vert2[1], &vert2[2]);

    printf("Enter vertex3 <x y z>:\n");
    scanf("%lf %lf %lf", &vert3[0], &vert3[1], &vert3[2]);

    double D_one_two = distCalc(vert1, vert2);
    double D_one_three = distCalc(vert1, vert3);
    double D_two_three = distCalc(vert3, vert2);

    printf("\nSides: 1-2: %lf, 1-3: %lf, 2-3: %lf", D_one_two, D_one_three, D_two_three);

    char* result = outcome(D_one_two, D_one_three, D_two_three);
    printf("\nResult after tedious calculations: \n%s", result);
    return 0;
}

