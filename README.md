# HomeServiceRobot - Robotics Nanodegree

<img src= "https://github.com/yesusbc/HomeServiceRobot/blob/master/visualize/homeservice.png" width="773" height="401">

## Required Packages
First download the four supporting packages to install for the project.

[gmapping](http://wiki.ros.org/slam_gmapping): With the gmapping_demo.launch file, you can easily perform SLAM and build a map of the environment with a robot equipped with laser range finder sensors or RGB-D cameras.

[turtlebot_teleop](http://wiki.ros.org/turtlebot_teleop): With the keyboard_teleop.launch file, you can manually control a robot using keyboard commands.

[turtlebot_rviz_launchers](http://wiki.ros.org/turtlebot_rviz_launchers): With the view_navigation.launch file, you can load a preconfigured rviz workspace. You’ll save a lot of time by launching this file, because it will automatically load the robot model, trajectories, and map for you.

[turtlebot_gazebo](http://wiki.ros.org/turtlebot_gazebo): With the turtlebot_world.launch you can deploy a turtlebot in a gazebo environment by linking the world file to it.

## rosdep Dependencies
After cloning the supporting package in `catkin_ws/src`, run `rosdep` on each of the package names to install their dependencies.

`rosdep -i install gmapping`

`rosdep -i install turtlebo`

## Tasks

### SLAM Testing
The `test_slam.sh` script launches a Gazebo environment, Rviz, Gmapping and Teleoperation. This will let you map your environment with the keyboard commands.
<img src= "https://github.com/yesusbc/HomeServiceRobot/blob/master/visualize/test_slam.png" width="773" height="401">

### Localization and Navigation Testing
Now that you have a map, The `test_navigation.sh` will use the Adaptive Monte Carlo Localization (AMCL) Algorithm to determine its localization inside the map, and to reach both of the goals predefined.
<img src= "https://github.com/yesusbc/HomeServiceRobot/blob/master/visualize/test_navigation.png" width="773" height="401">

### Pick Objects
The `pick_objects.sh` script assigns two goal poses to the robot consecutively as the robot traverses through the environment to simulate picking up objects from a location and dropping them off to another location.


### Add Marker
The `add_marker.sh` script adds markers to the goal positions depending just on time.


### Home Service
The final script `home_service.sh` will use this markers to simulate a robot picking up and dropping off an object. 
