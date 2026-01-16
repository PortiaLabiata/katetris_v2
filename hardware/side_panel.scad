include <bracket.scad>;
include <top_panel.scad>;

thickness = 3;
side_height = 110;
side_width = 25;

switch_to_bottom = 30;

module side_panel() {
	difference() {
		translate([-side_width/2, -side_height/2, 0])
		difference() {
			cube([side_width, side_height, thickness]);
			translate([side_width/2-3.7/2, 
				switch_to_bottom, -thickness])
				cube([3.7, 8.5, thickness*3]);
		}
		union() {
			mount_hole_mask(
				bracket_width/2-thickness*0.65,
				height/3
			);
			mount_hole_mask(
				bracket_width/2-thickness*0.65,
				-height/3
			);
		}
	}
}