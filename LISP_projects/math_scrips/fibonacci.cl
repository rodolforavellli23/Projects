#!/usr/bin/ecl -shell

#|

Fibonacci calculator - Sequence starting in 1

|#

; Variables

(defvar *my-pad* (format NIL "~4T"))
(defvar *my-line-char* #\-)
(defvar *my-num* 40)
(defvar *my-phy* (/ (1+ (sqrt 5)) 2))
(defvar *my-psy* (/ (1- (sqrt 5)) 2))

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
  (format t "~%~aPrint which fibonacci number? " pad)
  (finish-output)
  (let ( (input (read-line)) )
    (parse-integer input :junk-allowed t)
  )
)

;; Binet's Formula for finding fib at the nth position
(defun my-fib(&key (num 0)) 
  (/ (- (expt *my-phy* num) (expt *my-psy* num)) (sqrt 5))
)

(defun my-output(pad)
  (let ( (user-num (get-user-input pad)) )
    (if (and user-num (>= user-num 0))
      (format t "~%~aResult: ~d~%" pad (round (my-fib :num user-num)))
      (format t "~%~aInvalid input (please input a non-negative integer)~%" pad)
    )
  )
)

; Program Output
(my-spacer *my-pad* *my-line-char* *my-num*)
(my-output *my-pad*)
(my-spacer *my-pad* *my-line-char* *my-num*)
