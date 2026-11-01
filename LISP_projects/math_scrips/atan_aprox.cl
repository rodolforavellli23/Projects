#!/usr/bin/ecl -shell

;; Learning about how the atan function is implemented in Common LISP

;; Parameters

(defparameter *pi* (acos -1))

(defparameter *my-input* 10.0d0)

;; Helper functions

(defun my-print (n)
  (format t "~%~4Tatan(~F) is approximately ~F degrees~%~%" *my-input* n)
  (values)
)

(defun rad-to-deg(n)
    (/ (* n 180) *pi*)
)

;; Atan implementation, returns value in radians accurate to the 5th decimal point

(defun taylor-atan (n)
  (let ((acc n)) 
    (loop for k from 1 to 1000 do
      (let* (
	     (sign (expt -1 k))
	     (exponent (+ 1 (* 2 k)))
	     (term (/ (* sign (expt n exponent)) exponent))
	    )
      (setf acc (+ acc term))
      )
    )
    acc
  )
)

(defun my-atan(n) 
  (if (> n 1) 
    (- (/ *pi* 2) (taylor-atan (/ 1 n)))
    (taylor-atan n)
  )
)

;; Output
(my-print (rad-to-deg (my-atan *my-input*)))

