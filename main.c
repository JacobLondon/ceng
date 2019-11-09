#include <stdio.h>
#include <string.h>

#include "demo/demo.h"

int main(int argc, char **argv)
{
    for (int i = 0; i < argc; i++) {
        if (argv[i][0] == '-') {
            switch (argv[i][1]) {
            case 'f':
                first();
                goto Exit;
            case 'c':
                circle();
                goto Exit;
            }
        }
    }

Exit:
    return 0;
}
