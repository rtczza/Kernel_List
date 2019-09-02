#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

#define pri(fmt, ...) do { 	printf("["__FILE__"][%s]-%d: " ,__FUNCTION__,__LINE__ );\
						printf(fmt, ##__VA_ARGS__);} while (0)

struct car_list
{
	int price;

	struct list_head list;
};

struct car_list car;

int PrintList(struct car_list *car);	//遍历打印链表

int main()
{
	INIT_LIST_HEAD(&(car.list)); //初始化链表

	struct car_list car1;
	struct car_list car2;
	struct car_list car3;
	struct car_list car4;
	struct car_list car5;
	struct car_list car6;

	car1.price = 1111;
	car2.price = 2222;
	car3.price = 3333;

	list_add(&(car1.list), &(car.list)); //把节点加入到链表头中
	list_add(&(car2.list), &(car.list));
	list_add(&(car3.list), &(car.list));


	PrintList(&car);					//遍历打印链表

	car4.price = 4444;
	car5.price = 5555;
	car6.price = 6666;

	list_add_tail(&(car4.list), &(car.list)); //把节点加入到链表尾中
	list_add_tail(&(car5.list), &(car.list));
	list_add_tail(&(car6.list), &(car.list));

	PrintList(&car);					//遍历打印链表
	
	car2.price = 5555;
	car6.price = 5555;

	PrintList(&car);					//遍历打印链表
	
	
	/* 找到价格是5555的节点，并删除 */
	DelListNode(&car, 5555);

	PrintList(&car);					//遍历打印链表


	


	return 0;
}

/* 删除链表car中，数据域为price的节点 */
int DelListNode(struct car_list *car, int price)
{
	if(NULL == car) return -1;
	
	struct list_head *this, *next;
	struct car_list *tmp;		//临时变量，保存遍历时，临时的结构体

	list_for_each_safe(this, next, &(car->list)) //next备份this指针。此处不能用list_for_each
	{
		tmp = list_entry(this, struct car_list, list);

		if(price == tmp->price)
			list_del(this);
	}
	return 0;
}


/* 遍历打印链表 */
int PrintList(struct car_list *car)
{
	if(NULL == car) return -1;
	
	struct list_head *this;		//临时变量，保存链表中指针位置
	struct car_list *tmp;		//临时变量，保存遍历时，临时的结构体

	int i=0;

	printf(" ******************************** \n");

	list_for_each(this, &(car->list)) 	//遍历链表
	{
		tmp = list_entry(this, struct car_list, list);

		printf("[%d]tmp->price :%d \n", i, tmp->price);

		i++;
	}
	printf(" -------------------------------- \n");
	
	return 0;
}
















