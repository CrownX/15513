/*
 * @file cord.c
 * @brief Implementation of cords library
 *
 * 15-513 Introduction to Computer Systems
 *
 * TODO: fill in your name and Andrew ID below
 * @author XXX <XXX@andrew.cmu.edu>
 */

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "cord-interface.h"
#include "xalloc.h"

/***********************************/
/* Implementation (edit this part) */
/***********************************/

/**
 * @brief Checks if a cord is valid
 * @param[in] R
 * @return
 */
bool is_cord(const cord_t *R) {
    /* NULL */
    if (NULL == R)
        return true;

    /* Leaf */
    if (R->len > 0 && R->len == strlen(R->data))
        return R->left == NULL && R->right == NULL;

    /* Non-leaf */
    if (NULL == R->data) {
        size_t cord_len = 0;
        if (NULL != R->left) {
            if (!is_cord(R->left))
                return false;
            cord_len += R->left->len;
        }
        if (NULL != R->right) {
            if (!is_cord(R->right))
                return false;
            cord_len += R->right->len;
        }
        return cord_len == R->len;
    }

    return false;
}

/**
 * @brief Returns the length of a cord
 * @param[in] R
 * @return
 */
size_t cord_length(const cord_t *R) {
    /* NULL */
    if (NULL == R)
        return 0;

    /* Leaf */
    if (NULL == R->left && NULL == R->right)
        return R->len;

    /* Non-leaf */
    size_t cord_len = 0;
    if (NULL != R->left)
        cord_len += R->left->len;
    if (NULL != R->right)
        cord_len += R->right->len;

    return cord_len;
}

/**
 * @brief Allocates a new cord from a string
 * @param[in] s
 * @return
 */
const cord_t *cord_new(const char *s) {
    /* NULL */
    if (NULL == s || 0 == strlen(s))
        return NULL;

    /* Construct */
    cord_t *R = (cord_t *)xmalloc(sizeof(cord_t));
    R->len = strlen(s);
    R->left = NULL;
    R->right = NULL;
    R->data = s;

    return R;
}

/**
 * @brief Concatenates two cords into a new cord
 * @param[in] R
 * @param[in] S
 * @return
 */
const cord_t *cord_join(const cord_t *R, const cord_t *S) {
    /* NULL */
    if (NULL == R)
        return S;
    if (NULL == S)
        return R;

    /* Construct */
    cord_t *N = (cord_t *)xmalloc(sizeof(cord_t));
    N->len = R->len + S->len;
    N->left = R;
    N->right = S;
    N->data = NULL;

    return N;
}

/**
 * @brief Converts a cord to a string
 * @param[in] R
 * @return
 */
char *cord_tostring(const cord_t *R) {
    char *result = xmalloc(cord_length(R) + 1);
    /* NULL */
    if (NULL == R)
        return result;

    /* Recursion */
    char *left = cord_tostring(R->left);
    char *right = cord_tostring(R->right);

    /* Concatenate */
    strcat(result, left);
    strcat(result, right);

    /* Free */
    free(left);
    free(right);

    return result;
}

/**
 * @brief Returns the character at a position in a cord
 *
 * @param[in] R  A cord
 * @param[in] i  A position in the cord
 * @return The character at position i
 *
 * @requires i is a valid position in the cord R
 */
char cord_charat(const cord_t *R, size_t i) {
    assert(0 <= i && i <= cord_length(R));
    /* NULL */
    if (NULL == R)
        return '\0';

    /* Recurrsion */
    size_t left_len = 0, right_len = 0;
    if (NULL != R->left)
        left_len = R->left->len;
    if (NULL != R->right)
        right_len = R->right->len;

    if (i <= left_len)
        return cord_charat(R->left, i);
    else
        return cord_charat(R->right, i - left_len);
}

/**
 * @brief Gets a substring of an existing cord
 *
 * @param[in] R   A cord
 * @param[in] lo  The low index of the substring, inclusive
 * @param[in] hi  The high index of the substring, exclusive
 * @return A cord representing the substring R[lo..hi-1]
 *
 * @requires lo and hi are valid indexes in R, with lo <= hi
 */
const cord_t *cord_sub(const cord_t *R, size_t lo, size_t hi) {
    assert(0 <= lo && lo <= hi && hi <= cord_length(R));
    /* Not need to sub, include NULL */
    if (0 == lo && hi == cord_length(R))
        return R;

    /* Leaf */
    if (NULL == R->left && NULL == R->right) {
        const char *src = R->data;
        char *dst = xmalloc(hi - lo + 1);
        char *result = dst;
        for (int i = lo; i < hi; i++)
            *(dst + i) = *(src + i);
        return cord_new(result);
    }

    /* Non-leaf */
    size_t left_len = 0, right_len = 0;
    if (NULL != R->left)
        left_len = R->left->len;
    if (NULL != R->right)
        right_len = R->right->len;

    if (hi <= left_len)
        return cord_sub(R->left, lo, hi);
    else if (left_len <= lo)
        return cord_sub(R->right, lo - left_len, hi);
    else {
        const cord_t *left = cord_sub(R->left, lo, left_len);
        const cord_t *right = cord_sub(R->right, left_len, hi);
        return cord_join(left, right);
    }
}
