#!/usr/bin/ecl -shell

;; Hello World from LISP!

(defun Hello ()
  (format t "~%~4THello World! From ~a ~a~%~%" 
	  (lisp-implementation-type)
	  (lisp-implementation-version))
  (values)
)

(Hello)
