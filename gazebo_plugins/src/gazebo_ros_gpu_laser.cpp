/*
 * Copyright 2013-2018 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#include <gazebo_plugins/gazebo_ros_gpu_laser.h>

namespace gazebo
{
// Register this plugin with the simulator
GZ_REGISTER_SENSOR_PLUGIN(GazeboRosGpuLaser)

////////////////////////////////////////////////////////////////////////////////
// Constructor
GazeboRosGpuLaser::GazeboRosGpuLaser()
{
}

////////////////////////////////////////////////////////////////////////////////
// Destructor
GazeboRosGpuLaser::~GazeboRosGpuLaser()
{
}

////////////////////////////////////////////////////////////////////////////////
// Load the controller
void GazeboRosGpuLaser::Load(sensors::SensorPtr _parent, sdf::ElementPtr _sdf)
{
  // Warn user that this plugin is deprecated
  ROS_WARN_NAMED("laser", "gazebo_ros_gpu_laser is deprecated. Please use gazebo_ros_ray_sensor instead");

  // For API compatibility, gazebo_ros_gpu_laser should have output type laser scan
  if (!_sdf->HasElement("outputType"))
  {
    // Set outputType to sensor_msgs/LaserScan
    sdf::ElementPtr element = std::make_shared<sdf::Element>();
    element->SetName("outputType");
    element->AddValue("string", "", false, "");
    element->Set<std::string>(ros::message_traits::DataType<sensor_msgs::LaserScan>::value());
    _sdf->AddElementDescription(element);
    sdf::ElementPtr my_element = _sdf->GetElement("outputType");
  }

  // Load parent plugin
  this->GazeboRosRaySensor::Load(_parent, _sdf);
}

}
