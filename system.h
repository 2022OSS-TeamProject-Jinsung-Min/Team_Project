//system.h 21700256 박민, 21700305 박지성
//수정필요
typedef struct{ // 디저트 구조체
int dc; // 디저트의 대분류(drink or cake)
char *name; // 디저트의 이름
int size; // 음료 디저트 사이즈 (Tall, Grande, Venti)
int cost1; //
int cost2;
int cost3; // 디저트 가격
int togo; // 포장유무 
int coldHot; // 온도(1(ice) or 2(hot))
} Dessert;

void readDessert(Dessert s);

void listDessert(Dessert *s, int count);

int selectMenu(); 

void orderMenu(Dessert *s);

void deleteMenu(Dessert *arr);

void yourOrder(Dessert *s, int count);

void updateMenu(Dessert *s);
