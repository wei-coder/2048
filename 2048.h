#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <linux/input.h>

void left(int (*grid)[4]);
bool left_add(int (*grid)[4]);
bool rand_assign(int (*grid)[4]);
void show_grid(int (*grid)[4]);
void right(int (*grid)[4]);
bool right_add(int (*grid)[4]);
void up(int (*grid)[4]);
bool up_add(int (*grid)[4]);
void down(int (*grid)[4]);
bool down_add(int (*grid)[4]);

