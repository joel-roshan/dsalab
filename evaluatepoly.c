#include<stdio.h>
#include<math.h>
struct poly{
    int exp;
    float coef;};

void input(struct poly term[],int trms){
    for(int i=0;i<trms;i++){
        printf("enter coeff of term %d: ",i+1);
        scanf("%f",&term[i].coef);
        printf("enter exp of term %d: ",i+1);
        scanf("%d",&term[i].exp);}
    printf("\n\n");
    }
int eval(struct poly term[],int x,int n){
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=term[i].coef*(int)pow(x,term[i].exp);
    return sum; }  
int main()
{
    int n,x;
    printf("enter number of terms of the polynomial :");
    scanf("%d",&n);
    printf("enter value of x :");
    scanf("%d",&x);
    struct poly term[n];
    input(term,n);
    printf("value= %d",eval(term,x,n));
    return 0;
}
//make sure to use -lm while compiling (gcc evaluatepoly.c -lm)