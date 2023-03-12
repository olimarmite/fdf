/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 04:40:02 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/12 06:15:09 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <stdlib.h>

static MunitTest		test_suite_tests[] = {
	{(char *)"utils/atoi",
		test_atoi,
		NULL,
		NULL,
		MUNIT_TEST_OPTION_NONE,
		NULL},
	{(char *)"utils/strichr",
		test_strichr,
		NULL,
		NULL,
		MUNIT_TEST_OPTION_NONE,
		NULL},
	{(char *)"utils/atoi_base",
		test_atoi_base,
		NULL,
		NULL,
		MUNIT_TEST_OPTION_NONE,
		NULL},
	{NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}};

static const MunitSuite	test_suite = {
	(char *)"",
	test_suite_tests,
	NULL,
	1,
	MUNIT_SUITE_OPTION_NONE};


int	main(int argc, char *argv[MUNIT_ARRAY_PARAM(argc + 1)])
{
	return (munit_suite_main(&test_suite, NULL, argc, argv));
}
