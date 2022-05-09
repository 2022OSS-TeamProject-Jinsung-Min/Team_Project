#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "system.h"


int main(void){
Dessert arr[20];
Dessert order[20];
int count=0;
int menu;
int num1,num2;

arr[0].dc = 1;
arr[0].name = "OSS 라떼";  
arr[0].cost1 = 6100;
arr[1].dc = 1;
arr[1].name = "아메리카노";  
arr[1].cost1 = 4500;
arr[2].dc = 1;
arr[2].name = "초콜릿 모카";  
arr[2].cost1 = 5600;
arr[3].dc = 1;
arr[3].name = "카페 모카";  
arr[3].cost1 = 5100;
arr[4].dc = 1;
arr[4].name = "카페 라떼";  
arr[4].cost1 = 4600;
arr[5].dc = 1;
arr[5].name = "바닐라 라떼";  
arr[5].cost1 = 5800;
arr[6].dc = 2;
arr[6].name = "당근 케이크";  
arr[6].cost1 = 6100;
arr[7].dc = 2;
arr[7].name = "초코 케이크";  
arr[7].cost1 = 5800;
arr[8].dc = 2;
arr[8].name = "딸기 케이크";  
arr[8].cost1 = 6400;
arr[9].dc = 2;
arr[9].name = "뚱카롱";  
arr[9].cost1 = 3100;
arr[10].dc = 2;
arr[10].name = "김부각";  
arr[10].cost1 = 2100;
for(int i=0; i<11; i++){
    if(arr[i].dc == 1){
        arr[i].cost2 = arr[i].cost1+500;
        arr[i].cost3 = arr[i].cost2+500;
    }
    else if(arr[i].dc == 2){
         arr[i].cost2 =  arr[i].cost1;
        arr[i].cost3 =  arr[i].cost1;
    }
}
  



    while (1){
        menu = selectMenu();

        if (menu == 0) break;

        if (menu == 1){
            listDessert(arr,11);
        }
      
        else if (menu == 3){
            orderMenu(&order[count++]);
        }
        else if (menu == 5){
            listDessert(arr,11);
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
            listDessert(arr,11);
            printf("번호는 (취소 :0)? ");
            scanf("%d", &num1);
            updateMenu(&arr[num1-1]);
            printf("\n=> 수정됨!\n");
            }
       else if(menu == 8){
           yourOrder(order,count);
       }
        
    }
    printf("종료됨!\n");
    return 0;
}