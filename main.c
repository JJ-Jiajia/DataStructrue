#include <stdio.h>
#include "2.Linear_Lists/Sequential_List.c"

int main() {
    SqList*  list=(SqList*)malloc(sizeof(SqList));
    initSqList(list);
    printf("%d\n",list->listSize);
    return 0;
}