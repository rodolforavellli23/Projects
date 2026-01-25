#!/usr/bin/ecl -shell

;; Variable Definitions

(defvar *my-vector* (vector 1 2 1 2 3 1 2 3 4))
(defconstant +escape+ #\Escape)

;; Function Definitions

; The ANSII color escape codes I like to use
; \033[1;38;5;208m\] Bright Orange
; \033[0m\] Default Text Color (White)

(defun print-orange(text)
  (let ( (escape (code-char 27)) ) ; ecl will recognize 27 as the ASCII character for ESCAPE
    (format t "~%~4T~C\[1;38;5;208m~A~C\[0m~%"
          escape 
	  text 
	  escape
    )
  )
)

; Have to turn off the *print-pretty* parameter, so that we can print the output vector without breaks
(defun my-remove-duplicates(n e) 
  (let ( (*print-pretty* nil) ) 
    (format t "~%~4TVector ~C[1;38;5;208m*my-vector*~C[0m without any duplicate values = ~a~%"
	  e
	  e
	  (remove-duplicates n)
    )
  )
  (values)
)

(defun my-count(n i e) 
  (format t "~%~4TNumber of items equal to ~a in ~C[1;38;5;208m*my-vector*~C[0m = ~a~%" 
	  i
	  e
	  e
	  (count i n)
  )
  (values)
)

(defun my-remove (n i e) 
  (format t "~%~4TVector ~C[1;38;5;208m*my-vector*~C[0m without ~a = ~a~%"
	  e
	  e
	  i
	  (remove 1 *my-vector*)
  )
  (values)
)

(defun my-substitute(n out item e)
  (let ( (*print-pretty* nil) )
    (format t "~%~4TVector ~C[1;38;5;208m*my-vector*~C[0m with ~a replaced with ~a = ~a~%"
	  e
	  e
	  item
	  out
	  (substitute out item n)
    )
  )
  (values)
)

(defun my-find(n i e) 
  (format t "~%~4TVector ~C[1;38;5;208m*my-vector*~C[0m contains ~a? ~a~%"
	  e
	  e
	  i
	  (let ( (status (find i n)) )
	       (if (not (eq status nil)) (format NIL "Yes") (format NIL "No"))
	  )
  )
  (values)
)

(defun my-position (n i e) 
  (format t "~%~4TWhat is the index position of the item ~a on the vector ~C[1;38;5;208m*my-vector*~C[0m? ~
	     ~%~4TOn position ~a, from the index position 0~%"
	  i
	  e
	  e
	  (position i n)
	  )
  (values)
)

;; Text Output

(print-orange *my-vector*)
(my-remove-duplicates *my-vector* +escape+)
(my-count *my-vector* 1 +escape+)
(my-remove *my-vector* 1 +escape+)
(my-substitute *my-vector* 10 1 +escape+)
(my-find *my-vector* 4 +escape+)
(my-position *my-vector* 4 +escape+)
