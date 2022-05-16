//system.c 21700256 박민, 21700305 박지성
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "system.h"

void setArray(Dessert *arr, int count){
    for(int i=0; i<count; i++){
        arr[i].dc = 0;
        arr[i].name = " ";
        arr[i].cost1 = 0;
        arr[i].cost2 = 0;
        arr[i].cost3 = 0;
        arr[i].num = 0;
        arr[i].size = 0;
        arr[i].temp = 0;
        arr[i].togo = 0;
    }
}

void setDessert(Dessert *arr){ //매뉴 세팅
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
arr[10].name = "라즈베리 파이";  
arr[10].cost1 = 4100;
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
}

void readDessert(Dessert s){ 
    printf("%s  ",s.name);
    if(s.dc == 1)
        printf("%d  %d  %d",s.cost1,s.cost2,s.cost3);
    else printf("%d",s.cost1);
}
    
void listDessert(Dessert *s){
    printf("---------------------Coffee---------------------\n");
    printf("             Tall  Grande  Venti\n");
    for(int i=0; i<6; i++){
        printf("%d. ", i+1);
        readDessert(s[i]);
        printf("\n\n");
        }
     printf("---------------------Cake---------------------\n");
        
        for(int i=6; i<11; i++){
        printf("%d. ", i+1);
        readDessert(s[i]);
        printf("\n\n");
    }
} // 배열에 있는 디저트를 출력하는 함수(readDesert함수 사용)

int selectOption(){
    int menu;
    printf("\n**************** Dessert Foundation ****************\n");
    printf("1. Today's Dessert\n"); //메뉴 출력
    printf("2. Order Menu\n"); //메뉴 주문
    printf("3. Your Order\n"); //주문 내역 확인
    printf("4. Revise Menu\n"); //주문 내용 수정
    printf("5. Delete Menu\n"); //주문 내역 삭제
    printf("6. Save Order\n"); //주문 내용 저장
    printf("7. Print Last Order\n"); //최근 주문내역 출력
    printf("0. 종료\n\n");
    
    printf("=> Select Number: ");
    scanf("%d", &menu);
    return menu;
} // 프로그램 시 메뉴를 선택하는 함수

void orderMenu(Dessert s[],Dessert s2[],int count){
    printf("1.커피 2.케이크: "); //다른 번호를 눌렀을때 처리필요
    scanf("%d",&s[count].dc);
    if(s[count].dc == 1){
    printf("커피번호: ");
    scanf("%d",&s[count].num); //다른 번호를 눌렀을때 처리필요
    s[count].name = s2[(s[count].num)-1].name; //번호를 통해 기존 메뉴의 이름을 복사
    printf("1.Tall 2.Grande 3.Venti: ");
    scanf("%d",&s[count].size); //다른 번호를 눌렀을때 처리필요
    s[count].cost1 = s2[(s[count].num)-1].cost1;
    printf("1.ice 2.hot: ");
    scanf("%d",&s[count].temp); //다른 번호를 눌렀을때 처리필요
    printf("1.포장 2.매장: ");
    scanf("%d",&s[count].togo); //다른 번호를 눌렀을때 처리필요
    }
    else{
    getchar();
    printf("케이크 번호: ");
    scanf("%d",&s[count].num);
    s[count].name = s2[(s[count].num)-1].name; 
    s[count].cost1 = s2[(s[count].num)-1].cost1;
    printf("1.포장 2.매장: ");
    scanf("%d",&s[count].togo);
     }
} 

  void deleteMenu(Dessert *s){
    s->cost1 = -1;
}


void yourOrder(Dessert s[],int count){
        int total=0;
        printf("---------------------Coffee---------------------\n");
    for(int i=0; i<count; i++){
        if(s[i].dc == 1){
        if(s[i].cost1 == -1) continue;
        printf("%d. ", s[i].num);
        if(s[i].temp == 1) printf("*Ice %s*", s[i].name);
        else printf("*Hot %s*", s[i].name);
        if(s[i].size == 1){
            printf("  *Tall(%d)*",s[i].cost1);
            total += s[i].cost1;
        }
        else if(s[i].size == 2){
            s[i].cost2 = s[i].cost1+500;
            printf("  *Grande(%d)*",s[i].cost2);
            total += s[i].cost2;
        } 
        else {
            s[i].cost3 = s[i].cost1+1000;
            printf("  *Venti(%d)*",s[i].cost3);
            total += s[i].cost3;
        }
        if(s[i].togo == 1) printf("  *포장주문 O*");
        else printf("  *포장주문 X*");
        printf("\n\n");
    }
    }
     printf("---------------------Cake---------------------\n"); 
        for(int i=0; i<count; i++){
        if(s[i].dc == 2){
        if(s[i].cost1 == -1) continue;
        printf("%d. ", s[i].num);
        printf("*%s*", s[i].name);
        printf("  *%d*",s[i].cost1);
        if(s[i].togo == 1) printf("  *포장주문 O*");
        else printf("  *포장주문 X*");

        total += s[i].cost1;
        printf("\n\n");
    }
    }
printf("----------------------------------------------\n");
printf("  total: %d\n",total);
}

int updateMenu(Dessert s[],Dessert s2[], int count){
    int num1, num2;
    int count1=0;
    yourOrder(s,count);
    printf("변경하실 디저트 번호: ");
    scanf("%d",&num1);
    for (int i = 0; i<count; i++)
    {
        if(s[i].num == num1){
            num2 = i;
            count1 = 1;//변경할 디저트가 존재함을 의미
            break;
        }
    }
    if (count1 == 0){
    printf("해당 번호는 주문하신 메뉴에 존재하지 않습니다.\n");
    return 0;
    }

    else{
        listDessert(s2);
        printf("새로 주문하실 디저트를 선택하세요.\n\n");
        orderMenu(s,s2,num2);
        return 1;
    }
}

void saveOrder(Dessert s[], int count){
    FILE* fp;

    fp = fopen("menu.txt", "wt");
    for(int i = 0; i < count; i++){
        if(s[i].cost1 == -1)
            continue;
        if(s[i].dc == 1){
            fprintf(fp,"%d %d %s %d %d %d %d", s[i].dc, s[i].num, s[i].name, s[i].cost1, s[i].togo, s[i].size, s[i].temp);
        }
        else{
            fprintf(fp,"%d %d %s %d %d 0 0", s[i].dc, s[i].num, s[i].name, s[i].cost1, s[i].togo, s[i].size, s[i].temp);
        }
    }

    fclose(fp);
    printf("저장됨!\n");
}

int loadOrder(Dessert s[]){
    int count = 0;
    FILE* fp;


    fp = fopen("menu.txt", "r");
    if(fp == NULL){
        return count;
    }
    while(!feof(fp)){
            fscanf(fp, "%d %d %s %d %d %d %d", &s[count].dc, &s[count].num, s[count].name, &s[count].cost1, &s[count].togo, &s[count].size, &s[count].temp);
        if(s[count].cost1 != 0){
            count++;
        }
    }

    fclose(fp);

    printf("=> 최근 주문내역 출력");
    return count;
}


