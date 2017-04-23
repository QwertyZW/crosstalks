#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "lexer.h"
/* A test case that does nothing and succeeds. */
static void beginsWith_test_true(void **state) {
    (void) state; /* unused */

    int x = beginsWith("ifzzzz", "if");
    assert_int_equal(x, 2);
}

/* A test case that does nothing and succeeds. */
static void beginsWith_test_false(void **state) {
    (void) state; /* unused */

    int x = beginsWith("iifzzzz", "if");
    assert_int_equal(x, 0);
}

static void beginsWith_test_param1Null(void **state) {
    (void) state; /* unused */

    int x = beginsWith(0, "if");
    assert_int_equal(x, 0);
}

static void beginsWith_test_param2Null(void **state) {
    (void) state; /* unused */

    int x = beginsWith("iifzzzz", 0);
    assert_int_equal(x, 0);
}

static void beginsWith_test_paramAllNull(void **state) {
    (void) state; /* unused */

    int x = beginsWith(0, 0);
    assert_int_equal(x, 0);
}


static void beginsWith_test_param1Empty(void **state) {
    (void) state; /* unused */

    int x = beginsWith("", "if");
    assert_int_equal(x, 0);
}

static void beginsWith_test_param2Empty(void **state) {
    (void) state; /* unused */

    int x = beginsWith("iifzzzz", "");
    assert_int_equal(x, 0);
}

static void beginsWith_test_paramAllEmpty(void **state) {
    (void) state; /* unused */

    int x = beginsWith("", "");
    assert_int_equal(x, 0);
}

static void matchKeyword_test_if(void **state) {
    (void) state; /* unused */


    match x = matchKeyword("if it's etc");
    assert_int_equal(x.length, strlen("if"));
    x = matchKeyword("the if is not at the start here");
    assert_int_equal(x.length, 0);
    x = matchKeyword("continue it's etc");
    assert_int_equal(x.length, strlen("continue"));
    x = matchKeyword("the if is not at the start here");
    assert_int_equal(x.length, 0);
}

static void matchKeyword_test_continue(void **state) {
    (void) state; /* unused */

    match x = matchKeyword("continue it's etc");
    assert_int_equal(x.length, strlen("continue"));
    x = matchKeyword("the if is not at the start here");
    assert_int_equal(x.length, 0);
}

static void matchKeyword_test_empty(void **state) {
    (void) state; /* unused */

    match x = matchKeyword("");
    assert_int_equal(x.length, 0);
}

static void matchKeyword_test_null(void **state) {
    (void) state; /* unused */

    match x = matchKeyword(0);
    assert_int_equal(x.length, 0);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(beginsWith_test_true),
        cmocka_unit_test(beginsWith_test_false),
        cmocka_unit_test(beginsWith_test_param1Null),
        cmocka_unit_test(beginsWith_test_param2Null),
        cmocka_unit_test(beginsWith_test_paramAllNull),
        cmocka_unit_test(beginsWith_test_param1Empty),
        cmocka_unit_test(beginsWith_test_param2Empty),
        cmocka_unit_test(beginsWith_test_paramAllEmpty),
        cmocka_unit_test(matchKeyword_test_if),
        cmocka_unit_test(matchKeyword_test_continue),
        cmocka_unit_test(matchKeyword_test_empty),
        cmocka_unit_test(matchKeyword_test_null)
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
