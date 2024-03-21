%(New File - College Project)
O0001
(Setup Mill n°13)
N10 G17 G21 G90;
N20 G53 G00 Z -110; (This is the Z 0 position for the machine targeted by this program)
N30 M06 T13 S 2500 F 1000 M3;
N40 G43 H__ D 16;
(Routine)
(External Outline)
N50 G54 G41 G00 X 0 Y 0;
N60 G00 Z -15;
N70 G01 Z -5;
N80 G01 X 10;
N90 G01 X 0 Y 10;
N100 G01 Y 70;
N110 G01 X 5;
N120 G03 X 15 Y 80 I 0 J 10
N130 G01 Y 85;
N140 G03 X 30 Y 100 R 15;
N150 G01 X 70;
N160 G02 X 100 Y 70 R 30;
N170

(End of Program)
M30;
%