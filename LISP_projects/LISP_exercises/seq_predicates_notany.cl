#!/usr/bin/ecl -shell

; Variable Declaration
(defvar *my-sequence-1* #(1 2 3 4 5)); n
(defvar *my-sequence-2* #(1 2 3 4)); n
(defvar *my-sequence-3* #(5 4 3 2)); n
(defvar *my-pad* (format NIL "~4T")); pad
(defvar *my-str* (format NIL "-")); str
(defvar *my-num* 45); num
(defconstant +escape+ #\Escape); e

; Functions
; Naming Notes:
;	* is put as placeholder for a given
;       value.
; Argument Notes:
; 	c-exp = comparison expresion.
; 	s-* = string containing the name of
;     	      the variableto to be 
;	      displayed.

(defun my-spacer(pad str num)
  (format t "~%~a" pad)
  (loop for i from 0 to num do
    (format t "~a" str)
  )
  (format t "~%")
  (values)
)

(defun my-display(pad n e s-n)
  (format t 
	"~%~a~
        ~C\[1;38;5;208m~a~C\[0m ~
        = ~a~%"
          pad
          e
          s-n
          e
          n
  )
  (values)
)

(defun display-notany(pad n-1 e c-exp s-n-1 s-c-exp &optional (n-2 NIL) (s-n-2 NIL)) 
  (if (and (not (eq n-2 NIL)) (not (eq s-n-2 NIL)))
    (format t 
	   "~%~aAre all items in ~C\[1;38;5;208m~a~C\[0m not ~
	   ~a ~C\[1;38;5;208m~a~C\[0m? ~%~aResult: ~a~%" 
	   pad
	   e
	   s-n-1
	   e
	   s-c-exp
	   e
	   s-n-2
	   e
	   pad
	   (let ( (x (notany c-exp n-1 n-2)) ) 
	     (if x
	       (format NIL "True")
	       (format NIL "False")
	     )
	   )
    )
    (format t 
 	   "~%~aAre all items in ~C\[1;38;5;208m~a~C\[0m not ~
	   ~a?~%~aResult: ~a~%" 
	   pad
	   e
	   s-n-1
	   e
	   s-c-exp
	   pad
	   (let ( (x (notany c-exp n-1)) ) 
	     (if x
	       (format NIL "True")
	       (format NIL "False")
	     )
	   )
   )
  )
  (values)
)

; Text Output
(my-spacer *my-pad* *my-str* *my-num*)
(my-display *my-pad* *my-sequence-1* +escape+ "*my-sequence-1*")
(my-spacer *my-pad* *my-str* *my-num*)
(my-display *my-pad* *my-sequence-2* +escape+ "*my-sequence-2*")
(my-spacer *my-pad* *my-str* *my-num*)
(my-display *my-pad* *my-sequence-3* +escape+ "*my-sequence-3*")
(my-spacer *my-pad* *my-str* *my-num*)
(display-notany *my-pad* *my-sequence-1* +escape+ #'evenp "*my-sequence-1*" "even")
(my-spacer *my-pad* *my-str* *my-num*)
(display-notany *my-pad* *my-sequence-1* +escape+ #'oddp "*my-sequence-1*" "odd")
(my-spacer *my-pad* *my-str* *my-num*)
(display-notany *my-pad* *my-sequence-1* +escape+ #'numberp "*my-sequence-1*" "numbers")
(my-spacer *my-pad* *my-str* *my-num*)
(display-notany *my-pad* *my-sequence-2* +escape+ #'> "*my-sequence-2*"
	       (format NIL "greater ~%~athan" *my-pad*) *my-sequence-3* "*my-sequence-3*")
(my-spacer *my-pad* *my-str* *my-num*)
