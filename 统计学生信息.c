#include<stdio.h>
#include<stdlib.h>
struct Student {
    char name[20];
    int id;//学号
    int math;
    int chinese;
    int sum;
};
int cmp(const void* a, const void* b) 
{
    int mark1 = ((struct Student*)a)->sum;
    int mark2 = ((struct Student*)b)->sum;
    int id1= ((struct Student*)a)->id;
    int id2 = ((struct Student*)b)->id;
    if (mark1 != mark2)
    {
        return mark2 - mark1;//大到小排序
    }
    else
    {
        return id1 - id2;//第二字段排序
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    struct Student* stu = (struct Student*)malloc(sizeof(struct Student) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %d %d", stu[i].name, &stu[i].id, &stu[i].math, &stu[i].chinese);
        stu[i].sum = stu[i].chinese + stu[i].math;
    }
    qsort(stu, n, sizeof(struct Student), cmp);//按总分排序
    for (int i = 0; i < n; i++)
    {
        printf("%s %d\n", stu[i].name, stu[i].sum);
    }
    free(stu);
}