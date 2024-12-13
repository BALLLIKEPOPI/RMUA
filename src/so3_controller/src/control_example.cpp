#include <Eigen/Eigen>
#include <quadrotor_msgs/PositionCommand.h>
#include <ros/ros.h>
#include "key_detect/key_msg.h"

quadrotor_msgs::PositionCommand cmd;
enum KEYCODE{
  W = 1,A,S,D,Space,Ctrl,Na
};

void KeyCallback(const key_detect::key_msg::ConstPtr &msg)
{
  switch (msg->key_cmd)
  {
  case KEYCODE::W:
    cmd.velocity.x = 1.0;
    break;
  case KEYCODE::A:
    cmd.velocity.y = 1.0;
    break;
  case KEYCODE::S:
    cmd.velocity.x = -1.0;
    break;
  case KEYCODE::D:
    cmd.velocity.y = -1.0;
    break;
  case KEYCODE::Space:
    cmd.velocity.z = 1.0;
    break;
  case KEYCODE::Ctrl:
    cmd.velocity.z = -1.0;
    break;
  case KEYCODE::Na:
    cmd.velocity.x = 0.0;
    cmd.velocity.y = 0.0;
    cmd.velocity.z = 0.0;
    break;
  default:
    break;
  }
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "quad_sim_example");
  ros::NodeHandle nh("~");

  ros::Subscriber key_cmd = nh.subscribe("/keyboard_ctrl", 10, KeyCallback);
  ros::Publisher cmd_pub = nh.advertise<quadrotor_msgs::PositionCommand>("/velocity_cmd", 10);

  cmd.position.x = std::numeric_limits<float>::quiet_NaN(); // lower-order commands must be disabled by nan
  cmd.position.y = std::numeric_limits<float>::quiet_NaN(); // lower-order commands must be disabled by nan
  cmd.position.z = std::numeric_limits<float>::quiet_NaN(); // lower-order commands must be disabled by nan
  cmd.velocity.x = 0.0;
  cmd.velocity.y = 0.0;
  cmd.velocity.z = 0.0;

  ros::Duration(2.0).sleep();

  while (ros::ok())
  {
    cmd_pub.publish(cmd);

    ros::Duration(0.01).sleep();
    ros::spinOnce();
  }

  return 0;
}
