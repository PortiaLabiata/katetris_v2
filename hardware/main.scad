include <top_panel.scad>
include <side_panel.scad>
include <side_panel_2.scad>
include <bracket.scad>

top_panel();
translate([-width/2, 0, -side_width/2])
rotate([0, 90, 0])
	side_panel();
	
translate([width/2-thickness, 0, -side_width/2])
rotate([0, 90, 0])
	side_panel();
	
translate([0, -height/2, -thickness*3.3])
rotate([90, 0, 0])
	side_panel_2();
	
translate([0, height/2+thickness, -thickness*3.3])
rotate([90, 0, 0])
	side_panel_2();

color("blue")
translate([-width/2, -height/2, -side_width-thickness])
	cube([width, height, thickness]);
	
translate([
	-width/2+bracket_width-thickness, 
	height/3, 
	-side_width])
rotate([0, 0, -90])
bracket();

translate([
	width/2-bracket_width+thickness, 
	height/3, 
	-side_width])
rotate([0, 0, 90])
bracket();

translate([
	width/2-bracket_width+thickness, 
	-height/3, 
	-side_width])
rotate([0, 0, 90])
bracket();

translate([
	width/2-bracket_width+thickness, 
	height/3, 
	-side_width])
rotate([0, 0, 90])
bracket();

translate([
	-width/2+bracket_width-thickness, 
	-height/3, 
	-side_width])
rotate([0, 0, -90])
bracket();