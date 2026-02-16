#!/usr/bin/ecl -shell

; Variables

(defvar *my-string* "foobarbaz")

(defvar *my-pad* (format NIL "~4T"))

(defvar *my-line-char* "-")

(defvar *my-num* 45)

(defconstant +escape+ #\Escape)

; Functions
(defun my-spacer(pad str num)
  (format t "~%~a" pad)
  (loop for i from 0 to num do 
	(format t "~a" str)
  )
  (format t "~%")
  (values)
)

(defun my-display(pad n e s) 
  (format t "~%~a~C\[1;38;5;208m~a~C\[0m = ~C~a~C~%"
	  pad
	  e
	  s
	  e
	  #\"
	  n
	  #\"
  )
  (values)
)

(defun my-subseq(pad n e s num1 &optional (num2 NIL)) 
  (format t "~%~aMy subsequence of ~C\[1;38;5;208m~a~C\[0m is ~a~a ~
	     ~%~aFor num1 = ~a and num2 = ~a~%" 
	  pad
	  e
	  s
	  e
	  (if (eq num2 NIL) 
	    (subseq (copy-seq n) num1) 
	    (subseq (copy-seq n) num1 num2)
	  )
	  "."
	  pad
	  num1
	  num2
  )
  (values)
)
; Text Output
(my-spacer  *my-pad* *my-line-char* *my-num*)
(my-display *my-pad* *my-string* +escape+ "my-string")
(my-spacer  *my-pad* *my-line-char* *my-num*)
(my-subseq  *my-pad* *my-string* +escape+ "my-string" 3)
(my-spacer  *my-pad* *my-line-char* *my-num*)
(my-subseq  *my-pad* *my-string* +escape+ "my-string" 3 6)
(my-spacer  *my-pad* *my-line-char* *my-num*)
