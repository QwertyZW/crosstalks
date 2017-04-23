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

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(beginsWith_test_true),
        cmocka_unit_test(beginsWith_test_false),
        cmocka_unit_test(beginsWith_test_param1Null),
        cmocka_unit_test(beginsWith_test_param2Null),
        cmocka_unit_test(beginsWith_test_paramAllNull),
        cmocka_unit_test(beginsWith_test_param1Empty),
        cmocka_unit_test(beginsWith_test_param2Empty),
        cmocka_unit_test(beginsWith_test_paramAllEmpty)
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
