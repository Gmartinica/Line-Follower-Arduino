This was a project done for a robotics competition in Texas Tech University

It is a line-following robot which follows a black line on a white background.

It has three photosensors looking straight down which determine if the robot is centered on the black line by
following the logic: the black color absorbs all light while the white color reflects all light. Then depending
on the state of the robot it turns wheels to the desired direction to keep the robot moving forward without losing the
line.

If you want to build your own implementation of the robot, you would need to change its values inside the analogWrite(),
as the values there are independent of each implementation.
