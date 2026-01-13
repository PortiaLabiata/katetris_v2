#pragma once
#include <stdint.h>
#include <stddef.h>

namespace Tetris {

struct point_t {
	int8_t x, y;
};

struct piece_t {
	static inline const size_t _piece_size = 4;
	static inline const size_t _block_size = 16;
	using data_t = point_t[_piece_size];	

	data_t data;
	point_t center;
	uint8_t r, g, b;

	void draw();
};

static const piece_t t_piece = {
	.data = {{-1, 0}, {0, 0}, {1, 0}, {0, 1}},
	.center = {1, 1},
	.r = 116,
	.g = 116,
	.b = 116,
};

}
