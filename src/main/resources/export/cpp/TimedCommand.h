#set($command = $helper.getByName($command_name, $robot))
#header()

#pragma once

\#include "frc/commands/Subsystem.h"
\#include "frc/commands/TimedCommand.h"
\#include "Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class #class($command.name): public frc::TimedCommand {
public:
#@autogenerated_code("constructor", "    ")
#parse("${exporter_path}TimedCommand-constructor-header.h")
#end

    void Initialize() override;
    void Execute() override;
    void End() override;
    void Interrupted() override;

private:
#@autogenerated_code("variables", "    ")
#end
};

