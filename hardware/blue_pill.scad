module bpill_pcb(center=false) {
    color("blue")
        cube([53, 22, 1], center);
}

module bpill_pin_vertical() {
    translate([-1/2, -2.5/2, 0])
    union() {
        color("grey")
        translate([2/4, 2.5/2.5, -3])
            cube([0.5, 0.5, 11]);
        color("gold")
            cube([2, 2.5, 2]);
    }
}

module bpill_comb_vertical(n=20) {
    for (i=[0:1:(n-1)]) {
        translate([
            0, i*2.5, 0
        ])
            bpill_pin_vertical();
    }
}

module bpill_usb() {
    color("grey")
    translate([-7/2, -5/2, 0])
    difference() {
        cube([7, 5, 3]);
        translate([0.5/2, -0.5/2, 0.5/2])
            cube([6.5, 4.5, 2.5]);
    }
    color("black")
    translate([-6/2, -2, 1/2]) 
        cube([6, 4, 2]);
}

module bpill() {
    rotate([180, 0, 0])
    translate([-53/2, -22/2, -1])
    union() {
        bpill_pcb();
        rotate([0, 0, -90])
        translate([-22/2, 2, -3])
            bpill_usb();
        rotate([0, 0, -90])
        translate([-4, 2.5, 1])
            bpill_comb_vertical();
        rotate([0, 0, -90])
        translate([-4-15, 2.5, 1])
            bpill_comb_vertical();
        rotate([0, 180, -90])
        translate([7, 10, 0])
            bpill_comb_vertical(3);
        rotate([0, 180, -90])
        translate([7+2, 10, 0])
            bpill_comb_vertical(3);
        rotate([0, 90, 0])
        translate([0, (22-2*4)/2, 53-2])
            bpill_comb_vertical(4);
            
        color("black")
        translate([53/2, 22/4, -1])
        rotate([0, 0, 45])
            cube([7, 7, 1]);
    }
}

bpill();