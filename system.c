//system.c 21700256 박민, 21700305 박지성
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "system.h"

void readDessert(Dessert s){
    printf("%s  ",s.name);
    if(s.dc == 'c')
        printf("%d\t%d\t%d",s.cost1,s.cost2,s.cost3);
    else printf("%d",s.cost1);
}
    
    
    


void listDessert(Dessert *s){
    printf("--------------Coffee--------------\n\n");
    printf("                    Tall\tGrande\tVenti\n");
    for(int i=0; i<sizeof(*s)/sizeof(Dessert); i++){
        if(s[i].dc == 'c'){
        if(s[i].cost1 == -1) continue;
        printf("%d. ", i+1);
        readDessert(s[i]);
        printf("\n\n");
        }
      
    }
     printf("--------------Cake--------------\n\n");
        
        for(int i=0; i<sizeof(*s)/sizeof(Dessert); i++){
        if(s[i].dc == 'c'){
        if(s[i].cost1 == -1) continue;
        printf("%d. ", i+1);
        readDessert(s[i]);
        printf("\n\n");
    }
    
}
} // 배열에 있는 디저트를 출력하는 함수(readDesert함수 사용)




int selectMenu(){
    int menu;
    printf("\n/u1F370/u1F36E/uF9C1/u2615/u1F9CBu/1F379 Dessert Foundation /u2615/u1F9CBu/1F379/u1F370/u1F36E/uF9C1\n");
    printf("1. Today's Dessert(list)\n");
    //printf("2. Search By Name\n");
    printf("3. Order Menu()\n");
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
    printf("원하는 디저트 이름: ");
    scanf("%[^\n]s",s->name);
    getchar();
    printf("1.Tall 2.Grande 3.Venti: ");
    scanf("%d",&s->size);
    printf("1.ice 2.hot: ");
    scanf("%d",&s->coldHot);
    printf("1.포장 2.아님: ");
    scanf("%d",&s->togo); 
} 

  void deleteMenu(Dessert *s){
    s->cost1 = -1;
}


void yourOrder(Dessert *s){
    void listDessert(s);
}

void updateMenu(Dessert *s){
    printf("새로운 디저트 이름: ");
    scanf("%[^\n]s",s->name);
    getchar();
} 


