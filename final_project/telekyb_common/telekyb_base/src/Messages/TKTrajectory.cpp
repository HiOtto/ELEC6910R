/*
 * TKTrajectory.cpp
 *
 *  Created on: Nov 8, 2011
 *      Author: mriedel
 */

#include <telekyb_base/Messages/TKTrajectory.hpp>

namespace TELEKYB_NAMESPACE {

TKTrajectory::TKTrajectory()
	: position(0.0,0.0,0.0),
	  velocity(0.0,0.0,0.0),
	  acceleration(0.0,0.0,0.0),
	  jerk(0.0,0.0,0.0),
	  snap(0.0,0.0,0.0),
	  yawAngle(0.0),
	  yawRate(0.0),
	  yawAcceleration(0.0)
{
	// Default ControlTypes.
	xAxisCtrl = PosControlType::Position;
	yAxisCtrl = PosControlType::Position;
	zAxisCtrl = PosControlType::Position;

	yawCtrl = YawControlType::AngleOnBoard;
}

TKTrajectory::TKTrajectory(const telekyb_msgs::TKTrajectory& tkTrajMsg)
{
	fromTKTrajMsg(tkTrajMsg);
}

TKTrajectory::~TKTrajectory()
{

}

void TKTrajectory::toTKTrajMsg(telekyb_msgs::TKTrajectory& tkTrajMsg) const
{
	tkTrajMsg.position.x = position(0);
	tkTrajMsg.position.y = position(1);
	tkTrajMsg.position.z = position(2);

	tkTrajMsg.velocity.x = velocity(0);
	tkTrajMsg.velocity.y = velocity(1);
	tkTrajMsg.velocity.z = velocity(2);

	tkTrajMsg.acceleration.x = acceleration(0);
	tkTrajMsg.acceleration.y = acceleration(1);
	tkTrajMsg.acceleration.z = acceleration(2);

	tkTrajMsg.jerk.x = jerk(0);
	tkTrajMsg.jerk.y = jerk(1);
	tkTrajMsg.jerk.z = jerk(2);

	tkTrajMsg.snap.x = snap(0);
	tkTrajMsg.snap.y = snap(1);
	tkTrajMsg.snap.z = snap(2);

	tkTrajMsg.xAxisCtrlType = xAxisCtrl.index();
	tkTrajMsg.yAxisCtrlType = yAxisCtrl.index();
	tkTrajMsg.zAxisCtrlType = zAxisCtrl.index();

	tkTrajMsg.yawAngle = yawAngle;
	tkTrajMsg.yawRate = yawRate;
	tkTrajMsg.yawAcceleration = yawAcceleration;

	tkTrajMsg.yawCtrlType = yawCtrl.index();
}

/**
 * NOTE! No check on ENUMS!
 */
void TKTrajectory::fromTKTrajMsg(const telekyb_msgs::TKTrajectory& tkTrajMsg)
{
	position(0) = tkTrajMsg.position.x;
	position(1) = tkTrajMsg.position.y;
	position(2) = tkTrajMsg.position.z;

	velocity(0) = tkTrajMsg.velocity.x;
	velocity(1) = tkTrajMsg.velocity.y;
	velocity(2) = tkTrajMsg.velocity.z;

	acceleration(0) = tkTrajMsg.acceleration.x;
	acceleration(1) = tkTrajMsg.acceleration.y;
	acceleration(2) = tkTrajMsg.acceleration.z;

	jerk(0) = tkTrajMsg.jerk.x;
	jerk(1) = tkTrajMsg.jerk.y;
	jerk(2) = tkTrajMsg.jerk.z;

	snap(0) = tkTrajMsg.snap.x;
	snap(1) = tkTrajMsg.snap.y;
	snap(2) = tkTrajMsg.snap.z;

	xAxisCtrl = *PosControlType::get_by_index(tkTrajMsg.xAxisCtrlType % PosControlType::size);
	yAxisCtrl = *PosControlType::get_by_index(tkTrajMsg.yAxisCtrlType % PosControlType::size);
	zAxisCtrl = *PosControlType::get_by_index(tkTrajMsg.zAxisCtrlType % PosControlType::size);

	yawAngle = tkTrajMsg.yawAngle;
	yawRate = tkTrajMsg.yawRate;
	yawAcceleration = tkTrajMsg.yawAcceleration;

	yawCtrl = *YawControlType::get_by_index(tkTrajMsg.yawCtrlType % YawControlType::size);
}

}
