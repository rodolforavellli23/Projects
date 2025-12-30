#!/usr/bin/ecl -shell

; The let* function sequentially binds 
; variables and the let function doesn't

(let* ((x 10)
       (y (+ x 10)))
  (format t "~%~a~%" (list x y))
  )

(let ((x 10))
  (let ((y (+ x 10)))
    (format t "~%~a~%" (list x y)))
  )
