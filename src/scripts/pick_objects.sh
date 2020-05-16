#!/bin/sh
xterm -e "source ../../devel/setup.sh;
					export TURTLEBOT_GAZEBO_WORLD_FILE=/home/workspace/catkin_ws/src/turtlebot_simulator/turtlebot_gazebo/worlds/myhouse.world;
					roslaunch turtlebot_gazebo turtlebot_world.launch" &

sleep 5
xterm -e "export TURTLEBOT_GAZEBO_MAP_FILE=/home/workspace/catkin_ws/src/maps/map.yaml;
					roslaunch turtlebot_gazebo amcl_demo.launch" &

sleep 5
xterm -e "roslaunch turtlebot_rviz_launchers view_navigation.launch" 

sleep 5
xterm -e "rosrun pick_objects pick_objects" 
