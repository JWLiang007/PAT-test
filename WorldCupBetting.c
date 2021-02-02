#include <stdio.h>
int main() {
    char reflec[3]={'W','T','L'},output[3];
    double input[3],result=1,max[3]={0},tmp;
    for(int i = 0; i< 3;i++){
        for(int j = 0; j < 3.;j++){
            scanf("%lf",&tmp);
            if(tmp > max[i]){
                max[i] = tmp;
                output[i]=reflec[j];
            }
        }
        result *= max[i];
    }
    result = (result *0.65 - 1)*2;
    printf("%c %c %c %.2f",output[0],output[1],output[2],result);

    return 0;
}
