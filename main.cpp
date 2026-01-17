#include "osal.hpp"
#include "peripherals.hpp"
#include "sched.hpp"
#include "tetris.hpp"
#include "env.hpp"
#include "keypad.hpp"

using namespace OSAL;
using namespace OS;
using namespace Tetris;

#if !SITL
using namespace HAL;

TASK_FUNC(blink_task) {
	ioline_t led_line{GPIOC, 13U};
	led_line.cfg(linemode_t::out_pp);
	while (1) {
		led_line.toggle();
		osal->delay(500);
	}
}
#endif

TASK_FUNC(video_task) {
	disp->init();
	disp->clear();
	while (1) {
		disp->flush();
		osal->delay(10);
	}
}

static piece_t piece;
static grid_t grid;
static const rect_t screen_rect{
	.x = 0,
	.y = 0,
	.sx = disp_backend_t::_sizex,
	.sy = disp_backend_t::_sizey,
};

// Intended to be used with temporaries
static void clear_push(rect_t&& rect) {
	rect.grid2px().intersect(screen_rect);
	rect.translate(
		piece_t::_x_offset,
		piece_t::_y_offset
	);
	disp->clear_stack.push(rect);
}

TASK_FUNC(main_task) {
	osal->delay(2000);

	piece = t_piece;
	while (1) {
#if SITL == ON
		extern disp_pc_t disp_pc;
		if (disp_pc.deinit_flag)
			disp_pc.deinit();
#endif
		piece.center.y++;

		clear_push({
			.x = piece.center.x-1,
			.y = piece.center.y-1,
			.sx = 3,
			.sy = 1,
		});

		piece.draw();
		if (grid.collide_piece(piece)) {
			grid.add_piece(piece);

			piece = t_piece;	
			grid.draw();
		}

		osal->delay(1000);
	}
}

TASK_FUNC(keypad_task) {
	keypad->init();
	while (1) {
		const auto mask = keypad->read();		
		if (mask.bits.enter) {
			piece.rotate_right();

			clear_push({
				.x = piece.center.x-1,
				.y = piece.center.y-1,
				.sx = 3,
				.sy = 3,
			});
			piece.draw();
		}
		if (mask.bits.right) {
			piece.center.x++;

			clear_push({
				.x = piece.center.x-2,
				.y = piece.center.y-1,
				.sx = 1,
				.sy = 3,
			});
			piece.draw();
		}
		if (mask.bits.left) {
			piece.center.x--;

			clear_push({
				.x = piece.center.x+2,
				.y = piece.center.y-1,
				.sx = 1,
				.sy = 3,
			});
			piece.draw();
		}
		if (mask.bits.down) {
			piece.center.y++;

			clear_push({
				.x = piece.center.x-1,
				.y = piece.center.y-1,
				.sx = 3,
				.sy = 1,
			});
			piece.draw();
		}

		osal->delay(10);
	}
}

int main(void) {
	osal->init();

	sched->create_task({
		.func = video_task,
		.name = "video",
		.prio = 1,
		.stack_size = 512,
	});

	sched->create_task({
		.func = keypad_task,
		.name = "keypad",
		.prio = 1,
		.stack_size = 512,
	});

#if !SITL
	sched->create_task({
		.func = blink_task,
		.name = "blink",
		.prio = 3,
		.stack_size = 64,
	});
#endif
	sched->init();

	while (1)
		;
}
