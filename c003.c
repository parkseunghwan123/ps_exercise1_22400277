/*
Programming Studio C003
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findRoom(int persons[5]); // 5���� ȣ�� �� �� ���尡 �ִ� ���� ã�Ƴ���. (���ϰ� 1~5)
void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc); // ���� ����� ����Ѵ�.

int main() {
    char mnames[10][20]; // ���л����(�ִ� 10��)
    int mroom[10];       // ���л���ܺ� ȣ�� ���� ���
    char wnames[10][20]; // ���л����(�ִ� 10��)
    int wroom[10];       // ���л���ܺ� ȣ�� ���� ���
    int person[2][5] = {0}; // 2�� ���� 5�� ȣ���� ���� �ο� �� 
    int mcount = 0, wcount = 0; // �ο� �հ� (��, ��)
    int menu;

    srand(time(0));
    printf("===========================================\n");
    printf("��Ȱ�� ȣ�� ���� ���α׷�\n");
    printf("===========================================\n");

    while (1) {
        printf("�޴� : 1.���л� ��� 2.���л� ��� 0.���� > ");
        scanf("%d", &menu);
        if (menu == 0) break;
        else if (menu == 1) {
            if (mcount >= 10) {
                printf("���� �ʰ��Դϴ�. ��ϺҰ�!\n");
                continue;
            }
            printf("�л� �̸���? > ");
            scanf("%s", mnames[mcount]);
            int roomno = findRoom(person[0]);
            if (roomno != -1) {
                mroom[mcount] = 100 + roomno; // 100���� ȣ�� ����
                printf("%s �л� %dȣ�� �����Ǿ����ϴ�.\n", mnames[mcount], mroom[mcount]);
                person[0][roomno - 1]++; // ���л� ����
                mcount++;
            }
        }
        else if (menu == 2) {
            if (wcount >= 10) {
                printf("���� �ʰ��Դϴ�. ��ϺҰ�!\n");
                continue;
            }
            printf("�л� �̸���? > ");
            scanf("%s", wnames[wcount]);
            int roomno = findRoom(person[1]);
            if (roomno != -1) {
                wroom[wcount] = 200 + roomno; // 200���� ȣ�� ����
                printf("%s �л� %dȣ�� �����Ǿ����ϴ�.\n", wnames[wcount], wroom[wcount]);
                person[1][roomno - 1]++; // ���л� ����
                wcount++;
            }
        }
    }

    printf("===========================================\n");
    printf("��Ȱ�� ȣ�� ���� ����� ������ �����ϴ�.\n");
    printf("===========================================\n");
    printReport(mnames, mroom, mcount, wnames, wroom, wcount);

    return 0;
}

int findRoom(int persons[5]) {
// �� ���� ���� ������ �ڵ� ����

    // �� ���� ��ȣ�� ���� �迭�� �� ���� ����
    int aRoom[5];
    int count = 0;

    // �� ���� ã�Ƽ� aRoom�� ����
    for (int i = 0; i < 5; i++) {
        // �� ȣ�ǿ� ������ ����� 2�� �̸��� ��
        if (persons[i] < 2) { 
            // �� �� ��ȣ ����
            aRoom[count] = i;  
            count++;
        }
    }

    if (count == 0) {
        return -1; // �� ���� ������ -1 ��ȯ
    }

    // �������� �� �� ����
    srand(time(0));
    int randomIndex = rand() % count;

    return aRoom[randomIndex] + 1; // 1���� 5������ �� ��ȣ ��ȯ
}

void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc) {
// �� ���� ���� ������ �ڵ� ����
    
    // ���л� ��� ���
    printf("���л� ��� (%d��)\n", mc);
    for (int i = 0; i < mc; i++) {
        printf("%d. %s [%dȣ]\n", i + 1, mn[i], mr[i]);
    }

    printf("\n");

    // ���л� ��� ���
    printf("���л� ��� (%d��)\n", wc);
    for (int i = 0; i < wc; i++) {
        printf("%d. %s [%dȣ]\n", i + 1, wn[i], wr[i]);
    }

    printf("\n");

    // ȣ�Ǻ� ���� ��� ���
    printf("ȣ�Ǻ� ���� ���\n");

    // ȣ�� ����: 101ȣ�Ǻ��� 105ȣ�Ǳ���
    for (int i = 1; i <= 5; i++) {
        // 101ȣ~105ȣ�� 100����, 201ȣ~205ȣ�� 200����
        int roomNumber1 = 100 + i; // 101ȣ, 102ȣ, 103ȣ, 104ȣ, 105ȣ
        int roomNumber2 = 200 + i; // 201ȣ, 202ȣ, 203ȣ, 204ȣ, 205ȣ

        // 101~105ȣ�� ���� ���� Ȯ��
        printf("%d : ", roomNumber1); 
        int hasPerson = 0;  // �ش� ȣ�ǿ� ������ ����� �ִ��� üũ
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

        // 201~205ȣ�� ���� ���� Ȯ��

    for(int i=0; i<=5; i++){
        int roomNumber2 = 200 + i; // 201ȣ, 202ȣ, 203ȣ, 204ȣ, 205ȣ

        printf("%d : ", roomNumber2); 
        int hasPerson = 0;  // �ش� ȣ�ǿ� ������ ����� �ִ��� üũ
        for (int j = 0; j < wc; j++) {
            if (wr[j] == roomNumber2) {
                if (hasPerson) {
                    printf(" ");
                }
                printf("%s", wn[j]);
                hasPerson = 1;
            }
        }

        // ȣ�Ǻ� ��� ��� ������
        printf("\n");
    }
}
