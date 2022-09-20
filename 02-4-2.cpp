#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(void)
{
    //srand(time(NULL));
    printf("%d\n", time(NULL));
    printf("%d\n", time(NULL));
    printf("%d\n", time(NULL));
    printf("\n");
    // srand(1);

    printf("hellop\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Random number #%d: %d\n", i, rand());
        printf("Random number #%d: %d\n", i, rand());
        printf("Random number #%d: %d\n", i, rand()%100);
        printf("Random number #%d: %d\n", i, rand()%100);
    }

    srand(2);

    printf("hellop\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Random number #%d: %d\n", i, rand());
        printf("Random number #%d: %d\n", i, rand());
        printf("Random number #%d: %d\n", i, rand()%100);
        printf("Random number #%d: %d\n", i, rand()%100);
    }

    return 0;
}