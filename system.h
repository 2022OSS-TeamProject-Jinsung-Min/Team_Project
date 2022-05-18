//system.h 21700256 박민, 21700305 박지성

typedef struct{ // 디저트 구조체
int dc; // 디저트의 대분류(drink or cake)(1.커피, 2.케이크)
char *name; // 디저트의 이름
int num; //디저트 번호
int size; // 음료 디저트 사이즈 (Tall, Grande, Venti)(1, 2, 3)
int cost1; 
int cost2;
int cost3; // 디저트 가격
int togo; // 포장유무(1.포장 2.매장) 
int temp; // 온도(1(ice) or 2(hot))
} Dessert;

void savaOrder(Dessert s[], int count);//구현필요

void loadLastOrder(Dessert *s);//구현필요

void setArray(Dessert *arr, int count); //사용자의 주문을 담기위한 배열을 default로 초기화(segementation error방지)

void setDessert(Dessert *arr);

void readDessert(Dessert s);

void listDessert(Dessert *s);

int selectOption();

void orderMenu(Dessert s[],Dessert s2[], int count);

void deleteMenu(Dessert *arr);

void yourOrder(Dessert s[],int count);

int updateMenu(Dessert s[],Dessert s2[], int count);

void saveOrder(Dessert s[], int count); 

int loadOrder(Dessert *s[]);