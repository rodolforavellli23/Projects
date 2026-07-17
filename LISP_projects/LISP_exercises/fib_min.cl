#!/usr/bin/ecl -shell

(defconstant *my-pad* (format NIL "~4T"))

(defun fib (n)
  "Return the nth Fibonacci number."
  (if (< n 2)
      n
      (+ (fib (- n 1))
         (fib (- n 2))
      )
  )
)

(defun get-user-input(pad)
  (format t "~%~aPrint to which Fibonacci number? " pad)
  (finish-output)
  (let ( (input (read-line)) )
    (parse-integer input :junk-allowed t)
  )
)

(defun my-output(pad)
  (let ( (user-num (get-user-input pad)) )
    (if (and user-num (>= user-num 0))
      (format t "~%~aResult: ~d~%~%" pad (fib user-num))
      (format t "~%~aInvalid input (please input a non-negative integer)~%" pad)
    )
  )
)

"Text Output"
(my-output *my-pad*)
