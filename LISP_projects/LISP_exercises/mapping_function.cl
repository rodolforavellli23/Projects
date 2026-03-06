#!/usr/bin/ecl -shell

; Variable Declaration
(defvar *my-vector-1* #(1 2 3 4 5)); n-1
(defvar *my-vector-2* #(10 9 8 7 6)); n-2
(defvar *my-pad* (format NIL "~4T")); pad
(defvar *my-str* (format NIL "-")); str
(defvar *my-num* 103); num
(defconstant +escape+ #\Escape); e

; Function Declaration

; Functions
; Naming Notes:
;       * is put as placeholder for a given value.
; Argument Notes:
;       s-*   = string containing the name of the variableto to be displayed.
;	      func  = function to by applied to the map generated.

(defun my-spacer(pad str num)
  (format t "~%~a" pad)
  (loop for i from 0 to num do
    (format t "~a" str)
  )
  (format t "~%")
  (values)
)

(defun my-display(pad n e s-n)
  (format t "~%~a~C\[1;38;5;208m~a~C\[0m = ~a~%"
          pad
          e
          s-n
          e
          n
  )
  (values)
)

(defun display-map(pad n-1 e func s-n-1 s-func out-type s-out-type
		       &optional (n-2 NIL) (s-n-2 NIL))
  (let ( (*print-pretty* nil) )
    (if (and (not (eq n-2   NIL)) (not (eq s-n-2 NIL)))
      (format t "~%~aMapping ~C\[1;38;5;208m~a~C\[0m and ~
                ~C\[1;38;5;208m~a~C\[0m into a type ~
                ~C\[1;38;5;208m~a~C\[0m with a ~
                ~C\[1;38;5;208m~a~C\[0m expression: ~a~%"
                pad
                e
                s-n-1
                e
                e
                s-n-2
                e
                e
                s-out-type
                e
                e
                s-func
                e
                (map out-type func (copy-seq n-1) (copy-seq n-2))
     )
     (format t "~%~aMapping ~C\[1;38;5;208m~a~C\[0m into a type ~
                ~C\[1;38;5;208m~a~C\[0m with a ~C\[1;38;5;208m~a~C\[0m ~
                expression: ~a~%"
                pad
                e
                s-n-1
                e
                e
                s-out-type
                e
                e
                s-func
                e
                (map out-type func (copy-seq n-1))
     )
    )
    (values)
  )
)

; Text Output
(my-spacer *my-pad* *my-str* *my-num*)
(my-display *my-pad* *my-vector-1* +escape+ "*my-vector-1")
(my-spacer *my-pad* *my-str* *my-num*)
(my-display *my-pad* *my-vector-2* +escape+ "*my-vector-2")
(my-spacer *my-pad* *my-str* *my-num*)
(display-map *my-pad*
             *my-vector-1*
             +escape+
             #'*
	           "*my-vector-1*"
	           "multiply"
	           'vector
	           "vector"
	           *my-vector-2*
	           "*my-vector-2*")
(my-spacer *my-pad* *my-str* *my-num*)
(display-map *my-pad*
             *my-vector-1*
             +escape+
             #'(lambda (thing) (digit-char thing)) ; Only works for sequences where each element is only one digit/char in length.
	           "*my-vector-1*"
	           "lambda"
	           'string
	           "string")
(my-spacer *my-pad* *my-str* *my-num*)
(display-map *my-pad*
             *my-vector-2*
             +escape+
             #'(lambda (thing) (format NIL "~a" thing))
	           "*my-vector-2*"
	           "format"
	           'list
	           "list")
(my-spacer *my-pad* *my-str* *my-num*)