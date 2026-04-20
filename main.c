#include <stdio.h>
#include <stdlib.h>
#include "posList.h"
#include "sparseMatrix.h"

/* ──────────────────────────────────────
   과제 1: 양의 정수 순차리스트 메뉴
   ────────────────────────────────────── */
void runMenu() {
    PosList list;
    init(&list);

    int choice;
    int pos, val;

    while (1) {
        printf("\n==============================\n");
        printf("  양의 정수 순차 리스트 메뉴\n");
        printf("==============================\n");
        printf("1. 삽입 (insert)\n");
        printf("2. 삭제 (delete)\n");
        printf("3. 변경 (replace)\n");
        printf("4. 출력 (print)\n");
        printf("5. 전체 삭제 (clear)\n");
        printf("0. 종료\n");
        printf("선택: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("삽입할 위치 (1 ~ %d): ", list.size + 1);
                scanf("%d", &pos);
                printf("삽입할 양의 정수: ");
                scanf("%d", &val);
                insert(&list, pos, val);
                break;

            case 2:
                printf("삭제할 위치 (1 ~ %d): ", list.size);
                scanf("%d", &pos);
                deleteAt(&list, pos);
                break;

            case 3:
                printf("변경할 위치 (1 ~ %d): ", list.size);
                scanf("%d", &pos);
                printf("새로운 양의 정수: ");
                scanf("%d", &val);
                replace(&list, pos, val);
                break;

            case 4:
                printList(&list);
                break;

            case 5:
                clearList(&list);
                break;

            case 0:
                destroy(&list);
                printf("프로그램 종료\n");
                return;

            default:
                printf("[오류] 1~5 또는 0을 입력하세요.\n");
        }
    }
}

/* ──────────────────────────────────────
   과제 2: 희소행렬 + 전치행렬
   ────────────────────────────────────── */
void runSparseMatrix() {
    SparseMatrix* sm;
    sm_init(&sm, 10, 10);

    /* 10x10 희소행렬, 0이 아닌 원소 20개 초기화 */
    int data[20][3] = {
        {0,1,3}, {0,4,7}, {1,2,5}, {1,7,2},
        {2,0,9}, {2,5,1}, {3,3,4}, {3,8,6},
        {4,1,8}, {4,6,3}, {5,0,2}, {5,9,5},
        {6,2,7}, {6,4,1}, {7,3,9}, {7,7,4},
        {8,5,6}, {8,8,2}, {9,1,3}, {9,6,8}
    };

    for (int i = 0; i < 20; i++) {
        sm_add(sm, data[i][0], data[i][1], data[i][2]);
    }

    printf("\n==============================\n");
    printf("   과제 2: 희소행렬\n");
    printf("==============================\n");
    sm_print(sm);

    /* 전치행렬 */
    int moveCount = 0;
    SparseMatrix* trans = sm_transpose(sm, &moveCount);

    printf("\n[전치행렬]\n");
    sm_print(trans);
    printf("\n데이터 이동 횟수: %d회\n", moveCount);

    sm_destroy(&sm);
    sm_destroy(&trans);
}

/* ──────────────────────────────────────
   main
   ────────────────────────────────────── */
int main(void) {
    int sel;
    printf("==============================\n");
    printf("  과제 선택\n");
    printf("==============================\n");
    printf("1. 과제1 - 양의 정수 순차리스트\n");
    printf("2. 과제2 - 희소행렬 전치\n");
    printf("선택: ");
    scanf("%d", &sel);

    if (sel == 1)      runMenu();
    else if (sel == 2) runSparseMatrix();
    else               printf("잘못된 선택\n");

    return 0;
}
