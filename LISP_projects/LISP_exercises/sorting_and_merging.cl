#!/usr/bin/ecl -shell

; Variables
(defvar *my-vector-1* (vector "foo" "bar" "baz"))

(defvar *my-vector-2* #(1 3 5))

(defvar *my-vector-3* #(2 4 6))

(defvar *my-vector-4* (sort (copy-seq *my-vector-2*) #'>))

(defvar *my-vector-5* (sort (copy-seq *my-vector-3*) #'>))

(defvar *my-pad* (format NIL "~4T"))

(defvar *my-str* (format NIL "------------------------------------------------------------------------------------------------------------------------------------"))

(defconstant +escape+ #\Escape)

; Functions
(defun my-spacer(pad str) 
  (format t "~%~a~120@a~%" 
	  pad
	  str
  )
  (values)
)

(defun my-display(pad n e s) 
  (format t "~%~a~C\[1;38;5;208m~a~C\[0m = ~a~%"
	  pad
	  e
	  s
	  e
	  n
  )
  (values)
)

(defun display-sort(pad n op e s) 
  (format t "~%~aDisplaying ~C\[1;38;5;208m~a~C\[0m sorted = ~a~%"
	  pad
	  e
	  s
	  e
	  (sort (copy-seq n) op)
  )
  (values)
)

(defun display-merge(pad n m op fun e s1 s2 s3 s4) 
  (format t "~%~aDisplaying ~C\[1;38;5;208m~a~C\[0m and ~C\[1;38;5;208m~a~C\[0m ~
	  merged, with the result type being ~C\[1;38;5;208m~a~C\[0m ~
	  and the comparison function being ~C\[1;38;5;208m~a~C\[0m ~
	  = ~%~a~a~%" 
	  pad 
	  e 
	  s1 
	  e 
	  e
	  s2
	  e
	  e
	  s3
	  e
	  e
	  s4
	  e
	  pad
	  (merge op (copy-seq n) (copy-seq m) fun)
  )
  (values)
)

; Text Output
(my-spacer *my-pad* *my-str*)

(my-display *my-pad* *my-vector-1* +escape+ "*my-vector-1*")

(my-spacer *my-pad* *my-str*)

(my-display *my-pad* *my-vector-2* +escape+ "*my-vector-2*")

(my-spacer *my-pad* *my-str*)

(my-display *my-pad* *my-vector-3* +escape+ "*my-vector-3*")

(my-spacer *my-pad* *my-str*)

(my-display *my-pad* *my-vector-4* +escape+ "*my-vector-4*")

(my-spacer *my-pad* *my-str*)

(my-display *my-pad* *my-vector-5* +escape+ "*my-vector-5*")

(my-spacer *my-pad* *my-str*)

(display-sort *my-pad* *my-vector-1* #'string< +escape+  "*my-vector-1*")

(my-spacer *my-pad* *my-str*)

(display-merge *my-pad* *my-vector-2* *my-vector-3* 'vector #'< +escape+ "*my-vector-2*" "*my-vector-3*" "'vector" "#'<")

(my-spacer *my-pad* *my-str*)

(display-merge *my-pad* *my-vector-2* *my-vector-3* 'list #'< +escape+ "*my-vector-2*" "*my-vector-3*" "'list" "#'<")

(my-spacer *my-pad* *my-str*)

(display-merge *my-pad* *my-vector-4* *my-vector-5* 'vector #'> +escape+ "*my-vector-4*" "*my-vector-5*" "'vector" "#'>")

(my-spacer *my-pad* *my-str*)

(display-merge *my-pad* *my-vector-4* *my-vector-5* 'list #'> +escape+ "*my-vector-4*" "*my-vector-5*" "'list" "#'>")

(my-spacer *my-pad* *my-str*)
