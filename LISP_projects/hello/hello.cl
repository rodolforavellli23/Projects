#!/usr/bin/ecl -shell

;; Hello World from LISP!

(defun Hello ()
  (format t "~%~5THello World! From ~a ~a~%" 
	  (lisp-implementation-type)
	  (lisp-implementation-version))
  (values)
)

(Hello)
