program var_exercise_01
  ! Program Settings
  use, intrinsic :: iso_fortran_env, only: sp=>real32, dp=>real64
  implicit none

  ! Variable Declaration
  real(sp) :: float32
  real(dp) :: float64

  ! Static Variable Declaration
  character(4), parameter :: pad = adjustr(' ')
  character(*), parameter :: fmt_str = & 
             '( A, A, "Float32 = ", F10.8,' // &
              ' A, A, "Float64 = ", F18.16, A)'

  ! Variable Attribution
  float32 = 1.0_sp ! Explicit suffix for literal constants
  float64 = 1.0_dp

  ! Terminal Output
 
  ! The width of a Fw.d must be at least w >= 2 + d
  write(*, fmt_str) new_line('a'), &
                    pad, &
                    float32, &
                    new_line('a'), & 
                    pad, & 
                    float64, &
                    new_line('a')

end program var_exercise_01
