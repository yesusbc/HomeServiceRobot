#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <math.h>

class AddMarker
{
private:
  ros::NodeHandle n;
	ros::Publisher marker_pub;
	ros::Subscriber sub_amcl;
	visualization_msgs::Marker marker;
	uint32_t shape = visualization_msgs::Marker::SPHERE;
	double start_goal[2] = {-4, -1.7};
	double end_goal[2] = {0, 0.3};
	bool reached_start_goal = false;

public:
	AddMarker()
	{
		marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);
		sub_amcl = n.subscribe("/amcl_pose", 1, &AddMarker::poseAMCLCallback, this);

		// Set the frame ID and timestamp.  See the TF tutorials for information on these.
  	marker.header.frame_id = "/map";
  	marker.header.stamp = ros::Time::now();

  	// Set the namespace and id for this marker.  This serves to create a unique ID
  	// Any marker sent with the same namespace and id will overwrite the old one
  	marker.ns = "basic_shapes";
  	marker.id = 0;

  	// Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
  	marker.type = shape;

  	// Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
  	marker.action = visualization_msgs::Marker::ADD;

  	// Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
  	marker.pose.position.x = start_goal[0];
  	marker.pose.position.y = start_goal[1];
  	marker.pose.position.z = 0;
  	marker.pose.orientation.x = 0.0;
 		marker.pose.orientation.y = 0.0;
  	marker.pose.orientation.z = 0.0;
  	marker.pose.orientation.w = 1.0;

  	// Set the scale of the marker -- 1x1x1 here means 1m on a side
  	marker.scale.x = 0.3;
  	marker.scale.y = 0.3;
  	marker.scale.z = 0.3;

  	// Set the color -- be sure to set alpha to something non-zero!
  	marker.color.r = 0.0f;
  	marker.color.g = 1.0f;
  	marker.color.b = 0.0f;
  	marker.color.a = 1.0;

  	marker.lifetime = ros::Duration();

  	// Publish the marker
  	while (marker_pub.getNumSubscribers() < 1)
  	{
    	ROS_WARN_ONCE("Please create a subscriber to the marker");
    	sleep(1);
  	}
  	marker_pub.publish(marker);
	}

void poseAMCLCallback(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& msgAMCL)
	{
		double x_pos = msgAMCL->pose.pose.position.x;
		double y_pos = msgAMCL->pose.pose.position.y;

		double goal_distance = sqrt(pow((start_goal[0]-x_pos),2)+pow((start_goal[1]-y_pos),2));
		double end_distance = sqrt(pow((end_goal[0]-x_pos),2)+pow((end_goal[1]-y_pos),2));

		ROS_INFO("*");
		if (goal_distance < 0.5 && reached_start_goal==false)
		{
			ROS_INFO("Reached goal");
			ros::Duration(3).sleep();
			marker.action = visualization_msgs::Marker::DELETE;
			marker_pub.publish(marker);
			ROS_INFO("Object colected");
			reached_start_goal = true;

		}else if (end_distance < 0.5 && reached_start_goal)
		{
			ROS_INFO("Reached end goal");
			ros::Duration(3).sleep();
		  	marker.pose.position.x = end_goal[0];
		  	marker.pose.position.y = end_goal[1];
			marker.action = visualization_msgs::Marker::ADD;
			marker_pub.publish(marker);
			ROS_INFO("Object dropped");
			reached_start_goal = false;
		}
	}
};


int main( int argc, char** argv )
{
  ros::init(argc, argv, "add_markers");
	AddMarker addMarker;
	ros::spin();

	return 0;
}
