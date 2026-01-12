program char_exercise_01
        implicit none
        character(:), allocatable :: first_name, last_name
        character(4), parameter :: pad = adjustr(' ')

        first_name = "Rodolfo"
        last_name = "Ravelli"

        print *, new_line('a'), &
                 pad, &
                 first_name // " " &
                 // last_name, &
                 new_line('a')

end program char_exercise_01
