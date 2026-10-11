#include <stdio.h>
#include <stdlib.h> // 【必须】malloc 和 free 都在这个头文件里
#include <string.h>

struct student {
    char name[20];
    int score;
    struct student *next;
};

int main() {
    system("chcp 65001");
    
    struct student *head = NULL; // 链表头指针，初始为空（啥都没有）
    struct student *tail = NULL; // 链表尾指针，方便我们在尾巴后面继续接新节点
    struct student *p;           // 用来遍历的指针

    int count = 0; // 记录一共输入了几个学生

    printf("请输入学生姓名和分数（输入 0 0 结束）：\n");

    while (1) {
        char tempName[20];
        int tempScore;

        // 1. 先读取数据到一个临时变量里
        scanf("%s %d", tempName, &tempScore);

        // 2. 如果输入了 0 0，就跳出循环，结束输入
        if (tempScore == 0) {
            break;
        }

        // 3. 【核心】向系统申请一块新内存，大小为 struct student
        struct student *newNode = (struct student*)malloc(sizeof(struct student));
        
        // 必须判断是不是申请失败（比如内存满了）
        if (newNode == NULL) {
            printf("内存不足，创建节点失败！\n");
            break;
        }

        // 4. 把数据塞进这个新节点
        strcpy(newNode->name, tempName);
        newNode->score = tempScore;
        newNode->next = NULL; // 新节点是目前的最后一个，后面还没人

        // 5. 把新节点挂到链表上
        if (head == NULL) {
            // 如果现在是空链表，那新节点就是头，也是尾
            head = newNode;
            tail = newNode;
        } else {
            // 如果已经有节点了，就把它挂在尾巴后面，然后更新尾指针
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }

    // 6. 遍历打印我们建好的动态链表
    printf("\n====== 你的动态链表里有 %d 个学生 ======\n", count);
    p = head;
    while (p != NULL) {
        printf("%s %d\n", p->name, p->score);
        p = p->next;
    }

    // 7. 【极其重要】释放内存！用 malloc 借的，用完一定要还，不然会内存泄漏！
    printf("\n====== 释放内存中... ======\n");
    p = head;
    while (p != NULL) {
        struct student *temp = p; // 先记住当前节点
        p = p->next;              // 让 p 先走到下一个节点
        free(temp);               // 然后再释放刚才那个节点
        printf("已释放一个节点\n");
    }
    head = NULL; // 重置头指针

    return 0;
}