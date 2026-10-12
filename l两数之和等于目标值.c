#include<stdio.h>
#include<stdlib.h>
int main()
#include <stdio.h>
#include <stdlib.h>

/*
 * 两数之和：找出数组中两个下标不同的数，使它们的和等于目标值。
 *
 * 输入格式：
 *     第一行：目标值 target
 *     之后：  若干个整数，以 -1 结束（-1 本身不算数据）
 * 输出格式：
 *     [i,j]  找到的一对下标；没有找到时输出 “没有找到”
 */

#define MAXN 1000 /* 约定：数字个数小于 1000 */

int main(void)
{
    int *nums;      /* 动态数组 */
    int target;     /* 目标值 */
    int count = 0;  /* 实际读进来几个数 */
    int i, j;
    int found = 0;  /* 是否已经找到答案 */

    /* 1. 先读目标值；读不到就说明输入有问题，直接结束 */
    if (scanf("%d", &target) != 1) {
        fprintf(stderr, "没有读到目标值\n");
        return 1;
    }

    /* 2. 申请内存，必须判断是否成功，否则后面 nums[...] 会崩 */
    nums = (int *)malloc(MAXN * sizeof(int));
    if (nums == NULL) {
        fprintf(stderr, "内存不足\n");
        return 1;
    }

    /* 3. 读数据：
     *    count < MAXN   —— 防止越界写（第 1001 个数不会再塞进来）
     *    scanf != 1     —— 读到 EOF 或非数字就退出，不会死循环
     *    value == -1    —— 按约定结束输入
     *    先读到临时变量 value，确认有效才存进数组，
     *    这样数组里永远不会出现“没读到”的脏数据 */
    while (count < MAXN) {
        int value;
        if (scanf("%d", &value) != 1) {
            fprintf(stderr, "输入提前结束（没有读到 -1）\n");
            break;
        }
        if (value == -1) {
            break;
        }
        nums[count] = value;
        count++;
    }
    if (count == MAXN) {
        fprintf(stderr, "数字超过 %d 个，只处理前 %d 个\n", MAXN, MAXN);
    }

    /* 4. 暴力枚举每一对下标（j 从 i+1 开始，每对只查一次，也不用再判断 i != j） */
    for (i = 0; i < count && !found; i++) {
        for (j = i + 1; j < count; j++) {
            if (nums[i] + nums[j] == target) {
                printf("[%d,%d]\n", i, j);
                found = 1;
                break;
            }
        }
    }
    if (!found) {
        printf("没有找到\n"); /* 不需要这句的话删掉即可 */
    }

    /* 5. malloc 借的必须还 */
    free(nums);
    nums = NULL;

    return 0;
}
