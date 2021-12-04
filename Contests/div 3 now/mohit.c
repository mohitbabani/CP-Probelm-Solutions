#include<stdio.h>
#include<string.h>
int main(){
    // MOHIT BABANI
    // 19ESKCS143
    FILE *fp;
    fp = fopen("input.c", "r");
    char ROP[6][2] = {"==", "!=", "<=", ">=", "<", ">"};
                    // 0      1     2     3    4    5
    int fre[6];
    char data[50];
    memset(data,'$',sizeof(data));
    memset(fre,0,sizeof(fre));
    if(fp == NULL){
        printf("Failed to open input file\n");
        return 0;
    }
    while(fgets(data,50,fp) != NULL){
        for(int i=0;i<50;i++){
            if(data[i] == '>'){
                if(i+1 < 50 && data[i+1] == '='){
                    fre[3]++;
                }else{
                    fre[5]++;
                }
            }
            if(data[i] == '<'){
                if(i+1 < 50 && data[i+1] == '='){
                    fre[2]++;
                }else{
                    fre[4]++;
                }
            }
            if(i+1 < 50){
                if(data[i] == '=' && data[i+1] == '='){
                    fre[0]++;
                }
                if(data[i] == '!' && data[i+1] == '='){
                    fre[1]++;
                }
            }
        }
        memset(data,'$',sizeof(data));
    }
    for(int i=0;i<6;i++){
        for(int j=0;j<2;j++){
            printf("%c",ROP[i][j]);
        }
        printf(" : %d\n",fre[i]);
    }
    fclose(fp);
    return 0;
}