/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: Tue 24 Jul 2018 05:39:35 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define BLACK 2
#define WHITE 1
#define SIZE 20
int cross[SIZE][SIZE];
int draw_num[SIZE];
int X,Y;
void init_draw_num(void){
    int i = 0;
    for (;i < SIZE; i++){
        draw_num[i] = i;
    }
}
void draw_cross(){ 
    int i,j;
    printf("  ");
    for (i = 0;i < SIZE; i++){
        printf("%2d",draw_num[i]+1);
    }
    printf("\n");
    for (i = 0;i < SIZE; i++){
        printf("%2d",draw_num[i]+1);
        for(j = 0; j < SIZE; j++){
            if (cross[i][j] == WHITE){
                printf("★ ");
            }else if (cross[i][j] == BLACK){
                printf("☆ ");
            }else{
                printf("  ");
            }
        }
	printf("\n");
    }
}
void init_draw(void){
    printf("/**********five game****************/\n");
    printf("/***********************************/\n");
    int i;
    printf("  ");
    for (i = 0;i < SIZE; i++){
        printf("%2d",draw_num[i]+1);
    } 
        printf("\n");
    for (i = 0;i < SIZE; i++){
        printf("%2d\n",draw_num[i]+1);
    }
}
int  whocanwin(int color, const int X, const int Y){
    int count;
    int x;
    int y;

    count = 1;
    for (x = X - 1,y = Y;cross[x][y] == color && x>=0;x--)
        count ++;
    for (x = X + 1,y = Y;cross[x][y] == color && x<SIZE;x++)
        count ++;
    printf("shu %d\n",count);
    if (count == 5){
        return 1;
    }
    count = 1;
    for (y = Y - 1,x = X;cross[x][y] == color && y>=0;y--)
        count ++;
    for (y = Y + 1,x = X;cross[x][y] == color && y<SIZE;y++)
        count ++;
    printf("heng %d\n",count);
    if (count == 5){
        return 1;
    }
    count = 1;
    for (x = X - 1,y = Y - 1;cross[x][y] == color && x>=0 && y>=0;x--,y--)
        count ++;
    for (x = X + 1,y = Y + 1;cross[x][y] == color && x<SIZE && y< SIZE;x++,y++)
        count ++;
    printf("zhu %d\n",count);
    if (count == 5){
        return 1;
    }
    count = 1;
    for (x = X - 1,y = Y + 1;cross[x][y] == color && x>=0 && y<SIZE;x--,y++)
        count ++;
    for (x = X + 1,y = Y - 1;cross[x][y] == color && x<SIZE && y>= 0;x++, y--)
        count ++;
    printf("ci %d\n",count);
    if (count == 5){
        return 1;
    }
    return 0;
}
int black_go(){
    int x,y;
    int count;
    if (x > 20 || y > 20){
        printf("cant bigger than 20, input again\n");
        return -1;
    }

    printf("BLACK input pos(x y)\n");
    scanf("%d%d",&x,&y);
    system("clear");
    X = x - 1 ;
    Y = y - 1;
    cross[X][Y] = BLACK;
    draw_cross();
    if(whocanwin(BLACK,X,Y)){
        printf("black win!!!");
        exit(0);
    }
    return 0;
}
int white_go(){
    int x,y;
    if (x > 20 || y > 20){
        printf("cant bigger than 20, input again\n");
        return -1;
    }

    printf("White input pos(x y)\n");
    scanf("%d%d",&x,&y);
    system("clear");
    X = x - 1;
    Y = y - 1;
    cross[X][Y] = WHITE;
    draw_cross();
    if (whocanwin(WHITE,X,Y)){
        printf("white win!!!");
        exit(0);
    }
    return 0;
}
int main(int argc, const char* argv[]){
    int gofirst;
    init_draw_num();
    init_draw();

    printf("who go first(1.white,2.black)\n");
    scanf("%d",&gofirst);
    
    if (BLACK == gofirst){
        while(1){
            black_go();
            white_go();
        }
    }else{
        while(1){
            white_go();
            black_go();
        }
    }
    
    return 0;
}

