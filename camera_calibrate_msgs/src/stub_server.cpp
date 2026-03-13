// Copyright 2026 sherlock
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "camera_calibrate_msgs/srv/set_auto_capture_ctrl_params.hpp"
#include "camera_calibrate_msgs/srv/get_auto_capture_ctrl_params.hpp"
#include "camera_calibrate_msgs/srv/generate_camera_intrinsics.hpp"
#include "camera_calibrate_msgs/srv/launch_camera.hpp"
#include "camera_calibrate_msgs/srv/switch_coverage_mode.hpp"
#include "camera_calibrate_msgs/srv/switch_capture_mode.hpp"
#include "camera_calibrate_msgs/srv/delete_frame.hpp"
#include "camera_calibrate_msgs/srv/manual_capture.hpp"
#include "camera_calibrate_msgs/srv/confirm.hpp"
#include "camera_calibrate_msgs/srv/go_on.hpp"
#include "camera_calibrate_msgs/srv/request_all_frames.hpp"

class CapellaServiceServer : public rclcpp::Node
{
public:
  CapellaServiceServer()
  : Node("capella_service_server")
  {
    // LaunchCamera service
    launch_camera_service_ =
      create_service<camera_calibrate_msgs::srv::LaunchCamera>(
        "camera_calibrate/start_calibrate",
        std::bind(
          &CapellaServiceServer::handle_launch_camera, this,
          std::placeholders::_1, std::placeholders::_2));

    // AutoCaptureCtrlParamsApply service
    set_auto_capture_ctrl_params_service_ =
      create_service<camera_calibrate_msgs::srv::SetAutoCaptureCtrlParams>(
        "camera_calibrate/set_auto_capture_ctrl_params",
        std::bind(
          &CapellaServiceServer::handle_set_auto_capture_ctrl_params, this,
          std::placeholders::_1, std::placeholders::_2));

    // GetAutoCaptureCtrlParams service
    get_auto_capture_ctrl_params_service_ =
      create_service<camera_calibrate_msgs::srv::GetAutoCaptureCtrlParams>(
        "camera_calibrate/get_auto_capture_ctrl_params",
        std::bind(
          &CapellaServiceServer::handle_get_auto_capture_ctrl_params, this,
          std::placeholders::_1, std::placeholders::_2));

    // GenerateCameraIntrinsics service
    generate_camera_intrinsics_service_ =
      create_service<camera_calibrate_msgs::srv::GenerateCameraIntrinsics>(
        "camera_calibrate/generate_camera_intrinsic",
        std::bind(
          &CapellaServiceServer::handle_generate_camera_intrinsics, this,
          std::placeholders::_1, std::placeholders::_2));

    // SwitchCoverageMode service
    switch_coverage_mode_service_ =
      create_service<camera_calibrate_msgs::srv::SwitchCoverageMode>(
        "camera_calibrate/switch_coverage_mode",
        std::bind(
          &CapellaServiceServer::handle_switch_coverage_mode, this,
          std::placeholders::_1, std::placeholders::_2));

    // SwitchCaptureMode service
    switch_capture_mode_service_ =
      create_service<camera_calibrate_msgs::srv::SwitchCaptureMode>(
        "camera_calibrate/switch_capture_mode",
        std::bind(
          &CapellaServiceServer::handle_switch_capture_mode, this,
          std::placeholders::_1, std::placeholders::_2));

    // DeleteFrame service
    delete_frame_service_ =
      create_service<camera_calibrate_msgs::srv::DeleteFrame>(
        "camera_calibrate/delete_frame",
        std::bind(
          &CapellaServiceServer::handle_delete_frame, this,
          std::placeholders::_1, std::placeholders::_2));

    // ManualCapture service
    manual_capture_service_ =
      create_service<camera_calibrate_msgs::srv::ManualCapture>(
        "camera_calibrate/manual_capture",
        std::bind(
          &CapellaServiceServer::handle_manual_capture, this,
          std::placeholders::_1, std::placeholders::_2));

    // Confirm service
    confirm_service_ =
      create_service<camera_calibrate_msgs::srv::Confirm>(
        "camera_calibrate/confirm",
        std::bind(
          &CapellaServiceServer::handle_confirm, this,
          std::placeholders::_1, std::placeholders::_2));

    // GoOn service
    go_on_service_ =
      create_service<camera_calibrate_msgs::srv::GoOn>(
        "camera_calibrate/go_on",
        std::bind(
          &CapellaServiceServer::handle_go_on, this,
          std::placeholders::_1, std::placeholders::_2));

    // RequestAllFrames service
    request_all_frames_service_ =
      create_service<camera_calibrate_msgs::srv::RequestAllFrames>(
        "camera_calibrate/request_all_frames",
        std::bind(
          &CapellaServiceServer::handle_request_all_frames, this,
          std::placeholders::_1, std::placeholders::_2));

    RCLCPP_INFO(get_logger(), "CapellaServiceServer started with 11 services");
  }

private:
  void handle_set_auto_capture_ctrl_params(
    const std::shared_ptr<camera_calibrate_msgs::srv::SetAutoCaptureCtrlParams::Request>
    request,
    std::shared_ptr<camera_calibrate_msgs::srv::SetAutoCaptureCtrlParams::Response>
    response)
  {
    (void)request;  // unused, stub implementation
    response->success = true;
    response->infos = "SetAutoCaptureCtrlParams executed successfully (stub)";
    RCLCPP_INFO(
      get_logger(),
      "SetAutoCaptureCtrlParams: time_interval=%.2f, time_still=%.2f, pose_dis=%.2f, "
      "pose_direction=%.2f, calib_num_min=%u, calib_num_max=%u, sharpness_thr=%.2f",
      request->time_interval, request->time_still, request->pose_dis,
      request->pose_direction, request->calib_num_min, request->calib_num_max,
      request->sharpness_thr);
  }

  void handle_get_auto_capture_ctrl_params(
    const std::shared_ptr<camera_calibrate_msgs::srv::GetAutoCaptureCtrlParams::Request>
    request,
    std::shared_ptr<camera_calibrate_msgs::srv::GetAutoCaptureCtrlParams::Response>
    response)
  {
    (void)request;  // unused, stub implementation
    response->success = true;
    response->time_interval = 1.0f;
    response->time_still = 0.5f;
    response->pose_dis = 0.1f;
    response->pose_direction = 5.0f;
    response->calib_num_min = 10;
    response->calib_num_max = 50;
    response->sharpness_thr = 0.8f;
    RCLCPP_INFO(
      get_logger(),
      "GetAutoCaptureCtrlParams executed successfully (stub)");
  }

  void handle_generate_camera_intrinsics(
    const std::shared_ptr<camera_calibrate_msgs::srv::GenerateCameraIntrinsics::Request>
    request,
    std::shared_ptr<camera_calibrate_msgs::srv::GenerateCameraIntrinsics::Response>
    response)
  {
    (void)request;  // unused, stub implementation
    response->success = true;
    response->camera_info.header.stamp = now();
    response->camera_info.header.frame_id = "camera";
    response->camera_info.width = 640;
    response->camera_info.height = 480;
    response->camera_info.distortion_model = "plumb_bob";
    response->camera_info.d = {0.0, 0.0, 0.0, 0.0, 0.0};
    response->camera_info.k = {1.0, 0.0, 320.0, 0.0, 1.0, 240.0, 0.0, 0.0, 1.0};
    response->camera_info.r = {1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0};
    response->camera_info.p = {1.0, 0.0, 320.0, 0.0, 0.0, 1.0, 240.0, 0.0, 0.0, 0.0, 1.0, 0.0};
    RCLCPP_INFO(get_logger(), "GenerateCameraIntrinsics executed successfully (stub)");
  }

  void handle_launch_camera(
    const std::shared_ptr<camera_calibrate_msgs::srv::LaunchCamera::Request> request,
    std::shared_ptr<camera_calibrate_msgs::srv::LaunchCamera::Response> response)
  {
    response->success = true;
    response->infos = "Camera '" + request->camera_name + "' launched successfully (stub)";
    response->topic_origin = "/rgb_camera_back/image_raw";
    response->topic_undistroted = "/rgb_camera_back/image_raw";
    RCLCPP_INFO(
      get_logger(),
      "LaunchCamera: robot_name=%s, camera_name=%s, resolution=%ux%u",
      request->robot_name.c_str(), request->camera_name.c_str(),
      request->resolution_width, request->resolution_height);
  }

  void handle_switch_coverage_mode(
    const std::shared_ptr<camera_calibrate_msgs::srv::SwitchCoverageMode::Request> request,
    std::shared_ptr<camera_calibrate_msgs::srv::SwitchCoverageMode::Response> response)
  {
    (void)request;  // unused, stub implementation
    response->success = true;
    response->infos = "SwitchCoverageMode executed successfully (stub)";
    RCLCPP_INFO(
      get_logger(),
      "SwitchCoverageMode: show_coverage=%d",
      request->show);
  }

  void handle_switch_capture_mode(
    const std::shared_ptr<camera_calibrate_msgs::srv::SwitchCaptureMode::Request> request,
    std::shared_ptr<camera_calibrate_msgs::srv::SwitchCaptureMode::Response> response)
  {
    (void)request;  // unused, stub implementation
    response->success = true;
    response->infos = "SwitchCaptureMode executed successfully (stub)";
    RCLCPP_INFO(
      get_logger(),
      "SwitchCaptureMode: auto_mode=%d",
      request->auto_mode);
  }

  void handle_delete_frame(
    const std::shared_ptr<camera_calibrate_msgs::srv::DeleteFrame::Request> request,
    std::shared_ptr<camera_calibrate_msgs::srv::DeleteFrame::Response> response)
  {
    (void)request;  // unused, stub implementation
    response->success = true;
    response->infos = "DeleteFrame executed successfully (stub)";
    RCLCPP_INFO(
      get_logger(),
      "DeleteFrame: frame_id=%d",
      request->frame_id);
  }

  void handle_manual_capture(
    const std::shared_ptr<camera_calibrate_msgs::srv::ManualCapture::Request> request,
    std::shared_ptr<camera_calibrate_msgs::srv::ManualCapture::Response> response)
  {
    (void)request;  // unused, stub implementation
    response->success = true;
    response->infos = "ManualCapture executed successfully (stub)";
    response->image.header.stamp = now();
    response->image.header.frame_id = "camera";
    response->image.width = 640;
    response->image.height = 480;
    response->image.encoding = "rgb8";
    response->image.step = 640 * 3;
    response->image.data = std::vector<uint8_t>(640 * 480 * 3, 128);  // dummy data
    RCLCPP_INFO(get_logger(), "ManualCapture executed successfully (stub)");
  }

  void handle_confirm(
    const std::shared_ptr<camera_calibrate_msgs::srv::Confirm::Request> request,
    std::shared_ptr<camera_calibrate_msgs::srv::Confirm::Response> response)
  {
    (void)request;  // unused, stub implementation
    response->success = true;
    response->infos = "Confirm executed successfully (stub)";
    RCLCPP_INFO(
      get_logger(),
      "Confirm: valid=%d",
      request->valid);
  }

  void handle_go_on(
    const std::shared_ptr<camera_calibrate_msgs::srv::GoOn::Request> request,
    std::shared_ptr<camera_calibrate_msgs::srv::GoOn::Response> response)
  {
    (void)request;  // unused, stub implementation
    response->success = true;
    response->infos = "GoOn executed successfully (stub)";
    RCLCPP_INFO(get_logger(), "GoOn executed successfully (stub)");
  }

  void handle_request_all_frames(
    const std::shared_ptr<camera_calibrate_msgs::srv::RequestAllFrames::Request> request,
    std::shared_ptr<camera_calibrate_msgs::srv::RequestAllFrames::Response> response)
  {
    (void)request;  // unused, stub implementation
    response->frames.clear();

    camera_calibrate_msgs::msg::FrameCaptured frame;
    frame.id = 0;
    frame.image.header.stamp = now();
    frame.image.header.frame_id = "camera";
    frame.image.width = 640;
    frame.image.height = 480;
    frame.image.encoding = "rgb8";
    frame.image.step = 640 * 3;
    frame.image.data = std::vector<uint8_t>(frame.image.step * frame.image.height, 128);

    response->frames.push_back(frame);

    RCLCPP_INFO(get_logger(), "RequestAllFrames executed successfully (stub), returning 1 frame");
  }

  rclcpp::Service<camera_calibrate_msgs::srv::SetAutoCaptureCtrlParams>::SharedPtr
    set_auto_capture_ctrl_params_service_;
  rclcpp::Service<camera_calibrate_msgs::srv::GetAutoCaptureCtrlParams>::SharedPtr
    get_auto_capture_ctrl_params_service_;
  rclcpp::Service<camera_calibrate_msgs::srv::GenerateCameraIntrinsics>::SharedPtr
    generate_camera_intrinsics_service_;
  rclcpp::Service<camera_calibrate_msgs::srv::LaunchCamera>::SharedPtr
    launch_camera_service_;
  rclcpp::Service<camera_calibrate_msgs::srv::SwitchCoverageMode>::SharedPtr
    switch_coverage_mode_service_;
  rclcpp::Service<camera_calibrate_msgs::srv::SwitchCaptureMode>::SharedPtr
    switch_capture_mode_service_;
  rclcpp::Service<camera_calibrate_msgs::srv::DeleteFrame>::SharedPtr
    delete_frame_service_;
  rclcpp::Service<camera_calibrate_msgs::srv::ManualCapture>::SharedPtr
    manual_capture_service_;
  rclcpp::Service<camera_calibrate_msgs::srv::Confirm>::SharedPtr
    confirm_service_;
  rclcpp::Service<camera_calibrate_msgs::srv::GoOn>::SharedPtr
    go_on_service_;
  rclcpp::Service<camera_calibrate_msgs::srv::RequestAllFrames>::SharedPtr
    request_all_frames_service_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<CapellaServiceServer>());
  rclcpp::shutdown();
  return 0;
}
