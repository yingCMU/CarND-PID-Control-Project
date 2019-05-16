# effect of the P, I, D component
P component decides how quickly the error can be corrected based on current error value. 
The higher the P value, the sharper to turn when car is off the center and more oscillates would happen..

I component  decides  how quickly overall offset is corrected. THe higher the I value,the quicker recent errors start to be corrected. But too much I 
will cause instability.
D component is to decrease oscillation. but too much D will cause excessive response and overshoot.

In my implementation I have two PID controllers, one is to control angle the other to control speed(throttle).
The reason to control speed is in some sharp turn, sharp angle is not enough to pass through safely.

# how they chose the final hyperparameters (P, I, D coefficients). 
I manually tuned coefficients as follows:
1. Tune angle controller first:
first tune P parameter and set others to 0, increase P till car oscillate too much to be off the road. Set the P value
to be half of that value.
Then increase I until offset is corrected in sufficient time.
Last increase D until car is stable enough , not overshoot too much.
2. Tune throttle controller:
repeat the process of #1 until the car reduce speed when encountering sharp turns and maintain relatively stable speed (not reversing)


