program sum_of_numbers
  implicit none
  integer :: num1, num2, sum

  ! Prompt the user for input
  write(*,*) "Enter the first number: "
  read(*,*) num1

  write(*,*) "Enter the second number: "
  read(*,*) num2

  ! Calculate the sum
  sum = num1 + num2

  ! Print the result
  write(*,*) "The sum of", num1, "and", num2, "is", sum

end program sum_of_numbers
