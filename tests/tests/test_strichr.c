#include "../tests.h"

MunitResult test_strichr(const MunitParameter params[], void *data)
{
	(void)params;
	(void)data;

	munit_assert_int(ft_strichr("abcdefghijklmnop", 'b'), ==, 1);
	munit_assert_int(ft_strichr("0123456789", '9'), ==, 9);
	munit_assert_int(ft_strichr("abcdefghijklmnop", 'q'), ==, -1);
	munit_assert_int(ft_strichr("01234567891", '1'), ==, 1);
	munit_assert_int(ft_strichr("", '0'), ==, -1);
	munit_assert_int(ft_strichr("aaa", '\0'), ==, -1);
	munit_assert_int(ft_strichr("", '\0'), ==, -1);

	return (MUNIT_OK);
}
