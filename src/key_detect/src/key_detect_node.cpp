// #include "key_detect/key_msg.h"
#include "../include/key_detect/key_detect.hpp"
#include "ros/ros.h"
const int KEYCODE_W = 0x77;
const int KEYCODE_A = 0x61;
const int KEYCODE_S = 0x73;
const int KEYCODE_D = 0x64;
 
const int KEYCODE_A_CAP = 0x41;
const int KEYCODE_D_CAP = 0x44;
const int KEYCODE_S_CAP = 0x53;
const int KEYCODE_W_CAP = 0x57;
 
const int KEYCODE_0 = 0x30;
const int KEYCODE_9 = 0x39;
 
const int KEYCODE_z_P = 0x7A;
const int KEYCODE_x_D = 0x78;
const int KEYCODE_c_R = 0x63;
const int KEYCODE_v_N = 0x76;
const int KEYCODE_z_CAP_P = 0x5A;
const int KEYCODE_x_CAP_D = 0x58;
const int KEYCODE_c_CAP_R = 0x43;
const int KEYCODE_v_CAP_N = 0x56;
 
const int KEYCODE_BACKSPACE = 0x7F;
// const int KEYCODE_SHIFT = 0x10;
const int KEYCODE_CTRL = 0x11;
// const int KEYCODE_ALT = 0x11;
const int KEYCODE_ESC = 0x1B;
const int KEYCODE_ENTER = 0x0A;
const int KEYCODE_SPACE = 0x20;
enum KEYCODE{
  W = 1,A,S,D,Space,Ctrl,Na
};
// key_detect::key_msg kbc_msg;

int main(int argc, char **argv) {
  ros::init(argc, argv, "keyboard_control");
  ros::NodeHandle nh;
 
  // ros::Publisher pub_keyboard =
  //     nh.advertise<key_detect::key_msg>("/keyboard_ctrl", 1000);
 
  ros::Rate loop_rate(50);
 
  auto KBC = Keyboard_ctrl();
  while (ros::ok()) {
    auto key = KBC.get_keyboard_press_key();
    ROS_INFO("get keyboard press 0x%02X \n", key);
 
    // if (key == KEYCODE_SPACE) {
    //   kbc_msg.key_cmd = Space;
    //   ROS_INFO("start/stop car");
    // } else if (key == KEYCODE_W || key == KEYCODE_W_CAP) {
    //   kbc_msg.key_cmd = W;
    //   ROS_INFO("manu ctrl up");
    // } else if (key == KEYCODE_S || key == KEYCODE_S_CAP) {
    //   kbc_msg.key_cmd = S;
    //   ROS_INFO("manu ctrl down");
    // } else if (key == KEYCODE_A || key == KEYCODE_A_CAP) {
    //   kbc_msg.key_cmd = A;
    //   ROS_INFO("manu ctrl left");
    // } else if (key == KEYCODE_D || key == KEYCODE_D_CAP) {
    //   kbc_msg.key_cmd = D;
    //   ROS_INFO("manu ctrl right");
    // } else if (key == KEYCODE_CTRL) {
    //   kbc_msg.key_cmd = Ctrl;
    //   ROS_INFO("ctrl");
    // } else if (key == KEYCODE_ESC) {
    //   ROS_INFO("exit");
    //   return 0;
    // } else {
    //   kbc_msg.key_cmd = Na;
    //   ROS_INFO("no ctrl");
    // }
 
    // pub_keyboard.publish(kbc_msg);
 
    ros::spinOnce();
 
    loop_rate.sleep();
  }
  return 0;
}