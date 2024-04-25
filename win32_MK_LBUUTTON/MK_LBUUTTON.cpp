#include <iostream>
#include <functional>
#include<stack>
using namespace std;
typedef struct StackNode {
    int data;
    struct StackNode* next;
}Stacknode,*LinkStackPtr;
typedef struct {
    LinkStackPtr top;
    int count;
}LinkStack;
void LinkStackinit(LinkStack* S){
    S->top = NULL;
}
void Push(LinkStack* S, int e) {
    LinkStackPtr p = (LinkStackPtr)malloc(sizeof(Stacknode));
    p->data = e;
    p->next = S->top;
    S->top = p;
    S->count++;
}
int empty(LinkStack* S) {
    if (S->top == NULL) {
        return 0;
    }
    return 1;
}
int Pop(LinkStack* S) {
    if (empty(S))
        return 0;
    int e= S->top->data;
    LinkStackPtr p;
    p = S->top;
    S->top = S->top->next;
    free(p);
    S->count--;
    return e;
}
/* 使用迭代模拟递归 */
int forLoopRecur(int n) {
    LinkStack S;
    LinkStackinit(&S);
    int res = 0;
    for (int i = n; i > 0; i--)
        Push(&S,i);
    while (empty(&S)) {
        res =+(S.top->data);
        Pop(&S);
    }
    return res;
}
int main() {
    int res=forLoopRecur(10);
    cout << res << endl;
}