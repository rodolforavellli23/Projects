#!/usr/bin/ecl -shell

; Vectors exercise

; Global variables definition
(defvar *my_vect_1* 
  (make-array 2 :initial-contents '(1 2))
)

(defvar *my_vect_2* 
  (vector 1 3)
)

(defvar *my_vect_3* 
  (make-array 5 :initial-element 0)
)

(defvar *my_vect_4* 
  (make-array 5 :fill-pointer 0)
)

(defvar *my_vect_5* 
  (make-array 0 :fill-pointer 0 :adjustable t)
)

; Function definition
(defun my_print(n i) 
  (format t "~%~4Tmy_vect_~d = ~a~%"
	  i
	  n
  )
  (values)
)

; Program Logic

; Changing a value inside a vector
(setf (aref *my_vect_3* 0) 1)

; A vector can only have one element being
; pushed in or pop out at a time
(vector-push '0  *my_vect_4*)

(vector-push '1  *my_vect_4*)

(vector-push '2  *my_vect_4*)

(vector-pop *my_vect_4*)

; Unless you use a loop structure and the
; vector either has the available space, or 
; is resizeable
(loop for element in '(1 2 3 4 5) do 
      (vector-push-extend element 
			  *my_vect_5*
      )
)

; Text output
(my_print *my_vect_1* 1)
(my_print *my_vect_2* 2)
(my_print *my_vect_3* 3)
(my_print *my_vect_4* 4)
(my_print *my_vect_5* 5)
