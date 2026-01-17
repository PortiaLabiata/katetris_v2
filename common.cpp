#include "common.hpp"
#include "tetris.hpp"

namespace HAL {

size_t apb_presc_table[8] = {1, 1, 1, 1, 1, 2, 3, 4};

}

int bound(int x, int left, int right) {
	x = x < left ? left : x;
	x = x > right ? right : x;
	return x;
}

rect_t& rect_t::grid2px() {
	using namespace Tetris;
	x = x*static_cast<int>(piece_t::_block_size);
	y = y*static_cast<int>(piece_t::_block_size);
	sx = static_cast<int>(sx*piece_t::_block_size);
	sy = static_cast<int>(sy*piece_t::_block_size);

	return *this;
}

rect_t& rect_t::translate(int _x, int _y) {
	x += _x;
	y += _y;
	return *this;
}

rect_t& rect_t::intersect(const rect_t& other) {
	x = bound(x, other.x, other.x+other.sx);
	y = bound(y, other.y, other.y+other.sy);
	sx = MIN(x+sx, other.x+other.sx) - x;
	sy = MIN(y+sy, other.y+other.sy) - y;
	return *this;
}
