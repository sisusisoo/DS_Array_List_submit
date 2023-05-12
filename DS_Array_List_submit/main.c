#include <stdio.h>
#include <stdlib.h>
//커밋

#define MAX_LIST_SIZE 100
int move = 0;
typedef int element;
typedef struct {
	element array[MAX_LIST_SIZE];
	int size;
}ArrayListType;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	return;

}

void init(ArrayListType* L) {
	L->size = 0;
}

int is_empty(ArrayListType* L) {
	return L->size == 0;
}

int is_full(ArrayListType* L) {
	return L->size == MAX_LIST_SIZE;
}

element get_entry(ArrayListType* L, int pos) {
	if (pos < 0 || pos >= L->size) error("위치오류");
	else { return L->array[pos]; }

}

void print_list(ArrayListType* L) {

	int i;
	for (i = 0; i < L->size; i++) {
		printf("%d->", L->array[i]);
	}
	printf("\n");
}
void insert_last(ArrayListType* L, element item) {
	if (L->size >= MAX_LIST_SIZE) {
		error("리스트 오버플로우");

	}
	else {
		L->array[L->size++] = item;
	}
}

void insert(ArrayListType* L, int pos, element item) {
	if (L->size < pos) {
		error("size overflow");


	}
	else if (!is_full(L) && (L->size >= 0) && (pos <= L->size)) {
		move = 0;
		for (int i = (L->size - 1); i >= pos; i--) {
			L->array[i + 1] = L->array[i];
			move++;
		}
		L->size++;
		L->array[pos] = item;

	}
}
element delete(ArrayListType* L, int pos) {

	element item;
	if (pos < 0 || pos >= L->size) {
		error("위치오류");
	}
	else {
		move = 0;
		item = L->array[pos];
		for (int i = pos; i < (L->size - 1); i++) {
			L->array[i] = L->array[i + 1];
			move++;

		}
		L->size--;
		return item;

	}
}
void selecting(ArrayListType* L, int inputSel) {
	int inputItem = 0;
	int inputPos = 0;
	int outputNum;
	switch (inputSel) {
	case 1:
		printf("Enter the number and position :");
		scanf_s("%d %d", &inputPos, &inputItem);

		insert(L, inputPos, inputItem);//1부터 시작하게끔 하려고 
		printf("\n");
		printf("move: %d\n", move);
		break;
	case 2:
		printf("Enter the position :");
		scanf_s("%d", &inputPos);

		printf("move: %d\n", move);
		printf("delete: %d \n", delete(L, inputPos));
		printf("\n");

		break;
	case 3:
		print_list(L);
		break;
	case 4:
		exit(1);



	}
}
int main() {
	ArrayListType L;
	init(&L);
	int exit = 1;
	int inputSel;
	while (exit) {

		printf("(1) Insert(Start 0 / pos,value)\n");
		printf("(2) Delet\n");
		printf("(3) Print\n");
		printf("(4) Exit\n");
		printf("Enter the menu:");
		scanf_s("%d", &inputSel);
		if (inputSel < 5 && inputSel>0) {
			selecting(&L, inputSel);
		}
		else {

			printf("not correct number! try again\n");
		}



	}
}
