#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
 // Check for invalid usage
    if (argc < 2 || argc > 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
}