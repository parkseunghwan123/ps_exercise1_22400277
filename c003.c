/*
Programming Studio C003
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findRoom(int persons[5]); // 5개의 호실 중 빈 베드가 있는 방을 찾아낸다. (리턴값 1~5)
void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc); // 배정 결과를 출력한다.

int main() {
    char mnames[10][20]; // 남학생명단(최대 10명)
    int mroom[10];       // 남학생명단별 호실 배정 목록
    char wnames[10][20]; // 여학생명단(최대 10명)
    int wroom[10];       // 여학생명단별 호실 배정 목록
    int person[2][5] = {0}; // 2개 층별 5개 호실의 배정 인원 수 
    int mcount = 0, wcount = 0; // 인원 합계 (남, 여)
    int menu;

    srand(time(0));
    printf("===========================================\n");
    printf("생활관 호실 배정 프로그램\n");
    printf("===========================================\n");

    while (1) {
        printf("메뉴 : 1.남학생 등록 2.여학생 등록 0.종료 > ");
        scanf("%d", &menu);
        if (menu == 0) break;
        else if (menu == 1) {
            if (mcount >= 10) {
                printf("정원 초과입니다. 등록불가!\n");
                continue;
            }
            printf("학생 이름은? > ");
            scanf("%s", mnames[mcount]);
            int roomno = findRoom(person[0]);
            if (roomno != -1) {
                mroom[mcount] = 100 + roomno; // 100번대 호실 배정
                printf("%s 학생 %d호실 배정되었습니다.\n", mnames[mcount], mroom[mcount]);
                person[0][roomno - 1]++; // 남학생 배정
                mcount++;
            }
        }
        else if (menu == 2) {
            if (wcount >= 10) {
                printf("정원 초과입니다. 등록불가!\n");
                continue;
            }
            printf("학생 이름은? > ");
            scanf("%s", wnames[wcount]);
            int roomno = findRoom(person[1]);
            if (roomno != -1) {
                wroom[wcount] = 200 + roomno; // 200번대 호실 배정
                printf("%s 학생 %d호실 배정되었습니다.\n", wnames[wcount], wroom[wcount]);
                person[1][roomno - 1]++; // 여학생 배정
                wcount++;
            }
        }
    }

    printf("===========================================\n");
    printf("생활관 호실 배정 결과는 다음과 같습니다.\n");
    printf("===========================================\n");
    printReport(mnames, mroom, mcount, wnames, wroom, wcount);

    return 0;
}

int findRoom(int persons[5]) {
// 이 곳에 생각 정리와 코드 구현

    // 빈 방의 번호를 받을 배열과 빈 방의 개수
    int aRoom[5];
    int count = 0;

    // 빈 방을 찾아서 aRoom에 저장
    for (int i = 0; i < 5; i++) {
        // 각 호실에 배정된 사람이 2명 미만일 때
        if (persons[i] < 2) { 
            // 빈 방 번호 저장
            aRoom[count] = i;  
            count++;
        }
    }

    if (count == 0) {
        return -1; // 빈 방이 없으면 -1 반환
    }

    // 랜덤으로 빈 방 선택
    srand(time(0));
    int randomIndex = rand() % count;

    return aRoom[randomIndex] + 1; // 1부터 5까지의 방 번호 반환
}

void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc) {
// 이 곳에 생각 정리와 코드 구현
    
    // 남학생 명단 출력
    printf("남학생 명단 (%d명)\n", mc);
    for (int i = 0; i < mc; i++) {
        printf("%d. %s [%d호]\n", i + 1, mn[i], mr[i]);
    }

    printf("\n");

    // 여학생 명단 출력
    printf("여학생 명단 (%d명)\n", wc);
    for (int i = 0; i < wc; i++) {
        printf("%d. %s [%d호]\n", i + 1, wn[i], wr[i]);
    }

    printf("\n");

    // 호실별 배정 명단 출력
    printf("호실별 배정 명단\n");

    // 호실 배정: 101호실부터 105호실까지
    for (int i = 1; i <= 5; i++) {
        // 101호~105호는 100번대, 201호~205호는 200번대
        int roomNumber1 = 100 + i; // 101호, 102호, 103호, 104호, 105호
        int roomNumber2 = 200 + i; // 201호, 202호, 203호, 204호, 205호

        // 101~105호에 대한 배정 확인
        printf("%d : ", roomNumber1); 
        int hasPerson = 0;  // 해당 호실에 배정된 사람이 있는지 체크
        for (int j = 0; j < mc; j++) {
            if (mr[j] == roomNumber1) {
                if (hasPerson) {
                    printf(" ");
                }
                printf("%s", mn[j]);
                hasPerson = 1;
            }
        }
        printf("\n");
    }

        // 201~205호에 대한 배정 확인

    for(int i=0; i<=5; i++){
        int roomNumber2 = 200 + i; // 201호, 202호, 203호, 204호, 205호

        printf("%d : ", roomNumber2); 
        int hasPerson = 0;  // 해당 호실에 배정된 사람이 있는지 체크
        for (int j = 0; j < wc; j++) {
            if (wr[j] == roomNumber2) {
                if (hasPerson) {
                    printf(" ");
                }
                printf("%s", wn[j]);
                hasPerson = 1;
            }
        }

        // 호실별 명단 출력 마무리
        printf("\n");
    }
}
