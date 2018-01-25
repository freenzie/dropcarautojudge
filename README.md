# dropcarautojudge
hot wheel lane finisher, auto judge

Development:

25/1/2018
-Draft code in Arduino
-Use serial monitor to check flow

<======SETUP======>


<======LOOP======>
CHECK TRIGGER 1-4
RECORD RESULT LANE 1-4
BLINK WINNER LANE
LANE RESULT 
AFTER 3 SECOND GO TO RESET

<======START ACTION======>
PUSH START
START COUNTER
COUNT DOWN 5,4,3,2,1,GO
TURN SERVO
RESET SERVO AFTER 2 SECOND


<======RESET ACTION======>
CLEAR COUNTER
BLINK READY
RESET SERVO
ELSE ERROR
DISPLAY




