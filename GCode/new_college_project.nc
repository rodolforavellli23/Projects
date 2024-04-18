%
(New File - College Project)
(Fanuc CNC)
O0001
(Setup Mill n°13)
N010 G17 G21 G90 G94;
N020 G53 G00 H0 Z -110 M05; (This is the Z 0 position for the machine targeted by this program)
N030 T13;
N040 M06;
N050 G54 S 2500 M03;
N060 G43 H13 D13 Z 15;
(Routine)
(External Outline)
N070 G00 X 0 Y 0;
N080 G01 Z 5;
N090 G01 Z -3 F 1000;
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
N250 G01 X 0 Y 10 , C 10;
N260 G01 Z 15;
(Irregular internal cut 'A' - rotated 45º)
(Setup for Mill nº12)
N270 G53 G00 H0 Z -110 M05;
N280 T12;
N290 M06;
N300 G54 S2000 M03;
N310 G00 Z 15;
(start routine 'A')
N320 G00 X 20 Y 30;
N330 G52 X 20 Y 30;
N340 G01 Z 5;
N350 G68 X 0 Y 0 R 45;
N360 G01 Z -3 F1000;
N370 G01 Y -1.5;
N380 G02 X 0 Y 1.5 R 1.5;
N390 G01 X 36;
N400 G01 Y -11.5;
N410 G01 X 16.5;
N420 G01 Y -21.5;
N430 G01 X 13.5;
N440 G01 Y -1.5;
N450 G01 X 0;
N460 G69 G01 Z 15;
(End routine 'A')
(Circular Feature 'B' - With Radius == 10mm)
(start routine 'B')
(Milling central cylinder)
N470 G54 G01 X 70 Y 70;
N480 G01 Z 5;
N490 G01 Z -3;
N500 G01 X 74;
N510 G03 X 74 Y 70 I -4 J 0;
N520 G01 X 70;
N530 G01 Z 15;
(End cylindrical milling)
(Rotating drilling 8 diameter 5mm around the 'B' cylinder)
(setup for drill T11 - with a diameter == 5mm)
N540 G53 G00 H0 Z -110 M05;
N550 T11;
N560 M06;
N570 G54 S 1500 M03;
N580 G43 H 11 D 11 Z 15;
(routine 'B') ; Implement the changes suggested by the professor bellow - DONE
N590 G52 X 70 Y 70;
N600 G01 X 0 Y 0;
N610 G16 G01 X 20 Y 0;
N620 G98 G81 X 20 G91 Y 45 G90 R 5 Z -5 F 800 K 8;
N630 G80 G15 G01 Z 5;
(End Routine 'B')
(Five Consecutive drills on the bottom right section - Feature 'C')
N640 G54 G01 X 80 Y 32;
N650 G98 G81 X 80 G91 Y -10 G90 R 5 Z -5 F 800 K 3;
N660 G80 G01 Z 5;
N670 G01 Y 32;
N680 G98 G81 X 90 G91 Y -10 G90 R 5 Z -5 F 800 K 2;
N690 G80 G01 Z 5;
(End Routine 'C')
(End of Program)
N700 G53 H0 G00 Z -110 M05;
N710 M30;
%
