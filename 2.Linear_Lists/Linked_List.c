#include <stdio.h>
#include <stdlib.h>
#include "../1.PublicDefine/publicDefine.c"

typedef struct {
    ElemType data;//指针等于说是数组
    LinkList next;
} LNode, *LinkList;

//初始化函数
LinkList initLinkList(void) {
    LinkList L = (LinkList) malloc(sizeof(LNode));
    L->next = NULL;
    return L;
}

Status CreateList(LinkList l, int n) {

}

//销毁函数
Status destroyList(LinkList list) {
    if (!list) return ERROR;
    free(list);
    return OK;
}

//清空线性表
Status clearList(LinkList list) {
    if (!list) return ERROR;
    list->length = 0;
    return OK;
}

//判断是否空顺序线性表
Status listEmpty(LinkList list) {
    if (!list) return ERROR;
    if (list->length == 0) return TRUE;
    else return FALSE;
}

//返回长度
int listLength(LinkList list) {
    if (!list) return ERROR;
    return list->length;
}

//返回第i个位置元素,从0开始
ElemType getELem(LinkList list, int i) {
    if (!list) return ERROR;
    if (i < 0 || i >= list->length) return ERROR;
    return list->elem[i];
}

//返回元素在顺序表中的位置 返回i+1
int locateElem(LinkList list, ElemType e) {
    int i;
    if (!list || listEmpty(list)) return ERROR;
    for (i = 0; i < list->length; i++) {
        if (list->elem[i] == e) return i + 1;
    }
    if (i = list->length) return INFEASIBLE;
}

//返回前置元素
ElemType priorElem(LinkList list, ElemType e, ElemType *pre_e) {
    if (locateElem(list, e)) {
        *pre_e = getELem(list, ocateElem(list, e));
        return OK;
    }
    return INFEASIBLE;
}
//

