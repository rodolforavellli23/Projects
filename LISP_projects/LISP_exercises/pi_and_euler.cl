#!/usr/bin/ecl --shell

; π
(defvar *pi* (acos -1.0l0))

; e
(defvar *e* (exp 1.0l0))

(defun print_out() 
  (
   format t "~%~4Tπ = ~f ~
	     ~%~4Te = ~f~%"
	     *pi*
	     *e*
  )
  (values)
)

(print_out)
