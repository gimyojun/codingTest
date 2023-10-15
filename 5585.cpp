#include<iostream>

using namespace std;

int main(){

    int money = 1000;

    int a;
    scanf("%d", &a);
    int rtn = money - a;
    int count =0;


    while(1){

        if(rtn>=500){
            rtn = rtn % 500;

            count++;
            if(!rtn) break;
        }else if(rtn <500 && rtn >=100){
            int tmp = rtn / 100;
            rtn = rtn % 100;
            
            count = count + tmp;
            if(!rtn) break;
        }else if(rtn <100 && rtn >=50){

            int tmp = rtn / 50;
            rtn = rtn % 50;
            count = count + tmp;
            if(!rtn) break;
        }else if(rtn <50 && rtn >=10){

            int tmp = rtn / 10;
            rtn = rtn % 10;
            count = count + tmp;
            if(!rtn) break;
        }else if(rtn <10 && rtn >=5){

            int tmp = rtn / 5;
            rtn = rtn % 5;
            count = count + tmp;
            if(!rtn) break;
        }else if(rtn <5 && rtn >=1){

            count = count + rtn;
            break;


        }


    }
    printf("%d", count);




    return 0;
}
