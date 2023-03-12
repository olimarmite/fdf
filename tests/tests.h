#ifndef TESTS_H
# define TESTS_H

# include "munit/munit.h"
# include "../src/fdf.h"

MunitResult test_atoi(const MunitParameter params[], void *data);
MunitResult test_atoi_base(const MunitParameter params[], void *data);
MunitResult test_strichr(const MunitParameter params[], void *data);

#endif
