#!/usr/bin/ecl --shell

;;; Rolling dice program

;; Parameters
(defparameter *pad* (format NIL "~4T"))

;; Functions
(defun roll-dice (n)
  (let ((accept nil) (res 1))
    (loop while (not accept) do
	  (setf res (random n))
	  (when (not (= res 0))
	    (setf accept t)
	  )
    )
    (format NIL "~a" res)
  )
)

(defun type-check (n) 
  (if (typep n 'integer)
    n
    NIL
  )
)

(defun user-input () 
  (let ((cont t))
    (loop while cont do
	  (format t "~%~aHello! What is the number of faces of the dice you want to roll? " *pad*)
	  (finish-output)
	  (let* ((Size (read)) (size-t (type-check Size)))
	    (if (not size-t) 
	      (format t "~%~aSize must be an integer!~%" *pad*)
	      (format t "~%~aRolling dice D~a, result: ~a~%" *pad* Size (roll-dice Size))
            )
          )
	  (format t "~%~aDo you wish to continue rolling? Type \"break\" to exit program: " *pad*)
	  (finish-output)
	  (let ((response (read-line)))
	    (if (string-equal response "break")
	      (progn 
		(format t "~%~aExiting Program...~%~%" *pad*)
		(setf cont nil)
	      )
	      (format t "~%~aContinuing...~%" *pad*)
	    )
	  )
    )
  )
)

;; Main
(user-input)
