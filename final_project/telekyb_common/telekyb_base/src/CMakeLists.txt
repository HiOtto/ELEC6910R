
# Set Objects

set(MainSRCS
	TeleKyb.cpp
)

set(BaseSRCS
	Base/BaseSingleton.cpp
)

set(FileSRCS
	File/File.cpp
)

set(FiterSRCS
	Filter/FirFilter.cpp
	Filter/IIRFilter.cpp
)

set(MessagesSRCS
	Messages/TKState.cpp
	Messages/TKTrajectory.cpp
)

set(OptionsSRCS
	Options/BaseOption.cpp
	Options/CommonOptions.cpp
	Options/OptionContainer.cpp
	Options/RawOptionsContainer.cpp
)

set(ROSSRCS
	ROS/ROSBaseOption.cpp
	ROS/ROSModule.cpp
	ROS/ROSOptionContainer.cpp
	ROS/ROSOptionController.cpp
)

set(SpacesSRCS
	Spaces/Angle.cpp
)

set(TimesSRCS
	Time/Duration.cpp
	Time/Time.cpp
	Time/Timer.cpp
	Time/ThreadedCBTimer.cpp
)

set(ToolsSRCS
	Tools/XmlRpcHelper.cpp
	Tools/YamlHelper.cpp
)




# Build library
rosbuild_add_library(${PROJECT_NAME} 
	${BaseSRCS}
	${MainSRCS} 
	${OptionsSRCS} 
	${FileSRCS} 
	${FiterSRCS}
	${MessagesSRCS}
	${ROSSRCS}
	${SpacesSRCS}
	${TimesSRCS} 
	${ToolsSRCS}
)

rosbuild_link_boost(${PROJECT_NAME} system)