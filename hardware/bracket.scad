thickness = 3;
bracket_width = 10+thickness;
bracket_height = 10+thickness;
mount_hole_r = 1.77;

module bracket_side() {
	difference() {
		translate([-bracket_width/2, 
			-bracket_height/2, 0])
			cube([bracket_width,
				bracket_height, thickness]);
		translate([0, thickness/2, -thickness])
			cylinder(thickness*3, mount_hole_r,
				mount_hole_r, $fn=400);
	}
}

module bracket() {
	color("gold")
	union() {
		bracket_side();
		translate([
			0,
			-bracket_width/2+thickness,
			bracket_height/2,
		])
		rotate([90, 0, 0])
			bracket_side();
	}
}