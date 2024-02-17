#include <stdio.h>

// 函数用于判断是否可以通过给定的跳跃方式到达目标地点
int canReachDestination(int jump1, int jump2, int destination) {
    // 遍历所有可能的跳跃次数
    for (int x = 0; x <= 10; x++) {
        for (int y = 0; y <= 10; y++) {
            // 检查是否有一种跳跃方式可以到达目标地点
            if (x * jump1 + y * jump2 == destination || y * jump1 + x * jump2 == destination ||
                x * jump1 - y * jump2 == destination || y * jump1 - x * jump2 == destination) {
                return 1; // 可以到达
            }
        }
    }
    return 0; // 不能到达
}

int main() {
    int jump1, jump2, destination;

    // 读取输入
    scanf("%d %d %d", &jump1, &jump2, &destination);

    // 判断是否可以通过给定的跳跃方式到达目标地点
    if (canReachDestination(jump1, jump2, destination)) {
        printf("Yes\n");
    }
    else {
        printf("No\n");
    }

    return 0;
}
