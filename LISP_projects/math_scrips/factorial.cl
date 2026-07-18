#!/usr/bin/ecl -shell

; Variables

(defvar *my-pad* (format NIL "~4T"))
(defvar *my-line-char* #\-)
(defvar *my-num* 40)

; Functions

(defun fact(n) 
  (loop 
  	for i from 1 to n 
	for result = 1 
	then (* result i)
	finally (return result)
  )
)

(defun display(m) 
  (format t "~4T~a~%" m)
  (values)
)

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

(defun my-output(pad)
  (let ( (user-num (get-user-input pad)) )
    (if (and user-num (>= user-num 0))
      (format t "~%~aResult: ~d~%" pad (fact user-num))
      (format t "~%~aInvalid input (please input a non-negative integer)~%" pad)
    )
  )
)

; Text Output
(my-spacer *my-pad* *my-line-char* *my-num*)
(my-output *my-pad*)
(my-spacer *my-pad* *my-line-char* *my-num*)
