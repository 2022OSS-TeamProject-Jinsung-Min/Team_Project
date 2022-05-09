#include <stdio.h>
#include <product.h>

int addOrder(Dessert i, Dessert *d){
	int num = 0;
	printf("\n");
	printf("고르실 제품의 숫자를 입력해주시오.");
    	scanf("%d", num);
	if(num-1 <=5)
		d->dc = 'd';
	else
		d->dc = 'c';

        d->name = i[num-1].name;
	
	d-> cost = i[num-1].cost;
        printf("사이즈는 어떻게 하실껀가요?");
        scanf("%[^\n]s", d->size);

        printf("포장하실껀가요?");
        scanf("%d", &d->togo);

        printf("ice로 하실 껀가요 아니면 hot로 하실 껀가요?");
        scanf("%d", &d->coldHot);

    	
    
    	printf("==> 추가됨\n"); 
    	return 1;
}

void readDessert(Dessert *d){
    printf("%-15s %-15s %4d원 %3d %3d\n", d->name, d->size, d->cost, d->togo, d->coldHot);
}

int updateDessert(Dessert i, Dessert *d){
	int num = 0;
	printf("\n");
	printf("다시 선택하실 제품은 어떤 제품이신가요?");
	scanf("%d", num);
	if(num-1 <= 5)
		d->dc = 'd';
	else
		d->dc = 'c';

	d->name = i[num-1].name;

	printf("사이즈는 어떻게 하실껀가요?");
	scanf("%[^\n]s", d->size);
	
	d->cost = i.[num-1].cost;

	printf("포장하실껀가요?");
	scanf("%d", &d->togo);

	printf("ice로 하실 껀가요 아니면 hot로 하실 껀가요?");
	scanf("%d", &d->coldHot);

	printf("==> 수정됨!\n");
	return 1;
}

int deleteDessert(Dessert *d){
	d->cost = -1;
}
