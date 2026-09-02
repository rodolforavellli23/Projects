#!/usr/bin/awk -f

# Testing trigg on awk

BEGIN {
	myPad      = sprintf("%4s", " ");        # My pad
	pi_radians = atan2(0, -1);               # PI
	myAngle    = atan2(10, 16);              # On this version, y is before x
	ang_deg    = (myAngle * 180)/pi_radians; # Radians to degrees
	result     = sin(myAngle);               # Result
	printf("\n%sMy angle: %.10fº\n%sIts sine: %.10f\n\n", \
	       myPad,                                         \
	       ang_deg,                                       \
	       myPad,                                         \
	       result                                         \
	) 
}
