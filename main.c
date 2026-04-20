#include <stdio.h>
#include <stdlib.h>
#include "posList.h"

int main(void) {
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
                return 0;

            default:
                printf("[오류] 1~5 또는 0을 입력하세요.\n");
        }
    }
}
