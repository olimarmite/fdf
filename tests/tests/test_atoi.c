#include "../tests.h"

MunitResult test_atoi(const MunitParameter params[], void *data)
{
	int	nbr;

	(void)params;
	(void)data;

	nbr = 1;
	munit_assert_int(ft_atoi("42", &nbr), == ,0);
	munit_assert_int(nbr, ==, 42);

	nbr = 1;
	munit_assert_int(ft_atoi("-142", &nbr), == ,0);
	munit_assert_int(nbr, ==, -142);

	nbr = 1;
	munit_assert_int(ft_atoi("-24ABC", &nbr), ==, 0);
	munit_assert_int(nbr, ==, -24);

	nbr = 1;
	munit_assert_int(ft_atoi("+24", &nbr), == ,0);
	munit_assert_int(nbr, ==, 24);

	nbr = 1;
	munit_assert_int(ft_atoi("2147483647", &nbr), == ,0);
	munit_assert_int(nbr, ==, 2147483647);

	nbr = 1;
	munit_assert_int(ft_atoi("-2147483648", &nbr), ==, 0);
	munit_assert_int(nbr, ==, -2147483648);

	nbr = 1;
	munit_assert_int(ft_atoi(".2ABC", &nbr) , !=, 0);
	munit_assert_int(nbr, ==, 0);

	nbr = 1;
	munit_assert_int(ft_atoi("-", &nbr) , !=, 0);
	munit_assert_int(nbr, ==, 0);

	nbr = 1;
	munit_assert_int(ft_atoi("", &nbr) , !=, 0);
	munit_assert_int(nbr, ==, 0);

	nbr = 1;
	munit_assert_int(ft_atoi("-B", &nbr) , !=, 0);
	munit_assert_int(nbr, ==, 0);

	nbr = 1;
	munit_assert_int(ft_atoi("       	 24", &nbr) , !=, 0);
	munit_assert_int(nbr, ==, 0);

	nbr = 1;
	munit_assert_int(ft_atoi("2147483648", &nbr) , !=, 0);
	munit_assert_int(nbr, ==, 0);

	nbr = 1;
	munit_assert_int(ft_atoi("-2147483649", &nbr) , !=, 0);
	munit_assert_int(nbr, ==, 0);

	return (MUNIT_OK);
}
