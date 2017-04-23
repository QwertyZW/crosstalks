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
    assert_int_equal(x.length, 2);
    x = matchKeyword("the if is not at the start here");
    assert_int_equal(x.length, 0);
}

static void matchKeyword_test_continue(void **state) {
    (void) state; /* unused */

    match x = matchKeyword("continue it's etc");
    assert_int_equal(x.length, 8);
    x = matchKeyword("the continue is not at the start here");
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

static void matchSymbol_test_1char_alpha(void **state){
    (void) state; /* unused */
    
    match x = matchSymbol("a symbol");
    assert_int_equal(x.length, 1);
}

static void matchSymbol_test_1char_digit(void **state){
    (void) state; /* unused */

    match x = matchSymbol("1 symbol");
    assert_int_equal(x.length, 0);
}

static void matchSymbol_test_mulchar(void **state){
    (void) state; /* unused */

    match x = matchSymbol("abc1 symbol");
    assert_int_equal(x.length, 4);
}

static void matchSymbol_test_null(void **state){
    (void) state; /* unused */

    match x = matchSymbol(0);
    assert_int_equal(x.length, 0);
}

static void matchSymbol_test_empty(void **state){
    (void) state; /* unused */

    match x = matchSymbol("");
    assert_int_equal(x.length, 0);
}

static void isAlphaOrUnderscore_test(void **state){
    (void) state; /* unused */

    assert_int_equal(isAlphaOrUnderscore('A'), 1);
    assert_int_equal(isAlphaOrUnderscore('Z'), 1);
    assert_int_equal(isAlphaOrUnderscore('a'), 1);
    assert_int_equal(isAlphaOrUnderscore('z'), 1);
    assert_int_equal(isAlphaOrUnderscore('_'), 1);
    assert_int_equal(isAlphaOrUnderscore('G'), 1);
    assert_int_equal(isAlphaOrUnderscore('g'), 1);
    assert_int_equal(isAlphaOrUnderscore('-'), 0);
    assert_int_equal(isAlphaOrUnderscore('5'), 0);
}

static void isDigit_test(void **state){
    (void) state; /* unused */

    assert_int_equal(isDigit('a'), 0);
    assert_int_equal(isDigit('0'), 1);
    assert_int_equal(isDigit('9'), 1);
    assert_int_equal(isDigit('5'), 1);
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
        cmocka_unit_test(matchKeyword_test_null),
        cmocka_unit_test(matchSymbol_test_1char_alpha),
        cmocka_unit_test(matchSymbol_test_1char_digit),
        cmocka_unit_test(matchSymbol_test_mulchar),
        cmocka_unit_test(matchSymbol_test_null),
        cmocka_unit_test(matchSymbol_test_empty),
        cmocka_unit_test(isAlphaOrUnderscore_test),
        cmocka_unit_test(isDigit_test)
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
