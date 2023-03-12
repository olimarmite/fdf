#include "../tests.h"

# define HEX_UC_ALPHABET "0123456789ABCDEF"
# define DEC_ALPHABET "0123456789"

MunitResult test_atoi_base(const MunitParameter params[], void *data)
{
	int	nbr;
	(void)params;
	(void)data;

	nbr = 1;
	munit_assert_int(ft_atoi_base("2", &nbr, DEC_ALPHABET, 10), ==, 0);
	munit_assert_int(nbr, ==, 2);

	nbr = 1;
	munit_assert_int(ft_atoi_base("42", &nbr, DEC_ALPHABET, 10), ==, 0);
	munit_assert_int(nbr, ==, 42);

	nbr = 1;
	munit_assert_int(ft_atoi_base("-7542", &nbr, DEC_ALPHABET, 10), ==, 0);
	munit_assert_int(nbr, ==, -7542);

	nbr = 1;
	munit_assert_int(ft_atoi_base("-24ABC", &nbr, DEC_ALPHABET, 10), ==, 0);
	munit_assert_int(nbr, ==, -24);

	nbr = 1;
	munit_assert_int(ft_atoi_base("+24", &nbr, DEC_ALPHABET, 10), ==, 0);
	munit_assert_int(nbr, ==, 24);

	nbr = 1;
	munit_assert_int(ft_atoi_base("2147483647", &nbr, DEC_ALPHABET, 10), == ,0);
	munit_assert_int(nbr, ==, 2147483647);

	nbr = 1;
	munit_assert_int(ft_atoi_base("-2147483648", &nbr, DEC_ALPHABET, 10), ==, 0);
	munit_assert_int(nbr, ==, -2147483648);

	nbr = 1;
	munit_assert_int(ft_atoi_base(".2ABC", &nbr, DEC_ALPHABET, 10), !=, 0);
	munit_assert_int(nbr, ==, 0);

	nbr = 1;
	munit_assert_int(ft_atoi_base("-", &nbr, DEC_ALPHABET, 10), !=, 0);
	munit_assert_int(nbr, ==, 0);

	nbr = 1;
	munit_assert_int(ft_atoi_base("", &nbr, DEC_ALPHABET, 10) , !=, 0);
	munit_assert_int(nbr, ==, 0);

	nbr = 1;
	munit_assert_int(ft_atoi_base("-B", &nbr, DEC_ALPHABET, 10) , !=, 0);
	munit_assert_int(nbr, ==, 0);

	nbr = 1;
	munit_assert_int(ft_atoi_base("       	 24", &nbr, DEC_ALPHABET, 10) , !=, 0);
	munit_assert_int(nbr, ==, 0);

	nbr = 1;
	munit_assert_int(ft_atoi_base("2147483648", &nbr, DEC_ALPHABET, 10) , !=, 0);
	munit_assert_int(nbr, ==, 0);

	nbr = 1;
	munit_assert_int(ft_atoi_base("-2147483649", &nbr, DEC_ALPHABET, 10) , !=, 0);
	munit_assert_int(nbr, ==, 0);

	nbr = 1;
	munit_assert_int(ft_atoi_base("2A", &nbr, HEX_UC_ALPHABET, 16), ==, 0);
	munit_assert_int(nbr, ==, 42);

	nbr = 1;
	munit_assert_int(ft_atoi_base("FFFFFF", &nbr, HEX_UC_ALPHABET, 16) , ==, 0);
	munit_assert_int(nbr, ==, 16777215);

	nbr = 1;
	munit_assert_int(ft_atoi_base("-2A", &nbr, HEX_UC_ALPHABET, 16), ==, 0);
	munit_assert_int(nbr, ==, -42);

	nbr = 1;
	munit_assert_int(ft_atoi_base("-FFFFFF", &nbr, HEX_UC_ALPHABET, 16) , ==, 0);
	munit_assert_int(nbr, ==, -16777215);
	return (MUNIT_OK);
}
