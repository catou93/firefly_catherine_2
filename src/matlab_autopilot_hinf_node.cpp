#include <ros/ros.h>
#include <mav_msgs/default_topics.h>
#include <nav_msgs/Odometry.h>
#include <mav_msgs/eigen_mav_msgs.h>
#include <mav_msgs/conversions.h>
#include <tf_conversions/tf_eigen.h>
#include <trajectory_msgs/MultiDOFJointTrajectory.h>
#include "parameters.h"
#include "parameters_ros.h"
#include "common.h"
#include <autopilot_hinf.h>
#include <tf/tf.h>

autopilot_hinfModelClass gController;

bool gCommand_active;
ros::Time gCommand_time;

void OdometryCallback(const nav_msgs::Odometry::ConstPtr &odom) {
  mav_msgs::EigenOdometry odometry;
  mav_msgs::eigenOdometryFromMsg(*odom, &odometry);

/*  std::cout << "[ INFO] [" << ros::WallTime::now() <<
   "]: odom call back position " << odometry.position_W << std::endl; */

  // Get x,y,z
  gController.autopilot_hinf_U.X[6 ]  = odometry.position_W.x();
  gController.autopilot_hinf_U.X[7 ]  = odometry.position_W.y();
  gController.autopilot_hinf_U.X[8 ]  = odometry.position_W.z();

  // Transpose u,v,w to x_dot,y_dot,z_dot using Euler matrix
  Eigen::Matrix3d R_W_B = odometry.orientation_W_B.toRotationMatrix();
  Eigen::Vector3d velocity_W =  R_W_B * odometry.velocity_B;

  // Get u,v,w
  gController.autopilot_hinf_U.X[0 ]  = odometry.velocity_B.x();
  gController.autopilot_hinf_U.X[1 ]  = odometry.velocity_B.y();
  gController.autopilot_hinf_U.X[2 ]  = odometry.velocity_B.z();

  // Get phi,theta,psi using Euler matrix careful to the axis change ENU/NED
  double psi, phi, theta;
  psi = atan2(R_W_B(1,0),R_W_B(0,0));
  phi = atan2(R_W_B(2,1),R_W_B(2,2));
  theta = asin(-R_W_B(2,0));

  // Assign phi,theta,psi
  gController.autopilot_hinf_U.X[9 ]  = phi;
  gController.autopilot_hinf_U.X[10]  = theta;
  gController.autopilot_hinf_U.X[11]  = psi;

  // Get p,q,r
  gController.autopilot_hinf_U.X[3 ]  = odometry.angular_velocity_B.x();
  gController.autopilot_hinf_U.X[4 ]  = odometry.angular_velocity_B.y();
  gController.autopilot_hinf_U.X[5 ]  = odometry.angular_velocity_B.z();

  // Get euler rates from p,q,r using euler angles
  Eigen::Matrix3d H;
  H << 1.0, sin(phi)*tan(theta), cos(phi)*tan(theta),
       0.0, cos(phi),           -sin(phi),
       0.0, sin(phi)/cos(theta), cos(phi)/cos(theta);
  Eigen::Vector3d euler_rate = H*odometry.angular_velocity_B;

  /*std::cout << "[ INFO] " //<< ros::WallTime::now() <<
  ": phi: " << double(phi) <<
  " theta: " << double(theta) <<
  " psi: " << double(psi) << std::endl;*/
}

void MultiDofJointTrajectoryCallback(
    const trajectory_msgs::MultiDOFJointTrajectoryConstPtr& msg) {
    mav_msgs::EigenTrajectoryPoint eigen_reference;
    mav_msgs::eigenTrajectoryPointFromMsg(msg->points.front(), &eigen_reference);

    if (!gCommand_active){
      gCommand_active      = true;
      gCommand_time        = ros::Time::now();
    }

    gController.autopilot_hinf_U.ref[0 ]  = 0.0; //eigen_reference.position_W.x();
    gController.autopilot_hinf_U.ref[1 ]  = 0.0; //eigen_reference.position_W.y();
    gController.autopilot_hinf_U.ref[2 ]  = 1.0; //eigen_reference.position_W.z();
    gController.autopilot_hinf_U.ref[3 ]  = 0.0; //eigen_reference.getYaw();*/

    std::cout << "[ INFO] "// << ros::WallTime::now() <<
     ": reference callback position " << eigen_reference.position_W << std::endl;
}

int main(int argc, char** argv) {
  ros::init(argc, argv, "matlab_autopilot_hinf_node");
  ros::NodeHandle nh;
  ros::NodeHandle pnh("~");
  ROS_INFO("Matlab_autopilot_hinf_node main started");

  ros::Subscriber odometry_sub;
  odometry_sub = nh.subscribe(mav_msgs::default_topics::ODOMETRY, 1, OdometryCallback);

  ros::Subscriber cmd_multi_dof_joint_trajectory_sub;
  cmd_multi_dof_joint_trajectory_sub = nh.subscribe(mav_msgs::default_topics::COMMAND_TRAJECTORY, 1, MultiDofJointTrajectoryCallback);

  ros::Publisher motor_velocity_reference_pub_;
  motor_velocity_reference_pub_ = nh.advertise<mav_msgs::Actuators>(
        mav_msgs::default_topics::COMMAND_ACTUATORS, 1);

  ros::Rate r(500);

  gCommand_active = false;
  gController.initialize();

  while(ros::ok()) {
    if (gCommand_active) {

        gController.step();

        /*std::cout << "[ INFO] " //<< ros::WallTime::now() <<
        ": omega " << double(gController.autopilot_hinf_Y.omega[0]) << std::endl;*/

        // Get propellers velocity from gController
        Eigen::VectorXd omega(6);
        for(unsigned int i=0; i< 6; i++)
            omega[i] = gController.autopilot_hinf_Y.omega[i];

        // Publish: To Gazebo
        mav_msgs::ActuatorsPtr actuator_msg(new mav_msgs::Actuators);
        actuator_msg->angular_velocities.clear();
        for (int i = 0; i < 6; i++)
          actuator_msg->angular_velocities.push_back(omega[i]);
        actuator_msg->header.stamp =  ros::Time::now();
        motor_velocity_reference_pub_.publish(actuator_msg);
    }
    ros::spinOnce();
    r.sleep();
  }
  gController.terminate();

  return 0;
}
