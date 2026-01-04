#!/usr/bin/ecl -shell

;; Loops in ECL

(dotimes (x 10) (format t "~%~4T~d" x))
(format t "~%")

(dolist (x '(1 2 3)) (format t "~%~4T~d" x))
(format t "~%")
