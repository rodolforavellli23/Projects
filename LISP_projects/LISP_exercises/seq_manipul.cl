#!/usr/bin/ecl -shell

; Variable Declaration
(defvar *my-vect* #(1 2 3))
(defvar *my-list* '(4 5 6))
(defvar *my-string* "abc")
(defvar *my-char-list* '(#\d #\e #\f))
(defconstant +escape+ #\Escape)

; Functions
(defun printer-copy(s n e) 
  (format t "~%~4TCopy of ~C\[1;38;5;208m~a~C\[0m: ~a~%"
	  e
	  s
	  e
	  (copy-seq n)
  )
  (values)
)

(defun printer-reverse(s n e) 
  (format t "~%~4TReverse of ~C\[1;38;5;208m~a~C\[0m: ~a~%"
	  e
	  s
	  e
	  (reverse n)
  )
  (values)
)

(defun printer-concatenate(s1 s2 n m o e) 
  (let ( (*print-pretty* nil) ) 
    (format t "~%~4TConcatenation of ~C\[1;38;5;208m~a~C\[0m and ~
	  ~C\[1;38;5;208m~a~C\[0m: ~a~%"
	  e
	  s1
	  e
	  e
	  s2
	  e
	  (concatenate o n m)
    )
  (values)
  )
)

; Text Output
(printer-copy "*my-vect*" *my-vect* +escape+)

(printer-copy "*my-list*" *my-list* +escape+)

(printer-reverse "*my-vect*" *my-vect* +escape+)

(printer-reverse "*my-list*" *my-list* +escape+)

(printer-concatenate "*my-vect*"
		     "*my-list*"
		      *my-vect*
		      *my-list*
		      'vector
		      +escape+
)

(printer-concatenate "*my-vect*"
		     "*my-list*"
		      *my-vect*
		      *my-list*
		      'list
		      +escape+
)

(printer-concatenate "*my-string*"
		     "*my-char-list*"
		      *my-string*
		      *my-char-list*
		      'string
		      +escape+
)
