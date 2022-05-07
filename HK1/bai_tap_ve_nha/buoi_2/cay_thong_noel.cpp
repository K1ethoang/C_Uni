/*
    Ho Ten: Hoang Gia Kiet
    MSSV: 6251071049
    Lop: IT - 62
 */

#include <stdio.h>

int main()
{
    //         *
    //        ***
    //       *****
    //      *******
    //     *********
    //    ***********
    //   *************
    //        ***
    //        ***
    //        ***

    char c = '*';

    // ! sao

    // dong 1
    printf("%7c\n", c);

    // dong 2

    printf("%6c%c%c\n", c, c, c);

    // dong 3
    printf("%5c%c%c%c%c\n", c, c, c, c, c);

    // dong 4
    printf("%4c%c%c%c%c%c%c\n", c, c, c, c, c, c, c);

    // dong 5
    printf("%3c%c%c%c%c%c%c%c%c\n", c, c, c, c, c, c, c, c, c);
    // dong 6

    printf("%5c%c%c%c%c\n", c, c, c, c, c);
    // dong 7

    printf("%4c%c%c%c%c%c%c\n", c, c, c, c, c, c, c);
    // dong 8

    printf("%3c%c%c%c%c%c%c%c%c\n", c, c, c, c, c, c, c, c, c);
    // dong 9

    printf("%2c%c%c%c%c%c%c%c%c%c%c\n", c, c, c, c, c, c, c, c, c, c, c);
    // dong 10

    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c\n", c, c, c, c, c, c, c, c, c, c, c, c, c);

    // ! Than cay
    // dong 11

    printf("%6c%c%c\n", c, c, c);

    // dong 12
    printf("%6c%c%c\n", c, c, c);

    // dong 13
    printf("%6c%c%c\n", c, c, c);

    return 0;
}
