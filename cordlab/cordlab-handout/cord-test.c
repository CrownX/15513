/**
 * @file cord-test.c
 * @brief Program to test cords functionality
 */

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cord-interface.h"
#include "xalloc.h"

int main(int argc, char **argv) {
    printf("This is cord-test.c");

    const cord_t *c = cord_new("");
    assert(c == NULL);
    assert(cord_length(c) == 0);
    assert(cord_tostring(c) != NULL);


    return 0;
}
