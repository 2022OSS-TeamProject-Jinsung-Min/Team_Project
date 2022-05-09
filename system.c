//system.c 21700256 박민, 21700305 박지성
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "system.h"

void readDessert(Dessert s){
    printf("%s  ",s.name);
    if(s.dc == 1)
        printf("%d  %d  %d",s.cost1,s.cost2,s.cost3);
    else printf("%d",s.cost1);
}
    
    
    


void listDessert(Dessert *s, int count){
    printf("---------------------Coffee---------------------\n");
    printf("             Tall  Grande  Venti\n");
    for(int i=0; i<count; i++){
        if(s[i].dc == 1){
        if(s[i].cost1 == -1) continue;
        printf("%d. ", i+1);
        readDessert(s[i]);
        printf("\n\n");
        }
      
    }
     printf("---------------------Cake---------------------\n");
        
        for(int i=0; i<count; i++){
        if(s[i].dc == 2){
        if(s[i].cost1 == -1) continue;
        printf("%d. ", i+1);
        readDessert(s[i]);
        printf("\n\n");
    }
    
}
} // 배열에 있는 디저트를 출력하는 함수(readDesert함수 사용)




int selectMenu(){
    int menu;
    printf("\n**************** Dessert Foundation ****************\n");
    printf("1. Today's Dessert\n");
    //printf("2. Search By Name\n");
    printf("3. Order Menu\n");
    //printf("4. Save Order\n");
    printf("5. Delete Menu\n");
    //printf("6. View Last Order\n");
    printf("7. Revise Menu(for admin)\n");
    printf("8. Your Order\n");
    printf("0. 종료\n\n");
    
    printf("=> Select Number: ");
    scanf("%d", &menu);
    return menu;
} // 프로그램 시 메뉴를 선택하는 함수

void orderMenu(Dessert *s){
    getchar();
    printf("1.커피 2.케이크: ");
    scanf("%d",&s->dc);
    if(s->dc == 1){
    getchar();
    printf("원하는 디저트 이름: ");
    scanf("%[^\n]s",s->name);
    printf("1.Tall 2.Grande 3.Venti: ");
    getchar();
    scanf("%d",&s->size);
    printf("1.ice 2.hot: ");
    scanf("%d",&s->coldHot);
    printf("1.포장 2.매장: ");
    scanf("%d",&s->togo); 
    }
    else{
    getchar();
    printf("원하는 디저트 이름: ");
    scanf("%[^\n]s",s->name);
    printf("1.포장 2.매장: ");
    scanf("%d",&s->togo);
     }
} 

  void deleteMenu(Dessert *s){
    s->cost1 = -1;
}


void yourOrder(Dessert *s, int count){
        printf("---------------------Coffee---------------------\n");
    for(int i=0; i<count; i++){
        if(s[i].dc == 1){
        if(s[i].cost1 == -1) continue;
        printf("%d. ", i+1);
        printf("%s", s->name);
        printf("\n\n");
        }
      
    }
     printf("---------------------Cake---------------------\n");
        
        for(int i=0; i<count; i++){
        if(s[i].dc == 2){
        if(s[i].cost1 == -1) continue;
        printf("%d. ", i+1);
        printf("%s", s[i].name);
        printf("\n\n");
    }
    }
}

void updateMenu(Dessert *s){
    getchar();
    printf("새로운 디저트 이름: ");
    scanf("%[^\n]s",s->name);
    getchar();
} 


