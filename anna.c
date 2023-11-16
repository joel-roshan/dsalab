#include<stdio.h>
void print(int sr[10][3]){
    int i,j;
        for(i=0;i<sr[0][2]+1;i++){
            for(j=0;j<3;j++){
                printf("%d ",sr[i][j]);
            }
            printf("\n");
        } 
}
void Transpose(int sr[10][3],int transpose[10][3]){
    int i,j,k=1;
    int n=sr[0][2];
    transpose[0][0]=sr[0][1];
    transpose[0][1]=sr[0][0];
    transpose[0][2]=sr[0][2];
    for(i=0;i<sr[0][1];i++){
        for(j=0;j<=n;j++){
            if(sr[j][1]==i){
                transpose[k][0]=sr[j][1];
                transpose[k][1]=sr[j][0];
                transpose[k][2]=sr[j][2];
                k++;
            }
        }
    }
    
}
int Symmetric(int sr[10][3],int transpose[10][3]){
    int i,j,flag=0;
    for(i=0;i<sr[0][2]+1;i++){
        for(j=0;j<3;j++){
            if(sr[i][j]!=transpose[i][j]){
                flag=1;
                break;
             }
        }
    }
    if(flag==0){
       printf("Symmetric");
    }
    else{
        printf("Not Symmetric");
    }
}
int main(){
    int i,j,row,col,nz,k=1;
    printf("Enter rows: ");
    scanf("%d",&row);
    int sr[row][3];
    int transpose[10][3];
    printf("Enter col: ");
    scanf("%d",&col);
    printf("Enter number of non neg: ");
    scanf("%d",&nz);
    sr[0][0]=row;
    sr[0][1]=col;
    sr[0][2]=nz;
    for(i=1;i<nz+1;i++){
        printf("Enter row col and element: ");
        for(j=0;j<3;j++){
            
            scanf("%d",&sr[i][j]);
        }
    }
    printf("Sparse representation:\n");
    print(sr);
    Transpose(sr,transpose);
    printf("\nTranspose:\n");
    print(transpose);
    Symmetric(sr,transpose);
    return 0;
}