#pragma once
#include <stdint.h>
#include <stddef.h>
#include "osal_class.hpp"

namespace Tetris {

struct point_t {
	int8_t x, y;
};

struct piece_t;
struct grid_t {
	static const size_t _size = 20;
	static const size_t _size_x = 10;
	uint16_t data[_size];

	void draw();
	void add_piece(const piece_t& piece);
	bool collide_piece(const piece_t& piece);
};

using namespace OSAL;
struct piece_t {
	static constexpr size_t _piece_size = 4;
	static constexpr size_t _block_size = 8;
	static constexpr size_t _y_offset = 
			disp_backend_t::_sizey-_block_size*grid_t::_size;
	static constexpr size_t _x_offset = 
			(disp_backend_t::_sizex-_block_size*grid_t::_size_x)/2;
	using data_t = point_t[_piece_size];	

	data_t data;
	point_t center;
	uint8_t r, g, b;

	void draw();
	void rotate_right();
};
static const piece_t t_piece = {
	.data = {{-1, 0}, {0, 0}, {1, 0}, {0, 1}},
	.center = {1, -1},
	.r = 116,
	.g = 116,
	.b = 116,
};

}
