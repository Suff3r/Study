#include <stdio.h>
#include <math.h>

#define MAX 32

int convert(int a[],int b,int *n);
int get_length(int a[]);
int get_length_i(int a);
int mydiv(int a[],int b[],int na,int nb);
int make_num(int x,int y);
int div2(int x,int y);

int main(int argc, char* argv[])
{
    printf("%d ",div2(120,17));
    return 0;
}

int div2(int x,int y)
{
	int i;
    int a[MAX],b[MAX],na,nb;
    convert(a,x,&na);
    convert(b,y,&nb);

    return mydiv(a,b,na,nb);
}

int convert(int a[],int b,int *n)
{
	int i;
    for(i=0;i<MAX;i++) {
        a[i]= (b&(1<<i))>>i;
    }
    *n=get_length(a);
    return *n;
}

int get_length(int a[])
{
    int l=0;
	int i=0;
    for(i=0;i<MAX;i++) {
        if(a[i]!=0) l=i;
    }
    return l+1;
}

int get_length_i(int a)
{
    int temp_arr[MAX],itemp;
    convert(temp_arr,a,&itemp);
    return itemp;
}

int mydiv(int a[],int b[],int na,int nb)
{
    int p=0,q=0,x[MAX]={0},i,c=0,result=0;
    for(i=0;i<nb;i++) {
        q+=(b[i]<<i);
    }

    while(na>=0) {
        while(get_length_i(p)<nb && na>=0) {
            if(na==0 && p!=0) return p;
            p=make_num(p,*(a+na-1));
            na--;
            x[na]=0;
        }
        if(na>=0) {
            x[na]=1;
            p=q^p;
        }
    }

    c=get_length(x);
    for(i=c-1;i>=0;i--) {
        result=make_num(result,x[i]);
    }
    return result;
}

int make_num(int x,int y)
{
    return ((x<<1)|y);
}
