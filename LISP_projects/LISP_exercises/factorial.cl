#!/usr/bin/ecl -shell

#|

Learning how get user input and making
factorial in LISP

Notes 1:

The behavior of the "loop" macro, when combined with "from" and "to" is end inclusive. Where:

* TO is end inclusive:

	ecl-REPL> (loop for i from 1 to 5 collect i)

	(1 2 3 4 5)

* BELOW is end exclusive, like Python's range:

	ecl-REPL> (loop for i from 1 below 5 collect i)

	(1 2 3 4)

* DOWNTO is end inclusive (descending):

	ecl-REPL> (loop for i from 5 downto 1 collect i)

	(5 4 3 2 1)

* ABOVE is end exclusive (descending):

	ecl-REPL> (loop for i from 5 above 1 collect i)

	(5 4 3 2)

Notes 2:

The "&key" keyword allows for passing parameters with default values to functions.
And in any order as well.

|#

; Variables

(defvar *my-pad* (format NIL "~4T"))
(defvar *my-line-char* #\-)
(defvar *my-num* 40)

; Functions

(defun my-spacer(pad str num)
  (format t "~%~a" pad)
  (loop for i from 0 to num do
    (format t "~a" str)
  )
  (format t "~%")
  (values)
)

(defun get-user-input(pad)
  (format t "~%~aPrint factorial to which number? " pad)
  (finish-output)
  (let ( (input (read-line)) )
    (parse-integer input :junk-allowed t)
  )
)

(defun my-factorial(&key (num 0))
  (let ( (result 1) )
    (loop for i from 2 to num do
	     (setf result (* result i))
     finally (return result)
    )
  )
)

(defun my-output(pad)
  (let ( (user-num (get-user-input pad)) )
    (if (and user-num (>= user-num 0))
      (format t "~%~aResult: ~d~%" pad (my-factorial :num user-num))
      (format t "~%~aInvalid input (please input a non-negative integer)~%" pad)
    )
  )
)

; Program Output
(my-spacer *my-pad* *my-line-char* *my-num*)
(my-output *my-pad*)
(my-spacer *my-pad* *my-line-char* *my-num*)
