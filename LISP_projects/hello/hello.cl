#!/usr/bin/ecl -shell

;; Hello World program for Common Embedable LISP

(defun Hello()
  (format t "~%~10THello World! From ~a ~a~%"
	(lisp-implementation-type)
	(lisp-implementation-version))
  (values)
)

(Hello)
