program hello

        ! Variable Declaration
        
        implicit none
        CHARACTER(4) :: pad
        pad = ADJUSTR(" ") ! Adjusts the char given to the right of the total space aloted for the string size
        
        ! Terminal Output
        !
        ! Note:
        !       The '&' continuity operator allows for the use of multi-line arguments to commands.


        print '(4A)', & ! This first parameter represents the number of arguments 'print' is to receive 
              new_line('a'), &
              pad, &
              "Hello World! From Fortran 90!", &
              new_line('a')

end program hello
