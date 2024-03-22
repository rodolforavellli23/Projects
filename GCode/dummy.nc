%
(Setup Mill n°13)
N10 G49 G17 G21 G90;
N20 G00 Z -110; (This is the Z 0 position for the machine targeted by this program)
N30 T13 S 2500 F 1000 M06 M3;
N40 G00 X 0 Y 0;
(Routine)
(External Outline)
N60 G00 Z -15;
N70 G01 Z -5;
N80 G01 Y 70;
N90 G01 X 5;
N100 G03 X 15 Y 80 I 0 J 10
N110 G01 Y 85;
N120 G03 X 30 Y 100 R 15;
N130 G01 X 70;
N140 G02 X 100 Y 70 R 30;
N150 G01 Y 60;
N160 G01 X 92 Y 50;
N170 G01 X 100 Y 30;
N180 G01 Y 8;
N190 G01 X 92 Y 0;
N200 G01 X 78;
N210 G03 X 43 I -17.5 J -9.682458366;
N220 G01 X 10;
N230 G01 X 0 Y 10;
(Irregular cut - rotataded)
N240 G01 Z -15;
N250 G00 X 20 Y 30;


(End of Program)
M30;
%