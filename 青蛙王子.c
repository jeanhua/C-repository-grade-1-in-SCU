#include <stdio.h>

// ���������ж��Ƿ����ͨ����������Ծ��ʽ����Ŀ��ص�
int canReachDestination(int jump1, int jump2, int destination) {
    // �������п��ܵ���Ծ����
    for (int x = 0; x <= 10; x++) {
        for (int y = 0; y <= 10; y++) {
            // ����Ƿ���һ����Ծ��ʽ���Ե���Ŀ��ص�
            if (x * jump1 + y * jump2 == destination || y * jump1 + x * jump2 == destination ||
                x * jump1 - y * jump2 == destination || y * jump1 - x * jump2 == destination) {
                return 1; // ���Ե���
            }
        }
    }
    return 0; // ���ܵ���
}

int main() {
    int jump1, jump2, destination;

    // ��ȡ����
    scanf("%d %d %d", &jump1, &jump2, &destination);

    // �ж��Ƿ����ͨ����������Ծ��ʽ����Ŀ��ص�
    if (canReachDestination(jump1, jump2, destination)) {
        printf("Yes\n");
    }
    else {
        printf("No\n");
    }

    return 0;
}
