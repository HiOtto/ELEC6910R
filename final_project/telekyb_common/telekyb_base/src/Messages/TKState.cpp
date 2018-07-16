/*
 * TKState.cpp
 *
 *  Created on: Nov 8, 2011
 *      Author: mriedel
 */

#include <telekyb_base/Messages/TKState.hpp>

namespace TELEKYB_NAMESPACE {

TKState::TKState()
	: time(ros::Time::now()), position(0.0,0.0,0.0), orientation(1.0,0.0,0.0,0.0), linVelocity(0.0,0.0,0.0), angVelocity(0.0,0.0,0.0)
{
	// TODO Auto-generated constructor stub

}

TKState::TKState(const telekyb_msgs::TKState& tkStateMsg)
{
	fromTKStateMsg(tkStateMsg);
}

TKState::~TKState() {
	// TODO Auto-generated destructor stub
}

void TKState::toTKStateMsg(telekyb_msgs::TKState& tkStateMsg) const
{
	tkStateMsg.header.stamp = time.toRosTime();
	// Position
	tkStateMsg.pose.position.x = position(0);
	tkStateMsg.pose.position.y = position(1);
	tkStateMsg.pose.position.z = position(2);

	// Orientation
	tkStateMsg.pose.orientation.w = orientation.w();
	tkStateMsg.pose.orientation.x = orientation.x();
	tkStateMsg.pose.orientation.y = orientation.y();
	tkStateMsg.pose.orientation.z = orientation.z();

	// linear Velocity
	tkStateMsg.twist.linear.x = linVelocity(0);
	tkStateMsg.twist.linear.y = linVelocity(1);
	tkStateMsg.twist.linear.z = linVelocity(2);

	// angular Velocity
	tkStateMsg.twist.angular.x = angVelocity(0);
	tkStateMsg.twist.angular.y = angVelocity(1);
	tkStateMsg.twist.angular.z = angVelocity(2);

}

void TKState::fromTKStateMsg(const telekyb_msgs::TKState& tkStateMsg)
{
	time = Time(tkStateMsg.header.stamp);
	// Position
	position(0) = tkStateMsg.pose.position.x;
	position(1) = tkStateMsg.pose.position.y;
	position(2) = tkStateMsg.pose.position.z;

	// Orientation
	orientation.w() = tkStateMsg.pose.orientation.w;
	orientation.x() = tkStateMsg.pose.orientation.x;
	orientation.y() = tkStateMsg.pose.orientation.y;
	orientation.z() = tkStateMsg.pose.orientation.z;

	// linear Velocity
	linVelocity(0) = tkStateMsg.twist.linear.x;
	linVelocity(1) = tkStateMsg.twist.linear.y;
	linVelocity(2) = tkStateMsg.twist.linear.z;

	// angular Velocity
	angVelocity(0) = tkStateMsg.twist.angular.x;
	angVelocity(1) = tkStateMsg.twist.angular.y;
	angVelocity(2) = tkStateMsg.twist.angular.z;
}

Vector3D TKState::getEulerRPY() const
{
	return orientation.toRotationMatrix().eulerAngles(0,1,2); // xyz
}

}

