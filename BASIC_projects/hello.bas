10 REM Open the "version.txt" file
20 OPEN "~/Documentos/GitHub/Projects/BASIC_projects/version.txt" FOR READING AS 1
30
40 REM Read input file
50 INPUT 1 version$
60 CLOSE 1
70
80 PRINT "Hello World! From ", version$
90 END
