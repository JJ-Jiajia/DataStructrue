#include <stdio.h>
#include <stdlib.h>
#include "../1.PublicDefine/publicDefine.c"
#define LIST_INIT_SIZE 100 //线性表最大初始空间
#define LISTINCREMENT 10 //线性表分配空间增量
typedef struct {
    ElemType * elem;//指针等于说是数组
    int length;
    int listSize;
} SqList;
//初始化函数
Status initSqList(SqList* list){
    list->elem=    (ElemType*) malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!list->elem) exit(OVERFLOW);
    list->length=0;
    list->listSize=LIST_INIT_SIZE;
    return OK;
}
//增量添加
Status increaseSqListLength(SqList* list){
   ElemType * ptr=(ElemType*) realloc(list->elem,LISTINCREMENT*sizeof(ElemType));
    if(NULL==ptr)
        return OVERFLOW;
    list->elem=ptr;
    list->listSize+=LISTINCREMENT;
    return OK;
}
//销毁函数
Status destroyList(SqList* list){
    if(!list) return ERROR;
    free(list);
    return OK;
}
//清空线性表
Status  clearList(SqList* list){
    if(!list) return ERROR;
    list->length=0;
    return OK;
}
//判断是否空顺序线性表
Status listEmpty(SqList* list){
    if(!list) return ERROR;
    if(list->length==0) return TRUE;
    else return  FALSE;
}
//返回长度
int listLength(SqList* list){
    if(!list) return ERROR;
    return list->length;
}
//返回第i个位置元素,从0开始
ElemType getELem(SqList* list,int i){
    if(!list) return ERROR;
    if(i<0 || i>=list->length) return ERROR;
    return list->elem[i];
}
//返回元素在顺序表中的位置 返回i+1
int locateElem(SqList* list,ElemType e){
    int i;
    if(!list || listEmpty(list)) return ERROR;
    for(i=0;i<list->length;i++){
        if(list->elem[i]==e) return i+1;
    }
    if(i=list->length) return INFEASIBLE;
}
//返回前置元素
ElemType priorElem(SqList* list,ElemType e,ElemType* pre_e){
    if(locateElem(list,e)) {
        *pre_e=getELem(list,locateElem(list,e));
        return OK;
    }
    return  INFEASIBLE;
}
Status sqListInsert(SqList* list,ElemType e,int position){
    if(++list->length>list->listSize)
        if(-2!=increaseSqListLength(list)){
            for(int i=list->length;i>position;i--){
                list->elem[i]=list->elem[i-1];
            }
            list->elem[position]=e;
            return OK;
        }
    return ERROR;
}