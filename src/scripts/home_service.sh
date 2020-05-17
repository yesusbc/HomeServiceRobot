#!/bin/sh
xterm -e "source ../../devel/setup.sh;
					export TURTLEBOT_GAZEBO_WORLD_FILE=/home/workspace/catkin_ws/src/turtlebot_simulator/turtlebot_gazebo/worlds/myhouse.world;
					roslaunch turtlebot_gazebo turtlebot_world.launch" &

sleep 5
xterm -e "source ../../devel/setup.sh;
	  export TURTLEBOT_GAZEBO_MAP_FILE=/home/workspace/catkin_ws/src/maps/map.yaml;
					roslaunch turtlebot_gazebo amcl_demo.launch" &

sleep 5
xterm -e "source ../../devel/setup.sh;
	roslaunch turtlebot_rviz_launchers view_navigation.launch" &

sleep 15
xterm -e "source ../../devel/setup.sh;
	 rosrun add_markers add_markers" &

sleep 5
xterm -e "source ../../devel/setup.sh;
	 rosrun pick_objects pick_objects" 
