%
(Dummy)
(Routine)
(External Outline)
G00 X 0 Y 0;
G00 Z -15;
G01 Z -5;
G01 Y 70;
G01 X 5;
G03 X 15 Y 80 I 0 J 10
G01 Y 85;
G03 X 30 Y 100 R 15;
G01 X 70;
G02 X 100 Y 70 R 30;
G01 Y 60;
G01 X 92 Y 50;
G01 X 100 Y 30;
G01 Y 8;
G01 X 92 Y 0;
G01 X 78;
G03 X 43 I -17.5 J -9.682458366;
G01 X 10;
G01 X 0 Y 10;
(Irregular cut - rotataded)
G01 Z -15;
G00 X 20 Y 30; 

(End of Program)
M30;
%