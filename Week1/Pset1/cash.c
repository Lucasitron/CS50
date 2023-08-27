/*Autor: Lucasitron
**Description: Algoritimo guloso que conta quantas moedas serão utilizadas para
**chegar a um determinado valor que será obtido via input de usuário.
**
____________________________________________________________________________________*/
#include <cs50.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int
main(void){

    /*cash enter*/
    float insert = get_float("cash: ");

    /*float for int conversion*/
    int cash = insert * 100 + 0.0005;

    /*Valid entered validate*/
    if (cash < 0){
        exit(0);
    }


    /*cashback calculator*/
    int count = 0;

    /*25 decrement*/
    if (cash >= 25){
        count = count + (cash / 25);
        cash = cash - (25 * (cash / 25));

        if (cash == 0)
        {
            printf("back: %i",count);
            exit(0);
        }
    }

    /*10$ decrement*/
    if (cash >= 10){
        count = (count + (cash / 10));
        cash = cash - (10* (cash / 10));

        if (cash == 0)
        {
            printf("back: %i ", count);
            exit(0);
        }
    }

    /*5 decrement*/
    if (cash >= 5){
        count = (count + (cash / 5));
        cash = cash - (5 * (cash / 5));
        if (cash == 0){
            printf("back: %i ", count);
            exit(0);
        }
    }
    /*1 decrement*/
    if (cash >= 1){
        count =(count + (cash / 1));
        cash = cash - (1 * (cash / 1));

        if (cash == 0){
            printf("back: %i ", count);
            exit(0);
        }
    }


    return(0);
}
