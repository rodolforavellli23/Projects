#!/usr/bin/ecl -shell

(defparameter *fn* 
  (let ((count 0)) 
    #'(lambda () 
	(setf count (1+ count))
      )
  )
)

(defparameter *fn_list* 
  (let ((x 1))
    #'(lambda () 
	(let ((my_list '()))
	(dotimes(i 10) 
	  (setf y (* x 2))
	  (setq my_list 
		(append my_list (list y))) 
	  (setq x (1+ x))); increment x 
	my_list)
      )
  )
)

(format t "~%~4T~a~%" (funcall *fn*))
(format t "~%~4T~a~%" (funcall *fn_list*))
