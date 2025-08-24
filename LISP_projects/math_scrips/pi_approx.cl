#!/usr/bin/ecl -shell

;; Leibniz approximation for pi
(defun leibniz_pi (terms)
  (let ((sum 0.0))
   (dotimes (k terms)
     (let ((sign (expt -1.0 k))
	    (denom (+ (* 2.0 k) 1.0)))
      (incf sum (/ sign denom))))
   (* 4.0 sum)))

;; Nilakantha approximation for pi
(defun nilakantha_pi (terms)
  (let ((sum 3.0))
   (dotimes (n terms)
    (let* ((k (1+ n))
           (sign (expt -1.0 (1- k)))
           (denom (* (* 2.0 k)
	          (+ (* 2.0 k) 1.0)
	          (+ (* 2.0 k) 2.0))))
    (incf sum (* sign (/ 4.0 denom)))))
   sum))

;; test
(format t "~%~18T22/7 ~~= ~,7f~%" (float(/ 22 7)))
(format t "Leibniz (10,000 terms) ~~= ~,7f~%" (leibniz_pi 10000))
(format t "Nilakantha (100 terms) ~~= ~,7f~%" (nilakantha_pi 100))
