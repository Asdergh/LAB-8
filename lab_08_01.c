#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int main(){
    FILE* file = fopen("equations.txt", "w");
    float meu = 398600.4;
    float We = 7.2921159 * 0.00001;
    float Ra = 1.0;
    float Rp = (pow(We, 2) * pow(45000, 4) * pow(cos(63.4), 2)) / (2 * meu - pow(We, 2) * pow(45000, 3) * pow(cos(63.4), 2));
    float Va, Vw;
    for (Ra; Ra < 60000; Ra = Ra + 10){
        if (Va <= Vw){
            Va = pow(((2 * meu * Rp) / (Ra * (Ra + Rp))), 0.5);
            Vw = We * Ra * cos(63.4);
            fprintf(file, "%f      %f\n", Va, Vw);
        }
        else{
            Va = pow(((2 * meu * Rp) / (Ra * (Ra + Rp))), 0.5);
            fprintf(file, "%f\n", Va);
        }
        }
    }

