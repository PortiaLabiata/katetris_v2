include <top_panel.scad>
include <bracket.scad>

module bottom_panel() {
    difference() {
        translate([-width/2, -height/2, 0])
            cube([width, height, thickness]);
        mount_hole_mask(
            -bracket_width/2-thickness*1.5,
            height/3);
        mount_hole_mask(
            -bracket_width/2-thickness*1.5, 
            -height/3);
        mount_hole_mask(
            bracket_width/2+thickness*1.5,
            height/3);
        mount_hole_mask(
            bracket_width/2+thickness*1.5, 
            -height/3);
    }
}