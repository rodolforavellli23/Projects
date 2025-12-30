#!/usr/bin/ecl -shell

(defun test ()
  (let* ((a 10)
         (b (* a 2))
         (c (+ a b))
         (d (list a b c)))
  d))  ; Returns (10 20 30)

(format t "~%~10TTest = ~d~%" (test))
