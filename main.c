#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "system.h"



int main(void){
Dessert arr[20];
Dessert order[20];
arr[0].dc = 'd';
arr[0].name = "OSS 라떼";  
arr[0].cost1 = 6100;
arr[1].dc = 'd';
arr[1].name = "아메리카노";  
arr[1].cost1 = 4500;
arr[2].dc = 'd';
arr[2].name = "초콜릿 모카";  
arr[2].cost1 = 5600;
arr[3].dc = 'd';
arr[3].name = "카페 모카";  
arr[3].cost1 = 5100;
arr[4].dc = 'd';
arr[4].name = "카페 라떼";  
arr[4].cost1 = 4600;
arr[5].dc = 'd';
arr[5].name = "바닐라 라떼";  
arr[5].cost1 = 5800;
arr[6].dc = 'c';
arr[6].name = "당근 케이크";  
arr[6].cost1 = 6100;
arr[7].dc = 'c';
arr[7].name = "초코 케이크";  
arr[7].cost1 = 5800;
arr[8].dc = 'c';
arr[8].name = "딸기 케이크";  
arr[8].cost1 = 6400;
arr[9].dc = 'c';
arr[9].name = "뚱카롱";  
arr[9].cost1 = 3100;
arr[10].dc = 'c';
arr[10].name = "김부각";  
arr[10].cost1 = 2100;
for(int i=0; i<(sizeof(arr)/sizeof(int)); i++){
    if(arr[i].dc == 'd'){
        arr[i].cost2 = arr[i].cost1+500;
        arr[i].cost3 = arr[i].cost2+500;
    }
    else if(arr[i].dc == 'c'){
         arr[i].cost2 =  arr[i].cost1;
        arr[i].cost3 =  arr[i].cost1;
    }
}
    int count =0;
    int index =0;
    int menu;
    int num1,num2;


// printf("\n/u1F370/u1F36E/uF9C1/u2615/u1F9CBu/1F379 Dessert Foundation /u2615/u1F9CBu/1F379/u1F370/u1F36E/uF9C1\n");
//     printf("1. Today's Dessert(list)\n");
//     //printf("2. Search By Name\n");
//     printf("3. Order Menu()\n");
//     //printf("4. Save Order\n");
//     printf("5. Delete Menu\n");
//     //printf("6. View Last Order\n");
//     printf("7. Revise Menu\(for admin\)\n");
//     printf("8. Your Order\n");
//     printf("0. 종료\n\n");

    while (1){
        menu = selectMenu();

        if (menu == 0) break;

        if (menu == 1){
            listDessert(arr);
        }
      
        else if (menu == 3){
            orderMenu(&order);
        }
        else if (menu == 5){
            listDessert(arr);
            printf("번호는 (취소 :0)? ");
            scanf("%d", &num1);
            if(num1 == 0)
                printf("=> 취소 됨!\n");
            else{
                 printf("정말로 삭제하시겠습니까?(삭제 :1)");
                 scanf("%d", &num2);
                 if(num2 == 1)
                deleteMenu(&arr[num1-1]);
                 printf("\n=> 삭제됨!\n");
            }
        }
        else if (menu == 7){
            listDessert(arr);
            printf("번호는 (취소 :0)? ");
            scanf("%d", &num1);
            updateMenu(&arr[num1-1]);
            printf("\n=> 수정됨!\n");
            }
       else if(menu == 8){
           yourOrder(Dessert *order);
       }
        
    }
    printf("종료됨!\n");
    return 0;
}