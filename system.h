//system.h 21700256 박민, 21700305 박지성

typedef struct{ // 디저트 구조체
int dc; // 디저트의 대분류(drink or cake)
char *name; // 디저트의 이름
int num; //디저트 번호
int size; // 음료 디저트 사이즈 (Tall, Grande, Venti)
int cost1; 
int cost2;
int cost3; // 디저트 가격
int togo; // 포장유무 
int temp; // 온도(1(ice) or 2(hot))
} Dessert;

void setArray(Dessert *arr, int count); //사용자의 주문을 담기위한 배열을 default로 초기화(segementation error방지)

void setDessert(Dessert *arr);

void readDessert(Dessert s);

void listDessert(Dessert *s);

int selectOption();

void orderMenu(Dessert s[],Dessert s2[], int count);

void deleteMenu(Dessert *arr);

void yourOrder(Dessert s[],int count);

int updateMenu(Dessert s[],Dessert s2[], int count);