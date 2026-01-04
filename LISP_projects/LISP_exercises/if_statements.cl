#!/usr/bin/ecl -shell

(defun test() 
  (format t "~%~4T~a~%~4T~a~%~4T~a~%" 
	  (if (> 2 3) "Yup" "Nope") 
	  (if (> 2 3) "Yup") 
	  (if (> 3 2) "Yup" "Nope"))
  (values)
)

(test)
