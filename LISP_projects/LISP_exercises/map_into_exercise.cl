#!/usr/bin/ecl -shell

#|

MAP-INTO exercise

Note-1: MAP-INTO can extend adjustable vectors that are declared with :fill-pointer.
	But only up to the size the result vector has been set to.

Note-2: MAP-INTO is a desctructive function, that is, it'll alter the 
	internal values of the first sequence that is given to it. This effect carries
	over into the rest of the program afterwards.

Note-3: The first sequence given to MAP-INTO must have at least as 
	many elements as the other sequences being mapped in order for
	MAP-INTO to produce a meaningful result. Should the first sequence
	be an empty sequence the output of MAP-INTO will also be an empty
	sequence.

|#


; Variable Declaration

(defvar *vector-a* (make-array 5 :initial-element 0))
(defvar *vector-b* #(1 2 3 4 5))
(defvar *vector-c* #(10 9 8 7 6))
(defvar *my-pad* (format NIL "~4T")); pad
(defvar *my-str* (format NIL "-")); str
(defvar *my-num* 75); num
(defconstant +escape+ #\Escape); e

; Function Declaration

; Functions
; Naming Notes:
;       * is put as placeholder for a given value.
; Argument Notes:
;       s-*   = string containing the name of the variableto to be displayed.
;       func  = function to by applied to the map generated.

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

(defun display-map-into(pad n-1 e s-n-1 func s-func n-2 s-n-2
			    &optional (n-3 NIL) (s-n-3 NIL)) 
  (if (and (not (eq n-3 NIL))(not (eq s-n-3 NIL)))
    (format t 
	    "~%~aMapping into ~
	    ~C\[1;38;5;208m~a~C\[0m ~
	    with the ~
	    ~C\[1;38;5;208m~a~C\[0m ~
	    function the sequences ~
	    ~C\[1;38;5;208m~a~C\[0m ~
	    ~%~aand ~
	    ~C\[1;38;5;208m~a~C\[0m: ~
	    ~%~aResult: ~a~%"
	    pad
	    e
	    s-n-1
	    e
	    e
	    s-func
	    e
	    e
	    s-n-2
	    e
	    pad
	    e
	    s-n-3
	    e
	    pad
	    (map-into (copy-seq n-1) func 
		      (copy-seq n-1) (copy-seq n-2) (copy-seq n-3))
    )
    (format t 
	    "~%~aMapping into ~
	    ~C\[1;38;5;208m~a~C\[0m ~
	    with the ~
	    ~C\[1;38;5;208m~a~C\[0m ~
	    function the sequence ~
	    ~C\[1;38;5;208m~a~C\[0m: ~
	    ~%~aResult: ~a~%"
	    pad
	    e
	    s-n-1
	    e
	    e
	    s-func
	    e
	    e
	    s-n-2
	    e
	    pad
	    (map-into (copy-seq n-1) func 
		      (copy-seq n-1) (copy-seq n-2))
    )
  )
  (values)
)

; Text Output
(my-spacer *my-pad* *my-str* *my-num*)
(my-display *my-pad* *vector-a* +escape+ "*vector-a*")
(my-spacer *my-pad* *my-str* *my-num*)
(my-display *my-pad* *vector-b* +escape+ "*vector-b*")
(my-spacer *my-pad* *my-str* *my-num*)
(my-display *my-pad* *vector-c* +escape+ "*vector-c*")
(my-spacer *my-pad* *my-str* *my-num*)
(display-map-into *my-pad* 
		  *vector-a* 
		  +escape+
		  "*vector-a*"
		  #'+
		  "addition"
		  *vector-b*
		  "*vector-b*")
(my-spacer *my-pad* *my-str* *my-num*)
(display-map-into *my-pad* 
		  *vector-a* 
		  +escape+
		  "*vector-a*"
		  #'+
		  "addition"
		  *vector-b*
		  "*vector-b*"
		  *vector-c*
		  "*vector-c*")
(my-spacer *my-pad* *my-str* *my-num*)
(display-map-into *my-pad* 
		  *vector-b* 
		  +escape+
		  "*vector-b*"
		  #'+
		  "addition"
		  *vector-c*
		  "*vector-c*")
(my-spacer *my-pad* *my-str* *my-num*)
