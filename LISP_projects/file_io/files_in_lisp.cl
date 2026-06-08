#!/usr/bin/ecl -shell

#|

 * Introduction to file I/O in LISP *

 Program to print all the contents of a
 text file

 |#

(defvar *file-path* "./test.txt")

(let ( (in (open *file-path* :if-does-not-exist NIL)) )
  (format t "~%")
  (when in 
    (loop for line = (read-line in NIL) 
	  while line do (format t "~2T~a~%" line)
	  )
    )
  (close in)
)
