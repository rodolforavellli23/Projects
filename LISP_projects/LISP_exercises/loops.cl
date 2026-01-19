#!/usr/bin/ecl -shell

;; Loops in ECL

; Text output - Begin
(format t "~%")

; dotimes
(dotimes (x 10) 
  (format t "~4T~d " x)
  )
(format t "~%~%")

; dolist
(dolist (x '(1 2 3)) 
  (format t "~4T~d " x)
  )
(format t "~%~%")

(dolist (element '(a b c d))
  (format t "~4T~a " element)
  (values)
  )
(format t "~%~%")

; for loop over a given range
(loop for i from 0 to 9 do
  (format t "~4T~d " i)
  )
(format t "~%~%")

; for-each analog i Common LISP
(loop for element in '(1 2 3 4 5) do
  (format t "~4T~d " element)
  )
(format t "~%~%")

; Collection example
(defvar *x_collection*
 (loop for i from 1 to 9 collect 
       (* i i)
       )
 )

(loop for i from 0 to 8 do
      (format t "~4T~d " 
	      (elt *x_collection* i)
	      )
      )

(format t "~%~%")

(loop for element in *x_collection* do 
      (format t "~4T~d " 
	      element
	      )
      )

(format t "~%~%")

; Text Output End
