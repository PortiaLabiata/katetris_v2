width = 45;
height = 110;
thickness = 3;

cap_large_r = 11.5/2;
cap_small_r = 11.5/3;
mount_holes_r = 1.77;

mask_depth = thickness*3;

disp_pcb_short = 23;
disp_pcb_long = 35;

disp_side_long = 29.72;
disp_side_short = 26;

module cap_small_mask(x=0, y=0) {
	translate([x, y, -thickness])
		cylinder(thickness*3, cap_small_r, cap_small_r,
			$fn=400);
}

module cap_large_mask(x=0, y=0) {
	translate([x, y, -thickness])
		cylinder(thickness*3, 
			cap_large_r, cap_large_r,
			$fn=400);
}

module mount_hole_mask(x=0, y=0) {
    translate([x, y, -thickness])
        cylinder(mask_depth, 
            mount_holes_r, mount_holes_r, $fn=400);
}

module buttons_mask(d=40) {
	cap_large_mask(d, 0);
	cap_large_mask(0, d);
	cap_large_mask(-d, 0);
	cap_large_mask(0, -d);
	cap_large_mask(15, 15);
    
    mount_hole_mask(14, -12.25);
    mount_hole_mask(-14, -12.25);
    mount_hole_mask(0, 0);
}

module display_mask() {
    translate([
        -disp_side_short/2, 
        -disp_side_long/2, 
        -thickness
    ])
        cube([
            disp_side_short, 
            disp_side_long, 
            mask_depth
        ]);
    
    for (i = [-1, 1]) {
        for (j = [-1, 1]) {
            mount_hole_mask(
                disp_pcb_short/2*i, 
                disp_pcb_long/2*j
            );
        }
    }
}

module top_panel() {
	color("red")
    difference() {
        translate([-width/2, -height/2, 0])
            cube([width, height, thickness]);
        translate([0, height/4-4, 0])
            display_mask();
		translate([0, -30, 0])
			buttons_mask(11);
    }
}

top_panel();