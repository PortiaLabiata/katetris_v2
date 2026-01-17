include <top_panel.scad>
include <side_panel.scad>
include <side_panel_2.scad>
include <bottom_panel.scad>
include <bracket.scad>
use <blue_pill.scad>

#top_panel();
translate([0, 0, -side_width-thickness])
    bottom_panel();

translate([-width/2, 0, -side_width/2])
rotate([0, 90, 0])
	#side_panel();
	
translate([width/2-thickness, 0, -side_width/2])
rotate([0, 90, 0])
	#side_panel();
	
translate([0, -height/2, -thickness*4.1])
rotate([90, 0, 0])
	side_panel_2();
	
translate([0, height/2+thickness, -thickness*4.1])
rotate([90, 0, 0])
	side_panel_2();
	
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

// Button PCB
pcb_side = 42;
translate([-pcb_side/2, -50, -5])
color("brown")
    cube([pcb_side, pcb_side, 1]);
    
// Battery
bat_height = 50;
bat_width = 25;
bat_depth = 15;

color("black")
translate([-10, -50, -bat_depth-5])
    cube([
        bat_width,
        bat_height,
        bat_depth
    ]);

rotate([0, 0, 90])
translate([53/2, 0, -12])
    bpill();