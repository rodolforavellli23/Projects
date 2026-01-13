#!/usr/bin/ecl --shell

(ql:quickload :computable-reals)
(use-package :computable-reals)

(setq *print-prec* 50) ; Set the precision for printing the result
(defvar *res* (log-r 10)) ; Calculates the natural logarithm of 10 to 50 decimal places

(defun output() 
  (format t "~%~4TNatural log of 10 ~
	  to the 50th decimal~%~4Tpoint ~
	  of precision:~%~%~4T~f~%"
	  *res*
	  )
  (values)
)

(output)
