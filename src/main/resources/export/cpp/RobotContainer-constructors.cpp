#set($cmd = $robot.getProperty("Autonomous Command").getValue())
#foreach( $component in $components )
#if($component.getBase().getType() == "Command" && !($component.getProperty("Parameters").getValue().isEmpty()) && $component.name == $cmd)
m_setpoint,
#end
#if ($component.getBase().getType() == "Command" && $component.name == $cmd)
        #if( $component.getProperty("Parameter presets").getValue().isEmpty() )
                #if ($component.getProperty("Requires").getValue() != "None")
&m_#required_subsystem($component))#if($component.getProperty("Add Timeout").value == true).withTimeout($component.getProperty("Timeout").value)#end{
                #else
){
               #end
        #end
#end
#end

##${Collections.reverse($components)}
#foreach( $component in $components )
#if ($helper.exportsTo("OI", $component)
     && ("#constructor($component)" != "" || "#extra($component)" != "") && "#type($component)" != "Joystick" && "#type($component)" != "JoystickButton")
    #constructor($component)
    #extra($component)
#end
#end


${Collections.reverse($components)}
    // SmartDashboard Buttons
#foreach( $component in $components )
#if ($component.getBase().getType() == "Command"
     && $component.getProperty("Button on SmartDashboard").getValue())
#if( $component.getProperty("Parameter presets").getValue().isEmpty())
    frc::SmartDashboard::PutData("$component.getName()", new #new_command_instantiation( $component, $component, $set.getParameters()));
#else
#foreach( $set in $component.getProperty("Parameter presets").getValue() )
    frc::SmartDashboard::PutData("$component.getName(): $set.getName()", new #new_command_instantiation( $component, $component, $set.getParameters() ));
#end
#end
#end
#end
