! Euler method for solving dv/dt = g with initial condition v(0) = 0 
Program problem_1
    Implicit none 
    real(8) :: t, v, h
    real(8), PARAMETER :: g = 9.8 

    open(1, file = 'euler.txt')
    t = 0 
    v = 0
    h = 0.1 
    
    
    do while(t <= 5) 
        write(1, *) t, v 
        t = t + h
        v = v + h * f(t, v) 
    end do 

    contains 
        real function f(t, v)
            real(8), intent(in) :: t, v
            f = g
        end function  

end Program