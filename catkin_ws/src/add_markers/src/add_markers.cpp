#include <ros/ros.h>
#include <visualization_msgs/Marker.h>

int main( int argc, char** argv )
{
  // Create Node
  ros::init(argc, argv, "add_markers");
  ros::NodeHandle n;
  ros::Rate r(1);
  // Create Publisher
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);



  // Create marker
  visualization_msgs::Marker marker;

  // Set the namespace and id for this marker.  This serves to create a unique ID
  // Any marker sent with the same namespace and id will overwrite the old one
  marker.ns = "add_markers";
  marker.id = 0;
  
  // Set the marker type.  can be a CUBE, SPHERE, ARROW, or CYLINDER
  marker.type = visualization_msgs::Marker::CUBE;

  // Set the frame ID and timestamp.  See the TF tutorials for information on these.
  marker.header.frame_id = "map";
  marker.header.stamp = ros::Time::now();

  while (ros::ok())
  {
  // Set the pickup pose of the marker.
  // This is relative to the frame/time specified above
  marker.pose.position.x = -3.38;
  marker.pose.position.y = -1.8;
  marker.pose.position.z = 0;

  // Set the orientation of the marker.
  marker.pose.orientation.x = 0.0;
  marker.pose.orientation.y = 0.0;
  marker.pose.orientation.z = 0.0;
  marker.pose.orientation.w = 1.0;

  // Set the scale of the marker -- 1x1x1 here means 1m on a side
  marker.scale.x = 0.25;
  marker.scale.y = 0.25;
  marker.scale.z = 0.25;

  // Set the color -- be sure to set alpha to something non-zero!
  marker.color.r = 0.0f;
  marker.color.g = 1.0f;
  marker.color.b = 0.0f;
  marker.color.a = 1.0f;

  marker.lifetime = ros::Duration();

  // Check for subscribers
  while (marker_pub.getNumSubscribers() < 1)
    {
      if (!ros::ok())
      {
        return 0;
      }
      ROS_WARN_ONCE("Please create a subscriber to the marker");
      sleep(1);
    }
  ROS_INFO("Connected to Marker Subscriber");

    // Publish the marker
  marker_pub.publish(marker);
  ROS_INFO("Published marker at pick-up point");
  
   // pause 5 secs
    ros::Duration(5.0).sleep();
    // hide marker
     marker.action = visualization_msgs::Marker::DELETE;
     marker_pub.publish(marker);

// pause 5 secs
    ros::Duration(5.0).sleep();

  
          // Set the drop-off pose of the marker.
          // This is relative to the frame/time specified above
          marker.pose.position.x = -0.053;
          marker.pose.position.y = -3.36;
          marker.pose.position.z = 0;

          // Set the marker action to ADD.
          marker.action = visualization_msgs::Marker::ADD;
          // Publish the marker
          marker_pub.publish(marker);
          ROS_INFO("Published marker at drop_off point");
          

    // pause 5 secs
    ros::Duration(5.0).sleep();


      
    
    
  r.sleep();
  
   ros::spinOnce();
 

       
    }





}

