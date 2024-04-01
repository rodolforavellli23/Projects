%
(New File - College Project)
(Fanuc CNC)
O0001
(Setup Mill n°13)
N10 G17 G21 G90 G94;
N20 G53 G00 H0 Z -110 M05; (This is the Z 0 position for the machine targeted by this program)
N30 T13;
N40 M06;
N50 G54 S 2500 F 1000 M03;
N60 G43 H13 D13 Z -15;
(Routine)
(External Outline)
N70 G00 X 0 Y 0;
N80 G01 Z -5;
N90 G01 Z 5;
N100 G01 G41 Y 70;
N110 G01 X 5;
N120 G03 X 15 Y 80 I 0 J 10
N130 G01 Y 85;
N140 G03 X 30 Y 100 R 15;
N150 G01 X 70;
N160 G02 X 100 Y 70 R 30;
N170 G01 Y 60;
N180 G01 X 92 Y 50, R 15;
N190 G01 X 100 Y 30;
N200 G01 Y 8;
N210 G01 Y 0, C 8;
N220 G01 X 78, R 15;
N230 G03 X 43 I -17.5 J -9.682458366;
N240 G01 X 10;
N250 G01 Y 10 , C 10;
(Irregular internal cut 'A' - rotated 45º)
N260 G01 Z -15;
(Settup for Mill nº12)
N270 G53 G00 H0 Z -110 M05;
N280 T12;
N290 M06;
N300 G54 S2000 M03;
N310 G43 H12 D12 Z -15;
(start routine 'A')
N320 G00 X 20 Y 30;
N330 G52 X 20 Y 30;
N340 G01 X 0 Y 0;
N350 G68 R 45;
N360 G01 Z -5;
N370 G01 Z 5;
N380 G01 X -7.5;
N390 G42 G02 Y 7.5 R 7.5;
N400 G01 X 32.5 Y 1.5, R 6;
N410 G01 Y 0;
N420 G01 G40 X 0;
N430 G01 X -7.5;
N440 G41 G03 Y -7.5 R 7.5;
N450 G01 X 32.5;
N460 G01 G42 X 26.5 Y -17.5, R 6;
N470 G01 X 22.5;
N480 G01 Y -7.5;
N490 G01 X 15;
N500 G01 Y -17.5;
N510 G01 X 7.5;
N520 G01 Y -7.5;
N530 G01 G41 X 13.5 Y -27.5, R 6;
N540 G01 Y -17.5;
N550 G01 Y -27.5;
N560 G01 X 22.5 Y -21.5, R 6;
N570 G01 Y -17.5;
N580 G69 G01 Z -15;
(End routine 'A')
(Circular Feature 'B' - With Radius == 10mm)
(start routine 'B')
(Milling central cylinder)
N590 G54 G01 X 70 Y 70;
N600 G01 Z -5;
N660 G01 Z 5;
N670 G01 X 80;
N680 G03 I -10 J 0;
N690 G01 X 70;
N700 G01 Z -5;
N710 G01 Z -15;
(End cylindrical milling)
(Rotating drilling 8 diameter 5mm around the 'B' cylinder)
(settup for drill T11 - with a diameter == 5mm)
N720 G53 G00 H0 Z -110 M05;
N730 T11;
N740 M06;
N750 G54 S 1500 F 800 M03;
N760 G43 H 11 D 11 Z -15;
(routine 'B') 
     G52 X 70 Y 70;
     G01 X 0 Y 0;
     G68 R 45;
     (drilling routine)
				 G01 X 20;'
					G01 Z 5;
					G01 Z -5;
					G01 X 0;
					(end drilling routine)
					G68 X 0 Y 0 R 90;

(End of Program)
G53 H0 G00 Z -110 M05;
M30;
%