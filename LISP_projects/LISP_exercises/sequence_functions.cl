#!/usr/bin/ecl -shell

; Sequence functions in Common LISP

; Variable Definitions
(defvar *vect_1* (vector 1 2 3))

(setf (elt *vect_1* 0) 10)

; Functions
(defun my-printer(n i) 
  (format t "~%~4Tvect_~d = ~a~%"
	  i
	  n
  )
  (values)
)

(defun print_len(n i) 
  (format t 
	"~%~4TLength of vect_~d = ~d~%"
	i
	(length n)
  )
  (values)
)

(defun element_printer(n i e)
  (format t "~%~4TElement ~d of vec_~d ~
	  = ~a~%"
	  e
	  i
	  (elt n e)
  )
  (values)
)

; Text Output
(my-printer *vect_1* 1)
(print_len *vect_1* 1)
(element_printer *vect_1* 1 1)
