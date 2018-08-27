#pragma once

#define ARRAY_SIZE(x)		(sizeof(x) / sizeof((x)[0]))
#define destructor(destructor)	__attribute__((cleanup(destructor)))

int	usage(char **argv);
