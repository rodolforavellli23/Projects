#!/usr/bin/ecl -shell

;; LISP output exercises.
;; note: the (values) parameter suppresses 
;;       the NIL output to the console.

(defun out_1() 
  (format t "~%~4THello, ~a!~%" 
	  "Rodolfo"
	  )
  (values)
)

(defun out_2()
  (format t "~%~4Tx: ~d, y: ~d~%"
	 1 2 
	 )
  (values)
)

(defun out_3()
  (format t "~%~4T~d~%"
	  (+ 1 2 3)
	  )
  (values)
)

(out_1)
(out_2)
(out_3)
