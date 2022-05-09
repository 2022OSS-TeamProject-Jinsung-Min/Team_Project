#include <stdio.h>
#include <string.h>

typedef struct{//상품 구조체
	char dc; // 제품의 분류(drink or cake)
	char name[30]; // 제품의 이름
	char size[10]; // Short,Tall, Grande, Venti, 음식인 경우에는 cake
	int cost; // 판매가격
	int pack; // 포장유무 (1(yes) or 2(no))
	int clodHot; // 온도(1(ice) or 2(hot)), 음식인인 경우에는 0	
} Dessert;

int addOrder(Dessert i,Dessert *d);

void readDessert(Dessert *d);

int updateDessert(Dessert i, Dessert *d);

int deleteDessert(Dessert *d);
