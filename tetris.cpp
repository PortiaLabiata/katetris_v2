#include "tetris.hpp"
#include "osal.hpp"
#include "peripherals.hpp"

using namespace OSAL;

namespace Tetris {

void piece_t::draw() {
	OS::lock_guard_t guard(disp->dirty_queue);
	for (size_t i = 0; i < _piece_size; i++) {
		const auto& point = data[i];
		auto *block = disp->dirty_queue.emplace(
					_x_offset+(center.x+point.x)*_block_size,
					_y_offset+(center.y+point.y)*_block_size, 
					_block_size, _block_size);
		if (block) {
			block->fill(dirty_t::encode_color(r, g, b));
		}
	}
}

void piece_t::rotate_right() {
	for (size_t i = 0; i < _piece_size; i++) {
		point_t& point = data[i];
		auto temp = point.x;

		point.x = point.y;
		point.y = -temp;
	}
}

void grid_t::add_piece(const piece_t& piece) {
	for (size_t i = 0; i < piece_t::_piece_size; i++) {
		const auto& point = piece.data[i];
		const auto& center = piece.center;
		data[center.y+point.y] |= 1 << (point.x+center.x);
	}
}

bool grid_t::collide_piece(const piece_t& piece) {
	for (size_t i = 0; i < piece_t::_piece_size; i++) {
		const auto& point = piece.data[i];
		const auto& center = piece.center;
		if (point.y+center.y == _size-1)
			return true;
		if (data[center.y+point.y+1] >> (point.x+center.x)) 
			return true;
	}
	return false;
}

void grid_t::draw() {
	int i = _size;
	while (data[--i] != 0 && i >= 0) {
		for (size_t j = 0; j < _size_x+1; j++) {
			while (disp->dirty_queue.is_full()) {
				osal->delay(5);
			}
			auto *block = disp->dirty_queue.emplace(
				piece_t::_x_offset+j*piece_t::_block_size,
				piece_t::_y_offset+i*piece_t::_block_size, 
				piece_t::_block_size, 
				piece_t::_block_size);
			if (block) {
				if ((data[i] >> j) & 0x01) 
					block->fill(0xFFFF);
				else
					block->fill(0x0000);
			}
		}
	}
}

}
