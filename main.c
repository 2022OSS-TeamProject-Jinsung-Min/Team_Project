#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "system.h"
#include <memory.h>

int main(void){
Dessert arr[20];
Dessert order[50];
Dessert last[50];
int count=0;
int lastcount = 0;// 최근 주문내역 불러올시 받을 주문수 변수
int menu;
int num1,num2=0;

setDessert(arr);
setArray(order,50);
setArray(last, 50);

    while (1){
        menu = selectOption();

        if (menu == 0) break;

        if (menu == 1){
            listDessert(arr);
        }
      
        else if (menu == 2){
            orderMenu(order,arr,count++);
        }
        else if (menu == 3){
            yourOrder(order,count);
        }
        else if (menu == 4){
            if(updateMenu(order,arr,count)==1){
                 printf("\n=> 메뉴가 수정되었습니다!\n");
            }
            }
       else if(menu == 5){
           yourOrder(order,count);
           printf("취소하실 메뉴의 번호를 입력하세요: ");
           scanf("%d",&num1);
           for(int i=0; i<count; i++){
               if(order[i].num == num1){
                   printf("%s 주문을 취소하시겠습니까?\n",order[i].name);
                   printf("yes=> 1  no=> 2 : ");
                   scanf("%d",&num2);
                  if(num2==1){
                      deleteMenu(&order[i]);
                      printf("%s 주문이 취소되었습니다.\n",order[i].name);
                  }
                  else{
                      printf("주문 취소가 취소되었습니다.\n");
                  }
               }
               else{
                   printf("해당 번호의 메뉴가 주문내역에 존재하지 않습니다.\n");
               }
           }
       }
       else if (menu == 6){
           saveOrder(order, count);
       }
        else if(menu == 7){
            lastcount = loadOrder(last);
            if(lastcount == 0){
                printf("No previous Orders!\n");
            }
            else{
                yourOrder(last, lastcount); 
            }
        }
        
    }
    printf("종료됨!\n");
    return 0;
}