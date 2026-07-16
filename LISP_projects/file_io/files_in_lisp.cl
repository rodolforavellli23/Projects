#!/usr/bin/ecl -shell

#|

 * Introduction to file I/O in LISP *

 Program to print all the contents of a text file

|#

;; Variables

(defvar *Home* (user-homedir-pathname))

(defvar *file-path* (make-pathname 
		      :directory (append 
				   (pathname-directory *Home*)
				   '("Documentos" 
				     "GitHub"
				     "Projects" 
				     "LISP_projects" 
				     "file_io")
				   ) 
		      :name "test"
		      :type "txt")
  )

(defvar *pad* (format NIL "~2T"))

;; IO
(format t "~%")
(if (probe-file *file-path*) 
  (with-open-file (in *file-path* :direction :input)
      (loop for line = (read-line in NIL NIL) while line do 
	    (format t "~a~a~%" *pad* line)
	    )
      )
  (format t "Error: File not found at ~a~%" *file-path*)
  )
