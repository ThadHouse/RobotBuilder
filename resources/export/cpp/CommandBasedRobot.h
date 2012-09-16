\#include "WPILib.h"
\#include "Commands/Command.h"

class Robot : public IterativeRobot {
public:
  Command *autonomousCommand;
  static OI oi;
#@autogenerated_code("declarations", "    ")
#parse("${exporter-path}CommandBasedRobot-declarations.cpp")
#end
  virtual void RobotInit();
  virtual void AutonomousInit();
  virtual void AutonomousPeriodic();
  virtual void TeleopInit();
  virtual void TeleopPeriodic();
};

