#include "tests.h"
#include "binary.h"
#include <stdio.h>

// a test case that does nothing and succeeds
static void convert_binary_to_decimal(void **state)
{
    (void) state; // unused

    int result = 0;

    // convert binary to decimal
    result = convertBinaryToDecimal(11111111);

    printf("oyvey: %d", result);

    assert_int_equal(255, result);
}

static void convert_decimal_to_binary(void **state)
{
    (void) state; // unused

    long long result = 0;

    result = convertDecimalToBinary(255);

    assert_int_equal(11111111, result);
}

// a test case that does nothing and succeeds
static void null_test_success(void **state)
{
    (void) state; // unused
}

static void failing_test() {
	assert_false(1 != 2);
}

int main(void)
{
    const struct CMUnitTest do_something_tests[] = {
        cmocka_unit_test(convert_binary_to_decimal),
        cmocka_unit_test(convert_decimal_to_binary),
        cmocka_unit_test(null_test_success),
        cmocka_unit_test(failing_test),
    };

    return cmocka_run_group_tests(do_something_tests, NULL, NULL);
}
