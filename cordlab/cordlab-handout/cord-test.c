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
    /* cord_new() */
    const cord_t *c = cord_new("");
    assert(c == NULL);
    assert(cord_length(c) == 0);
    assert(cord_tostring(c) != NULL);

    /* is_cord() */
    /* 1. NULL */
    const cord_t *R1 = NULL;
    assert(is_cord(R1) == true);
    /* 2. Leaf */
    const cord_t *R2 = cord_new("happ");
    assert(R2->len == strlen("happ"));
    assert(R2->left == NULL);
    assert(R2->right == NULL);
    assert(strcmp(R2->data, "happ") == 0);
    assert(is_cord(R2) == true);
    /* 3. Non-leaf */
    const cord_t *R3 = cord_new("y birth");
    assert(is_cord(R3) == true);
    const cord_t *R4 = cord_join(R2, R3);
    assert(R4->left == R2);
    assert(R4->right == R3);
    assert(R4->data == NULL);
    assert(R4->len == cord_length(R4));
    assert(is_cord(R4) == true);
    const cord_t *R5 = cord_new("day!");
    assert(is_cord(R5) == true);
    const cord_t *R6 = cord_join(R4, R5);
    assert(is_cord(R6) == true);

    char *s = "invalid";
    cord_t *invalid1 = (cord_t *)xmalloc(sizeof(cord_t));
    invalid1->len = strlen(s);
    invalid1->left = NULL;
    invalid1->right = NULL;
    invalid1->data = s;
    // modify
    invalid1->len = 2;
    assert(is_cord(invalid1) == false);

    const cord_t *invalid2 = cord_join(R6, invalid1);
    assert(is_cord(invalid2) == false);

    /* cord_tostring() */
    char *S1 = cord_tostring(R1);
    printf("R1: %s\n", S1);
    char *S2 = cord_tostring(R2);
    printf("R2: %s\n", S2);
    char *S3 = cord_tostring(R3);
    printf("R3: %s\n", S3);
    char *S4 = cord_tostring(R4);
    printf("R4: %s\n", S4);
    char *S5 = cord_tostring(R5);
    printf("R5: %s\n", S5);
    char *S6 = cord_tostring(R6);
    printf("R6: %s\n", S6);

    /* cord_charat */
    char c1 = cord_charat(R1, 0);
    char c2 = cord_charat(R2, 0);
    char c3 = cord_charat(R2, 3);
    char c4 = cord_charat(R4, 4);
    printf("%c, %c, %c, %c\n", c1, c2, c3, c4);

    /* cord_sub */
    const cord_t *RR1 = cord_new("t");
    const cord_t *RR2 = cord_new("otally");
    const cord_t *RR3 = cord_join(RR1, RR2);
    
    const cord_t *RR4 = cord_new("efficien");
    const cord_t *RR5 = cord_new("t");
    const cord_t *RR6 = cord_join(RR4, RR5);

    const cord_t *RR = cord_join(RR3, RR6);
    char *RS = cord_tostring(RR);
    printf("%s, %d\n", RS, (int)(strlen(RS)));
    printf("cord_length: %d\n", (int)(cord_length(RR)));

    const cord_t *sub1 = cord_sub(RR, 1, 16);
    printf("%s\n", cord_tostring(sub1));
    const cord_t *sub2 = cord_sub(RR, 1, 11);
    printf("%s\n", cord_tostring(sub2));

    const cord_t *sub3 = cord_sub(RR, 2, 11);
    printf("%s\n", cord_tostring(sub3));

    return 0;
}
