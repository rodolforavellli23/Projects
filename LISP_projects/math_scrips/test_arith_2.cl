#!/usr/bin/ecl -shell

(defun test ()
  (let* ((x 10)
         (y (+ x 5))  ; Can use x here
         (z (+ x y))) ; Can use both x and y here
 (setf sum (+ x (+ y z)))
 sum))               ; Returns 50

(format t "~%~10TTest = ~d~%" (test))

