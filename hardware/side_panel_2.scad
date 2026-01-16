thickness = 3;
side_width_2 = 45;
side_height_2 = 25+thickness*2;

module side_panel_2() {
	color("green")
	translate([-side_width_2/2, -side_height_2/2, 0])
	cube([side_width_2, side_height_2, thickness]);
}