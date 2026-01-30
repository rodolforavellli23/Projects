#!/usr/bin/ecl -shell

; Variable Declaration

(defvar *my-vector-1* (vector 1 2 3 4 5))

(defvar *my-vector-2* (vector "foo" "bar" "baz" "foom"))

(defvar *my-vector-3* (vector 2 1 2 3 1 2 3 4))

(defvar *my-string* "abcd0001")

(defconstant +escape+ #\Escape)

; Function Declaration

(defun out1(n e s) 
  (format t "~%~4TEven elements in ~C\[1;38;5;208m~a~C\[0m = ~a~%"
	  e
	  s
	  e
	  (count-if #'evenp n)
  )
  (values)
)

(defun out2(n e s) 
  (format t "~%~4TOdd elements in ~C\[1;38;5;208m~a~C\[0m  = ~a~%"
	  e
	  s
	  e
	  (count-if-not #'evenp n)
  )
  (values)
)

(defun out3(n e s) 
  (format t "~%~4TCount of digits in ~C\[1;38;5;208m~a~C\[0m = ~a~%"
	  e
	  s
	  e
	  (position-if #'digit-char-p n)
  )
  (values)
)

(defun out4(n e s) 
  (let ( (*print-pretty* nil) )
    (format t "~%~4TElements that start with 'f' in ~C\[1;38;5;208m~a~C\[0m = ~a~%"
	  e
	  s
	  e
	  (remove-if-not 
	    #'(lambda (x) 
		(char= (elt x 0) #\f)
	      )
	    n
	  )
    )
  )
  (values)
)

(defun out5(n e s) 
  (format t "~%~4T~C\[1;38;5;208m~a~C\[0m without duplicates = ~a~%"
	  e
	  s
	  e
	  (remove-duplicates n)
  )
  (values)
)

(defun my-printer(n e s) 
  (format t "~%~4T~C\[1;38;5;208m~a~C\[0m = ~a~%"
	  e
	  s
	  e
	  n
  )
  (values)
)

; Text Output
(my-printer *my-vector-1* +escape+ "*my-vector-1*")
(my-printer *my-vector-2* +escape+ "*my-vector-2*")
(my-printer *my-vector-3* +escape+ "*my-vector-3*")
(my-printer *my-string*   +escape+ "*my-string*  ")
(out1       *my-vector-1* +escape+ "*my-vector-1*")
(out2       *my-vector-1* +escape+ "*my-vector-1*")
(out3       *my-string*   +escape+   "*my-string*")
(out4       *my-vector-2* +escape+ "*my-vector-2*")
(out5       *my-vector-3* +escape+ "*my-vector-3*")
