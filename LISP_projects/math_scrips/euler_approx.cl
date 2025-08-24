#!/usr/bin/ecl -shell

;; Fatorial Function

(defun fact (n)
  (let ((res 1))
   (dotimes (i n)
    (setf res (* res (+ i 1))))
  res))

;; Euler's Number Approximation

(defun calcEuler (terms)
  (let ((e 0.0))
    (dotimes (i terms)
      (setf e (+ e (/ 1.0 (fact i)))))
    e))

;; Test
(format t "~%~10Te ~~= ~,7f~%" (calcEuler 35))
