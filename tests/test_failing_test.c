#include "tests.h"

static void failing_test() {
	assert_false(1 != 2);
}

int main(void) {
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(failing_test),
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}